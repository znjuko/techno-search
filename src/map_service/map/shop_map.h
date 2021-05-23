#ifndef TECHNO_SEARCH_MAP_H
#define TECHNO_SEARCH_MAP_H

#include "map_models.h"

#include <map>
#include <vector>

class Map
{

  public:
    std::vector<Polygon> GetCounters();
    Polygon GetShop();
    std::vector<Polygon> GetFeatures();
    void SetCounters(std::map<Polygon, int> counters);
    void SetShop(const Polygon &shop);
    void SetFeatures(std::vector<Polygon> features);

  private:
    int id;
    std::map<Polygon, int> counters;
    std::vector<Polygon> features;
    Polygon shop;
};

#endif // TECHNO_SEARCH_MAP_H
