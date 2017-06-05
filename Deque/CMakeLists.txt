cmake_minimum_required(VERSION 3.7)
project(Deque)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp deque.template deque.h)
add_executable(Deque ${SOURCE_FILES})