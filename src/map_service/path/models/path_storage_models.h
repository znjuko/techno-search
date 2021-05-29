//
// Created by Никита Черных on 19.05.2021.
//

#ifndef RENAMEIT_MODELS_H
#define RENAMEIT_MODELS_H

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

class StoreModel
{
  public:
    StoreModel(const std::string &data);

    int ID; // store ID
    int Size; // size X adjacency
    std::vector<double> Adjacency;
};

#endif // RENAMEIT_MODELS_H
