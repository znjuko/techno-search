//
// Created by fillinmar on 14.04.2021.
//
#ifndef TECHNO_SEARCH_STORES_SERVICE_DELIVERY_H
#define TECHNO_SEARCH_STORES_SERVICE_DELIVERY_H

#include "common_exceptions.h"
#include "request_reader.h"
#include "router_setupper.h"
#include "store_usecase.h"
#include "writer.h"

#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>
#include <pistache/endpoint.h>

using namespace Pistache;

class StoreService : public IRouterSetupper
{
  public:
    StoreService() = delete;

//    StoreService(const JsonResponseWriter responseWriter, const JsonRequestBodyReader bodyReader,
//                 const RequestQueryReader queryReader, const StoreManager manager);

    StoreService(std::shared_ptr<JsonResponseWriter> responseWriter, std::shared_ptr<JsonRequestBodyReader> bodyReader,
                 std::shared_ptr<ErrorResponseWriter> errorWriter, std::shared_ptr<RequestQueryReader> queryReader,
                 std::shared_ptr<StoreManager> manager);
    void GetStoreMetadata(const Rest::Request &req, Http::ResponseWriter res);

    void GetStoreList(const Rest::Request &req, Http::ResponseWriter res);

    void UpdateStore(const Rest::Request &req, Http::ResponseWriter res);

    void AddStore(const Rest::Request &req, Http::ResponseWriter res);

//    void SetupService(std::shared_ptr<Rest::Router> router) override;
    void SetupService(Rest::Router &router) override;

    ~StoreService() override = default;

  private:
    std::make_shared<JsonResponseWriter> responseWriter;
    std::make_shared<JsonRequestBodyReader> bodyReader;
    std::make_shared<ErrorResponseWriter> errorWriter;
    std::make_shared<RequestQueryReader> queryReader;
    std::make_shared<StoreManager> manager;

};
#endif
