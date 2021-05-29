//
// Created by Никита Черных on 19.05.2021.
//

#ifndef TECHNO_SEARCH_PATH_STORAGE_H
#define TECHNO_SEARCH_PATH_STORAGE_H

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

#include "exceptions.h"
#include "models.h"

class Storage
{
  public:
    Storage() = delete;

    Storage(const Storage &str) = delete;

    Storage(std::shared_ptr<mongocxx::database> database);

    std::shared_ptr<StoreModel> GetStoreData(const int &ID);

  private:
    std::shared_ptr<mongocxx::database> database;
};

#endif // TECHNO_SEARCH_STORAGE_H
