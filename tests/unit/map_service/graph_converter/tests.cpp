#include "graph_converter.h"
#include "shop_map.h"

#include <gtest/gtest.h>
#include <iostream>
#include <map>

TEST(GRAPH_CONVERTER, GENERATE)
{
    Map map;

    Polygon shop;
    shop.AddPoint(Point(0, 0));
    shop.AddPoint(Point(0, 15));
    shop.AddPoint(Point(15, 15));
    shop.AddPoint(Point(21, 0));
    shop.InitLines();

    Polygon p1, p2, p3;
    p1.AddPoint(Point(3, 7));
    p1.AddPoint(Point(3, 14));
    p1.AddPoint(Point(7, 14));
    p1.AddPoint(Point(7, 7));
    p1.InitLines();
    p2.AddPoint(Point(8, 13));
    p2.AddPoint(Point(13, 13));
    p2.AddPoint(Point(15, 8));
    p2.AddPoint(Point(12, 8));
    p2.InitLines();
    p3.AddPoint(Point(12, 6));
    p3.AddPoint(Point(15, 6));
    p3.AddPoint(Point(17, 2));
    p3.AddPoint(Point(17, 1));
    p3.AddPoint(Point(12, 1));
    p3.InitLines();

    std::vector<Polygon> features;
    features.push_back(p1);
    features.push_back(p2);
    features.push_back(p3);
    map.SetFeatures(features);
    map.SetShop(shop);

    GraphConverter converter;
    converter.SetMap(map);
    converter.Generate();
}
