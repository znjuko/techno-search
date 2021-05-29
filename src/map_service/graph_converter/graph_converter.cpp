#include "shop_map.h"
#include <utility>
#include <vector>
#include "map_models.h"
#include "graph_converter.h"
#include <iostream>
#include "iomanip"

std::vector<Point> GraphConverter::GetPoints() {

    std::vector<Point> points = std::vector<Point>();

    std::vector<Polygon> features = map.GetFeatures();
    Polygon shop = map.GetShop();

    std::vector<double> xArray = getAllx();

    for(size_t i = 1; i < xArray.size(); ++i) {

        double leftX = xArray[i - 1];
        double rightX = xArray[i];

        Line leftLine(Point(leftX, 0), Point(leftX, 1));
        std::vector<Point> leftPoints = getAllIntersectionsWithVerticalLine(leftLine);
        std::sort(leftPoints.begin(), leftPoints.end(), [](const Point& p1,const Point& p2){return p1.y <= p2.y;});
        leftPoints.erase(unique(leftPoints.begin(), leftPoints.end()), leftPoints.end());

        Line rightLine(Point(rightX, 0), Point(rightX, 1));
        std::vector<Point> rightPoints = getAllIntersectionsWithVerticalLine(rightLine);
        std::sort(rightPoints.begin(), rightPoints.end(), [](const Point& p1,const Point& p2){return p1.y >= p2.y;});
        rightPoints.erase(unique(rightPoints.begin(), rightPoints.end()), rightPoints.end());


        std::vector<Point> basePoints = getBasePoints(leftPoints, rightPoints);
        std::vector<Point> featuresCenters = getFeaturesCenters((leftX + rightX) / 2);

        for(auto &p : basePoints) {
            points.push_back(p);
        }

        for(auto &p : featuresCenters) {
            points.push_back(p);
        }
    }

    std::vector<Point> featuresPoints  = getFeaturesPoints(features);

    for(auto &p : featuresPoints) {
        p.Show();
        points.push_back(p);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::sort(points.begin(), points.end(), [](const Point& p1,const Point& p2){return p1.x <= p2.x;});

    for(auto &p : points) {
        p.Show();
        std::cout << std::endl;
    }

    return points;
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

std::vector<Point> GraphConverter::getBasePoints(const std::vector<Point>& leftPoints, const std::vector<Point>& rightPoints) {

    std::vector<Point> basePoints;
    Polygon shop = map.GetShop();
    std::vector<Polygon> leftFeatures = getFeaturesIntersectedWithPoints(leftPoints);
    std::vector<Polygon> rightFeatures = getFeaturesIntersectedWithPoints(rightPoints);

    std::vector<Line> rightLines = std::vector<Line>();

    for(size_t i = 1; i < rightPoints.size(); ++i) {
        Line line = Line(rightPoints[i-1], rightPoints[i]);
        rightLines.push_back(line);
    }

    for(auto line : rightLines) {
        Point mid = line.GetMiddleOfLine();
        int flag = 1;

        for(auto feature : rightFeatures) {
            if(feature.IsPointInsidePolygon(mid) || feature.IsPointOnPolygon(mid)) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            basePoints.push_back(mid);
        }
    }

    return basePoints;
}

std::vector<Polygon> GraphConverter::getFeaturesIntersectedWithPoints(const std::vector<Point>& points) {
    std::vector<Polygon> features = map.GetFeatures();
    std::vector<Polygon> intersectedFeatures;

    for(Polygon feature : features) {
        for(auto point : points) {
            if (feature.IsPointOnPolygon(point)) {
                intersectedFeatures.push_back(feature);
                break;
            }
        }
    }


    return intersectedFeatures;
}
std::vector<Point> GraphConverter::getFeaturesCenters(const double &middleX) {

    std::vector<Point> featureCenters = std::vector<Point>();

    Line middleLine = Line(Point(middleX, 0), Point(middleX, 1));

    std::vector<Polygon> features = map.GetFeatures();

    std::vector<Point> intersectedPoints = getAllIntersectionsWithVerticalLine(middleLine);
    std::sort(intersectedPoints.begin(), intersectedPoints.end(), [](const Point& p1,const Point& p2){return p1.y <= p2.y;});

    std::vector<Line> allPoints = std::vector<Line>();


    for(size_t i = 1; i < intersectedPoints.size(); ++i) {
        Line line = Line(intersectedPoints[i - 1], intersectedPoints[i]);
        Point p = line.GetMiddleOfLine();

        int flag = 1;
        for(auto  feature : features) {
            if(feature.IsPointInsidePolygon(p)) {
                flag = 0;
                break;
            }
        }
        if(flag)
            featureCenters.push_back(p);
    }

    return featureCenters;
}

std::vector<std::vector<double>> GraphConverter::GetAdjacencyTableFromPoints(const std::vector<Point> &points) {

    std::vector<Polygon> features = map.GetFeatures();

    size_t matrixSize = points.size() + 1;
    std::vector<std::vector<double>> adjacencyTable(matrixSize);

    for (size_t i = 0 ; i < matrixSize ; ++i)
        adjacencyTable[i].resize(matrixSize);

    for (size_t i = 0 ; i < matrixSize ; ++i)
        adjacencyTable[0][i] = double(i);

    for (size_t i = 0 ; i < matrixSize ; ++i)
        adjacencyTable[i][0] = double(i);


    for(size_t i = 0; i < points.size(); ++i) {
        Point leftPoint = points[i];
        double leftX = leftPoint.x, rightX = leftPoint.x, currentX;
        size_t leftIndex = i, rightIndex;


        for(size_t j = i + 1; j < points.size(); ++j) {
            if (points[j].x > leftX) {
                rightX = points[j].x;
                rightIndex = j;
                break;
            }
        }

        currentX = rightX;
        while(currentX == rightX && rightIndex < points.size()) {
            Point rightPoint = points[rightIndex];
            Line line(leftPoint, rightPoint);

            int flag = 1;
            for(auto feature : features) {

                if(flag == 0){
                    break;
                }

                std::vector<Point*> interactions = feature.IntersectionWithVerticalLine(line);
                if(!interactions.empty()) {
                    for(auto point : interactions) {
                        if((point->x <= std::max(rightPoint.x, leftPoint.x) && point->x >= std::min(rightPoint.x, leftPoint.x) && point->y <= std::max(rightPoint.y, leftPoint.y) && point->y >= std::min(rightPoint.y, leftPoint.y))) {
                            if(rightPoint.counterID != -1 && *point == rightPoint) {
                                flag = 1;
                            }
                            else {
                                flag = 0;
                                break;
                            }
                        }
                    }
                }
            }

            if(flag) {
                double dist = leftPoint.GetDistanceToPoint(rightPoint);
                adjacencyTable[leftIndex + 1][rightIndex + 1] = dist;
                adjacencyTable[rightIndex + 1][leftIndex + 1] = dist;
            }
            rightIndex++;
            currentX = points[rightIndex].x;
        }


    }

    for (size_t i = 0 ; i < matrixSize ; ++i) {
        for(size_t j = 0; j < matrixSize; ++j) {
            std::cout << std::setw(5) << std::setprecision(2) << adjacencyTable[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return adjacencyTable;
}

std::vector<Point> GraphConverter::getFeaturesPoints(const std::vector<Polygon> &features) {

    std::vector<Point> featuresPoints = std::vector<Point>();

    for(auto feature : features) {
        featuresPoints.push_back(feature.GetFeaturePoint());
    }

    return featuresPoints;
}
