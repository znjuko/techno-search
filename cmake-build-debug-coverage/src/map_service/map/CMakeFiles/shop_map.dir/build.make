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
include src/map_service/map/CMakeFiles/shop_map.dir/depend.make

# Include the progress variables for this target.
include src/map_service/map/CMakeFiles/shop_map.dir/progress.make

# Include the compile flags for this target's objects.
include src/map_service/map/CMakeFiles/shop_map.dir/flags.make

src/map_service/map/CMakeFiles/shop_map.dir/shop_map.cpp.o: src/map_service/map/CMakeFiles/shop_map.dir/flags.make
src/map_service/map/CMakeFiles/shop_map.dir/shop_map.cpp.o: ../src/map_service/map/shop_map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/foxers/techno-search/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/map_service/map/CMakeFiles/shop_map.dir/shop_map.cpp.o"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shop_map.dir/shop_map.cpp.o -c /home/foxers/techno-search/src/map_service/map/shop_map.cpp

src/map_service/map/CMakeFiles/shop_map.dir/shop_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shop_map.dir/shop_map.cpp.i"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/foxers/techno-search/src/map_service/map/shop_map.cpp > CMakeFiles/shop_map.dir/shop_map.cpp.i

src/map_service/map/CMakeFiles/shop_map.dir/shop_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shop_map.dir/shop_map.cpp.s"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/foxers/techno-search/src/map_service/map/shop_map.cpp -o CMakeFiles/shop_map.dir/shop_map.cpp.s

# Object files for target shop_map
shop_map_OBJECTS = \
"CMakeFiles/shop_map.dir/shop_map.cpp.o"

# External object files for target shop_map
shop_map_EXTERNAL_OBJECTS =

src/map_service/map/libshop_map.a: src/map_service/map/CMakeFiles/shop_map.dir/shop_map.cpp.o
src/map_service/map/libshop_map.a: src/map_service/map/CMakeFiles/shop_map.dir/build.make
src/map_service/map/libshop_map.a: src/map_service/map/CMakeFiles/shop_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/foxers/techno-search/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libshop_map.a"
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map && $(CMAKE_COMMAND) -P CMakeFiles/shop_map.dir/cmake_clean_target.cmake
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shop_map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/map_service/map/CMakeFiles/shop_map.dir/build: src/map_service/map/libshop_map.a

.PHONY : src/map_service/map/CMakeFiles/shop_map.dir/build

src/map_service/map/CMakeFiles/shop_map.dir/clean:
	cd /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map && $(CMAKE_COMMAND) -P CMakeFiles/shop_map.dir/cmake_clean.cmake
.PHONY : src/map_service/map/CMakeFiles/shop_map.dir/clean

src/map_service/map/CMakeFiles/shop_map.dir/depend:
	cd /home/foxers/techno-search/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/foxers/techno-search /home/foxers/techno-search/src/map_service/map /home/foxers/techno-search/cmake-build-debug-coverage /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map /home/foxers/techno-search/cmake-build-debug-coverage/src/map_service/map/CMakeFiles/shop_map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/map_service/map/CMakeFiles/shop_map.dir/depend

