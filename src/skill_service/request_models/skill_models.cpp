//
// Created by paccbet on 14.04.2021.
//

#include "skill_models.h"

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
    auto idsValueParsed = std::vector<std::string>();
    boost::split(idsValueParsed, *idsValue, boost::is_any_of(","));
    ProductIDs = std::vector<int>(idsValueParsed.size());
    for (const auto &el : idsValueParsed)
    {
        ProductIDs.push_back(boost::lexical_cast<int>(el));
    }
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
    auto idsValueParsed = std::vector<std::string>();
    boost::split(idsValueParsed, *idsValue, boost::is_any_of(","));
    ProductIDs = std::vector<int>(idsValueParsed.size());
    for (const auto &el : idsValueParsed)
    {
        ProductIDs.push_back(boost::lexical_cast<int>(el));
    }
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

ProductPopularityMetric::ProductPopularityMetric() : ProductID(0), Popularity(0){};

void ProductPopularityMetric::Marshall(const std::string &body){};

nlohmann::json ProductPopularityMetric::UnMarshall()
{
    nlohmann::json output;
    output["product"] = ProductID;
    output["popularity"] = Popularity;

    return output;
}

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