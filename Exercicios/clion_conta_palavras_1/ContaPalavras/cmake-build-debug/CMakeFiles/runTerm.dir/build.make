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
CMAKE_SOURCE_DIR = /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/runTerm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTerm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTerm.dir/flags.make

CMakeFiles/runTerm.dir/termtest.cpp.o: CMakeFiles/runTerm.dir/flags.make
CMakeFiles/runTerm.dir/termtest.cpp.o: ../termtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTerm.dir/termtest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTerm.dir/termtest.cpp.o -c /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/termtest.cpp

CMakeFiles/runTerm.dir/termtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTerm.dir/termtest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/termtest.cpp > CMakeFiles/runTerm.dir/termtest.cpp.i

CMakeFiles/runTerm.dir/termtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTerm.dir/termtest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/termtest.cpp -o CMakeFiles/runTerm.dir/termtest.cpp.s

CMakeFiles/runTerm.dir/Terminal.cpp.o: CMakeFiles/runTerm.dir/flags.make
CMakeFiles/runTerm.dir/Terminal.cpp.o: ../Terminal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runTerm.dir/Terminal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTerm.dir/Terminal.cpp.o -c /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/Terminal.cpp

CMakeFiles/runTerm.dir/Terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTerm.dir/Terminal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/Terminal.cpp > CMakeFiles/runTerm.dir/Terminal.cpp.i

CMakeFiles/runTerm.dir/Terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTerm.dir/Terminal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/Terminal.cpp -o CMakeFiles/runTerm.dir/Terminal.cpp.s

# Object files for target runTerm
runTerm_OBJECTS = \
"CMakeFiles/runTerm.dir/termtest.cpp.o" \
"CMakeFiles/runTerm.dir/Terminal.cpp.o"

# External object files for target runTerm
runTerm_EXTERNAL_OBJECTS =

runTerm: CMakeFiles/runTerm.dir/termtest.cpp.o
runTerm: CMakeFiles/runTerm.dir/Terminal.cpp.o
runTerm: CMakeFiles/runTerm.dir/build.make
runTerm: lib/libgtestd.a
runTerm: lib/libgtest_maind.a
runTerm: lib/libgtestd.a
runTerm: CMakeFiles/runTerm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable runTerm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTerm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTerm.dir/build: runTerm

.PHONY : CMakeFiles/runTerm.dir/build

CMakeFiles/runTerm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTerm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTerm.dir/clean

CMakeFiles/runTerm.dir/depend:
	cd /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug /home/fran/CLionProjects/clion_conta_palavras_1/ContaPalavras/cmake-build-debug/CMakeFiles/runTerm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTerm.dir/depend

