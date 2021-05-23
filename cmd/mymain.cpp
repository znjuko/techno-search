//
// Created by fillinmar on 23.05.2021.
//

#include "postgres_storage.h"
#include "request_reader.h"

#include "store_delivery.h"
#include "store_storage.h"
#include "store_usecase.h"

#include "product_delivery.h"
#include "product_storage.h"
#include "product_usecase.h"

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

 struct HelloHandler : public Http::Handler {
  HTTP_PROTOTYPE(HelloHandler)
    void onRequest(const Http::Request&, Http::ResponseWriter writer) override{
        writer.send(Http::Code::Ok, "Hello, World!");
    }
};

//namespace Generic
//{
//
//void handleReady(const Rest::Request&, Http::ResponseWriter response)
//{
//    response.send(Http::Code::Ok, "1");
//}
//
//}
//
//void SetupService(Rest::Router &router)
//{
////    Routes::Post(router, "/record/:name/:value?", Routes::bind(&StatsEndpoint::doRecordMetric, this));
//    using namespace Rest;
////
////    Routes::Post(*router, "/record/:name/:value?", Routes::bind(&ProductService::AddProduct, this));
////    Routes::Get(*router, "/value/:name", Routes::bind(&ProductService::GetProductMetadata, this));
////    Routes::Get(*router, "/ready", Routes::bind(&ProductService::GetProductList, this));
//    Routes::Get(router, "/readyy", Routes::bind(&Generic::handleReady));
////    Routes::Put(*router, "/auth", Routes::bind(&ProductService::UpdateProduct, this));
//}

int main()
{
    sigset_t signals;
    if (sigemptyset(&signals) != 0
        || sigaddset(&signals, SIGTERM) != 0
        || sigaddset(&signals, SIGINT) != 0
        || sigaddset(&signals, SIGHUP) != 0
        || pthread_sigmask(SIG_BLOCK, &signals, nullptr) != 0)
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
    Port port(7770);
    auto addr = Address(Ipv4::any(), port);

    int thr = 2;

//    Address addr(Ipv4::any(), port);
//    Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));

//   auto router = std::shared_ptr<Rest::Router>();
//    Rest::Router router;
//    auto router = std::shared_ptr<Rest::Router>();
    Rest::Router router;

    // readers/marshallers and i.e.
    auto jsonRequestBodyReader = std::make_shared<JsonRequestBodyReader>();
    auto requestQueryReader = std::make_shared<RequestQueryReader>();
    auto requestReader = std::make_shared<RequestReader>();
    auto jsonResponseWriter = std::make_shared<JsonResponseWriter>();
    auto errorResponseWriter = std::make_shared<ErrorResponseWriter>();

    // shop service part only

//    try
//    {
//        pqxx::connection C("host=localhost port= 5432 user=fillinmar password=1234 dbname=technosearch");
//        pqxx::work W{C};
//
//        pqxx::result R{W.exec("SELECT * FROM store")};
//
//        std::cout << "Found " << R.size() << " records:\n";
//        for (auto row : R) std::cout << row[0].c_str() << '\n';
//        //            std::cout << row[0].type() << '\n';
//
//
//        std::cout << "OK.\n";
//    }
//    catch (std::exception const &e)
//    {
//        std::cerr << e.what() << '\n';
//        return 1;
//    }


    const char* options = "host=localhost port= 5432 user=fillinmar password=1234 dbname=test";

    auto commonPostgresStorage = std::make_shared<PostgresStorage>(options);
    auto shopStoreStorage = std::make_shared<StoreStorage>(commonPostgresStorage);
    auto shopStoreManager = std::make_shared<StoreManager>(shopStoreStorage);
//    auto shopStoreDelivery = std::make_shared<StoreService>(jsonResponseWriter, jsonRequestBodyReader, errorResponseWriter,
//                                                         requestQueryReader, shopStoreManager);
//    shopStoreDelivery->SetupService(router);

    auto shopProductStorage = std::make_shared<ProductStorage>(commonPostgresStorage);
    auto shopProductManager = std::make_shared<ProductManager>(shopProductStorage);
    auto shopProductDelivery = std::make_shared<ProductService>(jsonResponseWriter, jsonRequestBodyReader, errorResponseWriter,
                                                            requestQueryReader, shopProductManager);
   shopProductDelivery->SetupService(router);

//    SetupService(router);
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
//    auto skillDelivery = std::make_shared<MetricService>(jsonResponseWriter, jsonRequestBodyReader, errorResponseWriter,
//                                                         requestQueryReader, skillManager);
//    skillDelivery->SetupService(&router);
//    // end of skill service part
//
//    auto httpEndpoint = std::make_shared<Http::Endpoint>(addr);
//    httpEndpoint->setHandler(router.handler());
//    cout << "starting server on port " << portValue << endl;
//    httpEndpoint->serve();

    return 0;
}

//#include <pistache/endpoint.h>
//
// using namespace Pistache;
//
// struct HelloHandler : public Http::Handler {
//  HTTP_PROTOTYPE(HelloHandler)
//    void onRequest(const Http::Request&, Http::ResponseWriter writer) override{
//        writer.send(Http::Code::Ok, "Hello, World!");
//    }
//};
//
// int main() {
//    Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
//}

