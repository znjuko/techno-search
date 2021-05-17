project(models_tests)

add_executable(${PROJECT_NAME}  tests.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} Threads::Threads map_models)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})