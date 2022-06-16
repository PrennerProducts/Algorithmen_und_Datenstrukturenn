#include <string>

#pragma once

class ExtendedListItem {
public:
    ExtendedListItem* next;
    ExtendedListItem* previous;
    ExtendedListItem(int key);
    std::string toString();

    int key;
};