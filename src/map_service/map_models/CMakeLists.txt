find_package(nlohmann_json 3.2.0 REQUIRED)
FIND_PACKAGE(Boost 1.40 COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(LIBRARY_NAME map_models)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE
        #nlohmann_json::nlohmann_json
        #marshaller unmarshaller
        #common_exceptions pistache
        #${Boost_LIBRARIES}
        )