# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/ahmad/app/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ahmad/app/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahmad/CLionProjects/Eratosthenes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Eratosthenes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Eratosthenes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Eratosthenes.dir/flags.make

CMakeFiles/Eratosthenes.dir/main.cpp.o: CMakeFiles/Eratosthenes.dir/flags.make
CMakeFiles/Eratosthenes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Eratosthenes.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Eratosthenes.dir/main.cpp.o -c /home/ahmad/CLionProjects/Eratosthenes/main.cpp

CMakeFiles/Eratosthenes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eratosthenes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/Eratosthenes/main.cpp > CMakeFiles/Eratosthenes.dir/main.cpp.i

CMakeFiles/Eratosthenes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eratosthenes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/Eratosthenes/main.cpp -o CMakeFiles/Eratosthenes.dir/main.cpp.s

CMakeFiles/Eratosthenes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Eratosthenes.dir/main.cpp.o.requires

CMakeFiles/Eratosthenes.dir/main.cpp.o.provides: CMakeFiles/Eratosthenes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Eratosthenes.dir/build.make CMakeFiles/Eratosthenes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Eratosthenes.dir/main.cpp.o.provides

CMakeFiles/Eratosthenes.dir/main.cpp.o.provides.build: CMakeFiles/Eratosthenes.dir/main.cpp.o


CMakeFiles/Eratosthenes.dir/single_thread.cpp.o: CMakeFiles/Eratosthenes.dir/flags.make
CMakeFiles/Eratosthenes.dir/single_thread.cpp.o: ../single_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Eratosthenes.dir/single_thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Eratosthenes.dir/single_thread.cpp.o -c /home/ahmad/CLionProjects/Eratosthenes/single_thread.cpp

CMakeFiles/Eratosthenes.dir/single_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eratosthenes.dir/single_thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/Eratosthenes/single_thread.cpp > CMakeFiles/Eratosthenes.dir/single_thread.cpp.i

CMakeFiles/Eratosthenes.dir/single_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eratosthenes.dir/single_thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/Eratosthenes/single_thread.cpp -o CMakeFiles/Eratosthenes.dir/single_thread.cpp.s

CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.requires:

.PHONY : CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.requires

CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.provides: CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/Eratosthenes.dir/build.make CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.provides.build
.PHONY : CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.provides

CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.provides.build: CMakeFiles/Eratosthenes.dir/single_thread.cpp.o


CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o: CMakeFiles/Eratosthenes.dir/flags.make
CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o: ../eratosthenes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o -c /home/ahmad/CLionProjects/Eratosthenes/eratosthenes.cpp

CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/Eratosthenes/eratosthenes.cpp > CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.i

CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/Eratosthenes/eratosthenes.cpp -o CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.s

CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.requires:

.PHONY : CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.requires

CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.provides: CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.requires
	$(MAKE) -f CMakeFiles/Eratosthenes.dir/build.make CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.provides.build
.PHONY : CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.provides

CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.provides.build: CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o


CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o: CMakeFiles/Eratosthenes.dir/flags.make
CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o: ../multi_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o -c /home/ahmad/CLionProjects/Eratosthenes/multi_thread.cpp

CMakeFiles/Eratosthenes.dir/multi_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eratosthenes.dir/multi_thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/Eratosthenes/multi_thread.cpp > CMakeFiles/Eratosthenes.dir/multi_thread.cpp.i

CMakeFiles/Eratosthenes.dir/multi_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eratosthenes.dir/multi_thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/Eratosthenes/multi_thread.cpp -o CMakeFiles/Eratosthenes.dir/multi_thread.cpp.s

CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.requires:

.PHONY : CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.requires

CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.provides: CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/Eratosthenes.dir/build.make CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.provides.build
.PHONY : CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.provides

CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.provides.build: CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o


CMakeFiles/Eratosthenes.dir/multi_process.cpp.o: CMakeFiles/Eratosthenes.dir/flags.make
CMakeFiles/Eratosthenes.dir/multi_process.cpp.o: ../multi_process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Eratosthenes.dir/multi_process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Eratosthenes.dir/multi_process.cpp.o -c /home/ahmad/CLionProjects/Eratosthenes/multi_process.cpp

CMakeFiles/Eratosthenes.dir/multi_process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eratosthenes.dir/multi_process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/Eratosthenes/multi_process.cpp > CMakeFiles/Eratosthenes.dir/multi_process.cpp.i

CMakeFiles/Eratosthenes.dir/multi_process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eratosthenes.dir/multi_process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/Eratosthenes/multi_process.cpp -o CMakeFiles/Eratosthenes.dir/multi_process.cpp.s

CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.requires:

.PHONY : CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.requires

CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.provides: CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.requires
	$(MAKE) -f CMakeFiles/Eratosthenes.dir/build.make CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.provides.build
.PHONY : CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.provides

CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.provides.build: CMakeFiles/Eratosthenes.dir/multi_process.cpp.o


# Object files for target Eratosthenes
Eratosthenes_OBJECTS = \
"CMakeFiles/Eratosthenes.dir/main.cpp.o" \
"CMakeFiles/Eratosthenes.dir/single_thread.cpp.o" \
"CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o" \
"CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o" \
"CMakeFiles/Eratosthenes.dir/multi_process.cpp.o"

# External object files for target Eratosthenes
Eratosthenes_EXTERNAL_OBJECTS =

Eratosthenes: CMakeFiles/Eratosthenes.dir/main.cpp.o
Eratosthenes: CMakeFiles/Eratosthenes.dir/single_thread.cpp.o
Eratosthenes: CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o
Eratosthenes: CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o
Eratosthenes: CMakeFiles/Eratosthenes.dir/multi_process.cpp.o
Eratosthenes: CMakeFiles/Eratosthenes.dir/build.make
Eratosthenes: CMakeFiles/Eratosthenes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Eratosthenes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Eratosthenes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Eratosthenes.dir/build: Eratosthenes

.PHONY : CMakeFiles/Eratosthenes.dir/build

CMakeFiles/Eratosthenes.dir/requires: CMakeFiles/Eratosthenes.dir/main.cpp.o.requires
CMakeFiles/Eratosthenes.dir/requires: CMakeFiles/Eratosthenes.dir/single_thread.cpp.o.requires
CMakeFiles/Eratosthenes.dir/requires: CMakeFiles/Eratosthenes.dir/eratosthenes.cpp.o.requires
CMakeFiles/Eratosthenes.dir/requires: CMakeFiles/Eratosthenes.dir/multi_thread.cpp.o.requires
CMakeFiles/Eratosthenes.dir/requires: CMakeFiles/Eratosthenes.dir/multi_process.cpp.o.requires

.PHONY : CMakeFiles/Eratosthenes.dir/requires

CMakeFiles/Eratosthenes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Eratosthenes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Eratosthenes.dir/clean

CMakeFiles/Eratosthenes.dir/depend:
	cd /home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmad/CLionProjects/Eratosthenes /home/ahmad/CLionProjects/Eratosthenes /home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug /home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug /home/ahmad/CLionProjects/Eratosthenes/cmake-build-debug/CMakeFiles/Eratosthenes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Eratosthenes.dir/depend

