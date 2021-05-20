#include <vector>
#include <map>
#include "shop_map.h"
#include "graph_converter.h"
#include "map_models.h"

std::vector<Polygon> Map::GetCounters() {
    std::vector<Polygon> v;
    for(auto & counter : counters) {
        v.push_back(counter.first);
    }
    return v;
}
Polygon Map::GetShop() {
    return shop;
}

void Map::SetCounters(std::map<Polygon, int> counters) {
    this->counters = counters;
}
void Map::SetShop(Polygon shop) {
    this->shop = shop;
}


