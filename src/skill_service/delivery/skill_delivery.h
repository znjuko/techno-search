//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_SKILL_DELIVERY_H
#define TECHNO_SEARCH_SKILL_DELIVERY_H

#include "common_exceptions.h"
#include "request_reader.h"
#include "router_setupper.h"
#include "skill_usecase.h"
#include "writer.h"

#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>
#include <pistache/endpoint.h>

using namespace Pistache;

class MetricService : public IRouterSetupper
{
  public:
    MetricService() = delete;

    MetricService(std::shared_ptr<JsonResponseWriter> responseWriter, std::shared_ptr<JsonRequestBodyReader> bodyReader,
                  std::shared_ptr<ErrorResponseWriter> errorWriter, std::shared_ptr<RequestQueryReader> queryReader,
                  std::shared_ptr<MetricManager> manager);

    void GetCounterPopularityByShop(const Rest::Request &req, Http::ResponseWriter res);

    void GetProductPopularityByShop(const Rest::Request &req, Http::ResponseWriter res);

    void GetProductsTotalPopularity(const Rest::Request &req, Http::ResponseWriter res);

    void SetupService(Rest::Router *router) override;

    ~MetricService() override = default;

  private:
    std::shared_ptr<JsonResponseWriter> responseWriter;
    std::shared_ptr<JsonRequestBodyReader> bodyReader;
    std::shared_ptr<ErrorResponseWriter> errorWriter;
    std::shared_ptr<RequestQueryReader> queryReader;
    std::shared_ptr<MetricManager> manager;
};

#endif // TECHNO_SEARCH_SKILL_DELIVERY_H
