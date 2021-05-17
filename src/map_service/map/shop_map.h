#ifndef TECHNO_SEARCH_MAP_H
#define TECHNO_SEARCH_MAP_H

#include <vector>
#include <map>
#include "map_models.h"
//#include "graph_converter.h"

class Map {

public:
    std::vector<Polygon> GetCounters();
    Polygon GetShop();
    void SetCounters(std::map<Polygon, int> counters);
    void SetShop(Polygon shop);

private:
    int id;
    std::map<Polygon, int> counters;
    Polygon shop;

};


#endif //TECHNO_SEARCH_MAP_H
