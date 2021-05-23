cmake_minimum_required(VERSION 3.19)

project(techno_algo CXX)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(vendor)

add_subdirectory(cmd)
