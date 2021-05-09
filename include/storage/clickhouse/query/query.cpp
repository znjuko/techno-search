//
// Created by paccbet on 15.04.2021.
//

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "query.h"

ClickQuery::~ClickQuery() {
}

GetCounterPopularityMetricQuery::GetCounterPopularityMetricQuery() {
}

GetCounterPopularityMetricQuery::~GetCounterPopularityMetricQuery() {
}

std::string GetCounterPopularityMetricQuery::GetQuery() const {
    return this->query;
}

void GetCounterPopularityMetricQuery::SetupQuery(const GetCountersPopularityByShopRequest &req) {
    this->query = "SELECT storage_id, counter_id, count(*) as 'popularity' "
                  "FROM storage_counter_popularity WHERE storage_id=" + std::to_string(req.StorageID) + " " +
                  "GROUP BY storage_id,counter_id ORDER_BY counter_id;";
}

GetProductPopularityByShopMetricQuery::GetProductPopularityByShopMetricQuery() {
}

std::string GetProductPopularityByShopMetricQuery::GetQuery() const {
    return this->query;
}

void GetProductPopularityByShopMetricQuery::SetupQuery(const GetProductPopularityByShopRequest &req) {
    std::string inQuery = "";
    if (!req.ProductIDs.empty()) {
        std::ostringstream oss;
        std::copy(req.ProductIDs.begin(), req.ProductIDs.end(), std::ostream_iterator<int>(oss, ","));
        inQuery = oss.str();
        inQuery.pop_back();
    }

    this->query = "SELECT storage_id, product_id, count(*) as 'popularity' "
                  "FROM storage_product_popularity WHERE storage_id = " + std::to_string(req.StorageID) + " " +
                  "AND product_id IN (" + inQuery + ") " +
                  "GROUP BY storage_id, product_id ORDER BY product_id;";
}

GetProductPopularityByShopMetricQuery::~GetProductPopularityByShopMetricQuery() {
}

GetProductsTotalPopularityMetricQuery::GetProductsTotalPopularityMetricQuery() {
}

std::string GetProductsTotalPopularityMetricQuery::GetQuery() const {
    return this->query;
}

void GetProductsTotalPopularityMetricQuery::SetupQuery(const GetProductsTotalPopularityRequest &req) {
    std::string inQuery = "";
    if (!req.ProductIDs.empty()) {
        std::ostringstream oss;
        std::copy(req.ProductIDs.begin(), req.ProductIDs.end(), std::ostream_iterator<int>(oss, ","));
        inQuery = oss.str();
        inQuery.pop_back();
    }

    this->query = "SELECT product_id, count(*) as 'popularity' "
                  "FROM storage_product_popularity WHERE product_id IN (" + inQuery + ") " +
                  "GROUP BY product_id ORDER BY product_id;";
}

GetProductsTotalPopularityMetricQuery::~GetProductsTotalPopularityMetricQuery() {
}
