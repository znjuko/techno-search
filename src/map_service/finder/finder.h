#ifndef TECHNO_SEARCH_PATH_H
#define TECHNO_SEARCH_PATH_H

#include <algorithm>
#include <vector>

class PathFinder
{
  public:
    PathFinder() = default;

    std::vector<int> FindPath(const size_t &from, const size_t &to, const size_t &size,
                                 const std::vector<std::vector<double>> &AdjacencyTable);

    ~PathFinder() = default;
};

#endif // TECHNO_SEARCH_PATH_H
