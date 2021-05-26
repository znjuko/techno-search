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

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pqxx/pqxx>
#include <signal.h>

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

    const char *portValue = std::getenv("PORT");
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

    // shop service part only

    const char *options = "host=localhost port= 5432 user=fillinmar password=1234 dbname=technosearch";

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
    return 0;
}