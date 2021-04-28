//
// Created by paccbet on 15.04.2021.
//

#include "storage.h"

CounterPopularityMetricResponse MetricStorage::ResponseGetCounterPopularityByShop(
    const GetCountersPopularityByShopRequest &req)
{
    return CounterPopularityMetricResponse();
}

ShopProductPopularityMetricResponse MetricStorage::GetProductsPopularityByShop(
    const GetProductPopularityByShopRequest &req)
{
    return ShopProductPopularityMetricResponse();
}

ProductPopularityMetricResponse MetricStorage::GetProductsTotalPopularity(const GetProductsTotalPopularityRequest &req)
{
    return ProductPopularityMetricResponse();
}

MetricStorage::~MetricStorage()
{
}

MetricStorage::MetricStorage(ClickStorage *storage) : storage(storage)
{
}
