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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fran/CLionProjects/projeto-3-francin-guilherme-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projeto1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto1.dir/flags.make

CMakeFiles/Projeto1.dir/main.cpp.o: CMakeFiles/Projeto1.dir/flags.make
CMakeFiles/Projeto1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projeto1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projeto1.dir/main.cpp.o -c /home/fran/CLionProjects/projeto-3-francin-guilherme-1/main.cpp

CMakeFiles/Projeto1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/projeto-3-francin-guilherme-1/main.cpp > CMakeFiles/Projeto1.dir/main.cpp.i

CMakeFiles/Projeto1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/projeto-3-francin-guilherme-1/main.cpp -o CMakeFiles/Projeto1.dir/main.cpp.s

CMakeFiles/Projeto1.dir/uteis.cpp.o: CMakeFiles/Projeto1.dir/flags.make
CMakeFiles/Projeto1.dir/uteis.cpp.o: ../uteis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projeto1.dir/uteis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projeto1.dir/uteis.cpp.o -c /home/fran/CLionProjects/projeto-3-francin-guilherme-1/uteis.cpp

CMakeFiles/Projeto1.dir/uteis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto1.dir/uteis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/projeto-3-francin-guilherme-1/uteis.cpp > CMakeFiles/Projeto1.dir/uteis.cpp.i

CMakeFiles/Projeto1.dir/uteis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto1.dir/uteis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/projeto-3-francin-guilherme-1/uteis.cpp -o CMakeFiles/Projeto1.dir/uteis.cpp.s

CMakeFiles/Projeto1.dir/proj3.cpp.o: CMakeFiles/Projeto1.dir/flags.make
CMakeFiles/Projeto1.dir/proj3.cpp.o: ../proj3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Projeto1.dir/proj3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projeto1.dir/proj3.cpp.o -c /home/fran/CLionProjects/projeto-3-francin-guilherme-1/proj3.cpp

CMakeFiles/Projeto1.dir/proj3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto1.dir/proj3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/projeto-3-francin-guilherme-1/proj3.cpp > CMakeFiles/Projeto1.dir/proj3.cpp.i

CMakeFiles/Projeto1.dir/proj3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto1.dir/proj3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/projeto-3-francin-guilherme-1/proj3.cpp -o CMakeFiles/Projeto1.dir/proj3.cpp.s

# Object files for target Projeto1
Projeto1_OBJECTS = \
"CMakeFiles/Projeto1.dir/main.cpp.o" \
"CMakeFiles/Projeto1.dir/uteis.cpp.o" \
"CMakeFiles/Projeto1.dir/proj3.cpp.o"

# External object files for target Projeto1
Projeto1_EXTERNAL_OBJECTS =

Projeto1: CMakeFiles/Projeto1.dir/main.cpp.o
Projeto1: CMakeFiles/Projeto1.dir/uteis.cpp.o
Projeto1: CMakeFiles/Projeto1.dir/proj3.cpp.o
Projeto1: CMakeFiles/Projeto1.dir/build.make
Projeto1: CMakeFiles/Projeto1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Projeto1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projeto1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto1.dir/build: Projeto1

.PHONY : CMakeFiles/Projeto1.dir/build

CMakeFiles/Projeto1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projeto1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projeto1.dir/clean

CMakeFiles/Projeto1.dir/depend:
	cd /home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fran/CLionProjects/projeto-3-francin-guilherme-1 /home/fran/CLionProjects/projeto-3-francin-guilherme-1 /home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug /home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug /home/fran/CLionProjects/projeto-3-francin-guilherme-1/cmake-build-debug/CMakeFiles/Projeto1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projeto1.dir/depend
