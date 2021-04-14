cmake_minimum_required(VERSION 3.19)
project(shopService)

set(CMAKE_CXX_STANDARD 14)

add_executable(shopService main.cpp)
cmake_minimum_required(VERSION 3.6)
project("TECHNO_SEARCH")

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

#add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} marshaller unmarshaller models)

set(PostgreSQL_FOUND true)
set(PostgresSQL_INCLUDE_DIR ${PostgresSQL_INCLUDE_DIRS})
set(PostgresSQL_TYPE_INCLUDE_DIR ${PostgresSQL_INCLUDE_DIRS})
add_subdirectory(libpqxx)
target_link_libraries(${PROJECT_NAME} libpqxx)