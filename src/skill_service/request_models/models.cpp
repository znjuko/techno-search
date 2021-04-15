//
// Created by paccbet on 14.04.2021.
//

#include "models.h"

GetCountersPopularityByShopRequest::GetCountersPopularityByShopRequest() : StorageID(0)
{
}

void GetCountersPopularityByShopRequest::Marshall(const Http::Uri::Query &body){

};

GetProductPopularityByShopRequest::GetProductPopularityByShopRequest() : StorageID(0), ProductIDs(std::vector<int>())
{
}

void GetProductPopularityByShopRequest::Marshall(const Http::Uri::Query &body){

};

GetProductsTotalPopularityRequest::GetProductsTotalPopularityRequest() : ProductIDs(std::vector<int>())
{
}

void GetProductsTotalPopularityRequest::Marshall(const Http::Uri::Query &body){

};

CounterPopularityMetric::CounterPopularityMetric() : StorageID(0), CounterID(0), Popularity(0){};

void CounterPopularityMetric::Marshall(const std::string &body){};

nlohmann::json CounterPopularityMetric::UnMarshall()
{
    return nlohmann::json();
};

ShopProductPopularityMetric::ShopProductPopularityMetric() : StorageID(0), ProductID(0), Popularity(0){};

void ShopProductPopularityMetric::Marshall(const std::string &body){};

nlohmann::json ShopProductPopularityMetric::UnMarshall()
{
    return nlohmann::json();
};

ProductPopularityMetric::ProductPopularityMetric() : ProductID(0), Popularity(0){};

void ProductPopularityMetric::Marshall(const std::string &body){};

nlohmann::json ProductPopularityMetric::UnMarshall()
{
    return nlohmann::json();
};

CounterPopularityMetricResponse::CounterPopularityMetricResponse() : array(std::vector<CounterPopularityMetric>()){};

nlohmann::json CounterPopularityMetricResponse::UnMarshall()
{
    return nlohmann::json();
};

ShopProductPopularityMetricResponse::ShopProductPopularityMetricResponse()
    : array(std::vector<ShopProductPopularityMetric>()){};

nlohmann::json ShopProductPopularityMetricResponse::UnMarshall()
{
    return nlohmann::json();
};

ProductPopularityMetricResponse::ProductPopularityMetricResponse() : array(std::vector<ProductPopularityMetric>()){};

nlohmann::json ProductPopularityMetricResponse::UnMarshall()
{
    return nlohmann::json();
};
