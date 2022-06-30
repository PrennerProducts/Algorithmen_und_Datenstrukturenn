#include "item.h"

/*  function that returns the value/weight ratio of an item as float; used to sort items    */
float Item::getRatio() {
    return ((float)this->value / (float)this->weight);
};
