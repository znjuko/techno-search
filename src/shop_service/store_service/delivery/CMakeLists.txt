find_package(nlohmann_json 3.2.0 REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(SRC delivery.h delivery.cpp)

set(LIBRARY_NAME store_delivery)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
        ${LIBRARY_NAME} PRIVATE
        marshaller unmarshaller nlohmann_json::nlohmann_json
        pistache router_setupper request_reader response_writer
        store_usecase store_models
        ${Boost_LIBRARIES}
)