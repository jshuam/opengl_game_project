# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = "/home/josh/Dev/OpenGL Game Project/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/josh/Dev/OpenGL Game Project/build"

# Include any dependencies generated for this target.
include gl/CMakeFiles/gl.dir/depend.make

# Include the progress variables for this target.
include gl/CMakeFiles/gl.dir/progress.make

# Include the compile flags for this target's objects.
include gl/CMakeFiles/gl.dir/flags.make

# Object files for target gl
gl_OBJECTS =

# External object files for target gl
gl_EXTERNAL_OBJECTS =

gl/libgl.a: gl/CMakeFiles/gl.dir/build.make
gl/libgl.a: gl/CMakeFiles/gl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/josh/Dev/OpenGL Game Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libgl.a"
	cd "/home/josh/Dev/OpenGL Game Project/build/gl" && $(CMAKE_COMMAND) -P CMakeFiles/gl.dir/cmake_clean_target.cmake
	cd "/home/josh/Dev/OpenGL Game Project/build/gl" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gl/CMakeFiles/gl.dir/build: gl/libgl.a

.PHONY : gl/CMakeFiles/gl.dir/build

gl/CMakeFiles/gl.dir/clean:
	cd "/home/josh/Dev/OpenGL Game Project/build/gl" && $(CMAKE_COMMAND) -P CMakeFiles/gl.dir/cmake_clean.cmake
.PHONY : gl/CMakeFiles/gl.dir/clean

gl/CMakeFiles/gl.dir/depend:
	cd "/home/josh/Dev/OpenGL Game Project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/josh/Dev/OpenGL Game Project/src" "/home/josh/Dev/OpenGL Game Project/src/gl" "/home/josh/Dev/OpenGL Game Project/build" "/home/josh/Dev/OpenGL Game Project/build/gl" "/home/josh/Dev/OpenGL Game Project/build/gl/CMakeFiles/gl.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : gl/CMakeFiles/gl.dir/depend

