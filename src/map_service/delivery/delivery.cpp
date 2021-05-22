//
// Created by Никита Черных on 22.05.2021.
//

#include "delivery.h"

MapService::MapService(std::shared_ptr<JsonResponseWriter> responseWriter,
                       std::shared_ptr<JsonRequestBodyReader> bodyReader, std::shared_ptr<RequestReader> requestReader,
                       std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<MapManager> manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), errorWriter(errorWriter), queryReader(queryReader),
      manager(manager), requestReader(requestReader)
{
}

void MapService::SetupService(Rest::Router *router)
{
    router->addRoute(Http::Method::Get, "api/v1/shop/:shopID/map",
                     Pistache::Rest::Routes::bind(&MapService::GetShopMap, this));

    router->addRoute(Http::Method::Post, "api/v1/shop/:shopID/map",
                     Pistache::Rest::Routes::bind(&MapService::CreateShopMap, this));

    router->addRoute(Http::Method::Delete, "api/v1/shop/:shopID/map",
                     Pistache::Rest::Routes::bind(&MapService::DeleteShopMap, this));
}

void MapService::CreateShopMap(const Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<IMarshaller> mapReader = std::make_shared<StoreMap>();
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
    // some logic ...
}

void MapService::GetShopMap(const Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<StoreMapActionRequest>();
    try
    {
        requestReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    // some logic ...
}

void MapService::DeleteShopMap(const Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<StoreMapActionRequest>();
    try
    {
        requestReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    // some logic ...
}
