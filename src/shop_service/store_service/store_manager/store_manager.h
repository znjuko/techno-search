//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_MANAGER_H
#define TECHNO_SEARCH_STORE_MANAGER_H

#include "models.h"
#include "storage.h"

class StoreManager
{
  public:
    StoreManager() = delete;
    explicit StoreManager(const StoreManager &storage) noexcept;
    GetStoreMetadataResponse GetStoreMetadata(GetStoreMetadataRequest req);
    GetStoreListResponse GetListStore(GetStoreMetadataRequest req);
    UpdateStoreResponse UpdateStoreMetadata(UpdateStoreRequest req);
    AddStoreResponse AddStore(AddStoreRequest req);
    ~StoreManager();
  private:
    StoreStorage store;
};

#endif // TECHNO_SEARCH_STORE_MANAGER_H
