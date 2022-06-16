#include "extendedAvlTree.h"


#include <iostream>

AvlNode::AvlNode(int key) {
    this->left = NULL;
    this->right = NULL;
    this->key = key;
    this->height = 1;
}

// helper function which returns the max of the two inputs
int AvlNode::max(int n1, int n2) {
    return (n1> n2) ? n1 : n2;
}

// caluclate height difference of a given Node by calculating difference of heights of left and right subtree
int AvlNode::getHeightDifference() {
    int diff;
    if(this == NULL) {
        diff = 0;
    } else {
        diff = this->left->getHeight() - this->right->getHeight();
    }
    return diff;
}


// returns height of a given AVL Node
int AvlNode::getHeight() {
    if(this == NULL) {
        return 0;
    } else {
        return this->height;
    }
}


// insert a new node by recursively going to the sorted position which yields NULL
AvlNode* AvlNode::insert(int key) {
    if(this == NULL) {
        AvlNode* newNode = new AvlNode(key);
        return newNode;
    } else if(key > this->key) {
        this->right = this->right->insert(key);
    } else if(key < this->key) {
        this->left = this->left->insert(key);
    } else {
        return this;
    }
    // update heights of all other nodes
    this->height = 1 + this->max(this->left->getHeight(), this->right->getHeight());

    int diff = this->getHeightDifference();
    // check if rebalancing is necessary
    if(diff > 1) { // check which kind of rebalancing is necessary
        if(key > this->left->key){
            this->left = this->left->leftRotation();
            return this->rightRotation();
            
        } else if(key < this->left->key) {
            return this->rightRotation();
        }
    } else if(diff < -1) {// check which kind of rebalancing is necessary
        if(key > this->right->key) {
            return this->leftRotation();
        } else if(key < this->right->key) {
            this->right = this->right->rightRotation();
            return this->leftRotation();
        }
    }
    return this;
}



// perform a left rotation (see lecture)
AvlNode* AvlNode::leftRotation() {
    std::cout << "Do a left rotation on node " << this->key << "\n";
    AvlNode* rightNode = this->right;
    AvlNode* leftOfRightNode = rightNode->left;

    rightNode->left = this;
    this->right = leftOfRightNode;

    //update heights
    this->height = this->max(this->left->getHeight(), this->right->getHeight()) + 1;   
    rightNode->height = this->max((rightNode->left->getHeight()), rightNode->right->getHeight()) + 1; 
    return rightNode;
    
}


// perform a right rotation (see lecture)
AvlNode* AvlNode::rightRotation() {
    std::cout << "Do a right rotation on node " << this->key << "\n";
    AvlNode* leftNode = this->left;
    AvlNode* rightOfLeftNode = leftNode->right;

    leftNode->right = this;
    this->left = rightOfLeftNode;

    //update heights
    this->height = this->max(this->left->getHeight(), this->right->getHeight()) + 1;
    leftNode->height = this->max(leftNode->left->getHeight(), leftNode->right->getHeight()) + 1;
    return leftNode;
}






// function to print an AVL tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
std::string AvlNode::printPreorder() {
    std::stringstream output;
    output << "node:\t" << this->key << ",\t";
    output << "height:\t" << this->getHeight() << ",\t";
    output << "Diff:\t" << this->getHeightDifference() << "\n";

    if(this->left != NULL) {
        output << this->left->printPreorder();
    }
    if(this->right != NULL) {
        output << this->right->printPreorder();
    }
    return output.str();
}



        // Löschvorgang im AVL_Tree
        // Source: https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
        //************************************************************************************

AvlNode *AvlNode::minValueNode(AvlNode *node) {
    AvlNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}


AvlNode *AvlNode::deleteItem(int key) {
    std::cout << "Deleteing Root: " << key  << std::endl;
    AvlNode* root = this;

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->key )
        root->left = root->left->deleteItem(key);

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
    else if( key > root->key )
        root->right = root->right->deleteItem(key);

        // if key is same as root's key, then
        // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            AvlNode *temp = root->left ?
                         root->left :
                         root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            AvlNode* temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = root->right->deleteItem(temp->key);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max( root->left->getHeight(),
                           root->right->getHeight());

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = root->getHeightDifference();

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        root->left->getHeightDifference() >= 0)
        return root->rightRotation();

    // Left Right Case
    if (balance > 1 && root->left->getHeightDifference() < 0)
    {
        root->left = root->left->leftRotation();
        return root->rightRotation();
    }

    // Right Right Case
    if (balance < -1 && root->right->getHeightDifference() <= 0)
        return root->leftRotation();

    // Right Left Case
    if (balance < -1 && root->right->getHeightDifference() > 0)
    {
        root->right = root->right->rightRotation();
        return root->leftRotation();
    }

    return root;
        }



  
