#include "backpack.h"

/*  Optimized insertion sort algorithm utilizing the Item's getRatio() function */
void Backpack::sortAvailableItems() {
   int i = 0;
    while(i<(int)this->availableItems.size()) {
        Item x = this->availableItems[i];
        int j = i-1;
        while(j >= 0 && this->availableItems[j].getRatio() < x.getRatio()) {
            this->availableItems[j+1] = this->availableItems[j];
            j--;
        }
        this->availableItems[j+1] = x;
        i++;
    }
}


/*  Iterates through all packed items and returns the total value   */
int Backpack::getValuePacked() {
    int total = 0;
    for(int i = 0; i < (int)this->packedItems.size(); i++) {
        total += this->packedItems[i].value;
    }
    return total;
}

/*  the algorithm to pack the backpack  */
void Backpack::greedyPack() {
    this->packedItems.clear();  /*  resets the packedItems -> removes all elements! */
    this->currentWeight = 0;  /*  ...and also sets the current weight to 0.0  */

    this->sortAvailableItems(); //  sort the available items first!

    std::cout << "Backpack has been packed:\n"; //  output
    std::cout << "\t\tWeight\tValue\n"; //  output
    std::cout << "---------------------------------------------\n"; //  output

    for(int i = 0; i < (int)this->availableItems.size(); i++) { //  iterate through all available items
        if(this->currentWeight + (float)this->availableItems[i].weight <= this->maxWeight) {    //  check if the item still fits in the backpack
            this->packedItems.push_back(this->availableItems[i]);                   //  and if so, put it in there (by adding it to this->packedItems)
            currentWeight += this->availableItems[i].weight;                        //  adjust currentWeight accordingly
            std::cout << "\t" << this->availableItems[i].name << ":\t" << this->availableItems[i].weight << "\t" << this->availableItems[i].value << "\n";  //  output
        }
        if( (this->currentWeight - this->maxWeight) == 0) { //  if the backpack is completely full, the loop can be exited - small optimization
            break;
        }
    }
    std::cout << "---------------------------------------------\n"; //  output
    std::cout << "\tTotal:\t" << this->currentWeight << "\t" << this->getValuePacked() << "\n"; //  output
}


void Backpack::printItems() {
    for(int i = 0; i < (int)this->availableItems.size(); i++) {
        std::cout << this->availableItems[i].name << "\t" << this->availableItems[i].weight << "\t" << this->availableItems[i].value << "\t" << this->availableItems[i].getRatio() << "\n";
    }
}