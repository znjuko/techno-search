//
// Created by Никита Черных on 19.05.2021.
//

#include "models.h"

StoreModel::StoreModel(const std::string &data)
{
    auto jsonData = json::parse(data);

    ID = jsonData["id"];
    Size = jsonData["size"];

    auto adj = jsonData["adjacency_table"];
    for (const auto &item : adj)
    {
        Adjacency.push_back(boost::lexical_cast<double>(item));
    }

    auto cntrs = jsonData["counters"];
    for (const auto &item : cntrs)
    {
        Counters.push_back(boost::lexical_cast<int>(item));
    }
}