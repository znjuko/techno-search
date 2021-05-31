#ifndef TECHNO_SEARCH_MAP_USECASE_H
#define TECHNO_SEARCH_MAP_USECASE_H

#include "adapter.h"
#include "finder.h"
#include "map_models.h"
#include "map_request_models.h"
#include "map_storage.h"

class MapManager
{
  public:
    MapManager() = delete;

    MapManager(std::shared_ptr<Adapter> mapAdapter, std::shared_ptr<MapStorage> mapStorage,
               std::shared_ptr<PathFinder> pathFinder);

    std::shared_ptr<GetStorePathResponse> GetShopPath(std::shared_ptr<GetStorePathRequest> req);

    std::shared_ptr<RawStoreMap> GetStoreMap(const int &ID);

    std::shared_ptr<AdjacencyPoints> GetStoreAdjacencyCoords(const int &storeID);

    void CreateStoreMap(std::shared_ptr<StoreMap> map, std::shared_ptr<RawStoreMap> rawMap);

    ~MapManager() = default;

  private:
    std::shared_ptr<Adapter> mapAdapter;
    std::shared_ptr<MapStorage> mapStorage;
    std::shared_ptr<PathFinder> pathFinder;
};

#endif // TECHNO_SEARCH_MAP_USECASE_H