//
// Created by Никита Черных on 20.05.2021.
//

#ifndef TECHNO_ALGO_ADAPTER_H
#define TECHNO_ALGO_ADAPTER_H

#include "models.h"

#include <vector>

class Adapter
{
  public:
    Adapter() = default;

    std::vector<std::vector<int>> AdaptAdjacency(std::shared_ptr<StoreModel> model);

    ~Adapter() = default;
};

#endif // TECHNO_ALGO_ADAPTER_H
