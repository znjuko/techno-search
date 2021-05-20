#ifndef TECHNO_SEARCH_MAP_MODELS_H
#define TECHNO_SEARCH_MAP_MODELS_H

#include <nlohmann/json.hpp>
#include <vector>
#include <iostream>

class Point {

public:
    double x, y;

    void Show() const;

    Point(double _x, double  _y);

    ~Point() = default;

};

class Line {

public:
    Point p1, p2;

    void Show() const;

    Line(Point _p1, Point _p2);

    ~Line() = default;

    Point GetMiddleOfLine() const;

    Point * LineIntersectionWithLine(Line l);

};


class Polygon {

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

    std::vector<Point*> IntersectionWithVerticalLine(Line l);

private:

    std::vector<Point> vertices;
    std::vector<Line> lines;
    size_t count;
    
};


//class GetCoordinates : public IMarshaller
//{
//  public:
//    GetStoreMetadataRequest();
//
//    void Marshall(const std::string &body) override;
//
//    ~GetStoreMetadataRequest() override = default;
//
//    string name;
//};



#endif // TECHNO_SEARCH_MAP_MODELS_H
