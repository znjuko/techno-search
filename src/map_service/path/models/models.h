//
// Created by Никита Черных on 19.05.2021.
//

#ifndef RENAMEIT_MODELS_H
#define RENAMEIT_MODELS_H

#include <vector>
#include <string>

#include <nlohmann/json.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using json = nlohmann::json;

class StoreModel {
public:
    StoreModel(const std::string &data);

    int ID;
    int Size;
    std::vector<int> Adjacency;
    std::vector<int> Counters;
};


#endif //RENAMEIT_MODELS_H
