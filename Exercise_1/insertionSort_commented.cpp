//
// Created by McRebel on 29.05.2022.
//

void insertionSortBase(int array[], int array_size, bool asc) {
    int i = 0;
    while(i<array_size){
        int j = i;
        while(j > 0 && array[j-1] > array[j]){
            int currentValue = array[j];
            array[j] = array[j-1];
            array[j-1] = currentValue;
            j--;
        }
        i++;
    }
}

void insertionSortOptimized(int array[], int array_size, bool asc) {
    int i = 0;
    while(i<array_size){
        int x = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > x){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = x;
        i++;
    }
}

void insertionSortRecursive(int array[], int array_size, bool asc) {
    if(array_size > 0) {
        insertionSortRecursive(array, array_size-1, true);
        int x = array[array_size-1];
        int j = array_size-2;
        while( j >= 0 && array[j] > x){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = x;
    }
}