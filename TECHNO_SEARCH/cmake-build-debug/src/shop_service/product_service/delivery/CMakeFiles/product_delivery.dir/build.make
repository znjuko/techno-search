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
include src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/depend.make

# Include the progress variables for this target.
include src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/progress.make

# Include the compile flags for this target's objects.
include src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/flags.make

src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/product_service.cpp.o: src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/flags.make
src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/product_service.cpp.o: ../src/shop_service/product_service/delivery/product_service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/product_service.cpp.o"
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/product_delivery.dir/product_service.cpp.o -c "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/src/shop_service/product_service/delivery/product_service.cpp"

src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/product_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/product_delivery.dir/product_service.cpp.i"
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/src/shop_service/product_service/delivery/product_service.cpp" > CMakeFiles/product_delivery.dir/product_service.cpp.i

src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/product_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/product_delivery.dir/product_service.cpp.s"
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/src/shop_service/product_service/delivery/product_service.cpp" -o CMakeFiles/product_delivery.dir/product_service.cpp.s

# Object files for target product_delivery
product_delivery_OBJECTS = \
"CMakeFiles/product_delivery.dir/product_service.cpp.o"

# External object files for target product_delivery
product_delivery_EXTERNAL_OBJECTS =

src/shop_service/product_service/delivery/libproduct_delivery.a: src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/product_service.cpp.o
src/shop_service/product_service/delivery/libproduct_delivery.a: src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/build.make
src/shop_service/product_service/delivery/libproduct_delivery.a: src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libproduct_delivery.a"
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" && $(CMAKE_COMMAND) -P CMakeFiles/product_delivery.dir/cmake_clean_target.cmake
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/product_delivery.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/build: src/shop_service/product_service/delivery/libproduct_delivery.a

.PHONY : src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/build

src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/clean:
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" && $(CMAKE_COMMAND) -P CMakeFiles/product_delivery.dir/cmake_clean.cmake
.PHONY : src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/clean

src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/depend:
	cd "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/src/shop_service/product_service/delivery" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery" "/home/fillinmar/Рабочий стол/TECHNO_SEARCH/cmake-build-debug/src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/shop_service/product_service/delivery/CMakeFiles/product_delivery.dir/depend

