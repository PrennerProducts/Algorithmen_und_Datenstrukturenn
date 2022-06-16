cmake_minimum_required(VERSION 3.21)
project(Exercise_2_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise_2_2
        extendedListItem.cpp
        main.cpp
        doublyLinkedList.cpp doublyLinkedList.h)
