cmake_minimum_required(VERSION 3.21)
project(Exercise_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise_1
        Ware.cpp
        Ware.h main.cpp Sortiment.cpp Sortiment.h Algorithms.cpp Algorithms.h)
