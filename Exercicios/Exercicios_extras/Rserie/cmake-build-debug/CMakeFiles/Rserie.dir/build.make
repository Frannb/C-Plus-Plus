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
CMAKE_SOURCE_DIR = /home/fran/CLionProjects/Exercicios_extras/Rserie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Rserie.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rserie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rserie.dir/flags.make

CMakeFiles/Rserie.dir/main.cpp.o: CMakeFiles/Rserie.dir/flags.make
CMakeFiles/Rserie.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Rserie.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rserie.dir/main.cpp.o -c /home/fran/CLionProjects/Exercicios_extras/Rserie/main.cpp

CMakeFiles/Rserie.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rserie.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/Exercicios_extras/Rserie/main.cpp > CMakeFiles/Rserie.dir/main.cpp.i

CMakeFiles/Rserie.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rserie.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/Exercicios_extras/Rserie/main.cpp -o CMakeFiles/Rserie.dir/main.cpp.s

# Object files for target Rserie
Rserie_OBJECTS = \
"CMakeFiles/Rserie.dir/main.cpp.o"

# External object files for target Rserie
Rserie_EXTERNAL_OBJECTS =

Rserie: CMakeFiles/Rserie.dir/main.cpp.o
Rserie: CMakeFiles/Rserie.dir/build.make
Rserie: CMakeFiles/Rserie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Rserie"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rserie.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rserie.dir/build: Rserie

.PHONY : CMakeFiles/Rserie.dir/build

CMakeFiles/Rserie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Rserie.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Rserie.dir/clean

CMakeFiles/Rserie.dir/depend:
	cd /home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fran/CLionProjects/Exercicios_extras/Rserie /home/fran/CLionProjects/Exercicios_extras/Rserie /home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug /home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug /home/fran/CLionProjects/Exercicios_extras/Rserie/cmake-build-debug/CMakeFiles/Rserie.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rserie.dir/depend

