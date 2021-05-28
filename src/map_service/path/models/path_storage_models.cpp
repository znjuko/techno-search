//
// Created by Никита Черных on 19.05.2021.
//

#include "path_storage_models.h"

StoreModel::StoreModel(const std::string &data) {
    auto jsonData = json::parse(data);

    ID = jsonData["ID"];
    Size = jsonData["size"];

    auto adj = jsonData["adjacency_table"];
    for (const auto &item : adj) {
        Adjacency.push_back(boost::lexical_cast<double>(item));
    }
}