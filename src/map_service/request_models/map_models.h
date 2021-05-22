#ifndef TECHNO_SEARCH_MAP_MODELS_H
#define TECHNO_SEARCH_MAP_MODELS_H

#include "common_exceptions.h"
#include "marshaller.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

class Point
{

  public:
    double x, y;

    void Show() const;

    Point(double _x, double _y);

    ~Point() = default;

    bool operator==(const Point p) const
    {
        if (this->x == p.x && this->y == p.y)
        {
            return true;
        }
        return false;
    }
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

    Point GetPolygonCenter();

    Point GetPointWithLowestX();

    void InitLines();

    void AddPoint(Point p);

    std::vector<Line> GetLines();

    std::vector<Point> GetVertices();

    std::vector<Point *> IntersectionWithVerticalLine(Line l);

    bool IsPointOnPolygon(Point p);

    void SetID(const size_t &id);

  private:
    std::vector<Point> vertices;
    std::vector<Line> lines;
    size_t count; // количество точек
    size_t id;    // id прилавка
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

class RawStoreMap : public IMarshaller
{
  public:
    RawStoreMap() = default;

    void Marshall(const std::string &body) override;

    ~RawStoreMap() override = default;

    std::string RawMap;
};

class StoreMapActionRequest : public IRequestMarshaller
{
  public:
    StoreMapActionRequest();

    void Marshall(const Rest::Request &req) override;

    ~StoreMapActionRequest() override = default;

    int StoreID;
};

#endif // TECHNO_SEARCH_MAP_MODELS_H
