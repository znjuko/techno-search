//
// Created by Никита Черных on 20.05.2021.
//

#include "path_usecase.h"

PathManager::PathManager(std::shared_ptr<Adapter> mapAdapter, std::shared_ptr<Storage> mapStorage,
                         std::shared_ptr<PathFinder> pathFinder) : mapAdapter(mapAdapter),
                                                                   mapStorage(mapStorage),
                                                                   pathFinder(pathFinder) {

}

std::shared_ptr<GetStorePathResponse> PathManager::GetShopPath(std::shared_ptr<GetStorePathRequest> req) {
    auto storeData = mapStorage->GetStoreData(req->ShopID);
    auto path = pathFinder->FindPath(
            req->FromNode,
            req->ToNode,
            storeData->Size,
            mapAdapter->AdaptAdjacency(storeData));
    auto resp = std::make_shared<GetStorePathResponse>(path);
    return resp;
}
