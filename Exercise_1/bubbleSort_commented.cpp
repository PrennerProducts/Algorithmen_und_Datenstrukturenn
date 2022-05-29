//
// Created by McRebel on 29.05.2022.
//

// BubbleSort:   Komplexität = O(n²)


void bubbleSort(int* array, int array_size, bool asc) {     // Funktion mit einem int array , und der array_size, der bool Wert asc wird in der Funktion nicht verwendet daher kann er weggelassen werden!
    bool swapped = false;                                   //  Bool Variable swapped wird deklariert und mit false initialisiert.
    do {
        swapped = false;                                    // vor jeder Iteration wird swapped auf false gesetzt. (Falls in der Schleife nicht mehr geswapped wird = Abbruchkriterium der While-Schleife)
        for(int i=0; i<array_size-1;i++){                   // Schleife mit array_size durchläufen.
            if(array[i] > array[i+1]){                      // Überprüfung, ob der Wert an der Stelle[0] > Stelle[1], im besten Fall ist das Array bereits sortiert und swapped bleibt auf False
                int temp = array[i];                        // dann muss die For-Schleife nur einmal durchlaufen und die Komplexität ist: O(n)
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = true;
            }
        }
    } while (swapped == true);                              // Im worst case (Wenn das Array genau umgekerht Sortiert ist) muss für jede Iteration in der for-Schleife (Anzahl = n), die while-Schleife
}                                                           // zuerst n Mal ausgeführt werden, bei der nächsten iteration n-1, bei der nächsten n-2 .....  bist n-n (also 0 Mal).
                                                            // Bei der Landaunotation werden die Therme -1 , -2 usw weggelassen. Daher ist die Komplexität im worst case: n*n d.h. O(n*n) = 0(n²)

// Komplexitätsklasse = O(n²)