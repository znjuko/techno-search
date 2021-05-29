//
// Created by fillinmar on 14.04.2021.
//

#include "store_storage.h"

#include "../reader/stores_reader.h"
#include "store_query.h"


std::shared_ptr<GetStoreMetadataResponse> StoreStorage::GetStoreMetadata(std::shared_ptr<GetStoreMetadataRequest> req)
{
    auto q = std::make_shared<GetStoreMetadataQuery>();
    q->SetupQuery(req);

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
    auto reader = std::make_shared<StoreListReader>();

    storage->Select(q, reader);

    auto res = std::make_shared<GetStoreListResponse>();
    res->array = reader->Get();
    return res;
}
std::shared_ptr<UpdateStoreResponse> StoreStorage::UpdateStore(std::shared_ptr<UpdateStoreRequest> req, std::shared_ptr<UpdateStoreRequest> req2)
{
    auto q = std::make_shared<UpdateStoreQuery>();
    q->SetupQuery(req);
    storage->Insert(q);

    auto q2 = std::make_shared<UpdateStoreQuery>();
    q2->SetapQuery2(req2); //translate to postgres request
    auto reader = std::make_shared<UpdateStoreReader>();
    storage->Select(q2, reader);

    auto res = std::make_shared<UpdateStoreResponse>();
    res->array = reader->Get();
    return res;
}
//std::shared_ptr<UpdateStoreResponse> StoreStorage::UpdateStore(std::shared_ptr<UpdateStoreRequest> req)
//{
//    auto q = std::make_shared<UpdateStoreQuery>();
//    q->SetupQuery(req);
//    auto reader = std::make_shared<UpdateStoreReader>();
//
//    auto q2 = std::make_shared<GetStoreMetadataQuery>();
//    q2->SetupQuery(req); //translate to postgres request
//
//    storage->Insert(q);
//
//    auto res = std::make_shared<UpdateStoreResponse>();
//    res->array = reader->Get();
//    return res;
//}

std::shared_ptr<AddStoreResponse> StoreStorage::AddStore(std::shared_ptr<AddStoreRequest> req, std::shared_ptr<AddStoreRequest> req2)
{
    auto q = std::make_shared<AddStoreQuery>();
    q->SetupQuery(req);
    storage->Insert(q);

    auto q2 = std::make_shared<AddStoreQuery>();
    q2->SetupQueryForId(req2); //translate to postgres request
    auto reader = std::make_shared<AddStoreReader>();
    storage->Select(q2, reader);//return Id

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
