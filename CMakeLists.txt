project(techno_search CXX)
set(CMAKE_CXX_STANDARD 20)

CMAKE_MINIMUM_REQUIRED(VERSION 3.19.2)

option(test "Build all tests." ON)

add_subdirectory(src)
add_subdirectory(include)
#add_subdirectory(vendor)

add_executable(techno_search main.cpp)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} models)

if(test)
    enable_testing()

    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)

    add_subdirectory(tests)
endif(test)