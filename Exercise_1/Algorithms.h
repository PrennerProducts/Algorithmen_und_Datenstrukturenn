//
// Created by McRebel on 27.05.2022.
//

#ifndef EXERCISE_1_ALGORITHMS_H
#define EXERCISE_1_ALGORITHMS_H

#include "Sortiment.h"
#include "Ware.h"


class Algorithms {
public:
    void quicksort_seriennummer(Ware *waren[], int warenItemsAnzahl);
    int partition(Ware *waren[], int low, int high);
    void quicksort(Ware *waren[], int low, int high);

    void bubblesort_gewicht(Ware* waren[], int array_size);

    void mergesort_alphabetisch(Ware* waren[], int array_size);
    void mergesort(Ware *waren[], int left, int right);
    void merge(Ware* waren[], int left, int middle, int right);

    void insertionsort_Einkaufspreis(Ware* waren[], int array_size);
    void insertionsort_Verkaufspreis(Ware* waren[], int array_size);




};


#endif //EXERCISE_1_ALGORITHMS_H
