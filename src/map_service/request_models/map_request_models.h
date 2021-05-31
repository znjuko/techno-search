#ifndef TECHNO_SEARCH_MAP_REQUEST_MODELS_H
#define TECHNO_SEARCH_MAP_REQUEST_MODELS_H

#include "common_exceptions.h"
#include "map_models.h"
#include "marshaller.h"
#include "unmarshaller.h"

#include <boost/lexical_cast.hpp>
#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

class CounterWithPoints
{
  public:
    CounterWithPoints(int CounterID, int PointID)
    {
        this->CounterID = CounterID;
        this->PointID = PointID;
    }

    int CounterID;
    int PointID;
};
class StoreCountersAdjacency
{
  public:
    StoreCountersAdjacency();

    StoreCountersAdjacency(const std::string &data);

    int StoreID;
    std::vector<CounterWithPoints> counterWithPoints;
};

class StoreMap : public IMarshaller
{
  public:
    StoreMap();

    void Marshall(const std::string &body) override;

    ~StoreMap() override = default;

    Polygon StoreGeometry;
    std::vector<Polygon> InheritObjects;
    size_t StoreID;
};

class RawStoreMap : public IMarshaller, public IUnMarshaller
{
  public:
    RawStoreMap() = default;

    explicit RawStoreMap(const std::string &body);

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~RawStoreMap() override = default;

    int StoreID{};
    std::string Inherit;
    std::string Geometry;
};

class AdjacencyPoints : public IUnMarshaller
{
  public:
    AdjacencyPoints();

    explicit AdjacencyPoints(const std::string &body);

    nlohmann::json UnMarshall() override;

    ~AdjacencyPoints() override = default;

    int StoreID;
    std::vector<Point> Points;
};

class StoreActionRequest : public IQueryMarshaller
{
  public:
    StoreActionRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~StoreActionRequest() override = default;

    int StoreID;
};

class StoreAdjacencyPointsResponse : public IUnMarshaller
{
  public:
    StoreAdjacencyPointsResponse();

    nlohmann::json UnMarshall() override;

    ~StoreAdjacencyPointsResponse() override = default;

    std::vector<AdjacencyPoints> array;
};

class GetStorePathRequest : public IRequestMarshaller
{
  public:
    GetStorePathRequest();

    void Marshall(const Rest::Request &req) override;

    ~GetStorePathRequest() override = default;

    int StoreID, FromCounter, ToCounter;
};

class GetStorePathResponse : public IUnMarshaller
{
  public:
    explicit GetStorePathResponse(std::vector<size_t> Path);

    nlohmann::json UnMarshall() override;

    ~GetStorePathResponse() override = default;

    std::vector<size_t> Array;
};

class StoreModel
{
  public:
    StoreModel();

    StoreModel(const std::string &data);

    int ID;
    int Size;
    std::vector<double> Adjacency;
};

#endif // TECHNO_SEARCH_MAP_REQUEST_MODELS_H
