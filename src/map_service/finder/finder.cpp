#include "finder.h"

std::vector<size_t> PathFinder::FindPath(const size_t &from, const size_t &to, const size_t &size,
                                         const std::vector<std::vector<int>> &AdjacencyTable) {
    auto distance = std::vector<size_t>(size);
    auto vizited = std::vector<size_t>(size);
    const size_t limit = 10000;
    size_t temp, minindex, min, begin_index = from;

    for (int i = 0; i < size; i++) {
        distance[i] = limit;
        vizited[i] = 1;
    }
    distance[begin_index] = 0;
    do {
        minindex = limit;
        min = limit;
        for (size_t i = 0; i < size; i++) {
            if ((vizited[i] == 1) && (distance[i] < min)) {
                min = distance[i];
                minindex = i;
            }
        }
        if (minindex != limit) {
            for (size_t i = 0; i < size; i++) {
                if (AdjacencyTable[minindex][i] > 0) {
                    temp = min + AdjacencyTable[minindex][i];
                    if (temp < distance[i]) {
                        distance[i] = temp;
                    }
                }
            }
            vizited[minindex] = 0;
        }
    } while (minindex < limit);

    auto path = std::vector<size_t>(size);
    auto end = to;
    path[0] = to + 1;
    int k = 1;
    size_t weight = distance[to];

    while (end != begin_index) {
        for (int i = 0; i < size; i++)
            if (AdjacencyTable[i][to] != 0) {
                temp = weight - AdjacencyTable[i][to];
                if (temp == distance[i]) {
                    weight = temp;
                    end = i;
                    path[k] = i + 1;
                    k++;
                }
            }
    }

    return path;
};
