//
// Created by McRebel on 29.05.2022.
//

void insertionSortBase(int array[], int array_size, bool asc) {         // bool asc wird im Code nicht verwendet!
    int i = 0;
    while(i<array_size){                                                // 1. Schlüsselstelle: While-Schleife mit array_size (also n) durchläufen. (Kmplexität bist jetzt ist 0(n))
        int j = i;
        while(j > 0 && array[j-1] > array[j]){                          // 2. Schlüsselstelle: Im best case (Array verkehrt Sortiert) 0=(n)*0(1)  = 0(n), im worst case: 0(n) * O(n-1) = O(n²)
            int currentValue = array[j];                                // Zuweisen ist quasi "kostenlos" mit 0(1)
            array[j] = array[j-1];                                      // Zuweisen ist quasi "kostenlos" mit 0(1)
            array[j-1] = currentValue;                                  // Zuweisen ist quasi "kostenlos" mit 0(1)
            j--;                                                        // dekrement j
        }
        i++;                                                            // inkrement i
    }
}                                                                       // Komplexitätsklasse: 0(n²)

void insertionSortOptimized(int array[], int array_size, bool asc) {
    int i = 0;
    while(i<array_size){                                                // Schlüsselstelle: n durchläufe, im best case 0(n), wenn bereits Sortiert
        int x = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > x){                                  // Schlüsselstelle: Wenn das Array bereits Sortiert ist wird die 2. While Schleife nie ausgeführt! = best case = 0(n)
            array[j+1] = array[j];                                      // Im worst case Komplexitätsklasse (Konstanten werden vernachlässigt) = 0(n²)
            j--;
        }
        array[j+1] = x;
        i++;
    }
}

void insertionSortRecursive(int array[], int array_size, bool asc) {
    if(array_size > 0) {                                                    // Schlüsselstelle: es werden n Rekursionen ausgeführt!
        insertionSortRecursive(array, array_size-1, true);      // Rekursionsaufruf mit array_size -1
        int x = array[array_size-1];
        int j = array_size-2;
        while( j >= 0 && array[j] > x){                                     // Schlüsselstelle, im worst case für jede der n Rekursionen wir die While-Schleife n-2 = 0(n)*O(n-2) = 0(n²)
            array[j+1] = array[j];                                          // Zuweisungen haben 0(1) also quasi "kostenlos"
            j--;
        }
        array[j+1] = x;
    }
}

// Komplexitätsklasse: O(n²)