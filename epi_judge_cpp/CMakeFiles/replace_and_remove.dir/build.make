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
include CMakeFiles/replace_and_remove.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/replace_and_remove.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/replace_and_remove.dir/flags.make

CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o: CMakeFiles/replace_and_remove.dir/flags.make
CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o: replace_and_remove.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/replace_and_remove.cc"

CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/replace_and_remove.cc" > CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.i

CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/replace_and_remove.cc" -o CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.s

CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.requires:

.PHONY : CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.requires

CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.provides: CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.requires
	$(MAKE) -f CMakeFiles/replace_and_remove.dir/build.make CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.provides.build
.PHONY : CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.provides

CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.provides.build: CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o


# Object files for target replace_and_remove
replace_and_remove_OBJECTS = \
"CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o"

# External object files for target replace_and_remove
replace_and_remove_EXTERNAL_OBJECTS =

replace_and_remove: CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o
replace_and_remove: CMakeFiles/replace_and_remove.dir/build.make
replace_and_remove: CMakeFiles/replace_and_remove.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable replace_and_remove"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/replace_and_remove.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/replace_and_remove.dir/build: replace_and_remove

.PHONY : CMakeFiles/replace_and_remove.dir/build

CMakeFiles/replace_and_remove.dir/requires: CMakeFiles/replace_and_remove.dir/replace_and_remove.cc.o.requires

.PHONY : CMakeFiles/replace_and_remove.dir/requires

CMakeFiles/replace_and_remove.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/replace_and_remove.dir/cmake_clean.cmake
.PHONY : CMakeFiles/replace_and_remove.dir/clean

CMakeFiles/replace_and_remove.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/replace_and_remove.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/replace_and_remove.dir/depend

