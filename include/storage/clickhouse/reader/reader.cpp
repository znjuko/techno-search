//
// Created by paccbet on 15.04.2021.
//

#include "reader.h"

void ProductPopularityMetricReader::Execute(const Block &b) {
    auto lastSize = metrics.size();
    auto rowCount = b.GetRowCount();
    metrics.resize(lastSize + rowCount);

    for (size_t i = 0; i < rowCount; ++i) {
        auto item = ProductPopularityMetric();

        item.ProductID = (*b[0]->As<ColumnUInt64>())[i];
        item.Popularity = (*b[1]->As<ColumnUInt64>())[i];
        metrics[lastSize + i] = item;
    }
}

std::vector<ProductPopularityMetric> ProductPopularityMetricReader::Get() {
    return metrics;
}

void CounterPopularityMetricReader::Execute(const Block &b) {
    auto lastSize = metrics.size();
    auto rowCount = b.GetRowCount();
    metrics.resize(lastSize + rowCount);

    for (size_t i = 0; i < rowCount; ++i) {
        auto item = CounterPopularityMetric();

        item.StorageID = (*b[0]->As<ColumnInt64>())[i];
        item.CounterID = (*b[1]->As<ColumnUInt16>())[i];
        item.Popularity = (*b[2]->As<ColumnUInt64>())[i];
        metrics[lastSize + i] = item;
    }
}

std::vector<CounterPopularityMetric> CounterPopularityMetricReader::Get() {
    return metrics;
}

void ShopProductsPopularityMetricReader::Execute(const Block &b) {
    auto lastSize = metrics.size();
    auto rowCount = b.GetRowCount();
    metrics.resize(lastSize + rowCount);

    for (size_t i = 0; i < rowCount; ++i) {
        auto item = ShopProductPopularityMetric();

        item.StorageID = (*b[0]->As<ColumnInt64>())[i];
        item.ProductID = (*b[1]->As<ColumnUInt16>())[i];
        item.Popularity = (*b[2]->As<ColumnUInt64>())[i];
        metrics[lastSize + i] = item;
    }
}

std::vector<ShopProductPopularityMetric> ShopProductsPopularityMetricReader::Get() {
    return metrics;
}
