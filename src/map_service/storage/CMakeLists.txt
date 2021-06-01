
set(LIBRARY_NAME map_storage)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC} map_storage.cpp)

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

target_link_libraries(
        ${LIBRARY_NAME} PUBLIC
        mongo::bsoncxx_shared
        mongo::mongocxx_shared
        map_request_models
        map_models
        path_exceptions
)