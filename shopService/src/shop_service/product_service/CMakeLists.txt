add_subdirectory(request_models)
add_subdirectory(product_manager)
add_subdirectory(product_storage)
add_executable(${PROJECT_NAME} product_service.cpp product_service.h)