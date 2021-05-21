//
// Created by paccbet on 14.04.2021.
//

#include "models.h"

using namespace Pistache;

GetCountersPopularityByStoreRequest::GetCountersPopularityByStoreRequest() : StoreID(0)
{
}

void GetCountersPopularityByStoreRequest::Marshall(const Http::Uri::Query &query)
{
    auto storeParam = query.get("store");
    if (storeParam->empty())
    {
        throw EmptyValue("store");
    }
    StoreID = boost::lexical_cast<int>(*storeParam);
};

GetProductsPopularityByStoreRequest::GetProductsPopularityByStoreRequest() : StoreID(0), ProductIDs(std::vector<int>())
{
}

void GetProductsPopularityByStoreRequest::Marshall(const Http::Uri::Query &query)
{
    auto storeParam = query.get("store");
    if (storeParam->empty())
    {
        throw EmptyValue("store");
    }
    StoreID = boost::lexical_cast<int>(*storeParam);

    auto idsValue = query.get("ids");
    if (idsValue->empty())
    {
        throw EmptyValue("ids");
    }
    boost::split(ProductIDs, *idsValue, boost::is_any_of(","));
};

GetProductsTotalPopularityRequest::GetProductsTotalPopularityRequest() : ProductIDs(std::vector<int>())
{
}

void GetProductsTotalPopularityRequest::Marshall(const Http::Uri::Query &query)
{
    auto idsValue = query.get("ids");
    if (idsValue->empty())
    {
        throw EmptyValue("ids");
    }
    boost::split(ProductIDs, *idsValue, boost::is_any_of(","));
};

CounterPopularityMetric::CounterPopularityMetric() : StoreID(0), CounterID(0), Popularity(0){};

void CounterPopularityMetric::Marshall(const std::string &body){};

nlohmann::json CounterPopularityMetric::UnMarshall()
{
    nlohmann::json output;
    output["store"] = StoreID;
    output["counter"] = CounterID;
    output["popularity"] = Popularity;

    return output;
}

CounterPopularityMetric::CounterPopularityMetric(const CounterPopularityMetric &&other)
    : StoreID(other.StoreID), CounterID(other.CounterID), Popularity(other.Popularity){

                                                          };

ProductPopularityByStoreMetric::ProductPopularityByStoreMetric() : StoreID(0), ProductID(0), Popularity(0){};

void ProductPopularityByStoreMetric::Marshall(const std::string &body){};

nlohmann::json ProductPopularityByStoreMetric::UnMarshall()
{
    nlohmann::json output;
    output["store"] = StoreID;
    output["product"] = ProductID;
    output["popularity"] = Popularity;

    return output;
}

ProductPopularityByStoreMetric::ProductPopularityByStoreMetric(const ProductPopularityByStoreMetric &&other) noexcept
    : StoreID(other.StoreID), ProductID(other.ProductID), Popularity(other.Popularity){

                                                          };

ProductPopularityMetric::ProductPopularityMetric() : ProductID(0), Popularity(0){};

void ProductPopularityMetric::Marshall(const std::string &body){};

nlohmann::json ProductPopularityMetric::UnMarshall()
{
    nlohmann::json output;
    output["product"] = ProductID;
    output["popularity"] = Popularity;

    return output;
}

ProductPopularityMetric::ProductPopularityMetric(const ProductPopularityMetric &&other) noexcept
    : ProductID(other.ProductID), Popularity(other.Popularity){

                                  };

CountersPopularityMetricResponse::CountersPopularityMetricResponse() : Array(std::vector<CounterPopularityMetric>()){};

nlohmann::json CountersPopularityMetricResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = Array.begin(); item != Array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["values"] = outputArray;

    return output;
};

ProductsPopularityByStoreMetricResponse::ProductsPopularityByStoreMetricResponse()
    : Array(std::vector<ProductPopularityByStoreMetric>()){};

nlohmann::json ProductsPopularityByStoreMetricResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = Array.begin(); item != Array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["values"] = outputArray;

    return output;
};

ProductsPopularityMetricResponse::ProductsPopularityMetricResponse() : Array(std::vector<ProductPopularityMetric>()){};

nlohmann::json ProductsPopularityMetricResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = Array.begin(); item != Array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["values"] = outputArray;

    return output;
};
