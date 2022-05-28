//
// Created by McRebel on 27.05.2022.
//

#include "Algorithms.h"
#include "Sortiment.h"
#include "Ware.h"
#include <iostream>


//************************ -- QuickSort -- *************************
//Source: https://www.geeksforgeeks.org/quick-sort/

void Algorithms::quicksort_seriennummer(Ware *waren[], int warenItemsAnzahl) {

    quicksort(waren, 0, warenItemsAnzahl - 1);
}

int Algorithms::partition (Ware *waren[], int low, int high){
    Ware *pivot = waren[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (waren[j]->getSeriennummer() < pivot->getSeriennummer()){
            i++;
            std::swap(waren[i], waren[j]);
        }
    }
    std::swap(waren[i + 1], waren[high]);
    return (i + 1);
}

void Algorithms::quicksort(Ware *waren[], int low, int high){

    if (low < high){
        int pi = partition(waren, low, high);
        quicksort(waren, low, pi - 1);
        quicksort(waren, pi + 1, high);
    }
}

//************************ -- BubbleSort -- *************************
//Source: Sakai

void Algorithms::bubblesort_gewicht(Ware* waren[], int array_size) {
    bool swapped = false;
    do {
        swapped = false;
        for(int i=0; i < array_size-1;i++) {
                if (waren[i]->getGewicht() > waren[i + 1]->getGewicht()) {
                    std::swap(waren[i], waren[i+1]);
                    swapped = true;
            }
        }
    } while (swapped);
    }


//************************ -- MergeSort -- *************************
//Source: Sakai  und teilweise für merge:  https://www.geeksforgeeks.org/merge-sort/?ref=gcse

void Algorithms::mergesort_alphabetisch(Ware* waren[], int array_size){
    mergesort(waren, 0, array_size -1);
}

void Algorithms::mergesort(Ware *waren[], int left, int right) {
    if(left < right) {
        int middle = (right+left)/2;
        mergesort(waren,left, middle);
        mergesort(waren, middle+1, right);
        merge(waren, left, middle, right);
    }
}


void Algorithms::merge(Ware* waren[], int left, int middle, int right) {
    int i, j, k;
    Ware *tempWare[10];
    i = left;
    k = left;
    j = middle + 1;
    while(i <= middle && j <= right) {
        if(waren[i]->getBezeichnung() < waren[j]->getBezeichnung()) {
            tempWare[k] = waren[i];
            k++;
            i++;
        }
        else {
            tempWare[k] = waren[j];
            k++;
            j++;
        }
    }
    while(i <= middle) {
        tempWare[k] = waren[i];
        k++;
        i++;
    }
    while(j <= right) {
        tempWare[k] = waren[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++) {
        waren[i] = tempWare[i];
    }

}



//************************ -- InsertionSort -- *************************
//Source: Sakai

void Algorithms::insertionsort_Einkaufspreis(Ware* waren[], int array_size) {
    int i = 0;
    while(i<array_size){
        int j = i;
        while(j > 0 && waren[j-1]->getEinkaufspreis() > waren[j]->getEinkaufspreis()){
            std::swap(waren[j], waren[j-1]);
        //    double currentValue = waren[j]->getEinkaufspreis();
        //    waren[j]->setEinkaufspreis(waren[j-1]->getEinkaufspreis());
        //    waren[j-1]->setEinkaufspreis(currentValue);
            j--;
        }
        i++;
    }
}

//Source: Sakai
void Algorithms::insertionsort_Verkaufspreis(Ware* waren[], int array_size) {
    int i = 0;
    while(i<array_size){
        int j = i;
        while(j > 0 && waren[j-1]->getVerkaufspreis() > waren[j]->getVerkaufspreis()){
            std::swap(waren[j], waren[j-1]);
            j--;
        }
        i++;
    }

}

















