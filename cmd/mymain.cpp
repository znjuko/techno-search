//
// Created by fillinmar on 23.05.2021.
//

#include "postgres_storage.h"
#include "product_delivery.h"
#include "product_storage.h"
#include "product_usecase.h"
#include "request_reader.h"
#include "store_delivery.h"
#include "store_storage.h"
#include "store_usecase.h"

//#include "skill_delivery.h"
//#include "skill_storage.h"
//#include "skill_usecase.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
//#include <clickhouse/client.h>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pqxx/pqxx>
#include <signal.h>

// using namespace clickhouse;
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
    //    auto portValue = std::getenv("PORT");
    //    Port port;
    //    try
    //    {
    //        port = Port(portValue);
    //    }
    //    catch (const std::exception &e)
    //    {
    //        cout << "ERROR: " << e.what() << endl;
    //        return 0;
    //    }
    //    auto addr = Address(Ipv4::any(), port);
    //
    //    auto threadCountValue = std::getenv("THREADS");
    //    if (!threadCountValue)
    //    {
    //        cout << "ERROR: "
    //             << "empty thread number" << endl;
    //        return 0;
    //    }
    //    int threadCount = 0;
    //    try
    //    {
    //        threadCount = boost::lexical_cast<int>(threadCountValue);
    //    }
    //    catch (const std::exception &e)
    //    {
    //        cout << "ERROR: "
    //             << "wrong thread count value " << threadCountValue << endl;
    //        return 0;
    //    }
    Port port(7781);
    auto addr = Address(Ipv4::any(), port);

    int thr = 2;

    Rest::Router router;

    // readers/marshallers and i.e.
    auto jsonRequestBodyReader = std::make_shared<JsonRequestBodyReader>();
    auto requestQueryReader = std::make_shared<RequestQueryReader>();
    auto requestReader = std::make_shared<RequestReader>();
    auto jsonResponseWriter = std::make_shared<JsonResponseWriter>();
    auto errorResponseWriter = std::make_shared<ErrorResponseWriter>();

    // shop service part only
    const char *options = "host=localhost port= 5432 user=fillinmar password=1234 dbname=technosearch";

    try
    {
        pqxx::connection C("host=localhost port= 5432 user=fillinmar password=1234 dbname=technosearch");
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

    // end of shop service part

    auto httpEndpoint = std::make_shared<Http::Endpoint>(addr);
    httpEndpoint->setHandler(router.handler());
    cout << "starting server on port " << port << endl;
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
    //   Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
    return 0;

    // skill service part only

    //    auto clickOpts = ClientOptions();
    //
    //    auto clickHost = std::getenv("CLICK_HOST");
    //    if (!clickHost)
    //    {
    //        cout << "ERROR: "
    //             << "empty clickhouse hostname" << endl;
    //        return 0;
    //    }
    //    clickOpts.SetHost(clickHost);
    //    auto clickPort = std::getenv("CLICK_PORT");
    //    if (!clickPort)
    //    {
    //        cout << "ERROR: "
    //             << "empty clickhouse port" << endl;
    //        return 0;
    //    }
    //    try
    //    {
    //        clickOpts.SetPort(boost::lexical_cast<int>(clickPort));
    //    }
    //    catch (const std::exception &e)
    //    {
    //        cout << "ERROR: " << e.what() << endl;
    //    }
    //    auto clickUser = std::getenv("CLICK_USER");
    //    if (!clickUser)
    //    {
    //        cout << "ERROR: "
    //             << "empty clickhouse user" << endl;
    //        return 0;
    //    }
    //    clickOpts.SetUser(clickUser);
    //    auto clickPassword = std::getenv("CLICK_PASS");
    //    if (!clickPassword)
    //    {
    //        cout << "ERROR: "
    //             << "empty clickhouse pass" << endl;
    //        return 0;
    //    }
    //    clickOpts.SetUser(clickPassword);
    //    auto clickDB = std::getenv("CLICK_DB");
    //    if (!clickDB)
    //    {
    //        cout << "ERROR: "
    //             << "empty clickhouse database" << endl;
    //        return 0;
    //    }
    //    clickOpts.SetDefaultDatabase(clickDB);
    //
    //    auto commonClickStorage = std::make_shared<ClickStorage>(clickOpts);
    //    auto skillStorage = std::make_shared<MetricStorage>(commonClickStorage);
    //    auto skillManager = std::make_shared<MetricManager>(skillStorage);
    //    auto skillDelivery = std::make_shared<MetricService>(jsonResponseWriter, jsonRequestBodyReader,
    //    errorResponseWriter,
    //                                                         requestQueryReader, skillManager);
    //    skillDelivery->SetupService(&router);
    //    // end of skill service part
    //
    //    auto httpEndpoint = std::make_shared<Http::Endpoint>(addr);
    //    httpEndpoint->setHandler(router.handler());
    //    cout << "starting server on port " << portValue << endl;
    //    httpEndpoint->serve();

    //    return 0;
}
