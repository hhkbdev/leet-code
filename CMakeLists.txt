# CMake version
cmake_minimum_required(VERSION 3.24)

# Project information
project(
        MyProject
        VERSION 1.0
        DESCRIPTION "My project"
        LANGUAGES CXX
        )

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(tests)