cmake_minimum_required(VERSION 3.21)
project(GitHub_Algorithmen_Datenstrukturen)

set(CMAKE_CXX_STANDARD 14)

include_directories(Exercise_1)

add_executable(GitHub_Algorithmen_Datenstrukturen
        Exercise_1/Algorithms.cpp
        Exercise_1/Algorithms.h
        Exercise_1/main.cpp
        Exercise_1/Sortiment.cpp
        Exercise_1/Sortiment.h
        Exercise_1/Ware.cpp
        Exercise_1/Ware.h Exercise_1/bubbleSort_commented.cpp Exercise_1/insertionSort_commented.cpp Exercise_1/mergeSort_commented.cpp Exercise_2/HelperFunktions.cpp Exercise_2/HelperFunktions.h Exercise_2/Exercise_2_1/main.cpp Exercise_2/Exercise_2_1/binaryTree.cpp Exercise_2/Exercise_2_1/binaryTree.h Exercise_2/Exercise_2_1/binaryTreeNode.cpp Exercise_2/Exercise_2_1/binaryTreeNode.h)
