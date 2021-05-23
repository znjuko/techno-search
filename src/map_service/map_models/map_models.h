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

    bool operator== (Point p) const;

};

class Line {

public:
    Point p1, p2;

    void Show() const;

    Line(Point _p1, Point _p2);

    ~Line() = default;

    Point GetMiddleOfLine() const;

    Point* LineIntersectionWithLine(Line l);

    bool LineIntersectionWithPoint(Point p);

};


class Polygon {

public:
    Polygon();

    ~Polygon() = default;

    bool IsPointInsidePolygon(Point p);

    void ShowLines();

    Point* GetPolygonCenter();

    Point GetPointWithLowestX();

    void InitLines();

    void AddPoint(Point p);

    std::vector<Line> GetLines();

    std::vector<Point> GetVertices();

    std::vector<Point*> IntersectionWithVerticalLine(Line l);

    bool IsPointOnPolygon(Point p);

    bool operator== (Polygon p) const;

private:

    std::vector<Point> vertices;
    std::vector<Line> lines;
    size_t count;
    
};

#endif // TECHNO_SEARCH_MAP_MODELS_H
