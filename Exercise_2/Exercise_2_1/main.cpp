//
// Created by McRebel on 02.06.2022.
//

#include <string>
#include <iostream>
#include "binaryTreeNode.h"
#include "binaryTree.h"


int main() {
    BinaryTree christmasTree(7);
    christmasTree.insert(5);
    christmasTree.insert(3);
    christmasTree.insert(15);
    christmasTree.insert(13);
    christmasTree.insert(17);
    christmasTree.insert(12);
    christmasTree.insert(14);
    christmasTree.insert(16);
    christmasTree.insert(19);

    std::cout << christmasTree.printPreorder() << "\n";
    /*  --  Deletion of a leaf  --  */
    christmasTree.deleteItem(7);
    std::cout << christmasTree.printPreorder() << "\n";
    /*  --  Deletion of a node with one child  --  */
    //christmasTree.deleteItem(17);
    //std::cout << christmasTree.printPreorder() << "\n";
    /*  --  Deletion of a node with two children  --  */
    //christmasTree.deleteItem(15);
    //std::cout << christmasTree.printPreorder() << "\n";
}