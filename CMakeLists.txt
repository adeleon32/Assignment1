# CMakeList.txt : CMake project for Assignment1, include source and define
# project specific logic here.

cmake_minimum_required(VERSION 3.20)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

add_executable(Assignment1 Assignment1.cpp Assignment1.h)
