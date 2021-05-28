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

struct figure{
    std::string type;
    std::vector<std::vector<int>> coordinates;
};

struct properties{
    std::string id;
    int value;
};

struct heir{
    std::string type;
    properties props;
    std::vector<std::vector<int>> coordinates;
};

struct point{
    std::vector<int> counterID;
    std::vector<int> pointID;
};

class MapModel
{
public:
    MapModel(const std::string &data);
    int shopID;
    figure *geometry;
    heir *inherit;
};

class MapCounter
{
public:
    MapCounter(const std::string &data);
    int ID;
    point* conform;
};

#endif //TECHNO_SEARCH_MODELS_H
