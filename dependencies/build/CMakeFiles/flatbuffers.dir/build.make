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
CMAKE_SOURCE_DIR = /home/lezkus/Documents/CPProb/dependencies

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lezkus/Documents/CPProb/dependencies/build

# Utility rule file for flatbuffers.

# Include the progress variables for this target.
include CMakeFiles/flatbuffers.dir/progress.make

CMakeFiles/flatbuffers: CMakeFiles/flatbuffers-complete


CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-install
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-mkdir
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-update
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-patch
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-build
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-install
CMakeFiles/flatbuffers-complete: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'flatbuffers'"
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles
	/usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles/flatbuffers-complete
	/usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-done

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-install: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'flatbuffers'"
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E echo_append
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-install

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'flatbuffers'"
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/install
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/tmp
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp
	/usr/bin/cmake -E make_directory /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src
	/usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-mkdir

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-gitinfo.txt
flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'flatbuffers'"
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src && /usr/bin/cmake -P /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/tmp/flatbuffers-gitclone.cmake
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src && /usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-update: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'flatbuffers'"
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers && /usr/bin/cmake -E echo_append
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers && /usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-update

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-patch: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'flatbuffers'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-patch

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure: flatbuffers-prefix/tmp/flatbuffers-cfgcmd.txt
flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-update
flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'flatbuffers'"
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -DCMAKE_INSTALL_PREFIX=/home/lezkus/Documents/CPProb/dependencies/install "-GUnix Makefiles" /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-build: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'flatbuffers'"
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E echo_append
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-build

flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-test: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'flatbuffers'"
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E echo_append
	cd /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-build && /usr/bin/cmake -E touch /home/lezkus/Documents/CPProb/dependencies/build/flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-test

flatbuffers: CMakeFiles/flatbuffers
flatbuffers: CMakeFiles/flatbuffers-complete
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-install
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-mkdir
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-download
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-update
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-patch
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-configure
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-build
flatbuffers: flatbuffers-prefix/src/flatbuffers-stamp/flatbuffers-test
flatbuffers: CMakeFiles/flatbuffers.dir/build.make

.PHONY : flatbuffers

# Rule to build all files generated by this target.
CMakeFiles/flatbuffers.dir/build: flatbuffers

.PHONY : CMakeFiles/flatbuffers.dir/build

CMakeFiles/flatbuffers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flatbuffers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flatbuffers.dir/clean

CMakeFiles/flatbuffers.dir/depend:
	cd /home/lezkus/Documents/CPProb/dependencies/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lezkus/Documents/CPProb/dependencies /home/lezkus/Documents/CPProb/dependencies /home/lezkus/Documents/CPProb/dependencies/build /home/lezkus/Documents/CPProb/dependencies/build /home/lezkus/Documents/CPProb/dependencies/build/CMakeFiles/flatbuffers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flatbuffers.dir/depend

