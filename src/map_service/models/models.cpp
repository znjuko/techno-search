//
// Created by foxers on 27.05.2021.
//

#include "models.h"

MapModel::MapModel(const std::string &data)
{
    auto jsonData = json::parse(data);

    shopID = jsonData["shopID"];

    auto geo = jsonData["geometry"];
    for (const auto &item : geo)
    {
        geometry->type.push_back(geo["type"]);
        geometry->coordinates.push_back(geo["coordinates"]);
    }
    auto inh = jsonData["inherit"];
    for (const auto &item : inh)
    {
        inherit->type.push_back(inh["type"]); //Я вообще не понимаю, что не так здесь
        inherit->props.push_back(inh["props"]); //Не уверен как это делать правильно
        inherit->coordinates.push_back(inh["coordinates"]);
    }
}

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