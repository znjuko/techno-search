//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCTS_SERVICE_DELIVERY_H
#define TECHNO_SEARCH_PRODUCTS_SERVICE_DELIVERY_H

#include "common_exceptions.h"
#include "product_usecase.h"
#include "request_reader.h"
#include "router_setupper.h"
#include "writer.h"

#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>
#include <pistache/endpoint.h>
#include <product_usecase.h>

using namespace Pistache;

class ProductService : public IRouterSetupper
{
  public:
    ProductService() = delete;

    ProductService(std::shared_ptr<JsonResponseWriter> responseWriter, std::shared_ptr<JsonRequestBodyReader> bodyReader,
        std::shared_ptr<ErrorResponseWriter> errorWriter, std::shared_ptr<RequestQueryReader> queryReader,
        std::shared_ptr<ProductManager> manager);

    void GetProductMetadata(const Rest::Request &req, Http::ResponseWriter res);

    void GetProductList(const Rest::Request &req, Http::ResponseWriter res);

    void UpdateProduct(const Rest::Request &req, Http::ResponseWriter res);

    void AddProduct(const Rest::Request &req, Http::ResponseWriter res);

    void handleReady(const Rest::Request&, Http::ResponseWriter response);

//    void SetupService(std::shared_ptr<Rest::Router> router) override;
    void SetupService(Rest::Router &router) override;

    ~ProductService() override = default;

  private:
    std::shared_ptr<JsonResponseWriter> responseWriter;
    std::shared_ptr<JsonRequestBodyReader> bodyReader;
    std::shared_ptr<ErrorResponseWriter> errorWriter;
    std::shared_ptr<RequestQueryReader> queryReader;
    std::shared_ptr<ProductManager> manager;

};
#endif
