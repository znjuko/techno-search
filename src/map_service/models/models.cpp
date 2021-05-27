//
// Created by foxers on 27.05.2021.
//

#include "models.h"

MapModel::MapModel(const std::string &data)
{
    // something
}

MapCounter::MapCounter(const std::string &data)
{
    auto jsonData = json::parse(data);

    ID = jsonData["id"];

    auto obj = jsonData["objects"];
    for (const auto &item : obj)
    {
        counterID.push_back(obj["counterID"]);
        pointID.push_back(obj["pointID"]);
    }
}