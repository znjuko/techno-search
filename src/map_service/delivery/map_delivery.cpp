//
// Created by Никита Черных on 22.05.2021.
//

#include "map_delivery.h"

void MapService::CreateStoreMap(const Request &req, Http::ResponseWriter res)
{
    auto mapReader = std::make_shared<StoreMap>();
    try
    {
        bodyReader->ReadRequest(mapReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }

    auto rawMapReader = std::make_shared<RawStoreMap>();
    try
    {
        bodyReader->ReadRequest(rawMapReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }

    try
    {
        manager->CreateStoreMap(mapReader, rawMapReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }

    res.send(Http::Code::Ok, "map created");
}

void MapService::GetStoreMap(const Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<StoreActionRequest>();
    try
    {
        queryReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }

    std::shared_ptr<RawStoreMap> respWriter;
    try
    {
        respWriter = manager->GetStoreMap(reqReader->StoreID);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void MapService::GetAdjacency(const Request &req, Http::ResponseWriter res)
{

    auto reqReader = std::make_shared<StoreActionRequest>();
    try
    {
        queryReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "empty id", &res);
        return;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong format of store id, need int", &res);
        return;
    }

    std::shared_ptr<AdjacencyPoints> respWriter;
    try
    {
        respWriter = manager->GetStoreAdjacencyCoords(reqReader->StoreID);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }

    responseWriter->WriteResponse(respWriter, &res);
}

void MapService::GetStorePath(const Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<GetStorePathRequest>();
    try
    {
        requestReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong shop ID value", &res);
        return;
    }

    std::shared_ptr<GetStorePathResponse> respWriter;
    try
    {
        respWriter = manager->GetShopPath(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void MapService::SetupService(Router &router)
{
    router.addRoute(Http::Method::Get, "api/v1/shop/:shopID/map",
                    Pistache::Rest::Routes::bind(&MapService::GetStoreMap, this));
    router.addRoute(Http::Method::Get, "api/v1/shop/:shopID/map/adj",
                    Pistache::Rest::Routes::bind(&MapService::GetAdjacency, this));
    router.addRoute(Http::Method::Get, "api/v1/shop/:shopID/map/find",
                    Pistache::Rest::Routes::bind(&MapService::GetStorePath, this));

    router.addRoute(Http::Method::Post, "api/v1/shop/:shopID/map",
                    Pistache::Rest::Routes::bind(&MapService::CreateStoreMap, this));
}

MapService::MapService(std::shared_ptr<JsonResponseWriter> responseWriter,
                       std::shared_ptr<JsonRequestBodyReader> bodyReader, std::shared_ptr<RequestReader> requestReader,
                       std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<MapManager> manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), errorWriter(errorWriter), queryReader(queryReader),
      manager(manager), requestReader(requestReader)
{
}