//
// Created by Никита Черных on 20.05.2021.
//

#ifndef TECHNO_ALGO_ADAPTER_H
#define TECHNO_ALGO_ADAPTER_H

#include "map_request_models.h"

#include <vector>

class Adapter
{
  public:
    Adapter() = default;

    std::vector<std::vector<double>> AdaptAdjacency(std::shared_ptr<StoreModel> model);
    std::pair<std::vector<double>, int> AdaptAdjacencyVERSION2(std::vector<std::vector<double>> v);

    ~Adapter() = default;
};

#endif // TECHNO_ALGO_ADAPTER_H
