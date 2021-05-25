# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/foxers/techno-search

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/foxers/techno-search/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/depend.make

# Include the progress variables for this target.
include src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/progress.make

# Include the compile flags for this target's objects.
include src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/flags.make

src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/product_manager.cpp.o: src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/flags.make
src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/product_manager.cpp.o: ../src/shop_service/product_service/product_manager/product_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/foxers/techno-search/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/product_manager.cpp.o"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/product_manager.dir/product_manager.cpp.o -c /home/foxers/techno-search/src/shop_service/product_service/product_manager/product_manager.cpp

src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/product_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/product_manager.dir/product_manager.cpp.i"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/foxers/techno-search/src/shop_service/product_service/product_manager/product_manager.cpp > CMakeFiles/product_manager.dir/product_manager.cpp.i

src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/product_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/product_manager.dir/product_manager.cpp.s"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/foxers/techno-search/src/shop_service/product_service/product_manager/product_manager.cpp -o CMakeFiles/product_manager.dir/product_manager.cpp.s

# Object files for target product_manager
product_manager_OBJECTS = \
"CMakeFiles/product_manager.dir/product_manager.cpp.o"

# External object files for target product_manager
product_manager_EXTERNAL_OBJECTS =

src/shop_service/product_service/product_manager/libproduct_manager.a: src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/product_manager.cpp.o
src/shop_service/product_service/product_manager/libproduct_manager.a: src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/build.make
src/shop_service/product_service/product_manager/libproduct_manager.a: src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/foxers/techno-search/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libproduct_manager.a"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager && $(CMAKE_COMMAND) -P CMakeFiles/product_manager.dir/cmake_clean_target.cmake
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/product_manager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/build: src/shop_service/product_service/product_manager/libproduct_manager.a

.PHONY : src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/build

src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/clean:
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager && $(CMAKE_COMMAND) -P CMakeFiles/product_manager.dir/cmake_clean.cmake
.PHONY : src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/clean

src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/depend:
	cd /home/foxers/techno-search/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/foxers/techno-search /home/foxers/techno-search/src/shop_service/product_service/product_manager /home/foxers/techno-search/cmake-build-debug-coverage /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager /home/foxers/techno-search/cmake-build-debug-coverage/src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/shop_service/product_service/product_manager/CMakeFiles/product_manager.dir/depend

