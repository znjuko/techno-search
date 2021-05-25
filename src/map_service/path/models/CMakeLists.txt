find_package(nlohmann_json 3.9.1 REQUIRED)
find_package(Boost 1.71.0 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

set(LIBRARY_NAME path_storage_models)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE nlohmann_json::nlohmann_json ${Boost_LIBRARIES})