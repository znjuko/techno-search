#include "shop_map.h"

#include "graph_converter.h"
#include "map_models.h"

#include <map>
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

void Map::SetCounters(std::map<Polygon, int> counters)
{
    this->counters = counters;
}
void Map::SetShop(Polygon shop)
{
    this->shop = shop;
}

void Map::InitPointsAdjTable()
{
    GraphConverter converter;
    converter.SetMap(*this);
    this->basePoints = converter.GetPoints();
    this->adjTable = converter.GetAdjacencyTableFromPoints(this->basePoints);
}

std::map<int, int> Map::GetCountersPosition()
{
    std::map<int, Point> counterPointID;
    std::map<int, int> counterPositionID;

    for (auto f : features)
    {
        int _id = f.GetID();
        counterPointID[_id] = f.GetFeaturePoint();
    }

    std::map<int, Point>::iterator it;

    for (it = counterPointID.begin(); it != counterPointID.end(); it++)
    {
        int counterID = it->first;
        int pos = -1;
        Point p = it->second;

        for (int i = 0; i < basePoints.size(); ++i)
        {
            if (p == basePoints[i])
            {
                pos = i + 1;
            }
        }

        counterPositionID[counterID] = pos;
    }

    // id counter/ point position
    return counterPositionID;
}

void Map::SetID(int _id)
{
    id = _id;
}

std::vector<Point> Map::GetBasePoints()
{
    return basePoints;
}
