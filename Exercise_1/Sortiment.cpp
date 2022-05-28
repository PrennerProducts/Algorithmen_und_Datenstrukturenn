//
// Created by McRebel on 26.05.2022.
//

#include "Sortiment.h"
#include <iostream>
#include "Algorithms.h"
#include "Sortiment.h"

void Sortiment::addWare(Ware *ware) {
    for (int i = 0; i < 10; ++i) {
       // std::cout << "Wahre" << " Loop" << std::endl;
        if(waren[i] == nullptr  && Sortimentcout > 0){
           waren[i] = ware;
            Sortimentcout--;
           std::cout << "Wahre" << " hinzugefuegt" << std::endl;
            break;
        }
        else if(Sortimentcout < 1) {
            std::cout << "Waren sind bereits Voll, daher kein hinzufuegen moeglich!" << std::endl;
            break;
        }
    }
}




void Sortiment::sort(int modus) {
    Algorithms algorithms;

    if(modus == 1){
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        algorithms.quicksort_seriennummer(this->waren, 10);



    }
    else if(modus == 2){
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus:" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        algorithms.bubblesort_gewicht(this->waren, 10);




    }
    else if(modus == 3){
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        algorithms.mergesort_alphabetisch(this->waren, 10);


    }
    else if(modus == 4){
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante." << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        algorithms.insertionsort_Einkaufspreis(this->waren, 10);

    }
    else if(modus == 5){
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante." << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        algorithms.insertionsort_Verkaufspreis(this->waren, 10);

    }else{
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Ungültiger Sortiermodus! (Range: 1-5)" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
    }


}

void Sortiment::printArray(Ware* array[], int arrayLength, std::string heading) {
    std::cout << "========== " << heading << " ==========" << std::endl;
    for(int i = 0; i < arrayLength; i++) {
        if(i >= 0) {
            std::cout << " [ ";
        }
        std::cout << "Bezeichnung: " << array[i]->getBezeichnung() << " Seriennummer: " << array[i]->getSeriennummer() << " Gewicht: " <<
        array[i]->getGewicht() << " Einkaufspreis: " << array[i]->getEinkaufspreis() << " Verkaufspreis: " << array[i]->getVerkaufspreis() <<
        " ]" <<    std::endl;
        //std::cout << array[i]->getSeriennummer() << std::endl;
    }
    std::cout << std::endl << "==============================================" << std::endl;

}


