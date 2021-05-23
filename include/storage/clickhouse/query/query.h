//
// Created by paccbet on 15.04.2021.
//

#ifndef TECHNO_SEARCH_QUERY_H
#define TECHNO_SEARCH_QUERY_H

#include "skill_models.h"

#include <string>

class ClickQuery
{
  public:
    virtual std::string GetQuery() const = 0;

    virtual ~ClickQuery();
};

class GetCounterPopularityMetricQuery : public ClickQuery
{
  public:
    GetCounterPopularityMetricQuery();

    GetCounterPopularityMetricQuery(std::string *query) = delete;

    GetCounterPopularityMetricQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetCountersPopularityByStoreRequest> req);

    ~GetCounterPopularityMetricQuery() override;

  private:
    std::string query;
};

class GetProductPopularityByShopMetricQuery : public ClickQuery
{
  public:
    GetProductPopularityByShopMetricQuery();

    GetProductPopularityByShopMetricQuery(std::string *query) = delete;

    GetProductPopularityByShopMetricQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetProductsPopularityByStoreRequest> req);

    ~GetProductPopularityByShopMetricQuery() override;

  private:
    std::string query;
};

class GetProductsTotalPopularityMetricQuery : public ClickQuery
{
  public:
    GetProductsTotalPopularityMetricQuery();

    GetProductsTotalPopularityMetricQuery(std::string query) = delete;

    GetProductsTotalPopularityMetricQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetProductsTotalPopularityRequest> req);

    ~GetProductsTotalPopularityMetricQuery() override;

  private:
    std::string query;
};

#endif // TECHNO_SEARCH_QUERY_H
