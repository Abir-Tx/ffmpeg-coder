cmake_minimum_required(VERSION 3.12)
project(ffmpeg-coder VERSION 1.0.0)
message("FFMPEG CODER BUILD PROCESS")
message("--------------------------")


include_directories(include/ffmpeg-coder lib)




add_executable(ffmpeg-coder src/ffmpeg-coder.cpp)

