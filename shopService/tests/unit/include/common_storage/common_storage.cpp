//
// Created by fillinmar on 31.03.2021.
//
#include <gtest/gtest.h>
#include <iostream>

#include "commonStorage.h"

TEST(COMMON_STORAGE, QUERY)
{
    int a = 5;
    string stringFive = "5";
    IQuery* five= new IntQuery(a);
    EXPECT_EQ(five, stringFive);

}

