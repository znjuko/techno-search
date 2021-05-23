//
// Created by Никита Черных on 20.05.2021.
//

#ifndef TECHNO_SEARCH_MAP_USECASE_H
#define TECHNO_SEARCH_MAP_USECASE_H

#include "adapter.h"
#include "finder.h"
#include "models.h"
#include "path_models.h"
#include "storage.h"

class PathManager
{
  public:
    PathManager() = delete;

    PathManager(std::shared_ptr<Adapter> mapAdapter, std::shared_ptr<Storage> mapStorage,
                std::shared_ptr<PathFinder> pathFinder);

    std::shared_ptr<GetStorePathResponse> GetShopPath(std::shared_ptr<GetStorePathRequest> req);

    ~PathManager() = default;

  private:
    std::shared_ptr<Adapter> mapAdapter;
    std::shared_ptr<Storage> mapStorage;
    std::shared_ptr<PathFinder> pathFinder;
};

#endif // TECHNO_SEARCH_MAP_USECASE_H