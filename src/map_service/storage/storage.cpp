//
// Created by foxers on 27.05.2021.
//
#include <iostream>
#include "storage.h"

MapStorage::MapStorage(std::shared_ptr<mongocxx::database> database) : database(database) {};


void MapStorage::InsertStoreMap(std::shared_ptr<RawStoreMap> map) {
    database->collection("store_map").insert_one(make_document(
            kvp("ID", map->StoreID),
            kvp("inherit", map->Inherit),
            kvp("geometry", map->Geometry)));
}

std::shared_ptr<RawStoreMap> MapStorage::GetStoreMap(const int &ID) {
    auto storeCollection = database->collection("store_graph");

    auto selectStoreResult = storeCollection.find_one(make_document(kvp("ID", ID)));

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    if (!selectStoreResult) {
        throw StoreGraphNotFound(ID);
    }

    return std::make_shared<RawStoreMap>(selectStoreOutput);
}

std::shared_ptr<StoreModel> MapStorage::GetStoreAdjecency(const int &ID) {
    auto adjCollection = database->collection("store_adj");

    auto selectStoreResult = adjCollection.find_one(make_document(kvp("ID", ID)));
    if (!selectStoreResult) {
        throw StoreGraphNotFound(ID);
    }

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    return std::make_shared<StoreModel>(selectStoreOutput);
}

void MapStorage::CreateStoreAdjecencyCoords(const int &storeID, const std::vector<Point> &points) {
    auto adjCoordCollection = database->collection("store_adj_coords");

    document doc_builder{};
    doc_builder << "ID" << storeID;
    doc_builder << "size" << int(points.size());
    auto array_builder = doc_builder << "adjacency_table" << open_array;
    for (int i = 0; i < points.size(); ++i) {
        array_builder << make_document(
                kvp("pointID", i),
                kvp("X", points[i].x),
                kvp("Y", points[i].y));
    }
    array_builder << close_array;
    auto doc = doc_builder << finalize;
    adjCoordCollection.insert_one(doc.view());
}

std::shared_ptr<AdjecencyPoints> MapStorage::GetStoreAdjecencyCoords(const int &storeID) {
    auto adjCoordCollection = database->collection("store_adj_coords");

    auto selectStoreResult = adjCoordCollection.find_one(make_document(kvp("ID", storeID)));
    if (!selectStoreResult) {
        throw StoreGraphNotFound(storeID);
    }

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    return std::make_shared<AdjecencyPoints>(AdjecencyPoints(selectStoreOutput));
}

std::shared_ptr<ShopWithCountersAndPointsModel> MapStorage::GetCountersWithPointsByShopID(const int &shopID)
{
    auto storeCollection = database->collection("counters_with_points");

    auto selectCountersWithPointsResult = storeCollection.find_one(make_document(kvp("ID", shopID)));

    if (!selectCountersWithPointsResult)
    {
        throw StoreGraphNotFound(shopID);
    }

    auto selectCountersWithPointsOutput = bsoncxx::to_json(*selectCountersWithPointsResult);
    return std::make_shared<ShopWithCountersAndPointsModel>(selectCountersWithPointsOutput);
}

void MapStorage::AddCountersWithPoints(std::shared_ptr<ShopWithCountersAndPointsModel> data)
{
    auto storeCollection = database->collection("counters_with_points");
    auto builder = bsoncxx::builder::stream::document{};
    builder << "ShopID" << data->ShopID;
    auto array_builder = builder << "objects" << bsoncxx::builder::stream::open_array;
    for (auto & counterWithPoint : data->counterWithPoints) {
        array_builder << make_document(
            kvp("CounterID", counterWithPoint.CounterID),
            kvp("PointID", counterWithPoint.PointID));
    }
    array_builder << bsoncxx::builder::stream::close_array;
    auto doc = builder << bsoncxx::builder::stream::finalize;
    storeCollection.insert_one(doc.view());
}
