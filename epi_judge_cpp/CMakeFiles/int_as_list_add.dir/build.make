# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp"

# Include any dependencies generated for this target.
include CMakeFiles/int_as_list_add.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/int_as_list_add.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/int_as_list_add.dir/flags.make

CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o: CMakeFiles/int_as_list_add.dir/flags.make
CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o: int_as_list_add.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/int_as_list_add.cc"

CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/int_as_list_add.cc" > CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.i

CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/int_as_list_add.cc" -o CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.s

CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.requires:

.PHONY : CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.requires

CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.provides: CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.requires
	$(MAKE) -f CMakeFiles/int_as_list_add.dir/build.make CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.provides.build
.PHONY : CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.provides

CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.provides.build: CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o


# Object files for target int_as_list_add
int_as_list_add_OBJECTS = \
"CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o"

# External object files for target int_as_list_add
int_as_list_add_EXTERNAL_OBJECTS =

int_as_list_add: CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o
int_as_list_add: CMakeFiles/int_as_list_add.dir/build.make
int_as_list_add: CMakeFiles/int_as_list_add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable int_as_list_add"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/int_as_list_add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/int_as_list_add.dir/build: int_as_list_add

.PHONY : CMakeFiles/int_as_list_add.dir/build

CMakeFiles/int_as_list_add.dir/requires: CMakeFiles/int_as_list_add.dir/int_as_list_add.cc.o.requires

.PHONY : CMakeFiles/int_as_list_add.dir/requires

CMakeFiles/int_as_list_add.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/int_as_list_add.dir/cmake_clean.cmake
.PHONY : CMakeFiles/int_as_list_add.dir/clean

CMakeFiles/int_as_list_add.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/int_as_list_add.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/int_as_list_add.dir/depend

