#ifndef TECHNO_SEARCH_MAP_REQUEST_MODELS_H
#define TECHNO_SEARCH_MAP_MODELS_H

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

#endif // TECHNO_SEARCH_MAP_REQUEST_MODELS_H
