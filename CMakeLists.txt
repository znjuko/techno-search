#project(techno_search)
#CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)
#cmake_policy(VERSION 3.0)
#

#
#add_executable(techno_search main.cpp)
##target_link_libraries(${PROJECT_NAME} marshaller unmarshaller models)
#
##add_subdirectory(vendor)
#
##if(test)
##    enable_testing()
##
##    find_package(GTest REQUIRED)
##    find_package(Threads REQUIRED)
##
##    add_subdirectory(tests)
##endif(test)

cmake_minimum_required(VERSION 3.19)

project(techno_algo CXX)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)
##add_subdirectory(vendor)


set(MAIN_SRCS main.cpp)

add_executable(main ${MAIN_SRCS})