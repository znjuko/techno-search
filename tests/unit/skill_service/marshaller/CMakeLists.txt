find_package(nlohmann_json 3.2.0 REQUIRED)

file(GLOB SRCS *.cpp)

project(skill_service_marshaller_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        models
        marshaller unmarshaller nlohmann_json::nlohmann_json
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})