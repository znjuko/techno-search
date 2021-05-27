//
// Created by foxers on 27.05.2021.
//

#include "storage.h"

MapStorage::MapStorage(std::shared_ptr<mongocxx::database> database) : database(database){};

std::shared_ptr<InsertMapResponse> MapStorage::InsertMap(const string data)
{
    auto mapCollection = database->collection("map");

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = mapCollection.insert(data);

    return std::make_shared<InsertMapResponse>(result);
}

std::shared_ptr<MapModel> MapStorage::GetMapData(const int &ShopID)
{
    auto mapCollection = database->collection("map");

    auto selectMapResult = mapCollection.find_one(make_document(kvp("ShopID", ShopID)));
    if (!selectMapResult)
    {
        throw MapNotFound(ID);
    }

    auto selectMapOutput = bsoncxx::to_json(*selectMapResult);
    return std::make_shared<MapModel>(selectMapOutput);
}

