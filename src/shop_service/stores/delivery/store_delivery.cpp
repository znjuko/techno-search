//
// Created by fillinmar on 14.04.2021.
//

#include "store_delivery.h"

#include <utility>

void StoreService::GetStoreMetadata(const Rest::Request &req, Http::ResponseWriter res)
{

    auto reqReader = std::make_shared<GetStoreMetadataRequest>();
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

//    auto respWriter = std::make_shared<GetStoreMetadataResponse>();

    std::shared_ptr<GetStoreMetadataResponse> respWriter;
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

    std::shared_ptr<GetStoreListResponse> respWriter;
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

    auto reqReader2 = std::make_shared<UpdateStoreRequest>();
    try
    {
        bodyReader->ReadRequest(reqReader2, req);
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

    std::shared_ptr<UpdateStoreResponse> respWriter;
    try
    {
        respWriter = manager->UpdateStore(reqReader, reqReader2);
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

    auto reqReader2 = std::make_shared<AddStoreRequest>();
    try
    {
        bodyReader->ReadRequest(reqReader2, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong metadata", &res);
        return;
    }

    std::shared_ptr<AddStoreResponse> respWriter;
    try
    {
        respWriter = manager->AddStore(reqReader, reqReader2);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void StoreService::SetupService(Rest::Router &router)
{
    using namespace Rest;

    Routes::Post(router, "/store", Routes::bind(&StoreService::AddStore, this));
    Routes::Get(router, "/store", Routes::bind(&StoreService::GetStoreMetadata, this));
    Routes::Get(router, "/store/search", Routes::bind(&StoreService::GetStoreList, this));
    Routes::Put(router, "/store", Routes::bind(&StoreService::UpdateStore, this));
}

StoreService::StoreService(std::shared_ptr<JsonResponseWriter> responseWriter,
                             std::shared_ptr<JsonRequestBodyReader> bodyReader,
                             std::shared_ptr<ErrorResponseWriter> errorWriter,
                             std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<StoreManager> manager)
    : responseWriter(std::move(responseWriter)), bodyReader(std::move(bodyReader)), queryReader(std::move(queryReader)), manager(std::move(manager)),
      errorWriter(std::move(errorWriter))
{
}



