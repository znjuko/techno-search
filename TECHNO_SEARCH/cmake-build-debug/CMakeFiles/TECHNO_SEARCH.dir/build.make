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
CMAKE_SOURCE_DIR = "/home/fillinmar/Рабочий стол/TECHNO_SEARCH"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TECHNO_SEARCH.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TECHNO_SEARCH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TECHNO_SEARCH.dir/flags.make

CMakeFiles/TECHNO_SEARCH.dir/main.cpp.o: CMakeFiles/TECHNO_SEARCH.dir/flags.make
CMakeFiles/TECHNO_SEARCH.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TECHNO_SEARCH.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TECHNO_SEARCH.dir/main.cpp.o -c "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/main.cpp"

CMakeFiles/TECHNO_SEARCH.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TECHNO_SEARCH.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/main.cpp" > CMakeFiles/TECHNO_SEARCH.dir/main.cpp.i

CMakeFiles/TECHNO_SEARCH.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TECHNO_SEARCH.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/main.cpp" -o CMakeFiles/TECHNO_SEARCH.dir/main.cpp.s

# Object files for target TECHNO_SEARCH
TECHNO_SEARCH_OBJECTS = \
"CMakeFiles/TECHNO_SEARCH.dir/main.cpp.o"

# External object files for target TECHNO_SEARCH
TECHNO_SEARCH_EXTERNAL_OBJECTS =

TECHNO_SEARCH: CMakeFiles/TECHNO_SEARCH.dir/main.cpp.o
TECHNO_SEARCH: CMakeFiles/TECHNO_SEARCH.dir/build.make
TECHNO_SEARCH: /usr/local/lib/libpqxx-7.5.a
TECHNO_SEARCH: src/shop_service/store_service/request_models/libmodels.a
TECHNO_SEARCH: /usr/lib/x86_64-linux-gnu/libpq.so
TECHNO_SEARCH: CMakeFiles/TECHNO_SEARCH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TECHNO_SEARCH"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TECHNO_SEARCH.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TECHNO_SEARCH.dir/build: TECHNO_SEARCH

.PHONY : CMakeFiles/TECHNO_SEARCH.dir/build

CMakeFiles/TECHNO_SEARCH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TECHNO_SEARCH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TECHNO_SEARCH.dir/clean

CMakeFiles/TECHNO_SEARCH.dir/depend:
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/CMakeFiles/TECHNO_SEARCH.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TECHNO_SEARCH.dir/depend

