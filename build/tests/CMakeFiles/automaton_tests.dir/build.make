# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xian/local/Cpp23CellularAutomation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xian/local/Cpp23CellularAutomation/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/automaton_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/automaton_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/automaton_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/automaton_tests.dir/flags.make

tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.o: tests/CMakeFiles/automaton_tests.dir/flags.make
tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.o: /home/xian/local/Cpp23CellularAutomation/tests/test_automation.cpp
tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.o: tests/CMakeFiles/automaton_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xian/local/Cpp23CellularAutomation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.o"
	cd /home/xian/local/Cpp23CellularAutomation/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.o -MF CMakeFiles/automaton_tests.dir/test_automation.cpp.o.d -o CMakeFiles/automaton_tests.dir/test_automation.cpp.o -c /home/xian/local/Cpp23CellularAutomation/tests/test_automation.cpp

tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/automaton_tests.dir/test_automation.cpp.i"
	cd /home/xian/local/Cpp23CellularAutomation/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xian/local/Cpp23CellularAutomation/tests/test_automation.cpp > CMakeFiles/automaton_tests.dir/test_automation.cpp.i

tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/automaton_tests.dir/test_automation.cpp.s"
	cd /home/xian/local/Cpp23CellularAutomation/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xian/local/Cpp23CellularAutomation/tests/test_automation.cpp -o CMakeFiles/automaton_tests.dir/test_automation.cpp.s

# Object files for target automaton_tests
automaton_tests_OBJECTS = \
"CMakeFiles/automaton_tests.dir/test_automation.cpp.o"

# External object files for target automaton_tests
automaton_tests_EXTERNAL_OBJECTS =

tests/automaton_tests: tests/CMakeFiles/automaton_tests.dir/test_automation.cpp.o
tests/automaton_tests: tests/CMakeFiles/automaton_tests.dir/build.make
tests/automaton_tests: tests/CMakeFiles/automaton_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/xian/local/Cpp23CellularAutomation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable automaton_tests"
	cd /home/xian/local/Cpp23CellularAutomation/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/automaton_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/automaton_tests.dir/build: tests/automaton_tests
.PHONY : tests/CMakeFiles/automaton_tests.dir/build

tests/CMakeFiles/automaton_tests.dir/clean:
	cd /home/xian/local/Cpp23CellularAutomation/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/automaton_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/automaton_tests.dir/clean

tests/CMakeFiles/automaton_tests.dir/depend:
	cd /home/xian/local/Cpp23CellularAutomation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xian/local/Cpp23CellularAutomation /home/xian/local/Cpp23CellularAutomation/tests /home/xian/local/Cpp23CellularAutomation/build /home/xian/local/Cpp23CellularAutomation/build/tests /home/xian/local/Cpp23CellularAutomation/build/tests/CMakeFiles/automaton_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/automaton_tests.dir/depend

