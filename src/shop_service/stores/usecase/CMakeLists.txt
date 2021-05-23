find_package(nlohmann_json 3.2.0 REQUIRED)

set(SRC store_usecase.h store_usecase.cpp)

set(LIBRARY_NAME stores_usecase)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE stores_models
        stores_storage
        marshaller unmarshaller
        marshaller
        common_exceptions
        postgres_query postgres_reader postgres_storage
        )