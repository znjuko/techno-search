//
// Created by paccbet on 15.04.2021.
//

#include "reader.h"

void ProductPopularityMetricReader::Execute(const Block &b)
{
}

std::vector<ProductPopularityMetric> ProductPopularityMetricReader::Get()
{
    return metrics;
}

void CounterPopularityMetricReader::Execute(const Block &b)
{
}

std::vector<CounterPopularityMetric> CounterPopularityMetricReader::Get()
{
    return metrics;
}

void ShopProductsPopularityMetricReader::Execute(const Block &b)
{
}

std::vector<ShopProductPopularityMetric> ShopProductsPopularityMetricReader::Get()
{
    return metrics;
}
