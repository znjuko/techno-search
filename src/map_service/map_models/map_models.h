//
// Created by Никита Черных on 29.05.2021.
//

#ifndef TECHNO_SEARCH_MAP_MODELS_H
#define TECHNO_SEARCH_MAP_MODELS_H

#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

class Point
{

  public:
    Point();

    double x, y;

    void Show() const;

    Point(double _x, double _y);

    ~Point() = default;

    bool operator==(Point p) const;

    double GetDistanceToPoint(const Point &p);

    int counterID;
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

    bool operator==(Polygon p) const;

    Point GetFeaturePoint();

    void SetID(int _id);

    int GetID();

  private:
    std::vector<Point> vertices;
    std::vector<Line> lines;
    size_t count;
    int id;
};

#endif // TECHNO_SEARCH_MAP_MODELS_H
