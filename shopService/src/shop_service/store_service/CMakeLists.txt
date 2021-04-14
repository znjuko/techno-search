add_subdirectory(request_models)
add_subdirectory(store_manager)
add_subdirectory(store_storage)
add_executable(${PROJECT_NAME} store_service.cpp store_service.h)