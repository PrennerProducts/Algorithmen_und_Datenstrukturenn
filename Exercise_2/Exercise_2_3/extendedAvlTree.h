#include <string>
#include <iostream>
#include <sstream>

#pragma once

class AvlNode {
    public:
        int key;
        AvlNode* left;
        AvlNode* right;
        int height;

        AvlNode(int key);

        int max(int n1, int n2);
        int getHeightDifference();
        int getHeight();

        AvlNode* insert(int key);
        AvlNode* leftRotation();
        AvlNode* rightRotation();

        std::string printPreorder();


        AvlNode* deleteItem(int key);
        AvlNode * minValueNode(AvlNode* node);


};

