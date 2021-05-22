find_package(nlohmann_json 3.2.0 REQUIRED)

set(LIBRARY_NAME router_setupper)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#find_package(PkgConfig)
#pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

target_link_libraries(${LIBRARY_NAME} PUBLIC pistache)