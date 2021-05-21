//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_SKILL_MODELS_H
#define TECHNO_SEARCH_SKILL_MODELS_H

#include "common_exceptions.h"
#include "marshaller.h"
#include "unmarshaller.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <nlohmann/json.hpp>
#include <pistache/endpoint.h>
#include <pistache/http.h>

using namespace Pistache;

// TODO (n.chernyh) : move to smart pointers and add move constructors and etc for 5 part rule

class GetCountersPopularityByStoreRequest : public IQueryMarshaller
{
  public:
    GetCountersPopularityByStoreRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetCountersPopularityByStoreRequest() override = default;

    int StoreID;
};

class GetProductsPopularityByStoreRequest : public IQueryMarshaller
{
  public:
    GetProductsPopularityByStoreRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetProductsPopularityByStoreRequest() override = default;

    int StoreID;
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

    CounterPopularityMetric(const CounterPopularityMetric &&other);

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~CounterPopularityMetric() override = default;

    int StoreID, CounterID;
    unsigned long int Popularity;
};

class ProductPopularityByStoreMetric : public IMarshaller, public IUnMarshaller
{
  public:
    ProductPopularityByStoreMetric();

    ProductPopularityByStoreMetric(const ProductPopularityByStoreMetric &&other) noexcept;

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductPopularityByStoreMetric() override = default;

    int StoreID, ProductID;
    unsigned long int Popularity;
};

class ProductPopularityMetric : public IMarshaller, public IUnMarshaller
{
  public:
    ProductPopularityMetric();

    ProductPopularityMetric(const ProductPopularityMetric &&other) noexcept;

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductPopularityMetric() override = default;

    int ProductID;
    unsigned long int Popularity;
};

class CountersPopularityMetricResponse : public IUnMarshaller
{
  public:
    CountersPopularityMetricResponse();

    nlohmann::json UnMarshall() override;

    ~CountersPopularityMetricResponse() override = default;

    std::vector<CounterPopularityMetric> Array;
};

class ProductsPopularityByStoreMetricResponse : public IUnMarshaller
{
  public:
    ProductsPopularityByStoreMetricResponse();

    nlohmann::json UnMarshall() override;

    ~ProductsPopularityByStoreMetricResponse() override = default;

    std::vector<ProductPopularityByStoreMetric> Array;
};

class ProductsPopularityMetricResponse : public IUnMarshaller
{
  public:
    ProductsPopularityMetricResponse();

    nlohmann::json UnMarshall() override;

    ~ProductsPopularityMetricResponse() override = default;

    std::vector<ProductPopularityMetric> Array;
};

#endif // TECHNO_SEARCH_MAP_MODELS_H
