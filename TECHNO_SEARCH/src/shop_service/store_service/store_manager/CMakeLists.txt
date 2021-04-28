find_package(nlohmann_json 3.2.0 REQUIRED)

set(SRC store_manager.h store_manager.cpp)

set(LIBRARY_NAME store_manager)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE marshaller unmarshaller nlohmann_json::nlohmann_json)