set(LIBRARY_NAME graph_storage)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} INTERFACE)

target_sources(${LIBRARY_NAME} INTERFACE ${SRC})

target_include_directories(${LIBRARY_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} INTERFACE nlohmann_json::nlohmann_json)