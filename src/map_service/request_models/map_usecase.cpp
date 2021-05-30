//
// Created by Черных Никита Александрович on 23.05.2021.
//

#include "map_usecase.h"

MapManager::MapManager(std::shared_ptr<Adapter> mapAdapter, std::shared_ptr<MapStorage> mapStorage,
                       std::shared_ptr<PathFinder> pathFinder)
    : mapAdapter(mapAdapter), mapStorage(mapStorage), pathFinder(pathFinder)
{
}

std::shared_ptr<GetStorePathResponse> MapManager::GetShopPath(std::shared_ptr<GetStorePathRequest> req)
{
    auto storeData = mapStorage->GetStoreAdjacency(req->StoreID);
    auto path =
        pathFinder->FindPath(req->FromNode, req->ToNode, storeData->Size, mapAdapter->AdaptAdjacency(storeData));
    auto resp = std::make_shared<GetStorePathResponse>(path);
    return resp;
}