#ifndef TECHNO_SEARCH_PATH_H
#define TECHNO_SEARCH_PATH_H

#include <vector>

#include "models.h"

class PathFinder {
  PathFinder() = default;

  std::vector<size_t> FindPath(const size_t &from, const size_t &to, const size_t& size, const std::vector<std::vector<int>>& AdjacencyTable;

  ~PathFinder() = default;
};

#endif // TECHNO_SEARCH_PATH_H
