//
// Created by paccbet on 14.04.2021.
//

#include "usecase.h"

CounterPopularityMetricResponse MetricManager::ResponseGetCounterPopularityByShop(
    const GetCountersPopularityByShopRequest &req)
{
    return CounterPopularityMetricResponse();
}

ShopProductPopularityMetricResponse MetricManager::GetProductsPopularityByShop(
    const GetProductPopularityByShopRequest &req)
{
    return ShopProductPopularityMetricResponse();
}

ProductPopularityMetricResponse MetricManager::GetProductsTotalPopularity(const GetProductsTotalPopularityRequest &req)
{
    return ProductPopularityMetricResponse();
}

MetricManager::MetricManager(const MetricStorage &storage) noexcept : storage(storage)
{
}

MetricManager::~MetricManager() = default;
