# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/fran/Downloads/CLion-2019.2/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/fran/Downloads/CLion-2019.2/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fran/CLionProjects/clion-inversao-string/InversaoString

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/InversaoString.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/InversaoString.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InversaoString.dir/flags.make

CMakeFiles/InversaoString.dir/main.cpp.o: CMakeFiles/InversaoString.dir/flags.make
CMakeFiles/InversaoString.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/InversaoString.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/InversaoString.dir/main.cpp.o -c /home/fran/CLionProjects/clion-inversao-string/InversaoString/main.cpp

CMakeFiles/InversaoString.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InversaoString.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/clion-inversao-string/InversaoString/main.cpp > CMakeFiles/InversaoString.dir/main.cpp.i

CMakeFiles/InversaoString.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InversaoString.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/clion-inversao-string/InversaoString/main.cpp -o CMakeFiles/InversaoString.dir/main.cpp.s

# Object files for target InversaoString
InversaoString_OBJECTS = \
"CMakeFiles/InversaoString.dir/main.cpp.o"

# External object files for target InversaoString
InversaoString_EXTERNAL_OBJECTS =

InversaoString: CMakeFiles/InversaoString.dir/main.cpp.o
InversaoString: CMakeFiles/InversaoString.dir/build.make
InversaoString: CMakeFiles/InversaoString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable InversaoString"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InversaoString.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InversaoString.dir/build: InversaoString

.PHONY : CMakeFiles/InversaoString.dir/build

CMakeFiles/InversaoString.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InversaoString.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InversaoString.dir/clean

CMakeFiles/InversaoString.dir/depend:
	cd /home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fran/CLionProjects/clion-inversao-string/InversaoString /home/fran/CLionProjects/clion-inversao-string/InversaoString /home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug /home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug /home/fran/CLionProjects/clion-inversao-string/InversaoString/cmake-build-debug/CMakeFiles/InversaoString.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/InversaoString.dir/depend

