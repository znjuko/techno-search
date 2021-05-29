#ifndef TECHNO_SEARCH_GRAPH_CONVERTER_H
#define TECHNO_SEARCH_GRAPH_CONVERTER_H

#include "map_models.h"
#include "shop_map.h"

#include <vector>

class GraphConverter
{

  public:
    void SetMap(Map m);
    std::vector<Point> GetPoints();
    std::vector<std::vector<double>> GetAdjacencyTableFromPoints(const std::vector<Point> &points);

  private:
    std::vector<double> getAllx();
    std::vector<Point> getAllIntersectionsWithVerticalLine(Line line);
    std::vector<Point> getBasePoints(const std::vector<Point> &leftPoints, const std::vector<Point> &rightPoints);
    std::vector<Polygon> getFeaturesIntersectedWithPoints(const std::vector<Point> &points);
    std::vector<Point> getFeaturesCenters(const double &middleX);
    std::vector<Point> getFeaturesPoints(const std::vector<Polygon> &features);
    Map map;
};

#endif // TECHNO_SEARCH_GRAPH_CONVERTER_H
