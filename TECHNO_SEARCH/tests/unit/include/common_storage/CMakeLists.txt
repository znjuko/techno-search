file(GLOB SRCS *.cpp)

project(common_storage_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        common_storage
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})