# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/lezkus/Documents/CPProb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lezkus/Documents/CPProb/.build

# Include any dependencies generated for this target.
include CMakeFiles/cpprob.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpprob.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpprob.dir/flags.make

CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o: ../src/cpprob/cpprob.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/cpprob.cpp

CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/cpprob.cpp > CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/cpprob.cpp -o CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o


CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o: ../src/cpprob/sample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/sample.cpp

CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/sample.cpp > CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/sample.cpp -o CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o


CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o: ../src/cpprob/serialization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/serialization.cpp

CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/serialization.cpp > CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/serialization.cpp -o CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o


CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o: ../src/cpprob/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/socket.cpp

CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/socket.cpp > CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/socket.cpp -o CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o


CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o: ../src/cpprob/state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/state.cpp

CMakeFiles/cpprob.dir/src/cpprob/state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/state.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/state.cpp > CMakeFiles/cpprob.dir/src/cpprob/state.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/state.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/state.cpp -o CMakeFiles/cpprob.dir/src/cpprob/state.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o


CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o: ../src/cpprob/trace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/trace.cpp

CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/trace.cpp > CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/trace.cpp -o CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o


CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o: CMakeFiles/cpprob.dir/flags.make
CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o: ../src/cpprob/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o -c /home/lezkus/Documents/CPProb/src/cpprob/utils.cpp

CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/cpprob/utils.cpp > CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.i

CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/cpprob/utils.cpp -o CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.s

CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.requires:

.PHONY : CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.requires

CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.provides: CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpprob.dir/build.make CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.provides.build
.PHONY : CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.provides

CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.provides.build: CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o


# Object files for target cpprob
cpprob_OBJECTS = \
"CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o" \
"CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o" \
"CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o" \
"CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o" \
"CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o" \
"CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o" \
"CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o"

# External object files for target cpprob
cpprob_EXTERNAL_OBJECTS =

libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o
libcpprob.so: CMakeFiles/cpprob.dir/build.make
libcpprob.so: /usr/lib/libzmq.so
libcpprob.so: CMakeFiles/cpprob.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library libcpprob.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpprob.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpprob.dir/build: libcpprob.so

.PHONY : CMakeFiles/cpprob.dir/build

CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/cpprob.cpp.o.requires
CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/sample.cpp.o.requires
CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/serialization.cpp.o.requires
CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/socket.cpp.o.requires
CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/state.cpp.o.requires
CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/trace.cpp.o.requires
CMakeFiles/cpprob.dir/requires: CMakeFiles/cpprob.dir/src/cpprob/utils.cpp.o.requires

.PHONY : CMakeFiles/cpprob.dir/requires

CMakeFiles/cpprob.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpprob.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpprob.dir/clean

CMakeFiles/cpprob.dir/depend:
	cd /home/lezkus/Documents/CPProb/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lezkus/Documents/CPProb /home/lezkus/Documents/CPProb /home/lezkus/Documents/CPProb/.build /home/lezkus/Documents/CPProb/.build /home/lezkus/Documents/CPProb/.build/CMakeFiles/cpprob.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpprob.dir/depend

