set(LIBRARY_NAME marshaller)

file(GLOB SRC *.h *.cpp)

add_library(${LIBRARY_NAME} INTERFACE)

target_sources(${LIBRARY_NAME} INTERFACE ${SRC})

target_include_directories(${LIBRARY_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

target_link_libraries(${LIBRARY_NAME} PRIVATE PkgConfig::Pistache)
