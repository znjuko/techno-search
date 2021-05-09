//
// Created by paccbet on 14.04.2021.
//

#include "usecase.h"

CounterPopularityMetricResponse MetricManager::GetCounterPopularityByShop(
    const GetCountersPopularityByShopRequest &req)
{
    return this->storage.GetCounterPopularityByShop(req);
}

ShopProductPopularityMetricResponse MetricManager::GetProductsPopularityByShop(
    const GetProductPopularityByShopRequest &req)
{
    return this->storage.GetProductsPopularityByShop(req);
}

ProductPopularityMetricResponse MetricManager::GetProductsTotalPopularity(const GetProductsTotalPopularityRequest &req)
{
    return this->storage.GetProductsTotalPopularity(req);
}

MetricManager::MetricManager(const MetricStorage &storage) noexcept : storage(storage)
{
}

MetricManager::~MetricManager() = default;
