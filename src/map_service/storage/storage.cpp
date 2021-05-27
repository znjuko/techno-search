//
// Created by foxers on 27.05.2021.
//

#include "storage.h"

Storage::Storage(std::shared_ptr<mongocxx::database> database) : database(database){};

std::shared_ptr<StoreModel> MapStorage::GetMapData(const int &ID)
{
    auto storeCollection = database->collection("store_graph");

    auto selectStoreResult = storeCollection.find_one(make_document(kvp("ID", ID)));
    if (!selectStoreResult)
    {
        throw StoreGraphNotFound(ID);
    }

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    return std::make_shared<StoreModel>(selectStoreOutput);
}

std::shared_ptr<AddMapResponse> MapStorage::AddMap(std::shared_ptr<AddProductRequest> req,
                                                   std::shared_ptr<AddProductRequest> req2,
                                                   std::shared_ptr<AddProductRequest> req3)
{
    auto q = std::make_shared<AddMapQuery>();
    q->SetupQuery(req);
    storage->Insert(q);

    auto q2 = std::make_shared<AddProductQuery>();
    q2->SetupQueryForId(req2); //translate to postgres request
    auto reader = std::make_shared<AddProductReader>();
    storage->Select(q2, reader);//return Id

    auto res = std::make_shared<AddProductResponse>();
    res->array = reader->Get();
    return res;
}