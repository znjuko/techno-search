//
// Created by paccbet on 14.04.2021.
//

#include "delivery.h"

void MetricService::GetCounterPopularityByShop(Http::Request req, Http::ResponseWriter res)
{
    std::shared_ptr<GetCountersPopularityByShopRequest> reqReader;
    this->queryReader.ReadRequest(reqReader, req);

    auto respWriter = this->manager.GetCounterPopularityByShop(reqReader);
    this->responseWriter.WriteResponse(respWriter, res);
}

void MetricService::GetProductPopularityByShop(Http::Request req, Http::ResponseWriter res)
{
    std::shared_ptr<GetProductPopularityByShopRequest> reqReader;
    this->queryReader.ReadRequest(reqReader, req);

    auto respWriter = this->manager.GetProductsPopularityByShop(reqReader);
    this->responseWriter.WriteResponse(respWriter, res);
}

void MetricService::GetProductsTotalPopularity(Http::Request req, Http::ResponseWriter res)
{
    std::shared_ptr<GetProductsTotalPopularityRequest> reqReader;
    this->queryReader.ReadRequest(reqReader, req);

    auto respWriter = this->manager.GetProductsTotalPopularity(reqReader);
    this->responseWriter.WriteResponse(respWriter, res);
}

void MetricService::SetupService(Rest::Router router)
{
    router.addRoute(
            Http::Method::Get,
            "api/v1/metrics/shop/counters",
            Pistache::Rest::Routes::bind(&MetricService::GetCounterPopularityByShop, this));

    router.addRoute(
            Http::Method::Get,
            "api/v1/metrics/shop/products",
            Pistache::Rest::Routes::bind(&MetricService::GetProductPopularityByShop, this));

    router.addRoute(
            Http::Method::Get,
            "api/v1/metrics/products",
            Pistache::Rest::Routes::bind(&MetricService::GetProductsTotalPopularity, this));
}


MetricService::MetricService(const JsonResponseWriter &responseWriter, const JsonRequestBodyReader &bodyReader,
                             const RequestQueryReader &queryReader, const MetricManager &manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), queryReader(queryReader), manager(manager)
{
}
