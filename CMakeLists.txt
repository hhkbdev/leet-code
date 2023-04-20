cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(main src/31-next-permutation.cpp)

set_target_properties(main PROPERTIES CXX_STANDARD 17)