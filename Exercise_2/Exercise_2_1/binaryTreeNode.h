//
// Created by McRebel on 02.06.2022.
//

#ifndef GITHUB_ALGORITHMEN_DATENSTRUKTUREN_BINARYTREENODE_H
#define GITHUB_ALGORITHMEN_DATENSTRUKTUREN_BINARYTREENODE_H


class BinaryTreeNode {
public:
    int key;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int key);

    BinaryTreeNode* insert(int key);
    BinaryTreeNode* deleteItem(int key);
};

#endif //GITHUB_ALGORITHMEN_DATENSTRUKTUREN_BINARYTREENODE_H
