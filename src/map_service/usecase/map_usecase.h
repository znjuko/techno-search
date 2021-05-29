//
// Created by Черных Никита Александрович on 23.05.2021.
//

#ifndef TECHNO_SEARCH_MAP_USECASE_H
#define TECHNO_SEARCH_MAP_USECASE_H

#include "adapter.h"
#include "finder.h"
#include "map_request_models.h"
#include "storage.h"

class MapManager
{
  public:
    MapManager() = delete;

    MapManager(std::shared_ptr<Adapter> mapAdapter, std::shared_ptr<MapStorage> mapStorage,
               std::shared_ptr<PathFinder> pathFinder);

    std::shared_ptr<GetStorePathResponse> GetShopPath(std::shared_ptr<GetStorePathRequest> req);

    ~MapManager() = default;

  private:
    std::shared_ptr<Adapter> mapAdapter;
    std::shared_ptr<MapStorage> mapStorage;
    std::shared_ptr<PathFinder> pathFinder;
};

#endif // TECHNO_SEARCH_MAP_USECASE_H
