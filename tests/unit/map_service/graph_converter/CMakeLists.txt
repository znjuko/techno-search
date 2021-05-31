project(graph_converter_tests)

add_executable(${PROJECT_NAME}  tests.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} Threads::Threads shop_map map_models graph_converter map_adapter map_request_models)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})