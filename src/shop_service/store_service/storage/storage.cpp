//
// Created by fillinmar on 14.04.2021.
//

#include "storage.h"

#include <utility>

// TODO this

std::shared_ptr<GetStoreMetadataResponse> StoreStorage::GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req)
{
    auto q = std::shared_ptr<GetStoreMetadataQuery>();
    q->SetupQuery(req);
    std::shared_ptr<StoreMetadataReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<GetStoreMetadataResponse>();
    res->array = std::move(reader->Get());
    return res;
};
std::shared_ptr<GetStoreListRequest> GetListStore(std::shared_ptr<GetStoreListRequest> req);
std::shared_ptr<UpdateStoreRequest> UpdateStoreMetadata(std::shared_ptr<UpdateStoreRequest> req);
std::shared_ptr<AddStoreResponse> AddStore(std::shared_ptr<AddStoreResponse> req);