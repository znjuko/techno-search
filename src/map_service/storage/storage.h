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
#include "models.h"

class MapStorage
{
public:
    MapStorage() = delete;

    MapStorage(const MapStorage &str) = delete;

    MapStorage(std::shared_ptr<mongocxx::database> database);

    std::shared_ptr<MapModel> GetMapData(const int &ShopID);

    std::shared_ptr<InsertMapResponse> InsertMap(const int &ID);

private:
    std::shared_ptr<mongocxx::database> database;
};



#endif //TECHNO_SEARCH_STORAGE_H
