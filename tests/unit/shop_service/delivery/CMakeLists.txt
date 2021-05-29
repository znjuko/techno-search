project(product-service-models)

add_executable(${PROJECT_NAME}  delivery_tests.cpp main.cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)
FIND_PACKAGE( Boost 1.54.0 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        ## common
        nlohmann_json::nlohmann_json
        ${Boost_LIBRARIES}
        pistache
        #        clickhouse-cpp-lib

        request_reader
        response_writer
        marshaller
        unmarshaller
        common_exceptions
        router_setupper

        pthread
        Threads::Threads
        gtest
        ## shop service only
        postgres_storage
        postgres_reader
        postgres_query
        stores_delivery
        stores_query
        stores_reader
        stores_models
        stores_storage
        stores_usecase

        products_delivery
        products_query
        products_reader
        products_models
        products_storage
        products_usecase
)

