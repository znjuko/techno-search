//
// Created by paccbet on 15.04.2021.
//

#ifndef TECHNO_SEARCH_READER_H
#define TECHNO_SEARCH_READER_H

#include "models.h"

#include <clickhouse/client.h>
#include <vector>

using namespace clickhouse;

// TODO (n.chernyh): add move constr 1000000%!
class ClickReader
{
  public:
    virtual void Execute(const Block &b) = 0;

    virtual ~ClickReader() = default;
};

class ProductPopularityMetricReader : public ClickReader
{
  public:
    ProductPopularityMetricReader() = default;

    ProductPopularityMetricReader(const ProductPopularityMetricReader &r) = delete;

    ProductPopularityMetricReader(const std::vector<ProductPopularityMetric> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<ProductPopularityMetric> Get();

    ~ProductPopularityMetricReader() override = default;

  private:
    std::vector<ProductPopularityMetric> metrics;
};

class CounterPopularityMetricReader : public ClickReader
{
  public:
    CounterPopularityMetricReader() = default;

    CounterPopularityMetricReader(const ProductPopularityMetricReader &r) = delete;

    CounterPopularityMetricReader(const std::vector<CounterPopularityMetric> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<CounterPopularityMetric> Get();

    ~CounterPopularityMetricReader() override = default;

  private:
    std::vector<CounterPopularityMetric> metrics;
};

class ShopProductsPopularityMetricReader : public ClickReader
{
  public:
    ShopProductsPopularityMetricReader() = default;

    ShopProductsPopularityMetricReader(const ProductPopularityMetricReader &r) = delete;

    ShopProductsPopularityMetricReader(const std::vector<ShopProductPopularityMetric> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<ShopProductPopularityMetric> Get();

    ~ShopProductsPopularityMetricReader() override = default;

  private:
    std::vector<ShopProductPopularityMetric> metrics;
};

#endif // TECHNO_SEARCH_READER_H
