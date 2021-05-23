//
// Created by paccbet on 14.04.2021.
//

#include "skill_usecase.h"

std::shared_ptr<CountersPopularityMetricResponse> MetricManager::GetCounterPopularityByShop(
    std::shared_ptr<GetCountersPopularityByStoreRequest> req)
{
    return storage.GetCounterPopularityByShop(req);
}

std::shared_ptr<ProductsPopularityByStoreMetricResponse> MetricManager::GetProductsPopularityByShop(
    std::shared_ptr<GetProductsPopularityByStoreRequest> req)
{
    return storage.GetProductsPopularityByShop(req);
}

std::shared_ptr<ProductsPopularityMetricResponse> MetricManager::GetProductsTotalPopularity(
    std::shared_ptr<GetProductsTotalPopularityRequest> req)
{
    return storage.GetProductsTotalPopularity(req);
}

MetricManager::MetricManager(std::shared_ptr<MetricStorage> storage) noexcept : storage(storage)
{
}

MetricManager::~MetricManager() = default;
