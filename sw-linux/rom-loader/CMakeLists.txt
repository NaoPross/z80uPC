cmake_minimum_required(VERSION 3.7)

project(rom-loader LANGUAGES CXX)

add_executable(rom-loader main.cpp serial.cpp)
