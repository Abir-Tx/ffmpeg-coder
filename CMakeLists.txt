# Use cmake -G "Mingw Makefiles" before using Cmake on windows with g++ (mingw) compiler

cmake_minimum_required(VERSION 3.12)
project(ffmpeg-coder VERSION 1.0.0)
message("FFMPEG CODER BUILD PROCESS")
message("--------------------------")

set(CMAKE_CXX_FLAGS "-Wall -v")
include_directories(include/ffmpeg-coder lib)

# Placing the executable in the bin dir
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


file(GLOB SOURCES "src/*.cpp")
add_executable(ffmpeg-coder ${SOURCES})

# add_executable(ffmpeg-coder src/ffmpeg-coder.cpp src/test.cpp)

