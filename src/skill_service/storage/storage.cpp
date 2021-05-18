//
// Created by paccbet on 15.04.2021.
//

#include "storage.h"

#include <utility>

std::shared_ptr<CountersPopularityMetricResponse> GetCounterPopularityByShop::GetCounterPopularityByShop(
        std::shared_ptr<GetCountersPopularityByStoreRequest> req) {
    auto q = std::shared_ptr<GetCounterPopularityMetricQuery>();
    q->SetupQuery(req);
    std::shared_ptr<CounterPopularityMetricReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<CountersPopularityMetricResponse>();
    res->array = std::move(reader->Get());
    return res;
}

std::shared_ptr<ProductsPopularityByStoreMetricResponse> MetricStorage::GetProductsPopularityByShop(
        std::shared_ptr<GetProductsPopularityByStoreRequest> req) {
    auto q = std::shared_ptr<GetProductPopularityByShopMetricQuery>();
    q->SetupQuery(req);
    std::shared_ptr<ShopProductsPopularityMetricReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<ProductsPopularityByStoreMetricResponse>();
    res->array = std::move(reader->Get());
    return res;
}

std::shared_ptr<ProductsPopularityMetricResponse>
MetricStorage::GetProductsTotalPopularity(std::shared_ptr<GetProductsTotalPopularityRequest> req) {
    auto q = std::shared_ptr<GetProductsTotalPopularityMetricQuery>();
    q->SetupQuery(req);
    std::shared_ptr<ProductPopularityMetricReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<ProductsPopularityMetricResponse>();
    res->array = std::move(reader->Get());
    return res;
}

MetricStorage::~MetricStorage() {
}

MetricStorage::MetricStorage(std::shared_ptr<ClickStorage> storage) : storage(storage) {
}
