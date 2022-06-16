#include "doublyLinkedList.h"
#include <string>
#include <iostream>

int main() {

    doublyLinkedList list;

    list.insertSorted(5);
    list.insertSorted(7);
    list.insertSorted(19);
    list.insertSorted(54);
    list.insertSorted(1);
    list.insertSorted(9);
    list.insertSorted(17);
    list.insertSorted(17);
    list.insertSorted(108);
    list.insertSorted(8);

    list.print();


    doublyLinkedList list2;
    list2.insertSorted(2);
    list2.insertSorted(3);
    list2.insertSorted(4);

    list2.print();

    list.splice(&list2, 4);

    list.print();

    list2.print();




}