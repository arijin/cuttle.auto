cmake_minimum_required(VERSION 2.8.3)
project(quick_start)

find_package(autoware_build_flags REQUIRED)

set(CMAKE_CXX_FLAGS "-O2 -Wall ${CMAKE_CXX_FLAGS}")

catkin_package(
)
