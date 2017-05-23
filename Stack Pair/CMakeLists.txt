cmake_minimum_required(VERSION 3.7)
project(Stack_Pair)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp stack_pair.template stack_pair.h)
add_executable(Stack_Pair ${SOURCE_FILES})