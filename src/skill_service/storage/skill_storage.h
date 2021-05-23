//
// Created by paccbet on 15.04.2021.
//

#ifndef TECHNO_SEARCH_SKILL_STORAGE_H
#define TECHNO_SEARCH_SKILL_STORAGE_H

#include "click_common_storage.h"
#include "skill_models.h"

// TODO (n.chernyh) : do we need 5 rule here ?
class MetricStorage
{
  public:
    MetricStorage() = delete;

    explicit MetricStorage(std::shared_ptr<ClickStorage> storage);

    std::shared_ptr<CountersPopularityMetricResponse> GetCounterPopularityByShop(
        std::shared_ptr<GetCountersPopularityByStoreRequest> req);

    std::shared_ptr<ProductsPopularityByStoreMetricResponse> GetProductsPopularityByShop(
        std::shared_ptr<GetProductsPopularityByStoreRequest> req);

    std::shared_ptr<ProductsPopularityMetricResponse> GetProductsTotalPopularity(
        std::shared_ptr<GetProductsTotalPopularityRequest> req);

    ~MetricStorage();

  private:
    std::shared_ptr<ClickStorage> storage;
};

#endif // TECHNO_SEARCH_SKILL_STORAGE_H
