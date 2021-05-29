find_package(nlohmann_json 3.2.0 REQUIRED)

set(SRC product_delivery.h product_delivery.cpp)

set(LIBRARY_NAME products_delivery)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
        ${LIBRARY_NAME} PRIVATE
        marshaller unmarshaller
        nlohmann_json::nlohmann_json
        pistache router_setupper request_reader response_writer
        products_usecase products_models products_storage products_reader
        common_exceptions
        postgres_query postgres_reader postgres_storage
        ${Boost_LIBRARIES}
)