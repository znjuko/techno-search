//
// Created by Никита Черных on 20.05.2021.
//

#include "adapter.h"

std::vector<std::vector<int>> Adapter::AdaptAdjacency(std::shared_ptr<StoreModel> model)
{
    auto currSize = model->Size + 1;
    auto resp = std::vector<std::vector<int>>(currSize);
    for (auto &el : resp) el = std::vector<int>(currSize);

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
