#include "binaryTreeNode.h"

#include <iostream>

BinaryTreeNode::BinaryTreeNode(int key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

BinaryTreeNode* BinaryTreeNode::insert(int key) {
    if(key > this->key) {
        if(this->right == nullptr) {
            BinaryTreeNode* temp = new BinaryTreeNode(key);
            this->right = temp;
            return this->right;
        }
        this->right->insert(key);
    } else {
        if(this->left == nullptr) {
            BinaryTreeNode* temp = new BinaryTreeNode(key);
            this->left = temp;
            return this->left;
        }
        this->left->insert(key);
    }
    return this;
}

BinaryTreeNode* BinaryTreeNode::deleteItem(int key) {
    BinaryTreeNode* node = this;

    if(node == nullptr) {
        return this;
    } else if(key < node->key) {
        node->left = node->left->deleteItem(key);
    } else if(key > node->key) {
        node->right = node->right->deleteItem(key);
    } else {
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if(node->left == nullptr) { // only children in right subtree
            BinaryTreeNode* temp = node;
            node = node->right;
            delete temp;
        } else if(this->right == nullptr) { // only children in left subtree
            BinaryTreeNode* temp = node;
            node = node->left;
            delete temp;
        } else { // we have to keep the BST structure, here, we look for the minimum in the right subtree (see lecture)
            BinaryTreeNode* temp = node->right;
            while(temp->left != nullptr) {
                temp = temp->left;
            }
            node->key = temp->key;
            node->right = node->right->deleteItem(temp->key);
        }
    }
    return node;
}