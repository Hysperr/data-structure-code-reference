cmake_minimum_required(VERSION 3.3)
project(Complex_Numbers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp complex_number.cpp complex_number.h)
add_executable(Complex_Numbers ${SOURCE_FILES})