//
// Created by paccbet on 13.04.2021.
//
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    auto v = vector<int>(7,1);

    std::ostringstream oss;

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(oss, ","));
    std::cout << oss.str();
    return 0;
}