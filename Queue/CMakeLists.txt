cmake_minimum_required(VERSION 3.7)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp queue.template queue.h)
add_executable(Queue ${SOURCE_FILES})