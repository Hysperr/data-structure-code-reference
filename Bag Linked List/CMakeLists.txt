cmake_minimum_required(VERSION 3.7)
project(Bag_Linked_List)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    bag_linked_list.cpp
    bag_linked_list.h
    main.cpp
    node.cpp
    node.h)

add_executable(Bag_Linked_List ${SOURCE_FILES})