cmake_minimum_required(VERSION 3.19)
project(TestDijkstra)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_STANDARD 11)

add_executable(TestDijkstra src/map_service/map_graph/graph/graph.h tests/unit/map_service/map_graph/graph/graph.cpp)

add_executable(tests src/map_service/map_graph/graph/graph.h tests/unit/map_service/map_graph/graph/graph.cpp)
find_package(GTest REQUIRED)
target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
target_include_directories(tests PUBLIC include)
enable_testing()

add_test(gtests ./tests)