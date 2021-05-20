//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_USECASE_H
#define TECHNO_SEARCH_USECASE_H

#include "models.h"
#include "storage.h"

// TODO (n.chernyh) : here move all to smart pointers !!!
// maybe its overpriced. idk. need to look for docs
// need to add move constructor and etc from 5 rule

class MetricManager
{
  public:
    MetricManager() = delete;

    explicit MetricManager(const MetricStorage &storage) noexcept;

    std::shared_ptr<CountersPopularityMetricResponse> GetCounterPopularityByShop(std::shared_ptr<GetCountersPopularityByStoreRequest> req);

    std::shared_ptr<ProductsPopularityByStoreMetricResponse> GetProductsPopularityByShop(std::shared_ptr<GetProductsPopularityByStoreRequest> req);

    std::shared_ptr<ProductsPopularityMetricResponse> GetProductsTotalPopularity(std::shared_ptr<GetProductsTotalPopularityRequest> req);

    ~MetricManager();

  private:
    MetricStorage storage;
};

#endif // TECHNO_SEARCH_USECASE_H
