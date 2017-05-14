cmake_minimum_required(VERSION 3.3)
project(BagTemplatewithIterator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bag5.h
    bag5.template
    main.cpp
    node2.h
    node2.template)

add_executable(BagTemplatewithIterator ${SOURCE_FILES})