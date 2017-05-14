cmake_minimum_required(VERSION 3.3)
project(BagwithLinkList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bag3.cpp
    bag3.h
    main.cpp
    node1.cpp
    node1.h)

add_executable(BagwithLinkList ${SOURCE_FILES})