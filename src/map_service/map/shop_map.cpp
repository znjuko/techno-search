#include "shop_map.h"

#include "map_models.h"

#include <map>
#include <utility>
#include <vector>

std::vector<Polygon> Map::GetCounters()
{
    std::vector<Polygon> v;
    for (auto &counter : counters)
    {
        v.push_back(counter.first);
    }
    return v;
}
Polygon Map::GetShop()
{
    return shop;
}

void Map::SetCounters(std::map<Polygon, int> c)
{
    this->counters = std::move(c);
}
void Map::SetShop(const Polygon &s)
{
    this->shop = s;
}
void Map::SetFeatures(std::vector<Polygon> f)
{
    this->features = std::move(f);
}
std::vector<Polygon> Map::GetFeatures()
{
    return features;
}
