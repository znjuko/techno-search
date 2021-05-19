cmake_minimum_required(VERSION 3.19)
project(TestDijkstra)

set(CMAKE_C_STANDARD 17)

include_directories(src)

add_executable(TestDijkstra src/map_service/map_graph/graph/graph.h tests/unit/map_service/map_graph/graph/graph.cpp src/map_service/storage/storage.cpp src/map_service/storage/storage.h)

add_executable(tests src/map_service/map_graph/graph/graph.h tests/unit/map_service/map_graph/graph/graph.cpp)
find_package(GTest REQUIRED)
target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
target_include_directories(tests PUBLIC include)
enable_testing()

add_test(gtests ./tests)