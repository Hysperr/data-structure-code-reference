cmake_minimum_required(VERSION 3.7)
project(Bag_Linked_List_Template___Iterator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        bag.h
        bag.template
        main.cpp
        node.h
        node.template)

add_executable(Bag_Linked_List_Template___Iterator ${SOURCE_FILES})
