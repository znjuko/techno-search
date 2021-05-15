#include <gtest/gtest.h>
#include "models.h"
#include <iostream>

TEST(LINE, INTERSECTION) {

    Point p1(0,0),  p2(2,2);
    Point p3(0,1),  p4(3,0);

    Line l1(p1,p2), l2(p3,p4);

    Point* p = l1.LineIntersectionWithLine(l2);

    std::cout << p->x << ' ' << p->y;

    delete p;
}