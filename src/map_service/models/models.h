//
// Created by foxers on 27.05.2021.
//

#ifndef TECHNO_SEARCH_MODELS_H
#define TECHNO_SEARCH_MODELS_H

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

class MapModel
{
public:
    MapModel(const std::string &data);

    string map;
};

class MapCounter
{
public:
    MapCounter(const std::string &data);

    int ID;
    std::vector<int> counterID;
    std::vector<int> pointID;
};

#endif //TECHNO_SEARCH_MODELS_H
