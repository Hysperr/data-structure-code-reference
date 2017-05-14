cmake_minimum_required(VERSION 3.3)
project(BagwithLinkList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        bag_linked_list.cpp
        bag_linked_list.h
        bagLL_demo.cpp
        node.cpp
        node.h)

add_executable(BagwithLinkList ${SOURCE_FILES})