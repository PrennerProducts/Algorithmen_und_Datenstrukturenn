#include <vector>
#include <string>
#include <iostream>

#include "item.h"

#pragma once

/*  Class for Backpack, consisting of a maxWeight that can be put into a backpack, one that shows the weight that is currently in the backpack, 
    a vector representing all available items and a vector for the items that have been placed in the backpack.
    There is also a constructor to increase the ease/convenience of use, as well as functions to:
        * sort the available Items based on their getRatio()
        * greedily pack the backpack
        * get the value of all packed items
*/
struct Backpack {
    int maxWeight;
    std::vector<Item> availableItems;
    int currentWeight;
    std::vector<Item> packedItems;

    Backpack(float maxWeight, std::vector<Item>availableItems): maxWeight(maxWeight), availableItems(availableItems), currentWeight(0){};
    void sortAvailableItems();
    void greedyPack();
    int getValuePacked();
    void printItems();
};