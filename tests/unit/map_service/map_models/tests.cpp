#include "map_models.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(LINE, INTERSECTION_WITH_LINE) {

    Point p1(0,0),  p2(2,2);
    Point p3(0,1),  p4(3,0);

    Line l1(p1,p2), l2(p3,p4);

    Point* p = l1.LineIntersectionWithLine(l2);

    ASSERT_EQ(p->x, 0.75);
    ASSERT_EQ(p->y, 0.75);

    delete p;
}

TEST(LINE, INTERSECTION_WITH_POINT) {

    Point p1(0,0),  p2(2,2);
    Point p(9,9);

    Line l(p1,p2);

    bool res = l.LineIntersectionWithPoint(p);

    ASSERT_EQ(res, true);

}


TEST(POLYGON, INITLINES) {

    Point p1(0,0),  p2(2,0), p3(2,2),  p4(0, 2);

    Polygon p;
    p.AddPoint(p1);
    p.AddPoint(p2);
    p.AddPoint(p3);
    p.AddPoint(p4);

    p.InitLines();

    std::vector<Line> v = p.GetLines();
    std::vector<Line> _v;

    Line temp = Line(p1,p2);
    _v.push_back(temp);
    temp = Line(p2, p3);
    _v.push_back(temp);
    temp = Line(p3, p4);
    _v.push_back(temp);
    temp = Line(p4, p1);
    _v.push_back(temp);

    ASSERT_EQ(v.size(), _v.size());

    for(size_t i = 0; i < v.size(); ++i) {
        ASSERT_EQ(v[i].p1.x, _v[i].p1.x);
        ASSERT_EQ(v[i].p1.y, _v[i].p1.y);
        ASSERT_EQ(v[i].p2.x, _v[i].p2.x);
        ASSERT_EQ(v[i].p2.y, _v[i].p2.y);
        std::cout << "Line: " << '(' << v[i].p1.x << ' ' << v[i].p1.y <<  "), (" << v[i].p2.x << ' ' << v[i].p2.y << ')' << std::endl;
    }

}

TEST(POLYGON, POINT_INSIDE_POLYGON) {
    Point p1(0,0),  p2(2,0);
    Point p3(2,2),  p4(0,2);
    Point point(1, 1);

    Polygon p;
    p.AddPoint(p1);
    p.AddPoint(p2);
    p.AddPoint(p3);
    p.AddPoint(p4);
    p.InitLines();
    //p.ShowLines();

    ASSERT_EQ(true, p.IsPointInsidePolygon(point));
}

TEST(POLYGON, INTERSECTIONS_WITH_VERTICAL_LINE) {
    Point p1(0,0),  p2(2,0);
    Point p3(2,2),  p4(0,2);

    Polygon p;
    p.AddPoint(p1);
    p.AddPoint(p2);
    p.AddPoint(p3);
    p.AddPoint(p4);
    p.InitLines();

    Point pl1(3, 1);
    Point pl2(4, 2);
    Line line(pl1, pl2);

    std::vector<Point*> points = p.IntersectionWithVerticalLine(line);
    for(auto point : points) {
        point->Show();
        std::cout << std::endl;
        delete point;
    }
}

