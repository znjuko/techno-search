find_package(nlohmann_json 3.2.0 REQUIRED)

set(LIBRARY_NAME stores_storage)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE stores_models postgres_storage)