//
// Created by McRebel on 03.06.2022.
//

#ifndef EXERCISE_2_2_DOUBLYLINKEDLIST_H
#define EXERCISE_2_2_DOUBLYLINKEDLIST_H

#include "doublyLinkedList.h"
#include "extendedListItem.h"



class doublyLinkedList {
public:
    doublyLinkedList();

    ExtendedListItem* head;
    ExtendedListItem* tail;
    void insertSorted(int key);

    void append(doublyLinkedList* appendingList);
    void splice(doublyLinkedList* insertingList, int position);
    void insertAtStart(int key);
    void insertAtEnd(int key);
    void deleteItem(int key);
    void print();



};


#endif //EXERCISE_2_2_DOUBLYLINKEDLIST_H
