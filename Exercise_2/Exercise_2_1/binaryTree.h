//
// Created by McRebel on 02.06.2022.
//

#ifndef GITHUB_ALGORITHMEN_DATENSTRUKTUREN_BINARYTREE_H
#define GITHUB_ALGORITHMEN_DATENSTRUKTUREN_BINARYTREE_H


#include "binaryTreeNode.h"
#include <string>
#include <sstream>

#pragma once


class BinaryTree {
public:
    BinaryTreeNode* rootNode;

    BinaryTree(int rootNodeKey);

    BinaryTreeNode* search(int value);
    BinaryTreeNode* insert(int key);
    BinaryTreeNode* deleteItem(int key);
    BinaryTreeNode* findMin(BinaryTreeNode* node);
    BinaryTreeNode* findMax(BinaryTreeNode* node);
    std::string printPreorder(BinaryTreeNode* node);
    std::string printPreorder();

};




// std::string printPreorder(BinaryTreeNode* node);
// /*  --  Your TODO   --  */
// std::string printPostorder(BinaryTreeNode* node);
// std::string printInorder(BinaryTreeNode* node);

#endif //GITHUB_ALGORITHMEN_DATENSTRUKTUREN_BINARYTREE_H
