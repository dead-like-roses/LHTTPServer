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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lenny/CLionProjects/LHTTPServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LHTTPClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LHTTPClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LHTTPClient.dir/flags.make

CMakeFiles/LHTTPClient.dir/client.c.o: CMakeFiles/LHTTPClient.dir/flags.make
CMakeFiles/LHTTPClient.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LHTTPClient.dir/client.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LHTTPClient.dir/client.c.o   -c /Users/lenny/CLionProjects/LHTTPServer/client.c

CMakeFiles/LHTTPClient.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LHTTPClient.dir/client.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lenny/CLionProjects/LHTTPServer/client.c > CMakeFiles/LHTTPClient.dir/client.c.i

CMakeFiles/LHTTPClient.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LHTTPClient.dir/client.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lenny/CLionProjects/LHTTPServer/client.c -o CMakeFiles/LHTTPClient.dir/client.c.s

# Object files for target LHTTPClient
LHTTPClient_OBJECTS = \
"CMakeFiles/LHTTPClient.dir/client.c.o"

# External object files for target LHTTPClient
LHTTPClient_EXTERNAL_OBJECTS =

LHTTPClient: CMakeFiles/LHTTPClient.dir/client.c.o
LHTTPClient: CMakeFiles/LHTTPClient.dir/build.make
LHTTPClient: CMakeFiles/LHTTPClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LHTTPClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LHTTPClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LHTTPClient.dir/build: LHTTPClient

.PHONY : CMakeFiles/LHTTPClient.dir/build

CMakeFiles/LHTTPClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LHTTPClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LHTTPClient.dir/clean

CMakeFiles/LHTTPClient.dir/depend:
	cd /Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lenny/CLionProjects/LHTTPServer /Users/lenny/CLionProjects/LHTTPServer /Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug /Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug /Users/lenny/CLionProjects/LHTTPServer/cmake-build-debug/CMakeFiles/LHTTPClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LHTTPClient.dir/depend

