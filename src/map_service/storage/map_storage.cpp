#include "map_storage.h"

MapStorage::MapStorage(std::shared_ptr<mongocxx::database> database) : database(database){};

void MapStorage::CreateStoreMap(std::shared_ptr<RawStoreMap> map)
{
    database->collection("store_map")
        .insert_one(
            make_document(kvp("storeID", map->StoreID), kvp("inherit", map->Inherit), kvp("geometry", map->Geometry)));
}

std::shared_ptr<RawStoreMap> MapStorage::GetStoreMap(const int &ID)
{
    auto storeCollection = database->collection("store_map");

    auto selectStoreResult = storeCollection.find_one(make_document(kvp("storeID", ID)));

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    if (!selectStoreResult)
    {
        throw StoreGraphNotFound(ID);
    }

    return std::make_shared<RawStoreMap>(selectStoreOutput);
}

std::shared_ptr<StoreModel> MapStorage::GetStoreAdjacency(const int &ID)
{
    auto adjCollection = database->collection("store_adj");

    auto selectStoreResult = adjCollection.find_one(make_document(kvp("storeID", ID)));
    if (!selectStoreResult)
    {
        throw StoreGraphNotFound(ID);
    }

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    return std::make_shared<StoreModel>(selectStoreOutput);
}

void MapStorage::AddStoreAdjacency(std::shared_ptr<StoreModel> data)
{
    auto storeCollection = database->collection("store_adj");

    auto builder = bsoncxx::builder::stream::document{};
    builder << "storeID" << data->ID << "size" << data->Size;
    auto array_builder = builder << "adjacency_table" << bsoncxx::builder::stream::open_array;
    for (int i = 0; i < data->Adjacency.size(); ++i)
    {
        array_builder << data->Adjacency[i];
    }
    array_builder << bsoncxx::builder::stream::close_array;
    auto doc = builder << bsoncxx::builder::stream::finalize;
    storeCollection.insert_one(doc.view());
}

void MapStorage::CreateStoreAdjacencyCoords(const int &storeID, const std::vector<Point> &points)
{
    auto adjCoordCollection = database->collection("store_adj_coords");

    document doc_builder{};
    doc_builder << "storeID" << storeID;
    doc_builder << "size" << int(points.size());
    auto array_builder = doc_builder << "adjacency_table" << open_array;
    for (int i = 0; i < points.size(); ++i)
    {
        array_builder << make_document(kvp("pointID", i), kvp("x", points[i].x), kvp("y", points[i].y));
    }
    array_builder << close_array;
    auto doc = doc_builder << finalize;
    adjCoordCollection.insert_one(doc.view());
}

std::shared_ptr<AdjacencyPoints> MapStorage::GetStoreAdjacencyCoords(const int &storeID)
{
    auto adjCoordCollection = database->collection("store_adj_coords");

    auto selectStoreResult = adjCoordCollection.find_one(make_document(kvp("storeID", storeID)));
    if (!selectStoreResult)
    {
        throw StoreGraphNotFound(storeID);
    }

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    return std::make_shared<AdjacencyPoints>(AdjacencyPoints(selectStoreOutput));
}

std::shared_ptr<StoreCountersAdjacency> MapStorage::GetStoreCountersAdjacency(const int &shopID)
{
    auto storeCollection = database->collection("counters_with_points");

    auto selectCountersWithPointsResult = storeCollection.find_one(make_document(kvp("storeID", shopID)));

    if (!selectCountersWithPointsResult)
    {
        throw StoreGraphNotFound(shopID);
    }

    auto selectCountersWithPointsOutput = bsoncxx::to_json(*selectCountersWithPointsResult);
    return std::make_shared<StoreCountersAdjacency>(selectCountersWithPointsOutput);
}

void MapStorage::AddStoreCountersAdjacency(std::shared_ptr<StoreCountersAdjacency> data)
{
    auto storeCollection = database->collection("counters_with_points");
    auto builder = bsoncxx::builder::stream::document{};
    builder << "storeID" << data->StoreID;
    auto array_builder = builder << "objects" << bsoncxx::builder::stream::open_array;
    for (auto &counterWithPoint : data->counterWithPoints)
    {
        array_builder << make_document(kvp("counterID", counterWithPoint.CounterID),
                                       kvp("pointID", counterWithPoint.PointID));
    }
    array_builder << bsoncxx::builder::stream::close_array;
    auto doc = builder << bsoncxx::builder::stream::finalize;
    storeCollection.insert_one(doc.view());
}