set(MAIN_SRCS main.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SRCS})

find_package(nlohmann_json 3.2.0 REQUIRED)
FIND_PACKAGE( Boost 1.71.0 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        ## common
        nlohmann_json::nlohmann_json
        ${Boost_LIBRARIES}
        pistache
        clickhouse-cpp-lib

        request_reader
        response_writer
        marshaller
        unmarshaller
        common_exceptions
        router_setupper

        pthread
        Threads::Threads
        ## skill service only
        skill_delivery
        skill_usecase
        skill_storage
        click_storage
        skill_models
        click_query
        click_reader
)
