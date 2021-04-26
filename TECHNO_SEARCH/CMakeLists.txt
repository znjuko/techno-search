
cmake_minimum_required(VERSION 3.19)
project("TECHNO_SEARCH")

find_package(libpqxx CONFIG REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC libpqxx::pqxx marshaller unmarshaller models)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)
