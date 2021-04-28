project(techno_search)

CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

option(test "Build all tests." ON)

add_subdirectory(src)
add_subdirectory(include)

add_executable(techno_search main.cpp)
target_link_libraries(${PROJECT_NAME} marshaller unmarshaller models)

#if(test)
    enable_testing()

    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)

    add_subdirectory(tests)
#endif(test)