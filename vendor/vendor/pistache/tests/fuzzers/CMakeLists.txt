add_executable(fuzz_parser fuzz_parser.cpp)
target_link_libraries(fuzz_parser pistache_static)
set_target_properties(fuzz_parser PROPERTIES LINK_FLAGS $ENV{LIB_FUZZING_ENGINE})
