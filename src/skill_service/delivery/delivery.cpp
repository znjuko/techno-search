//
// Created by paccbet on 14.04.2021.
//

#include "delivery.h"

void MetricService::GetCounterPopularityByShop(Http::Request req, Http::Response res)
{
}

void MetricService::GetProductPopularityByShop(Http::Request req, Http::Response res)
{
}

void MetricService::GetProductsTotalPopularity(Http::Request req, Http::Response res)
{
}

void MetricService::SetupService(Rest::Router router)
{
}

MetricService::MetricService(const JsonResponseWriter &responseWriter, const JsonRequestBodyReader &bodyReader,
                             const RequestQueryReader &queryReader, const MetricManager &manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), queryReader(queryReader), manager(manager)
{
}
