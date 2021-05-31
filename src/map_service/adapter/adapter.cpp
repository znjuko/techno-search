//
// Created by Никита Черных on 20.05.2021.
//

#include "adapter.h"

std::vector<std::vector<double>> Adapter::AdaptAdjacency(std::shared_ptr<StoreModel> model)
{
    auto currSize = model->Size + 1;
    auto resp = std::vector<std::vector<double>>(currSize);
    for (auto &el : resp) el = std::vector<double>(currSize);

    size_t got = 0;
    for (size_t i = 0; i < model->Size; ++i)
    {
        for (size_t j = 0; j < model->Size - i; ++j)
        {
            auto pos = i + j + 1;
            resp[i][pos] = model->Adjacency[got + j];
            resp[pos][i] = model->Adjacency[got + j];
        }
        resp[i][i] = 0;

        got += (model->Size - i);
    }

    return resp;
}

std::pair<std::vector<double>, int> Adapter::AdaptAdjacencyVERSION2(std::vector<std::vector<double>> v) {

    std::vector<double> adj = std::vector<double>();

    for(size_t i = 0; i < v.size(); ++i) {
        for(size_t j = i + 1; j < v.size(); ++j) {
            adj.push_back(v[i][j]);
        }
    }
    std::pair<std::vector<double>, int> pair;
    pair.first = adj;
    pair.second = v.size() - 1;

    return pair;
}
