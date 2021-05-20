#include "shop_map.h"
#include <utility>
#include <vector>
#include "map_models.h"
#include "graph_converter.h"
#include <iostream>

std::vector<std::vector<double>> GraphConverter::Generate() {

    std::vector<std::vector<double>> adjacencyTable;

    std::vector<Polygon> features = map.GetFeatures();
    Polygon shop = map.GetShop();

    std::vector<double> xArray = getAllx();

    for(auto t : xArray) {
        std::cout << t << ' ';
    }
    std::cout << std::endl;

    for(size_t i = 1; i < xArray.size(); ++i) {

        double leftX = xArray[i - 1];
        double rightX = xArray[i];

        std::cout << leftX << ' ' << rightX << std::endl;

        Line leftLine(Point(leftX, 0), Point(leftX, 1));
        std::vector<Point> leftPoints = getAllIntersectionsWithVerticalLine(leftLine);
        std::sort(leftPoints.begin(), leftPoints.end(), [](const Point& p1,const Point& p2){return p1.y <= p2.y;});

        Line rightLine(Point(rightX, 0), Point(rightX, 1));
        std::vector<Point> rightPoints = getAllIntersectionsWithVerticalLine(rightLine);
        std::sort(rightPoints.begin(), rightPoints.end(), [](const Point& p1,const Point& p2){return p1.y <= p2.y;});

        std::vector<Point> points;
        points.insert(points.end(), leftPoints.begin(), leftPoints.end());
        points.insert(points.end(), rightPoints.begin(), rightPoints.end());
        points.erase(unique(points.begin(), points.end()), points.end());

        for(auto p : points) {
            p.Show();
            std::cout << std::endl;
        }

        std::vector<Point> basepoints = getBasePoints(points);

        break;

        std::cout << std::endl;
    }

    return adjacencyTable;
}
void GraphConverter::SetMap(Map m) {
    this->map = std::move(m);
}

std::vector<double> GraphConverter::getAllx() {

    std::vector<double> xArray = std::vector<double>();

    std::vector<Point> temp;
    temp = map.GetShop().GetVertices();

    for(auto p : temp) {
        xArray.push_back(p.x);
    }

    for(auto feature : map.GetFeatures()) {
        temp = feature.GetVertices();
        for(auto p : temp) {
            xArray.push_back(p.x);
        }
    }

    sort(xArray.begin(), xArray.end(), [](double a, double b){return a < b;});
    xArray.erase(unique( xArray.begin(), xArray.end() ), xArray.end());

    return xArray;
}

std::vector<Point> GraphConverter::getAllIntersectionsWithVerticalLine(Line line) {

    std::vector<Point> points;

    Polygon shop = map.GetShop();
    std::vector<Polygon> features = map.GetFeatures();

    std::vector<Point*> shopInteractions = shop.IntersectionWithVerticalLine(line);

    for(Polygon feature : features) {
        std::vector<Point*> interactions = feature.IntersectionWithVerticalLine(line);

        if(interactions.empty()) {
                continue;
        }

        for(auto p : interactions) {
            points.push_back(*p);
        }

    }

    for(auto p : shopInteractions) {
        points.push_back(*p);
        delete p;
    }


    return points;
}
std::vector<Point> GraphConverter::getBasePoints(std::vector<Point> points) {
    return std::vector<Point>();
}
