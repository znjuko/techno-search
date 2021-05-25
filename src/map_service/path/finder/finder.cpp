#include "finder.h"
#include <queue>
#include <limits>
#include <iostream>

std::vector<size_t> PathFinder::FindPath(const size_t &from, const size_t &to, const size_t &size,
                                         const std::vector<std::vector<int>> &AdjacencyTable,
                                         const std::vector<int> &CounterArray)
{
    auto distance = std::vector<size_t>(size);
    auto vizited = std::vector<size_t>(size);
    const size_t limit = std::numeric_limits<size_t>::max();
    size_t A = 0;
    size_t B = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(CounterArray[i] == from){
            A = i;
        }
        if(CounterArray[i] == to){
            B = i;
        }
    }
    size_t temp, minindex, min, begin_index = A;
    for (size_t i = 0; i < size; i++)
    {
        distance[i] = limit;
        vizited[i] = 1;
    }
    distance[begin_index] = 0;

    do
    {
        minindex = limit;
        min = limit;

        for (size_t i = 0; i < size; i++)
        {
            if (!((vizited[i] == 1) && (distance[i] < min)))
                continue;

            min = distance[i];
            minindex = i;
        }

        if (minindex == limit)
            continue;

        for (size_t i = 0; i < size; i++)
        {
            if (AdjacencyTable[minindex][i] <= 0)
                continue;

            temp = min + AdjacencyTable[minindex][i];
            if (temp < distance[i])
            {
                distance[i] = temp;
            }
        }
        vizited[minindex] = 0;
    } while (minindex < limit);

    auto path = std::vector<size_t>(size);
    auto end = B;
    path[0] = B + 1;
    int k = 1;
    size_t weight = distance[B];

    while (end != begin_index)
    {
        for (int i = 0; i < size; i++)
            if (AdjacencyTable[i][end] != 0) {
                temp = weight - AdjacencyTable[i][end];
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