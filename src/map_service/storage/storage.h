//
// Created by foxers on 27.05.2021.
//

#ifndef TECHNO_SEARCH_STORAGE_H
#define TECHNO_SEARCH_STORAGE_H

#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/json.hpp>
#include <cstdint>
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <vector>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;

#include "exceptions.h"
#include "map_models.h"

class MapStorage
{
  public:
    MapStorage() = delete;

    MapStorage(const MapStorage &str) = delete;

    MapStorage(std::shared_ptr<mongocxx::database> database);

    void InsertStoreMap(std::shared_ptr<RawStoreMap> map);

    std::shared_ptr<RawStoreMap> GetStoreMap(const int &ID);

    void AddStoreAdjacency(std::shared_ptr<StoreModel> data);

    void CreateStoreAdjacencyCoords(const int &storeID, const std::vector<Point> &points);

    std::shared_ptr<AdjacencyPoints> GetStoreAdjacencyCoords(const int &storeID);

    std::shared_ptr<StoreCountersAdjacency> GetStoreCountersAdjacency(const int &shopID);

    void AddStoreCountersAdjacency(std::shared_ptr<StoreCountersAdjacency> data);

    std::shared_ptr<StoreModel> GetStoreAdjacency(const int &ID);

    // TODO: add create adjecency && merge this shit
    // TODO: add counter to adj !!1

  private:
    std::shared_ptr<mongocxx::database> database;
};

#endif // TECHNO_SEARCH_STORAGE_H
