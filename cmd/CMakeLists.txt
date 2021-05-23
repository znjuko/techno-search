set(MAIN_SRCS main.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SRCS})

find_package(nlohmann_json 3.2.0 REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC
        ## common
        nlohmann_json::nlohmann_json
        ${Boost_LIBRARIES}
        pistache
        clickhouse-cpp-lib
        ## skill service only
        skill_delivery
        skill_usecase
        skill_storage
        click_storage
)
