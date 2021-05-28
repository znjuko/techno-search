#ifndef TECHNO_SEARCH_MAP_MODELS_H
#define TECHNO_SEARCH_MAP_MODELS_H

#include <nlohmann/json.hpp>
#include <vector>
#include <iostream>
#include "common_exceptions.h"
#include "marshaller.h"
#include "unmarshaller.h"


using json = nlohmann::json;

class Point {

public:
    double x, y;

    void Show() const;

    Point() = default;

    Point(double _x, double _y);

    ~Point() = default;

    bool operator==(Point p) const;

    double GetDistanceToPoint(const Point &p);

};

class Line {

public:
    Point p1, p2;

    void Show() const;

    Line(Point _p1, Point _p2);

    ~Line() = default;

    Point GetMiddleOfLine() const;

    Point *LineIntersectionWithLine(Line l);

    bool LineIntersectionWithPoint(Point p);

};


class Polygon {

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
    int id;    // id прилавка
};

class StoreMap : public IMarshaller {
public:
    StoreMap();

    void Marshall(const std::string &body) override;

    ~StoreMap() override = default;

    Polygon StoreGeometry;
    std::vector<Polygon> InheritObjects;
    size_t StoreID{};
};

class RawStoreMap : public IMarshaller, public IUnMarshaller {
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

class AdjecencyPoints: public IUnMarshaller {
public:
    AdjecencyPoints() = default;

    explicit AdjecencyPoints(const std::string &body);

    nlohmann::json UnMarshall() override;

    ~AdjecencyPoints() override = default;

    int StoreID;
    std::vector<Point> Points;
};

//
//class StoreMapActionRequest : public IRequestMarshaller
//{
//  public:
//    StoreMapActionRequest();
//
//    void Marshall(const Rest::Request &req) override;
//
//    ~StoreMapActionRequest() override = default;
//
//    int StoreID;
//};

#endif // TECHNO_SEARCH_MAP_MODELS_H
