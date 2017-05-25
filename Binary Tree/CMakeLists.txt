cmake_minimum_required(VERSION 3.7)
project(Binary_Tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp binary_tree.template binary_tree.h build_tree.cpp build_tree.h)
add_executable(Binary_Tree ${SOURCE_FILES})