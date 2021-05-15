#ifndef TECHNO_SEARCH_MAP_H
#define TECHNO_SEARCH_MAP_H

#include <vector>
#include <map>
#include "graph_converter.h"
#include "models.h"

class Map {

public:
    std::map<Polygon, int> getCounters();
    Feature getShop();

private:
    int id;
    std::map<Polygon, int> counters;
    Feature shop;
};


#endif //TECHNO_SEARCH_MAP_H
