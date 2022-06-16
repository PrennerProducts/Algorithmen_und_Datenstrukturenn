#include "binaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(int rootNodeKey) {
    BinaryTreeNode* root = new BinaryTreeNode(rootNodeKey);
    this->rootNode = root;
}

BinaryTreeNode* BinaryTree::insert(int key) {
    return this->rootNode->insert(key);
}

BinaryTreeNode* BinaryTree::search(int value) {
    BinaryTreeNode* node = this->rootNode;
    while(value != node->key && node != nullptr) {
        if(value > node->key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return node;
}

BinaryTreeNode* BinaryTree::deleteItem(int key) {
    return this->rootNode->deleteItem(key);
}

BinaryTreeNode* BinaryTree::findMin(BinaryTreeNode* node) {
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinaryTreeNode* BinaryTree::findMax(BinaryTreeNode* node) {
    while(node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// function to print a tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
std::string BinaryTree::printPreorder(BinaryTreeNode* node) {
    std::stringstream output;
    output << node->key << std::endl;

    if(node->left != nullptr) {
        output << this->printPreorder(node->left);
    }
    if(node->right != nullptr) {
        output << this->printPreorder(node->right);
    }
    return output.str();
}



std::string BinaryTree::printPreorder() {
    return this->printPreorder(this->rootNode);
}