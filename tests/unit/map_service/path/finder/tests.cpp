#include <gtest/gtest.h>
#include <iostream>

#include "finder.h"
#include <vector>

const std::vector<std::vector<double>> graphmatrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 1, 6},
        {0, 0, 1, 0, 0},
        {0, 0, 6, 0, 0}
};

const std::vector<std::vector<double>> graphmatrix2 = {
        {0, 5, 3, 0, 0, 0, 0},
        {5, 0, 0, 2, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 6, 7, 0},
        {0, 0, 0, 6, 0, 0, 5},
        {0, 0, 0, 7, 0, 0, 3},
        {0, 0, 0, 0, 5, 3, 0},
};

const std::vector<size_t> counters = {10, 11, 2, 95, 5};
const std::vector<size_t> counters2 = {101, 1, 13, 0, 5, 8, 21};

const size_t size = 5;
const size_t size2 = 7;

TEST(find_path, standalone1)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(10, 95, size, graphmatrix, counters);
    EXPECT_EQ(A[0], 4);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[2], 2);
    EXPECT_EQ(A[3], 1);
}

TEST(find_path, standalone2)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(11, 5, size, graphmatrix, counters);
    EXPECT_EQ(A[2], 2);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[0], 5);
}

TEST(find_path, reverse)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(95, 11, size, graphmatrix, counters);
    EXPECT_EQ(A[2], 4);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[0], 2);
}

TEST(find_path, different_ways)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(1, 21, size2, graphmatrix2, counters2);
    EXPECT_EQ(A[3], 2);
    EXPECT_EQ(A[2], 4);
    EXPECT_EQ(A[1], 6);
    EXPECT_EQ(A[0], 7);
}

TEST(find_path, to_the_start_and_back)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(1, 13, size2, graphmatrix2, counters2);
    EXPECT_EQ(A[2], 2);
    EXPECT_EQ(A[1], 1);
    EXPECT_EQ(A[0], 3);
}

TEST(find_path, to_the_start_and_back_different_ways)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(8, 5, size2, graphmatrix2, counters2);
    EXPECT_EQ(A[2], 6);
    EXPECT_EQ(A[1], 7);
    EXPECT_EQ(A[0], 5);
}

TEST(find_path, to_yourself)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(8, 8, size2, graphmatrix2, counters2);
    EXPECT_EQ(A[0], 6);
}