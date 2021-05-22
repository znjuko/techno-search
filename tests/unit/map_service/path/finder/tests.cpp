#include <gtest/gtest.h>
#include <iostream>

#include "finder.h"

const double graphmatrix = {
    {0, 1, 0, 0, 0},
    {1, 0, 3, 0, 0},
    {0, 3, 0, 1.5, 6},
    {0, 0, 1.5, 0, 0},
    {0, 0, 6, 0, 0},
};

const size_t counters = {10, 11, 2, 95, 5};

const size_t size = 5

TEST(find_path, standalone1)
{
F = PathFinder()
int *A = F.FindPath(10, 95, graphmatrix, counters, size);
EXPECT_EQ(A[0], 0);
EXPECT_EQ(A[1], 1);
EXPECT_EQ(A[2], 2);
EXPECT_EQ(A[3], 3);
}

TEST(find_path, standalone2)
{
    int *A = FindPath(11, 2, graphmatrix, counters, size);
    EXPECT_EQ(A[0], 1);
}