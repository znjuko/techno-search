//
// Created by fillinmar on 14.04.2021.
//

#include "store_storage.h"

#include "../reader/stores_reader.h"
#include "store_query.h"

#include <utility>

std::shared_ptr<GetStoreMetadataResponse> StoreStorage::GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req)
{
    auto q = std::make_shared<GetStoreMetadataQuery>();
    q->SetupQuery(req);
//    std::shared_ptr<StoreMetadataReader> reader;

    auto reader = std::make_shared<StoreMetadataReader>();
    storage->Select(q, reader);

    auto res = std::make_shared<GetStoreMetadataResponse>();
    res->array = reader->Get();
    return res;
}

std::shared_ptr<GetStoreListResponse> StoreStorage::GetStoreList(std::shared_ptr<GetStoreListRequest> req)
{
    auto q = std::make_shared<GetStoreListQuery>();
    q->SetupQuery(req);
//    std::shared_ptr<StoreListReader> reader;
    auto reader = std::make_shared<StoreListReader>();

    storage->Select(q, reader);

    auto res = std::make_shared<GetStoreListResponse>();
    res->array = reader->Get();
    return res;
}

std::shared_ptr<UpdateStoreResponse> StoreStorage::UpdateStore(std::shared_ptr<UpdateStoreRequest> req)
{
    auto q = std::make_shared<UpdateStoreQuery>();
    q->SetupQuery(req);
//    std::shared_ptr<StoreListReader> reader;
    auto reader = std::make_shared<UpdateStoreReader>();

    storage->Select(q, reader);

    auto res = std::make_shared<UpdateStoreResponse>();
//    res->array = reader->Get();
    return res;
}

std::shared_ptr<AddStoreResponse> StoreStorage::AddStore(std::shared_ptr<AddStoreRequest> req)
{
    auto q = std::make_shared<AddStoreQuery>();
    q->SetupQuery(req);
    auto reader = std::make_shared<AddStoreReader>();
//    std::shared_ptr<AddStoreReader> reader;

    storage->Select(q, reader);

    auto res = std::make_shared<AddStoreResponse>();
    res->array = reader->Get();
    return res;
}

StoreStorage::~StoreStorage()
{
}

StoreStorage::StoreStorage(std::shared_ptr<PostgresStorage> storage) : storage(storage)
{
}
