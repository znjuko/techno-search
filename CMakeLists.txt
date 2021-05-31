project(techno_search CXX)
set(CMAKE_CXX_STANDARD 20)

CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

option(test "Build all tests." ON)
set(CMAKE_CXX_FLAGS         "-Wno-unused -Wno-deprecated -Wno-comment -Wno-reorder -Wno-unused-parameter -Wno-unused-result -fpermissive -lpthread -pthread")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
find_package(Threads REQUIRED)
list(APPEND CMAKE_PREFIX_PATH "/home/linuxbrew/.linuxbrew/lib/cmake")

add_subdirectory(vendor)
add_subdirectory(include)
add_subdirectory(src)
#add_subdirectory(cmd)


if(test)
    enable_testing()

    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)

    add_subdirectory(tests)
endif(test)


