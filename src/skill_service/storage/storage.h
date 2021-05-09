//
// Created by paccbet on 15.04.2021.
//

#ifndef TECHNO_SEARCH_STORAGE_H
#define TECHNO_SEARCH_STORAGE_H

#include "common_storage.h"
#include "models.h"

// TODO (n.chernyh) : do we need 5 rule here ?
class MetricStorage {
public:
    MetricStorage() = delete;

    explicit MetricStorage(std::shared_ptr<ClickStorage> storage);

    CounterPopularityMetricResponse ResponseGetCounterPopularityByShop(const GetCountersPopularityByShopRequest &req);

    ShopProductPopularityMetricResponse GetProductsPopularityByShop(const GetProductPopularityByShopRequest &req);

    ProductPopularityMetricResponse GetProductsTotalPopularity(const GetProductsTotalPopularityRequest &req);

    ~MetricStorage();

private:
    std::shared_ptr<ClickStorage> storage;
};

#endif // TECHNO_SEARCH_STORAGE_H
