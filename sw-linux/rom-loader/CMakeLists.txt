cmake_minimum_required(VERSION 3.7)

project(rom-loader LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG  "-g")

add_executable(rom-loader main.cpp serial.cpp)
