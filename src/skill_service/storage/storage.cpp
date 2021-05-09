//
// Created by paccbet on 15.04.2021.
//

#include "storage.h"

CounterPopularityMetricResponse MetricStorage::GetCounterPopularityByShop(
        const GetCountersPopularityByShopRequest &req) {
    auto q = GetCounterPopularityMetricQuery();
    q.SetupQuery(req);
    std::shared_ptr<CounterPopularityMetricReader> reader;

    this->storage->Select(q, reader);

    auto res = CounterPopularityMetricResponse();
    res.array = reader->Get();
    return res;
}

ShopProductPopularityMetricResponse MetricStorage::GetProductsPopularityByShop(
        const GetProductPopularityByShopRequest &req) {
    auto q = GetProductPopularityByShopMetricQuery();
    q.SetupQuery(req);
    std::shared_ptr<ShopProductsPopularityMetricReader> reader;

    this->storage->Select(q, reader);

    auto res = ShopProductPopularityMetricResponse();
    res.array = reader->Get();
    return res;
}

ProductPopularityMetricResponse
MetricStorage::GetProductsTotalPopularity(const GetProductsTotalPopularityRequest &req) {
    auto q = GetProductsTotalPopularityMetricQuery();
    q.SetupQuery(req);
    std::shared_ptr<ProductPopularityMetricReader> reader;

    this->storage->Select(q, reader);

    auto res = ProductPopularityMetricResponse();
    res.array = reader->Get();
    return res;
}

MetricStorage::~MetricStorage() {
}

MetricStorage::MetricStorage(std::shared_ptr<ClickStorage> storage) : storage(storage) {
}
