//
// Created by paccbet on 13.04.2021.
//

#include "adapter.h"
#include "click_common_storage.h"
#include "finder.h"
#include "map_delivery.h"
#include "map_storage.h"
#include "map_usecase.h"
#include "postgres_storage.h"
#include "product_delivery.h"
#include "product_storage.h"
#include "product_usecase.h"
#include "request_reader.h"
#include "skill_delivery.h"
#include "skill_storage.h"
#include "skill_usecase.h"
#include "store_delivery.h"
#include "store_storage.h"
#include "store_usecase.h"

#include <boost/lexical_cast.hpp>
#include <clickhouse/client.h>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pqxx/pqxx>
#include <signal.h>

using namespace clickhouse;

using json = nlohmann::json;

using namespace Pistache;
using namespace Rest;

using namespace std;

int main()
{
    sigset_t signals;
    if (sigemptyset(&signals) != 0 || sigaddset(&signals, SIGTERM) != 0 || sigaddset(&signals, SIGINT) != 0 ||
        sigaddset(&signals, SIGHUP) != 0 || pthread_sigmask(SIG_BLOCK, &signals, nullptr) != 0)
    {
        perror("install signal handler failed");
        return 1;
    }

    auto portValue = std::getenv("PORT");
    Port port;
    try
    {
        port = Port(portValue);
    }
    catch (const std::exception &e)
    {
        cout << "ERROR: " << e.what() << endl;
        return 0;
    }
    auto addr = Address(Ipv4::any(), port);

    auto threadCountValue = std::getenv("THREADS");
    if (!threadCountValue)
    {
        cout << "ERROR: "
             << "empty thread number" << endl;
        return 0;
    }
    int threadCount = 0;
    try
    {
        threadCount = boost::lexical_cast<int>(threadCountValue);
    }
    catch (const std::exception &e)
    {
        cout << "ERROR: "
             << "wrong thread count value " << threadCountValue << endl;
        return 0;
    }

    Rest::Router router;

    // readers/marshallers and i.e.

    auto jsonRequestBodyReader = std::make_shared<JsonRequestBodyReader>();
    auto requestQueryReader = std::make_shared<RequestQueryReader>();
    auto requestReader = std::make_shared<RequestReader>();
    auto jsonResponseWriter = std::make_shared<JsonResponseWriter>();
    auto errorResponseWriter = std::make_shared<ErrorResponseWriter>();

    // skill service part only

    auto clickOpts = ClientOptions();

    auto clickHost = std::getenv("CLICK_HOST");
    if (!clickHost)
    {
        cout << "ERROR: "
             << "empty clickhouse hostname" << endl;
        return 0;
    }
    clickOpts.SetHost(clickHost);
    auto clickPort = std::getenv("CLICK_PORT");
    if (!clickPort)
    {
        cout << "ERROR: "
             << "empty clickhouse port" << endl;
        return 0;
    }
    try
    {
        clickOpts.SetPort(boost::lexical_cast<int>(clickPort));
    }
    catch (const std::exception &e)
    {
        cout << "ERROR: " << e.what() << endl;
    }
    auto clickUser = std::getenv("CLICK_USER");
    if (!clickUser)
    {
        cout << "ERROR: "
             << "empty clickhouse user" << endl;
        return 0;
    }
    clickOpts.SetUser(clickUser);

    auto commonClickStorage = std::make_shared<ClickStorage>(clickOpts);
    auto skillStorage = std::make_shared<MetricStorage>(commonClickStorage);
    auto skillManager = std::make_shared<MetricManager>(skillStorage);
    auto skillDelivery = std::make_shared<MetricService>(jsonResponseWriter, jsonRequestBodyReader, errorResponseWriter,
                                                         requestQueryReader, skillManager);
    skillDelivery->SetupService(router);

    // "host=localhost port= 5432 user=fillinmar password=1234 dbname=technosearch"
    auto options = std::getenv("DB_OPTIONS");
    try
    {
        pqxx::connection C(options);
        std::cout << "Connected to " << C.dbname() << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    auto commonPostgresStorage = std::make_shared<PostgresStorage>(options);
    auto shopStoreStorage = std::make_shared<StoreStorage>(commonPostgresStorage);
    auto shopStoreManager = std::make_shared<StoreManager>(shopStoreStorage);
    auto shopStoreDelivery = std::make_shared<StoreService>(jsonResponseWriter, jsonRequestBodyReader,
                                                            errorResponseWriter, requestQueryReader, shopStoreManager);
    shopStoreDelivery->SetupService(router);

    auto shopProductStorage = std::make_shared<ProductStorage>(commonPostgresStorage);
    auto shopProductManager = std::make_shared<ProductManager>(shopProductStorage);
    auto shopProductDelivery = std::make_shared<ProductService>(
        jsonResponseWriter, jsonRequestBodyReader, errorResponseWriter, requestQueryReader, shopProductManager);
    shopProductDelivery->SetupService(router);

    // map service only
    auto mongoURI = std::getenv("MONGO_URI");
    if (!mongoURI)
    {
        cout << "ERROR: "
             << "empty mongo uri" << endl;
        return 0;
    }
    auto mongoDB = std::getenv("MONGO_DB");
    if (!mongoURI)
    {
        cout << "ERROR: "
             << "empty mongo db" << endl;
        return 0;
    }
    mongocxx::instance instance{}; // This should be done only once.
    // "mongodb://localhost:27017"
    mongocxx::uri uri(mongoURI);
    mongocxx::client client(uri);
    mongocxx::database db = client[mongoDB];
    auto dbShared = std::make_shared<mongocxx::database>(db);

    auto mapStorage = std::make_shared<MapStorage>(dbShared);
    auto mapManager =
        std::make_shared<MapManager>(std::make_shared<Adapter>(), mapStorage, std::make_shared<PathFinder>());
    auto mapDelivery = std::make_shared<MapService>(
        jsonResponseWriter, jsonRequestBodyReader, errorResponseWriter,
        std::make_shared<RequestReader>(),requestQueryReader,  mapManager);
    mapDelivery->SetupService(router);
    // starting service
    auto httpEndpoint = std::make_shared<Http::Endpoint>(addr);
    httpEndpoint->setHandler(router.handler());
    cout << "starting server on port " << portValue << endl;
    httpEndpoint->serveThreaded();

    int signal = 0;
    int status = sigwait(&signals, &signal);
    if (status == 0)
    {
        std::cout << "received signal " << signal << std::endl;
    }
    else
    {
        std::cerr << "sigwait returns " << status << std::endl;
    }

    httpEndpoint->shutdown();

    return 0;
}