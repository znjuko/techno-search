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
    virtual void SetupReader(const Block &b) = 0;

    virtual ~ClickReader() = default;
};

class ProductPopularityMetricReader : public ClickReader
{
  public:
    ProductPopularityMetricReader() = default;

    ProductPopularityMetricReader(const ProductPopularityMetricReader &b) = delete;

    ProductPopularityMetricReader(const Block &b) = delete;

    ProductPopularityMetricReader(Block *b) = delete;

    void SetupReader(const Block &b) override;

    std::vector<ProductPopularityMetric> Read();

    ~ProductPopularityMetricReader() override = default;

  private:
    Block b;
};

class CounterPopularityMetricReader : public ClickReader
{
  public:
    CounterPopularityMetricReader() = default;

    CounterPopularityMetricReader(const ProductPopularityMetricReader &b) = delete;

    CounterPopularityMetricReader(const Block &b) = delete;

    CounterPopularityMetricReader(Block *b) = delete;

    void SetupReader(const Block &b) override;

    std::vector<CounterPopularityMetric> Read();

    ~CounterPopularityMetricReader() override = default;

  private:
    Block b;
};

class ShopProductsPopularityMetricReader : public ClickReader
{
  public:
    ShopProductsPopularityMetricReader() = default;

    ShopProductsPopularityMetricReader(const ProductPopularityMetricReader &b) = delete;

    ShopProductsPopularityMetricReader(const Block &b) = delete;

    ShopProductsPopularityMetricReader(Block *b) = delete;

    void SetupReader(const Block &b) override;

    std::vector<ShopProductPopularityMetric> Read();

    ~ShopProductsPopularityMetricReader() override = default;

  private:
    Block b;
};

#endif // TECHNO_SEARCH_READER_H
