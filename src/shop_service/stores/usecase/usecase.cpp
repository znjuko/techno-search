//
// Created by fillinmar on 14.04.2021.
//

#include "usecase.h"

std::shared_ptr<GetStoreMetadataResponse> StoreManager::GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req)
{
    return storage->GetStoreMetadata(req);
}

std::shared_ptr<GetStoreListResponse> StoreManager::GetStoreList(std::shared_ptr<GetStoreListRequest> req)
{
    return storage->GetStoreList(req);
}

std::shared_ptr<UpdateStoreResponse> StoreManager::UpdateStore(std::shared_ptr<UpdateStoreRequest> req)
{
    return storage->UpdateStoreMetadata(req);
}

std::shared_ptr<AddStoreResponse> StoreManager::AddStore(std::shared_ptr<AddStoreRequest> req)
{
    return storage->AddStore(req);
}

StoreManager::StoreManager(const std::shared_ptr<StoreStorage> &storage) : storage(storage)
{
}

StoreManager::~StoreManager() = default;
