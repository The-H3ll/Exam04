# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Users/molabhai/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/molabhai/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/molabhai/Desktop/Exam04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/molabhai/Desktop/Exam04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exam04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exam04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exam04.dir/flags.make

CMakeFiles/Exam04.dir/microshell.c.o: CMakeFiles/Exam04.dir/flags.make
CMakeFiles/Exam04.dir/microshell.c.o: ../microshell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/molabhai/Desktop/Exam04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exam04.dir/microshell.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Exam04.dir/microshell.c.o   -c /Users/molabhai/Desktop/Exam04/microshell.c

CMakeFiles/Exam04.dir/microshell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exam04.dir/microshell.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/molabhai/Desktop/Exam04/microshell.c > CMakeFiles/Exam04.dir/microshell.c.i

CMakeFiles/Exam04.dir/microshell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exam04.dir/microshell.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/molabhai/Desktop/Exam04/microshell.c -o CMakeFiles/Exam04.dir/microshell.c.s

# Object files for target Exam04
Exam04_OBJECTS = \
"CMakeFiles/Exam04.dir/microshell.c.o"

# External object files for target Exam04
Exam04_EXTERNAL_OBJECTS =

Exam04: CMakeFiles/Exam04.dir/microshell.c.o
Exam04: CMakeFiles/Exam04.dir/build.make
Exam04: CMakeFiles/Exam04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/molabhai/Desktop/Exam04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Exam04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exam04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exam04.dir/build: Exam04

.PHONY : CMakeFiles/Exam04.dir/build

CMakeFiles/Exam04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exam04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exam04.dir/clean

CMakeFiles/Exam04.dir/depend:
	cd /Users/molabhai/Desktop/Exam04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/molabhai/Desktop/Exam04 /Users/molabhai/Desktop/Exam04 /Users/molabhai/Desktop/Exam04/cmake-build-debug /Users/molabhai/Desktop/Exam04/cmake-build-debug /Users/molabhai/Desktop/Exam04/cmake-build-debug/CMakeFiles/Exam04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exam04.dir/depend

