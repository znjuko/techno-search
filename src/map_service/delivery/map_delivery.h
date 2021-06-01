//
// Created by Никита Черных on 22.05.2021.
//

#ifndef TECHNO_SEARCH_MAP_DELIVERY_H
#define TECHNO_SEARCH_MAP_DELIVERY_H

#include "map_request_models.h"
#include "map_storage.h"
#include "map_usecase.h"
#include "request_reader.h"
#include "router_setupper.h"
#include "writer.h"

#include <pistache/endpoint.h>
#include <pistache/router.h>

using namespace Pistache;

class MapService : IRouterSetupper
{
  public:
    MapService() = delete;

    MapService(std::shared_ptr<JsonResponseWriter> responseWriter, std::shared_ptr<JsonRequestBodyReader> bodyReader,
               std::shared_ptr<ErrorResponseWriter> errorWriter, std::shared_ptr<RequestReader> requestReader, std::shared_ptr<RequestQueryReader> queryReader,
               std::shared_ptr<MapManager> manager);

    void CreateStoreMap(const Rest::Request &req, Http::ResponseWriter res);

    void GetStoreMap(const Rest::Request &req, Http::ResponseWriter res);

    void GetAdjacency(const Rest::Request &req, Http::ResponseWriter res);

    void GetStorePath(const Rest::Request &req, Http::ResponseWriter res);

    void SetupService(Rest::Router &router) override;

    ~MapService() override = default;

  private:
    std::shared_ptr<JsonResponseWriter> responseWriter;
    std::shared_ptr<JsonRequestBodyReader> bodyReader;
    std::shared_ptr<RequestReader> requestReader;
    std::shared_ptr<ErrorResponseWriter> errorWriter;
    std::shared_ptr<RequestQueryReader> queryReader;
    std::shared_ptr<MapManager> manager;
};

#endif // TECHNO_SEARCH_MAP_DELIVERY_H
