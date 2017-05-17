cmake_minimum_required(VERSION 3.3)
project(BagTemplatewithIterator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        bag.h
        bag.template
    main.cpp
        node.h
        node.template)

add_executable(BagTemplatewithIterator ${SOURCE_FILES})