//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORES_MANAGER_H
#define TECHNO_SEARCH_STORES_MANAGER_H

#include "models.h"
#include "store_storage.h"

class StoreManager
{
  public:
    StoreManager() = delete;
    StoreManager(const std::shared_ptr<StoreStorage> &storage);
    std::shared_ptr<GetStoreMetadataResponse> GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req);
    std::shared_ptr<GetStoreListResponse> GetStoreList(std::shared_ptr<GetStoreListRequest> req);
    std::shared_ptr<UpdateStoreResponse> UpdateStore(std::shared_ptr<UpdateStoreRequest> req);
    std::shared_ptr<AddStoreResponse> AddStore(std::shared_ptr<AddStoreRequest> req);
    ~StoreManager();

  private:
    std::shared_ptr<StoreStorage> storage;
};

#endif
