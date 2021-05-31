#include "finder.h"
#include <cmath>
#include <limits>

std::vector<size_t> PathFinder::FindPath(const size_t &from, const size_t &to, const size_t &size,
                                         const std::vector<std::vector<double>> &AdjacencyTable)
{
    auto distance = std::vector<double>(size);
    auto vizited = std::vector<size_t>(size);
    const double limit = std::numeric_limits<double>::max();
    const size_t limit_index = std::numeric_limits<size_t>::max();
    size_t A = from;
    size_t B = to;
    double temp, min;
    size_t minindex, begin_index = A;
    for (size_t i = 0; i < size; i++)
    {
        distance[i] = limit;
        vizited[i] = 1;
    }
    distance[begin_index] = 0;

    do
    {
        minindex = limit_index;
        min = limit;

        for (size_t i = 0; i < size; i++)
        {
            if (!((vizited[i] == 1) && (distance[i] < min)))
                continue;

            min = distance[i];
            minindex = i;
        }

        if (minindex == limit_index)
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
    } while (minindex < limit_index);

    auto path = std::vector<size_t>(size);
    auto end = B;
    path[0] = B;
    int k = 1;
    double weight = distance[B];

    while (end != begin_index)
    {
        for (int i = 0; i < size; i++)
            if (AdjacencyTable[i][end] != 0)
            {
                temp = weight - AdjacencyTable[i][end];
                temp = round(temp*10)/10;

                distance[i] = round(distance[i]*10)/10;

                if (temp == distance[i])
                {
                    weight = temp;
                    end = i;
                    path[k] = i;
                    k++;
                }
            }
    }
    return path;
};