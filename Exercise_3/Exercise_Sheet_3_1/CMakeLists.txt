cmake_minimum_required(VERSION 3.21)
project(Exercise_Sheet_3_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise_Sheet_3_1
        edge.cpp
        edge.h
        extendedGraph.cpp
        extendedGraph.h
        main.cpp)
