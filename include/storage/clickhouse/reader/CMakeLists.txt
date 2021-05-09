find_package(nlohmann_json 3.2.0 REQUIRED)
find_library(clickhouse clickhouse-cpp-lib REQUIRED)
#find_package(CLICKHOUSE-CLIENT REQUIRED)
#find_package(pistache)

MESSAGE(${clickhouse})

set(LIBRARY_NAME click_reader)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE models ${clickhouse} clickhouse-cpp-lib)