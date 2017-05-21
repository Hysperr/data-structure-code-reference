cmake_minimum_required(VERSION 3.7)
project(Sequence)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        sequence.cpp
        sequence.h
        sequence_exam.cpp)
add_executable(Sequence ${SOURCE_FILES})