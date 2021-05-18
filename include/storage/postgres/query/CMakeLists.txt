find_package(nlohmann_json 3.2.0 REQUIRED)

set(LIBRARY_NAME postgres_query)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

find_package(libpqxx CONFIG REQUIRED)

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE store_models libpqxx::pqxx)
