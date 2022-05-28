//
// Created by McRebel on 26.05.2022.
//

#ifndef EXERCISE_1_SORTIMENT_H
#define EXERCISE_1_SORTIMENT_H

#include "Ware.h"
#include <iostream>




class Sortiment {
public:
    Ware* waren[10] = {};
    int Sortimentcout = 10;


    Sortiment(){
        std::cout << "Calling Sortiment Konstructor" << std::endl;
    }
    ~Sortiment(){
        std::cout << "Calling Sortiment Destructor" << std::endl;
    }


    void addWare(Ware* ware);

    void sort(int modus);


    void printArray(Ware* array[], int arrayLength, std::string heading);

};



#endif //EXERCISE_1_SORTIMENT_H
