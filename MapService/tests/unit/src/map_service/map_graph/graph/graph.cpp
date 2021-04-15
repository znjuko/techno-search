#include <gtest/gtest.h>
#include <iostream>

#include "graph.h"

const double graphmatrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 1.5, 6},
        {0, 0, 1.5, 0, 0},
        {0, 0, 6, 0, 0},
};

TEST(find_path, standalone1)
{
    int *A = FindPath(graphmatrix, 0, 3);
}
