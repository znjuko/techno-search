project(techno_search)

CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

add_subdirectory(src)
add_subdirectory(include)

add_executable(techno_search main.cpp)
target_link_libraries(${PROJECT_NAME} marshaller unmarshaller models)