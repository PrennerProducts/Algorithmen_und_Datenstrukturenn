//
// Created by McRebel on 29.05.2022.
//
                                                                        // Komplexitätsklasse: 0(n log(n))
void merge(int array[], int left, int middle, int right) {      // Merge zusammenführen
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1];                                          // Dekleration und Definition von remporären Arrays: linkes und rechtes Array
    int rightArray[n1];

    for(int i= 0; i < n1; i++) {
        leftArray[i] = array[left + i];                         // Das linke und rechte array wird mit den daten von dem OrginalenArray initialisiert
    }
    for(int j = 0; j < n2; j++) {
        rightArray[j] = array[middle + j + 1];
    }

    int k = 0, l = 0, m = left;
    while(k < n1 && l < n2){
        if(leftArray[k] <= rightArray[l]) {                 // Schlüsselstelle:
            array[m] = leftArray[k];
            k++;
        } else {                                           // Schlüsselstelle:    worst case 0(n log(n))
            array[m] = rightArray[l];
            l++;
        }
        m++;
    }

    while(k<n1){
        array[m] = leftArray[k];            // Zuweisung der verbleibenden Elemente von den temporären Array in das OrginaleArray
        k++;
        m++;
    }

    while(l<n2){
        array[m] = rightArray[l];          // Zuweisung der verbleibenden Elemente von den temporären Array in das OrginaleArray
        l++;
        m++;
    }
}

void mergeSort(int array[], int left, int right) {      // mergeSort Funktion, left= Index von Subarray, right= Index von Subarray, array[]= das Array das sortiert werden sollte.
    if(left < right) {                                  // ueberprüfung on left<right (ansonsten abbruchkriterium der Rekursion)
        int middle = left+(right-left)/2;
        mergeSort(array, left, middle);             // Rekursiver aufruf von mergeSort
        mergeSort(array, middle+1, right);           // Rekursiver aufruf von mergeSort
        merge(array, left, middle, right);              // aufruf von merge
    }
}