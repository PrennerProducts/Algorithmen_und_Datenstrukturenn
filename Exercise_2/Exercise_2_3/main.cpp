#include "extendedAvlTree.h"
#include <iostream>

int main() {
    AvlNode* root = new AvlNode(10);
    // always give the root, as it could be changed with any insertion (in comparison to BST!)
    root = root->insert(15);
    root = root->insert(5);
    root = root->insert(8);
    root = root->insert(3);
    
    /* -- Scenarion 1 - rightRotation -- */
    //root = root->insert(2);

    /* -- Scenarion 2 - leftRotation -- */
    // root = root->insert(17);
    // root = root->insert(19);

    /* -- Scenarion 3 - rightRotation, then leftRotation -- */
    // root = root->insert(17);
    // root = root->insert(16);

    /* -- Scenarion 4 - leftRotation, then rightRotattion -- */
    // root = root->insert(17);
    // root = root->insert(6);
    // root = root->insert(7);

    std::cout << root->printPreorder();
    std::cout << "Perfectly balanced! As all things should be!\n";

    root->deleteItem(3);
    std::cout << root->printPreorder();
    std::cout << "Perfectly balanced! As all things should be!\n";
    return 0;
}
