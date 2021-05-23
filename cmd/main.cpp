////
//// Created by paccbet on 13.04.2021.
////
//
//#include "click_common_storage.h"
//#include "request_reader.h"
//#include "skill_delivery.h"
//#include "skill_storage.h"
//#include "skill_usecase.h"
//
//#include <boost/algorithm/string.hpp>
//#include <boost/lexical_cast.hpp>
//#include <clickhouse/client.h>
//#include <pistache/endpoint.h>
//#include <pistache/http.h>
//#include <pistache/router.h>
//
//using namespace clickhouse;
//
//using namespace Pistache;
//using namespace Rest;
//
//using namespace std;
//
//int main()
//{
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
//
//    Rest::Router router;
//
//    // readers/marshallers and i.e.
//
//    auto jsonRequestBodyReader = std::make_shared<JsonRequestBodyReader>();
//    auto requestQueryReader = std::make_shared<RequestQueryReader>();
//    auto requestReader = std::make_shared<RequestReader>();
//    auto jsonResponseWriter = std::make_shared<JsonResponseWriter>();
//    auto errorResponseWriter = std::make_shared<ErrorResponseWriter>();
//
//    // skill service part only
//
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
//
//    return 0;
//}