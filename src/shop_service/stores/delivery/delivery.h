//
// Created by fillinmar on 14.04.2021.
//
#ifndef TECHNO_SEARCH_STORES_SERVICE_DELIVERY_H
#define TECHNO_SEARCH_STORES_SERVICE_DELIVERY_H

#include "reader.h"
#include "router_setupper.h"
#include "usecase.h"
#include "writer.h"

#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>
#include <pistache/endpoint.h>

using namespace Pistache;

class StoreService : public IRouterSetupper
{
  public:
    StoreService() = delete;

    StoreService(const JsonResponseWriter &responseWriter, const JsonRequestBodyReader &bodyReader,
                 const RequestQueryReader &queryReader, const StoreManager &manager);

    void GetStoreMetadata(const Http::Request &req, Http::ResponseWriter res);

    void GetStoreList(const Http::Request &req, Http::ResponseWriter res);

    void UpdateStore(const Http::Request &req, Http::ResponseWriter res);

    void AddStore(const Http::Request &req, Http::ResponseWriter res);

    void SetupService(Rest::Router router) override;

    ~StoreService() override = default;

  private:
    JsonResponseWriter responseWriter;
    JsonRequestBodyReader bodyReader;
    ErrorResponseWriter errorWriter;
    RequestQueryReader queryReader;
    StoreManager manager;
};
#endif
