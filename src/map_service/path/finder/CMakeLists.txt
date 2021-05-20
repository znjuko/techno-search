find_package(nlohmann_json 3.2.0 REQUIRED)

set(LIBRARY_NAME path_finder)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC .)

target_link_libraries(${LIBRARY_NAME} PRIVATE graph_storage_models)