//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_SKILL_DELIVERY_H
#define TECHNO_SEARCH_SKILL_DELIVERY_H

#include "reader.h"
#include "router_setupper.h"
#include "usecase.h"
#include "writer.h"

#include <pistache/endpoint.h>

using namespace Pistache;

/* TODO(n.chernyh) : add smart pointers (

   for writers/readers - add shared
   for usecase - add unique ptr

  ) */

class MetricService : public IRouterSetupper
{
  public:
    MetricService() = delete;

    MetricService(const JsonResponseWriter &responseWriter, const JsonRequestBodyReader &bodyReader,
                  const RequestQueryReader &queryReader, const MetricManager &manager);

    void GetCounterPopularityByShop(Http::Request req, Http::ResponseWriter res);

    void GetProductPopularityByShop(Http::Request req, Http::ResponseWriter res);

    void GetProductsTotalPopularity(Http::Request req, Http::ResponseWriter res);

    void SetupService(Rest::Router router) override;

    ~MetricService() override = default;

  private:
    JsonResponseWriter responseWriter;
    JsonRequestBodyReader bodyReader;
    RequestQueryReader queryReader;
    MetricManager manager;
};

#endif // TECHNO_SEARCH_SKILL_DELIVERY_H
