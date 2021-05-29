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
    void InitPointsAdjTable();
    void SetID(int _id);
    std::map<int, int> GetCountersPosition();
    std::vector<Point> GetBasePoints();
  private:
    int id;
    std::map<Polygon, int> counters;
    std::vector<Polygon> features;
    std::vector<Point> basePoints;
    std::vector<std::vector<double>> adjTable;
    Polygon shop;
};

#endif // TECHNO_SEARCH_MAP_H
