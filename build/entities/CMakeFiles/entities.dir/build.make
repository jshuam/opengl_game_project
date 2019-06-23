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
include entities/CMakeFiles/entities.dir/depend.make

# Include the progress variables for this target.
include entities/CMakeFiles/entities.dir/progress.make

# Include the compile flags for this target's objects.
include entities/CMakeFiles/entities.dir/flags.make

entities/CMakeFiles/entities.dir/Entity.cpp.o: entities/CMakeFiles/entities.dir/flags.make
entities/CMakeFiles/entities.dir/Entity.cpp.o: /home/josh/Dev/OpenGL\ Game\ Project/src/entities/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josh/Dev/OpenGL Game Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object entities/CMakeFiles/entities.dir/Entity.cpp.o"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/entities.dir/Entity.cpp.o -c "/home/josh/Dev/OpenGL Game Project/src/entities/Entity.cpp"

entities/CMakeFiles/entities.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entities.dir/Entity.cpp.i"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josh/Dev/OpenGL Game Project/src/entities/Entity.cpp" > CMakeFiles/entities.dir/Entity.cpp.i

entities/CMakeFiles/entities.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entities.dir/Entity.cpp.s"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josh/Dev/OpenGL Game Project/src/entities/Entity.cpp" -o CMakeFiles/entities.dir/Entity.cpp.s

entities/CMakeFiles/entities.dir/EntityManager.cpp.o: entities/CMakeFiles/entities.dir/flags.make
entities/CMakeFiles/entities.dir/EntityManager.cpp.o: /home/josh/Dev/OpenGL\ Game\ Project/src/entities/EntityManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/josh/Dev/OpenGL Game Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object entities/CMakeFiles/entities.dir/EntityManager.cpp.o"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/entities.dir/EntityManager.cpp.o -c "/home/josh/Dev/OpenGL Game Project/src/entities/EntityManager.cpp"

entities/CMakeFiles/entities.dir/EntityManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entities.dir/EntityManager.cpp.i"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/josh/Dev/OpenGL Game Project/src/entities/EntityManager.cpp" > CMakeFiles/entities.dir/EntityManager.cpp.i

entities/CMakeFiles/entities.dir/EntityManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entities.dir/EntityManager.cpp.s"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/josh/Dev/OpenGL Game Project/src/entities/EntityManager.cpp" -o CMakeFiles/entities.dir/EntityManager.cpp.s

# Object files for target entities
entities_OBJECTS = \
"CMakeFiles/entities.dir/Entity.cpp.o" \
"CMakeFiles/entities.dir/EntityManager.cpp.o"

# External object files for target entities
entities_EXTERNAL_OBJECTS =

entities/libentities.a: entities/CMakeFiles/entities.dir/Entity.cpp.o
entities/libentities.a: entities/CMakeFiles/entities.dir/EntityManager.cpp.o
entities/libentities.a: entities/CMakeFiles/entities.dir/build.make
entities/libentities.a: entities/CMakeFiles/entities.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/josh/Dev/OpenGL Game Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libentities.a"
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && $(CMAKE_COMMAND) -P CMakeFiles/entities.dir/cmake_clean_target.cmake
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/entities.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
entities/CMakeFiles/entities.dir/build: entities/libentities.a

.PHONY : entities/CMakeFiles/entities.dir/build

entities/CMakeFiles/entities.dir/clean:
	cd "/home/josh/Dev/OpenGL Game Project/build/entities" && $(CMAKE_COMMAND) -P CMakeFiles/entities.dir/cmake_clean.cmake
.PHONY : entities/CMakeFiles/entities.dir/clean

entities/CMakeFiles/entities.dir/depend:
	cd "/home/josh/Dev/OpenGL Game Project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/josh/Dev/OpenGL Game Project/src" "/home/josh/Dev/OpenGL Game Project/src/entities" "/home/josh/Dev/OpenGL Game Project/build" "/home/josh/Dev/OpenGL Game Project/build/entities" "/home/josh/Dev/OpenGL Game Project/build/entities/CMakeFiles/entities.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : entities/CMakeFiles/entities.dir/depend

