#ifndef TECHNO_SEARCH_PATH_H
#define TECHNO_SEARCH_PATH_H

#include "models.h"

#include <vector>
#include <algorithm>

class PathFinder
{
public:
    PathFinder() = default;

    std::vector<size_t> FindPath(const size_t &from, const size_t &to, const size_t &size,
                                 const std::vector<std::vector<double>> &AdjacencyTable,
                                 const std::vector<size_t> &CounterArray);

    ~PathFinder() = default;
};

#endif // TECHNO_SEARCH_PATH_H
