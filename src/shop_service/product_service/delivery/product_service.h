//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_SERVICE_H
#define TECHNO_SEARCH_STORE_SERVICE_H

#include "request_reader.h"
#include "router_setupper.h"
#include "usecase.h"
#include "writer.h"

#include <pistache/endpoint.h>

using namespace Pistache;

class ProductService : public IRouterSetupper
{
  private:
    RequestReader requestReader;
    ResponseWriter responseWriter;
    StoreManager store;

  public:
    ProductService() = delete;
    void GetProductMetadata(Http::RequestReader req, Http : ResponseWriter res);
    void GetListProduct(Http::RequestReader req, Http : ResponseWriter res);
    void AddProduct(Http::RequestReader req, Http : ResponseWriter res);
    void UpdateProduct(Http::RequestReader req, Http : ResponseWriter res);
    void SetupService(Http : Router router) override;
    ~ProductService() = default;
};
#endif // TECHNO_SEARCH_STORE_SERVICE_H
