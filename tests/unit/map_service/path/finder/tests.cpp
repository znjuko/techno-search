#include <gtest/gtest.h>
#include <iostream>

#include "finder.h"
#include <vector>

const std::vector<std::vector<int>> graphmatrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 1, 6},
        {0, 0, 1, 0, 0},
        {0, 0, 6, 0, 0},
};

const std::vector<int> counters = {10, 11, 2, 95, 5};

const size_t size = 4;

TEST(find_path, standalone1)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(10, 95, size, graphmatrix, counters);
    EXPECT_EQ(A[0], 1);
    EXPECT_EQ(A[1], 2);
    EXPECT_EQ(A[2], 3);
    EXPECT_EQ(A[3], 4);
}

TEST(find_path, standalone2)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(11, 95, size, graphmatrix, counters);
    EXPECT_EQ(A[1], 2);
}

TEST(find_path, standalone3)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(11, 5, size, graphmatrix, counters);
    EXPECT_EQ(A[2], 2);
}