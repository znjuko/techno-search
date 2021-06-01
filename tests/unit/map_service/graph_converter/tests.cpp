#include "graph_converter.h"
#include "shop_map.h"
#include "adapter.h"
#include <gtest/gtest.h>
#include <map>
#include <time.h>

#include "finder.h"
#include "map_request_models.h"

TEST(GRAPH_CONVERTER, GENERATE_1)
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
    p1.SetID(1);
    p1.InitLines();
    p2.AddPoint(Point(8, 13));
    p2.AddPoint(Point(13, 13));
    p2.AddPoint(Point(15, 8));
    p2.AddPoint(Point(12, 8));
    p2.SetID(2);
    p2.InitLines();
    p3.AddPoint(Point(12, 6));
    p3.AddPoint(Point(15, 6));
    p3.AddPoint(Point(17, 2));
    p3.AddPoint(Point(17, 1));
    p3.AddPoint(Point(12, 1));
    p3.SetID(3);
    p3.InitLines();

    std::vector<Polygon> features;
    features.push_back(p1);
    features.push_back(p2);
    features.push_back(p3);
    map.SetFeatures(features);
    map.SetShop(shop);

    clock_t start = clock();

    map.InitPointsAdjTable();

    PathFinder pf;
    std::vector<int> path = pf.FindPath(34, 0, map.GetAdj().size(), map.GetAdj());

    for(auto point : path) {
        std::cout << point << ' ';
    }

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::cout << std::endl << elapsed << std::endl;

}

TEST(GRAPH_CONVERTER, GENERATE_2)
{
    Map map;

    Polygon shop;
    shop.AddPoint(Point(0, 0));
    shop.AddPoint(Point(0, 10));
    shop.AddPoint(Point(10, 10));
    shop.AddPoint(Point(10, 0));
    shop.InitLines();

    Polygon p1;
    p1.AddPoint(Point(3, 3));
    p1.AddPoint(Point(3, 6));
    p1.AddPoint(Point(6, 6));
    p1.AddPoint(Point(6, 3));
    p1.SetID(13);
    p1.InitLines();

    std::vector<Polygon> features;
    features.push_back(p1);
    map.SetFeatures(features);
    map.SetShop(shop);

    GraphConverter converter;
    converter.SetMap(map);
    map.InitPointsAdjTable();

    std::cout << std::endl;
    std::map<int, int> counterPosID = map.GetCountersPosition();
    std::map<int, int>::iterator it;
//    for (it = counterPosID.begin(); it != counterPosID.end(); it++)
//    {
//        std::cout << it->first << ' ' << it->second << std::endl;
//    }

//    std::vector<std::vector<double>> v = map.GetAdj();
//
//    Adapter ad;
//    std::pair<std::vector<double>, int> p = ad.AdaptAdjacencyVERSION2(v);
//
//    for(auto t : p.first) {
//        std::cout << t << ' ';
//    }
//    std::cout << std::endl;
//
//    auto model = std::make_shared<StoreModel>();
//    model->Adjacency = p.first;
//    model->Size = p.second;
//    std::vector<std::vector<double>> adj = ad.AdaptAdjacency(model);
//
//    for (size_t i = 0; i < adj.size(); ++i)
//    {
//        for (size_t j = 0; j < adj.size(); ++j)
//        {
//            std::cout << std::setw(5) << std::setprecision(2) << adj[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }

}