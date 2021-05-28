set(LIBRARY_NAME map_storage)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

target_link_libraries(
        ${LIBRARY_NAME} PRIVATE
        mongo::bsoncxx_shared mongo::mongocxx_shared
        map_storage_models
        map_models
        path_storage_models
        path_exceptions
)