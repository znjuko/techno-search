//
// Created by Никита Черных on 21.05.2021.
//

#ifndef TECHNO_ALGO_PATH_DELIVERY_H
#define TECHNO_ALGO_PATH_DELIVERY_H

#include "path_models.h"
#include "path_usecase.h"
#include "request_reader.h"
#include "router_setupper.h"
#include "writer.h"

#include <pistache/endpoint.h>
#include <pistache/router.h>

using namespace Pistache;

class PathService : public IRouterSetupper
{
  public:
    PathService() = delete;

    PathService(std::shared_ptr<JsonResponseWriter> responseWriter, std::shared_ptr<JsonRequestBodyReader> bodyReader,
                std::shared_ptr<RequestReader> requestReader, std::shared_ptr<ErrorResponseWriter> errorWriter,
                std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<PathManager> manager);

    void GetStorePath(const Rest::Request &req, Http::ResponseWriter res);

    void SetupService(Rest::Router *router) override;

    ~PathService() override = default;

  private:
    std::shared_ptr<JsonResponseWriter> responseWriter;
    std::shared_ptr<JsonRequestBodyReader> bodyReader;
    std::shared_ptr<RequestReader> requestReader;
    std::shared_ptr<ErrorResponseWriter> errorWriter;
    std::shared_ptr<RequestQueryReader> queryReader;
    std::shared_ptr<PathManager> manager;
};

#endif // TECHNO_ALGO_PATH_DELIVERY_H
