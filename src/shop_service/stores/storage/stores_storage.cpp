//
// Created by fillinmar on 14.04.2021.
//

#include "stores_storage.h"

#include "../query/query.h"
#include "../reader/stores_reader.h"

#include <utility>

std::shared_ptr<GetStoreMetadataResponse> StoreStorage::GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req)
{
    auto q = std::shared_ptr<GetStoreMetadataQuery>();
    q->SetupQuery(req);
    std::shared_ptr<StoreMetadataReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<GetStoreMetadataResponse>();
    res->array = std::move(reader->Get());
    return res;
}

std::shared_ptr<GetStoreListResponse> StoreStorage::GetStoreList(std::shared_ptr<GetStoreListRequest> req)
{
    auto q = std::shared_ptr<GetStoreListQuery>();
    q->SetupQuery(req);
    std::shared_ptr<StoreListReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<GetStoreListResponse>();
    res->array = std::move(reader->Get());
    return res;
}

std::shared_ptr<AddStoreResponse> StoreStorage::AddStore(std::shared_ptr<AddStoreRequest> req)
{
    auto q = std::shared_ptr<AddStoreQuery>();
    q->SetupQuery(req);
    std::shared_ptr<AddStoreReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<AddStoreResponse>();
    res->array = std::move(reader->Get());
    return res;
}

StoreStorage::~StoreStorage()
{
}

StoreStorage::StoreStorage(std::shared_ptr<PostgresStorage> storage) : storage(storage)
{
}
