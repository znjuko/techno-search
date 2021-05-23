cmake_minimum_required(VERSION 3.16.2)

project(techno_search CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS         "-Wno-unused -Wno-deprecated -Wno-comment -Wno-reorder -Wno-unused-parameter -fpermissive -lpthread -pthread")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
find_package(Threads REQUIRED)
list(APPEND CMAKE_PREFIX_PATH "/home/linuxbrew/.linuxbrew/lib/cmake")

message(${CMAKE_PREFIX_PATH})

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(vendor)

add_subdirectory(cmd)


