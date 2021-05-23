//
// Created by paccbet on 15.04.2021.
//

#include "click_reader.h"

void ProductPopularityMetricReader::Execute(const Block &b)
{
    auto lastSize = metrics.size();
    auto rowCount = b.GetRowCount();
    metrics.resize(lastSize + rowCount);

    for (size_t i = 0; i < rowCount; ++i)
    {
        metrics[lastSize + i].ProductID = (*b[0]->As<ColumnUInt64>())[i];
        metrics[lastSize + i].Popularity = (*b[1]->As<ColumnUInt64>())[i];
    }
}

std::vector<ProductPopularityMetric> ProductPopularityMetricReader::Get()
{
    return metrics;
}

void CounterPopularityMetricReader::Execute(const Block &b)
{
    auto lastSize = metrics.size();
    auto rowCount = b.GetRowCount();
    metrics.resize(lastSize + rowCount);

    for (size_t i = 0; i < rowCount; ++i)
    {
        metrics[lastSize + i].StoreID = (*b[0]->As<ColumnInt64>())[i];
        metrics[lastSize + i].CounterID = (*b[1]->As<ColumnUInt16>())[i];
        metrics[lastSize + i].Popularity = (*b[2]->As<ColumnUInt64>())[i];
    }
}

std::vector<CounterPopularityMetric> CounterPopularityMetricReader::Get()
{
    return metrics;
}

void ShopProductsPopularityMetricReader::Execute(const Block &b)
{
    auto lastSize = metrics.size();
    auto rowCount = b.GetRowCount();
    metrics.resize(lastSize + rowCount);

    for (size_t i = 0; i < rowCount; ++i)
    {
        metrics[lastSize + i].StoreID = (*b[0]->As<ColumnInt64>())[i];
        metrics[lastSize + i].ProductID = (*b[1]->As<ColumnUInt16>())[i];
        metrics[lastSize + i].Popularity = (*b[2]->As<ColumnUInt64>())[i];
    }
}

std::vector<ProductPopularityByStoreMetric> ShopProductsPopularityMetricReader::Get()
{
    return metrics;
}
