//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_STORAGE_H
#define TECHNO_SEARCH_STORE_STORAGE_H

#include "models.h"
#include "postgres_storage.h"

#include <memory>

class StoreStorage
{
  public:
    StoreStorage() = delete;

    explicit StoreStorage(std::shared_ptr<PostgresStorage> storage);

    std::shared_ptr<GetStoreMetadataResponse> GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req);

    std::shared_ptr<GetStoreListResponse> GetStoreList(std::shared_ptr<GetStoreListRequest> req);

    std::shared_ptr<UpdateStoreResponse> UpdateStore(std::shared_ptr<UpdateStoreRequest> req, std::shared_ptr<UpdateStoreRequest> req2);

    std::shared_ptr<AddStoreResponse> AddStore(std::shared_ptr<AddStoreRequest> req, std::shared_ptr<AddStoreRequest> req2);

    ~StoreStorage();

  private:
    std::shared_ptr<PostgresStorage> storage;
};
#endif
