find_package(nlohmann_json 3.2.0 REQUIRED)

set(SRC usecase.cpp usecase.h)

set(LIBRARY_NAME products_usecase)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PRIVATE products_storage products_models
        )