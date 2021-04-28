find_package(nlohmann_json 3.2.0 REQUIRED)

set(SRC product_storage.cpp product_storage.h)

set(LIBRARY_NAME product_storage)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE marshaller unmarshaller nlohmann_json::nlohmann_json)