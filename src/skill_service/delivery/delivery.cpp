//
// Created by paccbet on 14.04.2021.
//

#include "delivery.h"

void MetricService::GetCounterPopularityByShop(const Http::Request& req, Http::ResponseWriter res) {
    std::shared_ptr<GetCountersPopularityByStoreRequest> reqReader;
    try {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::bad_lexical_cast &e) {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong storage id", &res);
        return;
    }

    std::shared_ptr<CountersPopularityMetricResponse> respWriter;
    try {
        respWriter = manager.GetCounterPopularityByShop(reqReader);
    }
    catch (const std::exception &e) {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void MetricService::GetProductPopularityByShop(const Http::Request& req, Http::ResponseWriter res) {
    std::shared_ptr<GetProductsPopularityByStoreRequest> reqReader;
    try {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::bad_lexical_cast &e) {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong storage id", &res);
        return;
    }
    catch (const boost::exception &e) {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong product ids", &res);
        return;
    }

    std::shared_ptr<ProductsPopularityByStoreMetricResponse> respWriter;
    try {
        respWriter = manager.GetProductsPopularityByShop(reqReader);
    }
    catch (const std::exception &e) {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void MetricService::GetProductsTotalPopularity(const Http::Request& req, Http::ResponseWriter res) {
    std::shared_ptr<GetProductsTotalPopularityRequest> reqReader;
    try {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::exception &e) {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong product ids", &res);
        return;
    }

    std::shared_ptr<ProductsPopularityMetricResponse> respWriter;
    try {
        respWriter = manager.GetProductsTotalPopularity(reqReader);
    }
    catch (const std::exception &e) {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.Writeesponse(respWriter, &res);
}

void MetricService::SetupService(Rest::Router router) {
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
        : responseWriter(responseWriter), bodyReader(bodyReader), queryReader(queryReader), manager(manager) {
}
