//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_SERVICE_H
#define TECHNO_SEARCH_STORE_SERVICE_H

#include "reader.h"
#include "router_setupper.h"
#include "usecase.h"
#include "writer.h"

#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>
#include <pistache/endpoint.h>

using namespace Pistache;

class ProductService : public IRouterSetupper
{
  public:
    ProductService() = delete;

    ProductService(const JsonResponseWriter &responseWriter, const JsonRequestBodyReader &bodyReader,
                   const RequestQueryReader &queryReader, const ProductManager &manager);

    void GetProductMetadata(const Http::Request &req, Http::ResponseWriter res);

    void GetProductList(const Http::Request &req, Http::ResponseWriter res);

    void UpdateProduct(const Http::Request &req, Http::ResponseWriter res);

    void AddProduct(const Http::Request &req, Http::ResponseWriter res);

    void SetupService(Rest::Router router) override;

    ~ProductService() override = default;

  private:
    JsonResponseWriter responseWriter;
    JsonRequestBodyReader bodyReader;
    ErrorResponseWriter errorWriter;
    RequestQueryReader queryReader;
    ProductManager manager;
};
#endif // TECHNO_SEARCH_STORE_SERVICE_H
