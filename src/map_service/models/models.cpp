//
// Created by foxers on 27.05.2021.
//

#include "models.h"

MapCounter::MapCounter(const std::string &data)
{
    auto jsonData = json::parse(data);

    ID = jsonData["id"];

    auto obj = jsonData["objects"];
    for (const auto &item : obj)
    {
        conform->counterID.push_back(obj["counterID"]);
        conform->pointID.push_back(obj["pointID"]);
    }
}