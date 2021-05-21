file(GLOB SRCS *.cpp)

project(graph_tests)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        path_finder
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})