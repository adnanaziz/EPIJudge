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
include CMakeFiles/majority_element.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/majority_element.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/majority_element.dir/flags.make

CMakeFiles/majority_element.dir/majority_element.cc.o: CMakeFiles/majority_element.dir/flags.make
CMakeFiles/majority_element.dir/majority_element.cc.o: majority_element.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/majority_element.dir/majority_element.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/majority_element.dir/majority_element.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/majority_element.cc"

CMakeFiles/majority_element.dir/majority_element.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/majority_element.dir/majority_element.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/majority_element.cc" > CMakeFiles/majority_element.dir/majority_element.cc.i

CMakeFiles/majority_element.dir/majority_element.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/majority_element.dir/majority_element.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/majority_element.cc" -o CMakeFiles/majority_element.dir/majority_element.cc.s

CMakeFiles/majority_element.dir/majority_element.cc.o.requires:

.PHONY : CMakeFiles/majority_element.dir/majority_element.cc.o.requires

CMakeFiles/majority_element.dir/majority_element.cc.o.provides: CMakeFiles/majority_element.dir/majority_element.cc.o.requires
	$(MAKE) -f CMakeFiles/majority_element.dir/build.make CMakeFiles/majority_element.dir/majority_element.cc.o.provides.build
.PHONY : CMakeFiles/majority_element.dir/majority_element.cc.o.provides

CMakeFiles/majority_element.dir/majority_element.cc.o.provides.build: CMakeFiles/majority_element.dir/majority_element.cc.o


# Object files for target majority_element
majority_element_OBJECTS = \
"CMakeFiles/majority_element.dir/majority_element.cc.o"

# External object files for target majority_element
majority_element_EXTERNAL_OBJECTS =

majority_element: CMakeFiles/majority_element.dir/majority_element.cc.o
majority_element: CMakeFiles/majority_element.dir/build.make
majority_element: CMakeFiles/majority_element.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable majority_element"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/majority_element.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/majority_element.dir/build: majority_element

.PHONY : CMakeFiles/majority_element.dir/build

CMakeFiles/majority_element.dir/requires: CMakeFiles/majority_element.dir/majority_element.cc.o.requires

.PHONY : CMakeFiles/majority_element.dir/requires

CMakeFiles/majority_element.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/majority_element.dir/cmake_clean.cmake
.PHONY : CMakeFiles/majority_element.dir/clean

CMakeFiles/majority_element.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/majority_element.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/majority_element.dir/depend

