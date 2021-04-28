//
// Created by paccbet on 15.04.2021.
//

#ifndef TECHNO_SEARCH_QUERY_H
#define TECHNO_SEARCH_QUERY_H

#include "models.h"

#include <clickhouse/client.h>

using namespace clickhouse;

class ClickQuery
{
  public:
    virtual Block *GetQuery() = 0;

    virtual ~ClickQuery();
};

class GetCounterPopularityMetricQuery : public ClickQuery
{
  public:
    GetCounterPopularityMetricQuery();

    GetCounterPopularityMetricQuery(Block *query) = delete;

    GetCounterPopularityMetricQuery(const Block &query) = delete;

    Block *GetQuery() override;

    void SetupQuery(const GetCountersPopularityByShopRequest &req);

    ~GetCounterPopularityMetricQuery() override;

  private:
    Block *query;
};

class GetShopPopularityMetricQuery : public ClickQuery
{
  public:
    GetShopPopularityMetricQuery();

    GetShopPopularityMetricQuery(Block *query) = delete;

    GetShopPopularityMetricQuery(const Block &query) = delete;

    Block *GetQuery() override;

    void SetupQuery(const GetCountersPopularityByShopRequest &req);

    ~GetShopPopularityMetricQuery() override;

  private:
    Block *query;
};

class GetProductPopularityMetricQuery : public ClickQuery
{
  public:
    GetProductPopularityMetricQuery();

    GetProductPopularityMetricQuery(Block *query) = delete;

    GetProductPopularityMetricQuery(const Block &query) = delete;

    Block *GetQuery() override;

    void SetupQuery(const GetCountersPopularityByShopRequest &req);

    ~GetProductPopularityMetricQuery() override;

  private:
    Block *query;
};

#endif // TECHNO_SEARCH_QUERY_H
