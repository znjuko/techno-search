#include <vector>
#include <map>
#include "shop_map.h"
#include "graph_converter.h"
#include "models.h"

std::vector<Polygon> Map::getCounters() {
    std::vector<Polygon> v;
    for(std::map<Polygon,int>::iterator it = counters.begin(); it != counters.end(); ++it) {
        v.push_back(it->first);
    }
    return v;
}

Feature Map::getShop() {
    return shop;
}

