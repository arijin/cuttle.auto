# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /opt/cmake-3.21.4/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arijin/cuttle.auto/ros/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arijin/cuttle.auto/ros/build

# Utility rule file for run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.

# Include any custom commands dependencies for this target.
include perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/compiler_depend.make

# Include the progress variables for this target.
include perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/progress.make

perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test:
	cd /home/arijin/cuttle.auto/ros/build/perception/detection/packages/roi_map_object_filter && ../../../../catkin_generated/env_cached.sh /usr/bin/python2 /opt/ros/melodic/share/catkin/cmake/test/run_tests.py /home/arijin/cuttle.auto/ros/build/test_results/roi_map_object_filter/rostest-test_test_roi_object_filter.xml "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/arijin/cuttle.auto/ros/src/perception/detection/packages/roi_map_object_filter --package=roi_map_object_filter --results-filename test_test_roi_object_filter.xml --results-base-dir \"/home/arijin/cuttle.auto/ros/build/test_results\" /home/arijin/cuttle.auto/ros/src/perception/detection/packages/roi_map_object_filter/test/test_roi_object_filter.test "

run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test: perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test
run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test: perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/build.make
.PHONY : run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test

# Rule to build all files generated by this target.
perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/build: run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test
.PHONY : perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/build

perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/clean:
	cd /home/arijin/cuttle.auto/ros/build/perception/detection/packages/roi_map_object_filter && $(CMAKE_COMMAND) -P CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/cmake_clean.cmake
.PHONY : perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/clean

perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/depend:
	cd /home/arijin/cuttle.auto/ros/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arijin/cuttle.auto/ros/src /home/arijin/cuttle.auto/ros/src/perception/detection/packages/roi_map_object_filter /home/arijin/cuttle.auto/ros/build /home/arijin/cuttle.auto/ros/build/perception/detection/packages/roi_map_object_filter /home/arijin/cuttle.auto/ros/build/perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : perception/detection/packages/roi_map_object_filter/CMakeFiles/run_tests_roi_map_object_filter_rostest_test_test_roi_object_filter.test.dir/depend

