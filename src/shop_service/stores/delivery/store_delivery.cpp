//
// Created by fillinmar on 14.04.2021.
//

#include "store_delivery.h"

void StoreService::GetStoreMetadata(const Rest::Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<GetStoreMetadataRequest>();
//    std::shared_ptr<GetStoreMetadataRequest> reqReader;
    try
    {
        queryReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong storage id", &res);
        return;
    }

    auto respWriter = std::make_shared<GetStoreMetadataResponse>();

//    std::shared_ptr<GetStoreMetadataResponse> respWriter;
    try
    {
        respWriter = manager->GetStoreMetadata(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void StoreService::GetStoreList(const Rest::Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<GetStoreListRequest>();
//    std::shared_ptr<GetStoreListRequest> reqReader;
    try
    {
        queryReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong storages` name", &res);
        return;
    }

//    std::shared_ptr<GetStoreListResponse> respWriter;
    auto respWriter = std::make_shared<GetStoreListResponse>();
    try
    {
        respWriter = manager->GetStoreList(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void StoreService::UpdateStore(const Rest::Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<UpdateStoreRequest>();
//    std::shared_ptr<UpdateStoreRequest> reqReader;
    try
    {
        bodyReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong store id", &res);
        return;
    }

//    std::shared_ptr<UpdateStoreResponse> respWriter;
    auto respWriter = std::make_shared<UpdateStoreResponse>();
    try
    {
        respWriter = manager->UpdateStore(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void StoreService::AddStore(const Rest::Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<AddStoreRequest>();
//    std::shared_ptr<AddStoreRequest> reqReader;
    try
    {
        bodyReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong store metadata", &res);
        return;
    }

//    std::shared_ptr<AddStoreResponse> respWriter;
    auto respWriter = std::make_shared<AddStoreResponse>();
    try
    {
        respWriter = manager->AddStore(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

//void StoreService::SetupService(std::shared_ptr<Rest::Router> router)
//{
////    Routes::Post(router, "/record/:name/:value?", Routes::bind(&StatsEndpoint::doRecordMetric, this));
//    router->addRoute(Http::Method::Get, "api/v1/store",
//                    Pistache::Rest::Routes::bind(&StoreService::GetStoreMetadata, this));
//
//    router->addRoute(Http::Method::Get, "api/v1/store/search",
//                    Pistache::Rest::Routes::bind(&StoreService::GetStoreList, this));
//
//    router->addRoute(Http::Method::Post, "api/v1/store", Pistache::Rest::Routes::bind(&StoreService::AddStore, this));
//
//    router->addRoute(Http::Method::Put, "api/v1/store", Pistache::Rest::Routes::bind(&StoreService::UpdateStore, this));
//}
void StoreService::SetupService(Rest::Router &router)
{
//    Routes::Post(router, "/record/:name/:value?", Routes::bind(&StatsEndpoint::doRecordMetric, this));
    using namespace Rest;

    Routes::Post(router, "/records/:name/:value?", Routes::bind(&StoreService::AddStore, this));
    Routes::Get(router, "/store", Routes::bind(&StoreService::GetStoreMetadata, this));
    Routes::Get(router, "/store/search", Routes::bind(&StoreService::GetStoreList, this));
    Routes::Put(router, "/auths", Routes::bind(&StoreService::UpdateStore, this));
}

StoreService::StoreService(std::shared_ptr<JsonResponseWriter> responseWriter,
                             std::shared_ptr<JsonRequestBodyReader> bodyReader,
                             std::shared_ptr<ErrorResponseWriter> errorWriter,
                             std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<StoreManager> manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), queryReader(queryReader), manager(manager),
      errorWriter(errorWriter)
{
}


