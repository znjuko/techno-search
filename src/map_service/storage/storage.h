//
// Created by foxers on 27.05.2021.
//

#ifndef TECHNO_SEARCH_STORAGE_H
#define TECHNO_SEARCH_STORAGE_H

#include "models.h"

class MapStorage
{
public:
    Storage() = delete;

    Storage(const Storage &str) = delete;

    Storage(std::shared_ptr<mongocxx::database> database);

    std::shared_ptr<StoreModel> GetMapData(const int &ID);

private:
    std::shared_ptr<mongocxx::database> database;
};

#endif //TECHNO_SEARCH_STORAGE_H
