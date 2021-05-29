#ifndef TECHNO_SEARCH_MAP_REQUEST_MODELS_H
#define TECHNO_SEARCH_MAP_REQUEST_MODELS_H

#include "common_exceptions.h"
#include "marshaller.h"
#include "unmarshaller.h"

#include <boost/lexical_cast.hpp>
#include <bsoncxx/json.hpp>
#include <cstdint>
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

class CounterWithPoints
{
  public:
    int CounterID;
    int PointID;
    CounterWithPoints(int CounterID, int PointID)
    {
        this->CounterID = CounterID;
        this->PointID = PointID;
    }
};
class StoreCountersAdjacency
{
  public:
    StoreCountersAdjacency(const std::string &data);

    int ShopID;
    std::vector<CounterWithPoints> counterWithPoints;
};

class Point
{
  public:
    double x, y;

    void Show() const;

    Point() = default;

    Point(double _x, double _y);

    ~Point() = default;

    bool operator==(Point p) const;

    double GetDistanceToPoint(const Point &p);
};

class Line
{
  public:
    Point p1, p2;

    void Show() const;

    Line(Point _p1, Point _p2);

    ~Line() = default;

    Point GetMiddleOfLine() const;

    Point *LineIntersectionWithLine(Line l);

    bool LineIntersectionWithPoint(Point p);
};

class Polygon
{
  public:
    Polygon();

    ~Polygon() = default;

    bool IsPointInsidePolygon(Point p);

    void ShowLines();

    Point *GetPolygonCenter();

    Point GetPointWithLowestX();

    void InitLines();

    void AddPoint(Point p);

    std::vector<Line> GetLines();

    std::vector<Point> GetVertices();

    std::vector<Point *> IntersectionWithVerticalLine(Line l);

    bool IsPointOnPolygon(Point p);

    void SetID(const int &id);

    bool operator==(Polygon p) const;

    Point GetFeaturePoint();

  private:
    std::vector<Point> vertices;
    std::vector<Line> lines;
    size_t count;
    int id; // id прилавка
};

class StoreMap : public IMarshaller
{
  public:
    StoreMap();

    void Marshall(const std::string &body) override;

    ~StoreMap() override = default;

    Polygon StoreGeometry;
    std::vector<Polygon> InheritObjects;
    size_t StoreID{};
};

class RawStoreMap : public IMarshaller, public IUnMarshaller
{
  public:
    RawStoreMap() = default;

    RawStoreMap(const std::string &body);

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~RawStoreMap() override = default;

    int StoreID;
    std::string Inherit;
    std::string Geometry;
};

class AdjacencyPoints : public IUnMarshaller
{
  public:
    AdjacencyPoints() = default;

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

    int StoreID, FromNode, ToNode;
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
    StoreModel(const std::string &data);

    int ID;
    int Size;
    std::vector<double> Adjacency;
};

#endif // TECHNO_SEARCH_MAP_REQUEST_MODELS_H
