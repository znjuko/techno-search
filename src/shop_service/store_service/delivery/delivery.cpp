//
// Created by fillinmar on 14.04.2021.
//

#include "delivery.h"

void StoreService::GetStoreMetadata(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<GetStoreMetadataRequest> reqReader;
    try
    {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong storage id", &res);
        return;
    }

    std::shared_ptr<GetStoreMetadataResponse> respWriter;
    try
    {
        respWriter = manager.GetStoreMetadata(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void StoreService::GetStoreList(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<GetStoreMetadataRequest> reqReader;
    try
    {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong storages` name", &res);
        return;
    }

    std::shared_ptr<GetStoreMetadataResponse> respWriter;
    try
    {
        respWriter = manager.GetStoreList(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void StoreService::UpdateStore(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<UpdateStoreRequest> reqReader;
    try
    {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::exception &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong store id", &res);
        return;
    }

    std::shared_ptr<UpdateStoreResponse> respWriter;
    try
    {
        respWriter = manager.UpdateStore(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void StoreService::AddStore(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<AddStoreRequest> reqReader;
    try
    {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::exception &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong product ids", &res);
        return;
    }

    std::shared_ptr<AddStoreResponse> respWriter;
    try
    {
        respWriter = manager.AddStore(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void StoreService::SetupService(Rest::Router router)
{
    router.addRoute(Http::Method::Get, "api/v1/shop/store",
                    Pistache::Rest::Routes::bind(&StoreService::GetStoreMetadata, this));

    router.addRoute(Http::Method::Get, "api/v1/shop/store/search",
                    Pistache::Rest::Routes::bind(&StoreService::GetStoreList, this));

    router.addRoute(Http::Method::Post, "api/v1/shop", Pistache::Rest::Routes::bind(&StoreService::AddStore, this));

    router.addRoute(Http::Method::Put, "api/v1/shop", Pistache::Rest::Routes::bind(&StoreService::UpdateStore, this));
}

StoreService::StoreService(const JsonResponseWriter &responseWriter, const JsonRequestBodyReader &bodyReader,
                           const RequestQueryReader &queryReader, const StoreManager &manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), queryReader(queryReader), manager(manager)
{
}
