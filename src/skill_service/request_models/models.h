//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_MODELS_H
#define TECHNO_SEARCH_MODELS_H

#include "marshaller.h"
#include "unmarshaller.h"

#include <nlohmann/json.hpp>

class GetCountersPopularityByShopRequest : public IMarshaller
{
  public:
    GetCountersPopularityByShopRequest();

    void Marshall(const std::string &body) override;

    ~GetCountersPopularityByShopRequest() override = default;

    int StorageID;
};

class GetProductPopularityByShopRequest : public IMarshaller
{
  public:
    GetProductPopularityByShopRequest();

    void Marshall(const std::string &body) override;

    ~GetProductPopularityByShopRequest() override = default;

    int StorageID;
    std::vector<int> ProductIDs;
};

class GetProductsTotalPopularityRequest : public IMarshaller
{
  public:
    GetProductsTotalPopularityRequest();

    void Marshall(const std::string &body) override;

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

#endif // TECHNO_SEARCH_MODELS_H
