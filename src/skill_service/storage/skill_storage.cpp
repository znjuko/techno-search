//
// Created by paccbet on 15.04.2021.
//

#include "skill_storage.h"

#include <utility>

std::shared_ptr<CountersPopularityMetricResponse> MetricStorage::GetCounterPopularityByShop(
    std::shared_ptr<GetCountersPopularityByStoreRequest> req)
{
    auto q = std::make_shared<GetCounterPopularityMetricQuery>();
    q->SetupQuery(req);
    auto reader = std::make_shared<CounterPopularityMetricReader>();

    storage->Select(q, reader);

    auto res = std::make_shared<CountersPopularityMetricResponse>();
    res->Array = reader->Get();
    return res;
}

std::shared_ptr<ProductsPopularityByStoreMetricResponse> MetricStorage::GetProductsPopularityByShop(
    std::shared_ptr<GetProductsPopularityByStoreRequest> req)
{
    auto q = std::shared_ptr<GetProductPopularityByShopMetricQuery>();
    q->SetupQuery(req);
    auto reader = std::make_shared<ShopProductsPopularityMetricReader>();

    storage->Select(q, reader);

    auto res = std::make_shared<ProductsPopularityByStoreMetricResponse>();
    res->Array = reader->Get();
    return res;
}

std::shared_ptr<ProductsPopularityMetricResponse> MetricStorage::GetProductsTotalPopularity(
    std::shared_ptr<GetProductsTotalPopularityRequest> req)
{
    auto q = std::shared_ptr<GetProductsTotalPopularityMetricQuery>();
    q->SetupQuery(req);
    auto reader = std::make_shared<ProductPopularityMetricReader>();

    storage->Select(q, reader);

    auto res = std::make_shared<ProductsPopularityMetricResponse>();
    res->Array = reader->Get();
    return res;
}

MetricStorage::~MetricStorage()
{
}

MetricStorage::MetricStorage(std::shared_ptr<ClickStorage> storage) : storage(storage)
{
}
