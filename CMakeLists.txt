cmake_minimum_required(VERSION 3.9)
project(project1)
include(ExternalProject)

# Set GoogleTest directory
set(GTEST_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest)

# Set compiler flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors -g")

# Include GoogleTest into the build
find_package(Threads)
ExternalProject_Add(googletest
    DOWNLOAD_NO_PROGRESS 1
    UPDATE_DISCONNECTED 1
    GIT_REPOSITORY https://github.com/google/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GTEST_DIRECTORY}
)

# Include the GoogleTest headers and libraries
include_directories(${GTEST_DIRECTORY}/include)
link_directories(${GTEST_DIRECTORY}/lib)

# Include project headers
include_directories(./include)

set(SOURCE_FILES
    src/Sudoku.cpp
    tests/main.cpp
    tests/SudokuTest.cpp
)

# Make the project root directory the working directory when we run
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(testing ${SOURCE_FILES})
add_dependencies(testing googletest)
target_link_libraries(testing gtest ${CMAKE_THREAD_LIBS_INIT})