find_package(nlohmann_json 3.2.0 REQUIRED)

set(LIBRARY_NAME unmarshaller)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} INTERFACE)

target_sources(${LIBRARY_NAME} INTERFACE ${SRC})

target_include_directories(${LIBRARY_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} INTERFACE nlohmann_json::nlohmann_json)