//#include <algorithm>
//
//#include <pistache/endpoint.h>
//#include <pistache/http.h>
//#include <pistache/router.h>
//
//using namespace Pistache;
//
//void printCookies(const Http::Request& req)
//{
//    auto cookies = req.cookies();
//    std::cout << "Cookies: [" << std::endl;
//    const std::string indent(4, ' ');
//    for (const auto& c : cookies)
//    {
//        std::cout << indent << c.name << " = " << c.value << std::endl;
//    }
//    std::cout << "]" << std::endl;
//}
//
//namespace Generic
//{
//
//void handleReady(const Rest::Request&, Http::ResponseWriter response)
//{
//    response.send(Http::Code::Ok, "1");
//}
//
//}
//
//class StatsEndpoint
//{
//  public:
//    explicit StatsEndpoint(Address addr)
//        : httpEndpoint(std::make_shared<Http::Endpoint>(addr))
//    { }
//
//    void init(size_t thr = 2)
//    {
//        auto opts = Http::Endpoint::options()
//            .threads(static_cast<int>(thr));
//        httpEndpoint->init(opts);
//        setupRoutes();
//    }
//
//    void start()
//    {
//        httpEndpoint->setHandler(router.handler());
//        httpEndpoint->serve();
//    }
//
//  private:
//    void setupRoutes()
//    {
//        using namespace Rest;
//
//        Routes::Post(router, "/record/:name/:value?", Routes::bind(&StatsEndpoint::doRecordMetric, this));
//        Routes::Get(router, "/value/:name", Routes::bind(&StatsEndpoint::doGetMetric, this));
//        Routes::Get(router, "/ready", Routes::bind(&Generic::handleReady));
//        Routes::Get(router, "/auth", Routes::bind(&StatsEndpoint::doAuth, this));
//    }
//
//    void doRecordMetric(const Rest::Request& request, Http::ResponseWriter response)
//    {
//        auto name = request.param(":name").as<std::string>();
//
//        Guard guard(metricsLock);
//        auto it = std::find_if(metrics.begin(), metrics.end(), [&](const Metric& metric) {
//          return metric.name() == name;
//        });
//
//        int val = 1;
//        if (request.hasParam(":value"))
//        {
//            auto value = request.param(":value");
//            val        = value.as<int>();
//        }
//
//        if (it == std::end(metrics))
//        {
//            metrics.push_back(Metric(std::move(name), val));
//            response.send(Http::Code::Created, std::to_string(val));
//        }
//        else
//        {
//            auto& metric = *it;
//            metric.incr(val);
//            response.send(Http::Code::Ok, std::to_string(metric.value()));
//        }
//    }
//
//    void doGetMetric(const Rest::Request& request, Http::ResponseWriter response)
//    {
//        auto name = request.param(":name").as<std::string>();
//
//        Guard guard(metricsLock);
//        auto it = std::find_if(metrics.begin(), metrics.end(), [&](const Metric& metric) {
//          return metric.name() == name;
//        });
//
//        if (it == std::end(metrics))
//        {
//            response.send(Http::Code::Not_Found, "Metric does not exist");
//        }
//        else
//        {
//            const auto& metric = *it;
//            response.send(Http::Code::Ok, std::to_string(metric.value()));
//        }
//    }
//
//    void doAuth(const Rest::Request& request, Http::ResponseWriter response)
//    {
//        printCookies(request);
//        response.cookies()
//            .add(Http::Cookie("lang", "en-US"));
//        response.send(Http::Code::Ok);
//    }
//
//    class Metric
//    {
//      public:
//        explicit Metric(std::string name, int initialValue = 1)
//            : name_(std::move(name))
//            , value_(initialValue)
//        { }
//
//        int incr(int n = 1)
//        {
//            int old = value_;
//            value_ += n;
//            return old;
//        }
//
//        int value() const
//        {
//            return value_;
//        }
//
//        const std::string& name() const
//        {
//            return name_;
//        }
//
//      private:
//        std::string name_;
//        int value_;
//    };
//
//    using Lock  = std::mutex;
//    using Guard = std::lock_guard<Lock>;
//    Lock metricsLock;
//    std::vector<Metric> metrics;
//
//    std::shared_ptr<Http::Endpoint> httpEndpoint;
//    Rest::Router router;
//};
//
//int main(int argc, char* argv[])
//{
//    Port port(9080);
//
//    int thr = 2;
//
//    if (argc >= 2)
//    {
//        port = static_cast<uint16_t>(std::stol(argv[1]));
//
//        if (argc == 3)
//            thr = std::stoi(argv[2]);
//    }
//
//    Address addr(Ipv4::any(), port);
//
//    std::cout << "Cores = " << hardware_concurrency() << std::endl;
//    std::cout << "Using " << thr << " threads" << std::endl;
//
//    StatsEndpoint stats(addr);
//
//    stats.init(thr);
//    stats.start();
//}
