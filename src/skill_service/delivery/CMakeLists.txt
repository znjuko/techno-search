find_package(nlohmann_json 3.2.0 REQUIRED)
FIND_PACKAGE( Boost 1.71.0 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(LIBRARY_NAME skill_delivery)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#find_package(PkgConfig)
#pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

target_link_libraries(
        ${LIBRARY_NAME} PRIVATE

        common_exceptions

        marshaller unmarshaller
        skill_models
        click_storage
        click_query
        click_reader
        skill_storage
        skill_usecase


        nlohmann_json::nlohmann_json
        pistache router_setupper
        request_reader response_writer
        ${Boost_LIBRARIES}
)