//
// Created by Никита Черных on 21.05.2021.
//

#include "path_delivery.h"
#include "common_exceptions.h"

void PathService::SetupService(Rest::Router *router)
{
    router->addRoute(Http::Method::Get, "api/v1/shop/:shopID/map/find",
                     Pistache::Rest::Routes::bind(&PathService::GetStorePath, this));
}

PathService::PathService(std::shared_ptr<JsonResponseWriter> responseWriter,
                         std::shared_ptr<JsonRequestBodyReader> bodyReader,
                         std::shared_ptr<RequestReader> requestReader, std::shared_ptr<ErrorResponseWriter> errorWriter,
                         std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<PathManager> manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), errorWriter(errorWriter), queryReader(queryReader),
      manager(manager), requestReader(requestReader)
{
}

void PathService::GetStorePath(const Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<GetStorePathRequest>();
    try
    {
        requestReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue& e)
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
