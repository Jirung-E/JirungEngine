# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/JirungEngine/src/Util

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/JirungEngine/src/Util

# Include any dependencies generated for this target.
include CMakeFiles/Util.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Util.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Util.dir/flags.make

CMakeFiles/Util.dir/Util.o: CMakeFiles/Util.dir/flags.make
CMakeFiles/Util.dir/Util.o: Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/JirungEngine/src/Util/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Util.dir/Util.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Util.dir/Util.o -c /workspace/JirungEngine/src/Util/Util.cpp

CMakeFiles/Util.dir/Util.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Util.dir/Util.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/JirungEngine/src/Util/Util.cpp > CMakeFiles/Util.dir/Util.i

CMakeFiles/Util.dir/Util.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Util.dir/Util.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/JirungEngine/src/Util/Util.cpp -o CMakeFiles/Util.dir/Util.s

CMakeFiles/Util.dir/Util.o.requires:

.PHONY : CMakeFiles/Util.dir/Util.o.requires

CMakeFiles/Util.dir/Util.o.provides: CMakeFiles/Util.dir/Util.o.requires
	$(MAKE) -f CMakeFiles/Util.dir/build.make CMakeFiles/Util.dir/Util.o.provides.build
.PHONY : CMakeFiles/Util.dir/Util.o.provides

CMakeFiles/Util.dir/Util.o.provides.build: CMakeFiles/Util.dir/Util.o


# Object files for target Util
Util_OBJECTS = \
"CMakeFiles/Util.dir/Util.o"

# External object files for target Util
Util_EXTERNAL_OBJECTS =

libUtil.a: CMakeFiles/Util.dir/Util.o
libUtil.a: CMakeFiles/Util.dir/build.make
libUtil.a: CMakeFiles/Util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspace/JirungEngine/src/Util/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUtil.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Util.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Util.dir/build: libUtil.a

.PHONY : CMakeFiles/Util.dir/build

CMakeFiles/Util.dir/requires: CMakeFiles/Util.dir/Util.o.requires

.PHONY : CMakeFiles/Util.dir/requires

CMakeFiles/Util.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Util.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Util.dir/clean

CMakeFiles/Util.dir/depend:
	cd /workspace/JirungEngine/src/Util && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/JirungEngine/src/Util /workspace/JirungEngine/src/Util /workspace/JirungEngine/src/Util /workspace/JirungEngine/src/Util /workspace/JirungEngine/src/Util/CMakeFiles/Util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Util.dir/depend

