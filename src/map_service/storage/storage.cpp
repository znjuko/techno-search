//
// Created by foxers on 27.05.2021.
//
#include <iostream>
#include "storage.h"

MapStorage::MapStorage(std::shared_ptr<mongocxx::database> database) : database(database){};

void MapStorage::InsertMap(const std::string data)
{
    auto mapCollection = database->collection("map");

    auto doc = bsoncxx::from_json(data);

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = mapCollection.insert_one(std::move(doc));
}

std::shared_ptr<MapModel> MapStorage::GetMapData(const int &ShopID)
{
    auto mapCollection = database->collection("map");

    auto selectMapResult = mapCollection.find_one(make_document(kvp("ShopID", ShopID)));
    /*if (!selectMapResult)
    {
        throw MapNotFound(ShopID);
    }*/

    auto selectMapOutput = bsoncxx::to_json(*selectMapResult);
    return std::make_shared<MapModel>(selectMapOutput);
}

std::shared_ptr<MapCounterStorage> MapCounterStorage::GetMapCounterData(const int &ID)
{
    auto MapCounterCollection = database->collection("MapCounter");

    auto selectMapCounterResult = MapCounterCollection.find_one(make_document(kvp("ID", ID)));
    /*if (!selectMapResult)
    {
        throw MapNotFound(ShopID);
    }*/

    auto selectMapCounterOutput = bsoncxx::to_json(*selectMapCounterResult);
    return std::make_shared<MapCounterStorage>(selectMapCounterOutput);
}