#include "finder.h"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

const std::vector<std::vector<double>> graphmatrix = {
    {0, 1, 0, 0, 0}, {1, 0, 3, 0, 0}, {0, 3, 0, 1, 6}, {0, 0, 1, 0, 0}, {0, 0, 6, 0, 0}};

const std::vector<std::vector<double>> graphmatrix2 = {
    {0, 5, 3, 0, 0, 0, 0}, {5, 0, 0, 2, 0, 0, 0}, {3, 0, 0, 0, 0, 0, 0}, {0, 2, 0, 0, 6, 7, 0},
    {0, 0, 0, 6, 0, 0, 5}, {0, 0, 0, 7, 0, 0, 3}, {0, 0, 0, 0, 5, 3, 0},
};

const size_t size = 5;
const size_t size2 = 7;

TEST(find_path, standalone1)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(1, 4, size, graphmatrix);
    EXPECT_EQ(A[0], 4);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[2], 2);
    EXPECT_EQ(A[3], 1);
}

TEST(find_path, standalone2)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(2, 5, size, graphmatrix);
    EXPECT_EQ(A[2], 2);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[0], 5);
}

TEST(find_path, reverse)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(4, 2, size, graphmatrix);
    EXPECT_EQ(A[2], 4);
    EXPECT_EQ(A[1], 3);
    EXPECT_EQ(A[0], 2);
}

TEST(find_path, different_ways)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(2, 7, size2, graphmatrix2);
    EXPECT_EQ(A[3], 2);
    EXPECT_EQ(A[2], 4);
    EXPECT_EQ(A[1], 6);
    EXPECT_EQ(A[0], 7);
}

TEST(find_path, to_the_start_and_back)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(2, 3, size2, graphmatrix2);
    EXPECT_EQ(A[2], 2);
    EXPECT_EQ(A[1], 1);
    EXPECT_EQ(A[0], 3);
}

TEST(find_path, to_the_start_and_back_different_ways)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(6, 5, size2, graphmatrix2);
    EXPECT_EQ(A[2], 6);
    EXPECT_EQ(A[1], 7);
    EXPECT_EQ(A[0], 5);
}

TEST(find_path, to_yourself)
{
    PathFinder F;
    std::vector<size_t> A = F.FindPath(6, 6, size2, graphmatrix2);
    EXPECT_EQ(A[0], 6);
}