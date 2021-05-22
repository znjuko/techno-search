#include "map_models.h"

#include <cmath>
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

    size_t intersectionsCount = 0;

    for (auto line : lines)
    {
        Point *point = l.LineIntersectionWithLine(line);
        if (point != nullptr && point->x >= p.x && point->x >= std::min(line.p1.x, line.p2.x) &&
            point->x <= std::max(line.p1.x, line.p2.x) && point->y >= std::min(line.p1.y, line.p2.y) &&
            point->y <= std::max(line.p1.y, line.p2.y))
        {
            ++intersectionsCount;
        }
    }

    if (intersectionsCount % 2 == 1)
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
    std::vector<Point *> points = std::vector<Point *>();

    for (auto line : lines)
    {
        Point *point = l.LineIntersectionWithLine(line);

        if (point == nullptr)
        {
            continue;
        }

        if (point->x <= std::max(line.p1.x, line.p2.x) && point->x >= std::min(line.p1.x, line.p2.x) &&
            point->y <= std::max(line.p1.y, line.p2.y) && point->y >= std::min(line.p1.y, line.p2.y))
        {
            points.push_back(point);
            continue;
        }
        delete point;
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

bool Polygon::IsPointOnPolygon(Point p)
{

    for (auto v : vertices)
    {
        if (v == p)
        {
            return true;
        }
    }

    for (auto line : lines)
    {
        if (line.LineIntersectionWithPoint(p))
        {
            return true;
        }
    }

    return false;
}

void Polygon::SetID(const size_t &id)
{
    this->id = id;
}

void Line::Show() const
{
    p1.Show();
    std::cout << ' ';
    p2.Show();
    std::cout << std::endl;
}

bool Line::LineIntersectionWithPoint(Point p)
{
    double a = this->p2.y - this->p1.y;
    double b = this->p1.x - this->p2.x;
    double c = a * (this->p1.x) + b * (this->p1.y);

    if (a * p.x + b * p.y == c)
    {
        if (p.x <= std::max(this->p1.x, this->p2.x) && p.x >= std::min(this->p1.x, this->p2.x) &&
            p.y <= std::max(this->p1.y, this->p2.y) && p.y >= std::min(this->p1.y, this->p2.y))
            return true;
    }

    return false;
}

void Point::Show() const
{
    std::cout << '(' << this->x << ", " << this->y << ')';
}

void StoreMap::Marshall(const std::string &body)
{
    auto jsonBody = json::parse(body);
    StoreID = jsonBody["shopID"];

    for (const auto &geometry : jsonBody["geometry"])
    {
        for (const auto &coord : geometry["coordinates"])
        {
            StoreGeometry.AddPoint(Point(coord[0], coord[1]));
        }
    }
    StoreGeometry.InitLines();

    for (const auto &geometry : jsonBody["inherit"])
    {
        auto poly = Polygon();
        for (const auto &coord : geometry["coordinates"])
        {
            poly.AddPoint(Point(coord[0], coord[1]));
        }
        poly.InitLines();
        poly.SetID(geometry["props"][0]["value"]);
        InheritObjects.push_back(poly);
    }
}

StoreMap::StoreMap()
{
}

void RawStoreMap::Marshall(const std::string &body)
{
    RawMap = body;
}

void StoreMapActionRequest::Marshall(const Rest::Request &req)
{
    StoreID = req.param(":shopID").as<int>();
}

StoreMapActionRequest::StoreMapActionRequest()
{
}
