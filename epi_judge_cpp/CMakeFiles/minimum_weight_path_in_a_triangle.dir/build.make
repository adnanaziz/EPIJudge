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
include CMakeFiles/minimum_weight_path_in_a_triangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minimum_weight_path_in_a_triangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minimum_weight_path_in_a_triangle.dir/flags.make

CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o: CMakeFiles/minimum_weight_path_in_a_triangle.dir/flags.make
CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o: minimum_weight_path_in_a_triangle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/minimum_weight_path_in_a_triangle.cc"

CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/minimum_weight_path_in_a_triangle.cc" > CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.i

CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/minimum_weight_path_in_a_triangle.cc" -o CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.s

CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.requires:

.PHONY : CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.requires

CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.provides: CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.requires
	$(MAKE) -f CMakeFiles/minimum_weight_path_in_a_triangle.dir/build.make CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.provides.build
.PHONY : CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.provides

CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.provides.build: CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o


# Object files for target minimum_weight_path_in_a_triangle
minimum_weight_path_in_a_triangle_OBJECTS = \
"CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o"

# External object files for target minimum_weight_path_in_a_triangle
minimum_weight_path_in_a_triangle_EXTERNAL_OBJECTS =

minimum_weight_path_in_a_triangle: CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o
minimum_weight_path_in_a_triangle: CMakeFiles/minimum_weight_path_in_a_triangle.dir/build.make
minimum_weight_path_in_a_triangle: CMakeFiles/minimum_weight_path_in_a_triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minimum_weight_path_in_a_triangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimum_weight_path_in_a_triangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minimum_weight_path_in_a_triangle.dir/build: minimum_weight_path_in_a_triangle

.PHONY : CMakeFiles/minimum_weight_path_in_a_triangle.dir/build

CMakeFiles/minimum_weight_path_in_a_triangle.dir/requires: CMakeFiles/minimum_weight_path_in_a_triangle.dir/minimum_weight_path_in_a_triangle.cc.o.requires

.PHONY : CMakeFiles/minimum_weight_path_in_a_triangle.dir/requires

CMakeFiles/minimum_weight_path_in_a_triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minimum_weight_path_in_a_triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minimum_weight_path_in_a_triangle.dir/clean

CMakeFiles/minimum_weight_path_in_a_triangle.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/minimum_weight_path_in_a_triangle.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/minimum_weight_path_in_a_triangle.dir/depend

