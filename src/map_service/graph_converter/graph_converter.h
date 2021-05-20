#ifndef TECHNO_SEARCH_GRAPH_CONVERTER_H
#define TECHNO_SEARCH_GRAPH_CONVERTER_H

#include "shop_map.h"
#include "map_models.h"
#include <vector>

class GraphConverter{

public:
    void SetMap(Map m);
    std::vector<std::vector<double>> Generate();
private:

    std::vector<double> getAllx();
    std::vector<Point> getAllIntersectionsWithVerticalLine(Line line);
    std::vector<Point> getBasePoints(std::vector<Point> points);

    Map map;
};

#endif //TECHNO_SEARCH_GRAPH_CONVERTER_H
