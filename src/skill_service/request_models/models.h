//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_MAP_MODELS_H
#define TECHNO_SEARCH_MODELS_H

#include "marshaller.h"
#include "unmarshaller.h"

#include <nlohmann/json.hpp>
#include <pistache/endpoint.h>

using namespace Pistache;

// TODO (n.chernyh) : move to smart pointers and add move constructors and etc for 5 part rule

class GetCountersPopularityByShopRequest : public IQueryMarshaller
{
  public:
    GetCountersPopularityByShopRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetCountersPopularityByShopRequest() override = default;

    int StorageID;
};

class GetProductPopularityByShopRequest : public IQueryMarshaller
{
  public:
    GetProductPopularityByShopRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetProductPopularityByShopRequest() override = default;

    int StorageID;
    std::vector<int> ProductIDs;
};

class GetProductsTotalPopularityRequest : public IQueryMarshaller
{
  public:
    GetProductsTotalPopularityRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetProductsTotalPopularityRequest() override = default;

    std::vector<int> ProductIDs;
};

class CounterPopularityMetric : public IMarshaller, public IUnMarshaller
{
  public:
    CounterPopularityMetric();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~CounterPopularityMetric() override = default;

    int StorageID, CounterID;
    unsigned long int Popularity;
};

class ShopProductPopularityMetric : public IMarshaller, public IUnMarshaller
{
  public:
    ShopProductPopularityMetric();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ShopProductPopularityMetric() override = default;

    int StorageID, ProductID;
    unsigned long int Popularity;
};

class ProductPopularityMetric : public IMarshaller, public IUnMarshaller
{
  public:
    ProductPopularityMetric();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductPopularityMetric() override = default;

    int ProductID;
    unsigned long int Popularity;
};

class CounterPopularityMetricResponse : public IUnMarshaller
{
  public:
    CounterPopularityMetricResponse();

    nlohmann::json UnMarshall() override;

    ~CounterPopularityMetricResponse() override = default;

    std::vector<CounterPopularityMetric> array;
};

class ShopProductPopularityMetricResponse : public IUnMarshaller
{
  public:
    ShopProductPopularityMetricResponse();

    nlohmann::json UnMarshall() override;

    ~ShopProductPopularityMetricResponse() override = default;

    std::vector<ShopProductPopularityMetric> array;
};

class ProductPopularityMetricResponse : public IUnMarshaller
{
  public:
    ProductPopularityMetricResponse();

    nlohmann::json UnMarshall() override;

    ~ProductPopularityMetricResponse() override = default;

    std::vector<ProductPopularityMetric> array;
};

#endif // TECHNO_SEARCH_MAP_MODELS_H
