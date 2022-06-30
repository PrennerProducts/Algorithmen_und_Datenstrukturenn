#include "item.h"
#include "backpack.h"
#include <vector>

int main() {
    std::vector<Item> items = { //  creation of the availableItems
        {"1", 5, 8}, {"2", 5, 8}, {"3", 6, 6}, {"4", 8, 5}, {"5", 10, 10}, {"6", 11, 5},
        {"7", 12, 10}, {"8", 15, 17}, {"9", 15, 20}, {"10", 30, 20}
    };
    Backpack bp((float)20, items);  //  creation of the backpack, utilizing the constructor
    bp.greedyPack();                //  greedily pack backpack
}