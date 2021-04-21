cmake_minimum_required(VERSION 3.12)
project(ffmpeg-coder VERSION 1.0.0)
message("FFMPEG CODER BUILD PROCESS")
message("--------------------------")

set(CMAKE_CXX_FLAGS "-Wall -v")
include_directories(include/ffmpeg-coder lib)

# Placing the executable in the bin dir
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)



add_executable(ffmpeg-coder src/ffmpeg-coder.cpp)

