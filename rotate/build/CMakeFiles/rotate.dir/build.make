# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/usuario/practicas/p11-files/rotate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usuario/practicas/p11-files/rotate/build

# Include any dependencies generated for this target.
include CMakeFiles/rotate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rotate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rotate.dir/flags.make

CMakeFiles/rotate.dir/src/rotate.cc.o: CMakeFiles/rotate.dir/flags.make
CMakeFiles/rotate.dir/src/rotate.cc.o: ../src/rotate.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/practicas/p11-files/rotate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rotate.dir/src/rotate.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rotate.dir/src/rotate.cc.o -c /home/usuario/practicas/p11-files/rotate/src/rotate.cc

CMakeFiles/rotate.dir/src/rotate.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rotate.dir/src/rotate.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/practicas/p11-files/rotate/src/rotate.cc > CMakeFiles/rotate.dir/src/rotate.cc.i

CMakeFiles/rotate.dir/src/rotate.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rotate.dir/src/rotate.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/practicas/p11-files/rotate/src/rotate.cc -o CMakeFiles/rotate.dir/src/rotate.cc.s

# Object files for target rotate
rotate_OBJECTS = \
"CMakeFiles/rotate.dir/src/rotate.cc.o"

# External object files for target rotate
rotate_EXTERNAL_OBJECTS =

rotate: CMakeFiles/rotate.dir/src/rotate.cc.o
rotate: CMakeFiles/rotate.dir/build.make
rotate: CMakeFiles/rotate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usuario/practicas/p11-files/rotate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rotate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rotate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rotate.dir/build: rotate

.PHONY : CMakeFiles/rotate.dir/build

CMakeFiles/rotate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rotate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rotate.dir/clean

CMakeFiles/rotate.dir/depend:
	cd /home/usuario/practicas/p11-files/rotate/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usuario/practicas/p11-files/rotate /home/usuario/practicas/p11-files/rotate /home/usuario/practicas/p11-files/rotate/build /home/usuario/practicas/p11-files/rotate/build /home/usuario/practicas/p11-files/rotate/build/CMakeFiles/rotate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rotate.dir/depend

