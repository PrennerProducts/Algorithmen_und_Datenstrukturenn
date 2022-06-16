#include <iostream>
#include <sstream>

#include "extendedListItem.h"


ExtendedListItem::ExtendedListItem(int key) {
    this->key = key;
    this->next = nullptr;
    this->previous = nullptr;

}

std::string ExtendedListItem::toString() {
    std::stringstream s;
    if(this->previous != nullptr) {
        s << "(" << this->previous->key << ") <-> ";
    }
    s << this->key;
    if(this->next != nullptr) {
        s << " <-> (" << this->next->key << ")";
    }
    s << std::endl;
    return s.str();
}


