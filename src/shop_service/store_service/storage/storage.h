//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_STORAGE_H
#define TECHNO_SEARCH_STORE_STORAGE_H

#include "models.h"
#include "common_storage.h"
#include <memory>

class StoreStorage
{
  public:
    StoreStorage() = delete;

    explicit StoreStorage(std::shared_ptr<PostgresStorage> storage);

    std::shared_ptr<GetStoreMetadataResponse> GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req);

    std::shared_ptr<GetStoreListRequest> GetListStore(std::shared_ptr<GetStoreListRequest> req);

    std::shared_ptr<UpdateStoreRequest> UpdateStoreMetadata(std::shared_ptr<UpdateStoreRequest> req);

    std::shared_ptr<AddStoreResponse> AddStore(std::shared_ptr<AddStoreResponse> req);

  private:
    std::shared_ptr<StoreStorage> storage;
};
#endif // TECHNO_SEARCH_STORE_STORAGE_H
