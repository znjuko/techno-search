#include "map_models.h"

#include <nlohmann/json.hpp>

Point::Point(double _x, double _y) : x(_x), y(_y)
{
}

Point Line::GetMiddleOfLine() const
{
    Point p((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    return p;
}

Point *Line::LineIntersectionWithLine(Line l)
{
    double a1 = this->p2.y - this->p1.y;
    double b1 = this->p1.x - this->p2.x;
    double c1 = a1 * (this->p1.x) + b1 * (this->p1.y);

    double a2 = l.p2.y - l.p1.y;
    double b2 = l.p1.x - l.p2.x;
    double c2 = a2 * (l.p1.x) + b2 * (l.p1.y);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        return nullptr;
    }

    double x = (b2 * c1 - b1 * c2) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;
    auto p = new Point(x, y);
    return p;
}

Line::Line(Point _p1, Point _p2) : p1(_p1), p2(_p2)
{
}

Polygon::Polygon() : vertices(), lines(), count(0)
{
}

bool Polygon::IsPointInsidePolygon(Point p)
{
    Point p1 = p;
    Point p2(p.x + 1, p.y);
    Line l(p1, p2);

    size_t IntersectionsCount = 0;

    for (auto line : lines)
    {
        Point *point = l.LineIntersectionWithLine(line);
        if (point != nullptr && p.x <= point->x)
        {
            ++IntersectionsCount;
        }
        delete point;
    }

    if (IntersectionsCount % 2 == 1)
    {
        return true;
    }

    return false;
}

Point Polygon::GetPolygonCenter()
{
    Point centroid(0, 0);
    return centroid;
}

Point Polygon::GetPointWithLowestX()
{
    Point min = vertices[0];
    for (size_t i = 1; i < vertices.size(); ++i)
    {
        if (vertices[i].x < min.x)
        {
            min = vertices[i];
        }
    }
    return min;
}

void Polygon::InitLines()
{
    for (size_t i = 1; i < vertices.size(); ++i)
    {
        Line l(vertices[i - 1], vertices[i]);
        lines.push_back(l);
    }
    Line l(vertices[vertices.size() - 1], vertices[0]);
    lines.push_back(l);
}

void Polygon::AddPoint(Point p)
{
    ++this->count;
    vertices.push_back(p);
}

std::vector<Point *> Polygon::IntersectionWithVerticalLine(Line l)
{
    std::vector<Point *> points;
    for (auto line : lines)
    {
        Point *point = l.LineIntersectionWithLine(line);
        if (point != nullptr)
        {
            points.push_back(point);
        }
    }
    return points;
}

std::vector<Line> Polygon::GetLines()
{
    return lines;
}

std::vector<Point> Polygon::GetVertices()
{
    return vertices;
}

void Polygon::ShowLines()
{
    for (auto l : lines)
    {
        l.Show();
    }
}

void Line::Show() const
{
    p1.Show();
    std::cout << ' ';
    p2.Show();
    std::cout << std::endl;
}

void Point::Show() const
{
    std::cout << '(' << x << ", " << y << ')';
}