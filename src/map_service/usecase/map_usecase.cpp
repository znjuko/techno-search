//
// Created by Черных Никита Александрович on 23.05.2021.
//

#include "map_usecase.h"
#include "shop_map.h"
#include <vector>
#include "map_models.h"
#include <map>
#include "graph_converter.h"

MapManager::MapManager(std::shared_ptr<Adapter> mapAdapter, std::shared_ptr<MapStorage> mapStorage,
                       std::shared_ptr<PathFinder> pathFinder)
    : mapAdapter(mapAdapter), mapStorage(mapStorage), pathFinder(pathFinder)
{
}

void MapManager::CreateStoreMap(std::shared_ptr<StoreMap> map, std::shared_ptr<RawStoreMap> rawMap)
{
    mapStorage->CreateStoreMap(rawMap);

    std::vector<Polygon> features = map->InheritObjects;
    for(auto f : features) {
        f.InitLines();
    }
    Map shopMap;
    shopMap.SetID(map->StoreID);
    shopMap.SetFeatures(features);
    shopMap.SetShop(map->StoreGeometry);
    shopMap.InitPointsAdjTable();

    Adapter adapter;
    auto strAdj = std::make_shared<StoreModel>();
    strAdj->ID = shopMap.GetID();
    strAdj->Adjacency = adapter.AdaptAdjacencyVERSION2(shopMap.GetAdj()).first;
    strAdj->Size = adapter.AdaptAdjacencyVERSION2(shopMap.GetAdj()).second;
    mapStorage->AddStoreAdjacency(strAdj);

    auto strCntrAdj = std::make_shared<StoreCountersAdjacency>();
    std::map<int, int> countersPos = shopMap.GetCountersPosition();
    std::map<int, int>::iterator it;
    for (it = countersPos.begin(); it != countersPos.end(); it++)
    {
        int counterID = it->first;
        int pos = it->second;
        auto temp = CounterWithPoints(counterID, pos);
        strCntrAdj->counterWithPoints.push_back(temp);
    }
    strCntrAdj->StoreID = shopMap.GetID();
    mapStorage->AddStoreCountersAdjacency(strCntrAdj);

    auto points = shopMap.GetBasePoints();
    mapStorage->CreateStoreAdjacencyCoords(map->StoreID, points);
}

std::shared_ptr<GetStorePathResponse> MapManager::GetShopPath(std::shared_ptr<GetStorePathRequest> req)
{
    auto storeData = mapStorage->GetStoreAdjacency(req->StoreID);
    auto countAd = mapStorage->GetStoreCountersAdjacency(req->StoreID);

    int from = 0, to = 0;
    for (const auto &el : countAd->counterWithPoints)
    {
        if (el.CounterID == req->FromCounter)
        {
            from = el.PointID;
        }

        if (el.CounterID == req->ToCounter)
        {
            to = el.PointID;
        }
    }

    auto path = pathFinder->FindPath(from, to, storeData->Size, mapAdapter->AdaptAdjacency(storeData));
    auto resp = std::make_shared<GetStorePathResponse>(path);
    return resp;
}

std::shared_ptr<RawStoreMap> MapManager::GetStoreMap(const int &ID)
{
    return mapStorage->GetStoreMap(ID);
}

std::shared_ptr<AdjacencyPoints> MapManager::GetStoreAdjacencyCoords(const int &storeID)
{
    return mapStorage->GetStoreAdjacencyCoords(storeID);
}
