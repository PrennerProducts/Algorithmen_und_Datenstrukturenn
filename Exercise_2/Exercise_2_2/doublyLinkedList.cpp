//
// Created by McRebel on 03.06.2022.
//

#include <iostream>
#include "doublyLinkedList.h"


doublyLinkedList::doublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;

}

void doublyLinkedList::insertSorted(int key) {
    ExtendedListItem* prev = nullptr;
    ExtendedListItem* current = this->head;
    ExtendedListItem* newItem = new ExtendedListItem(key); //create the new ExtendedListItem

    if(this->head == nullptr || key < this->head->key) {// list is empty OR new is samller than head->key => insert at front
        this->insertAtStart(key);
        return;
    }

    if(key > this->tail->key) { // new key is larger than tail->key=> insert at end
        this->insertAtEnd(key);
        return;
    }
    // search for correct position to insert
    bool inserted = false;
    while(inserted == false) {
        prev = current;
        current = current->next;

        if(key < current->key) {
            prev->next = newItem;
            newItem->previous = prev;
            newItem->next = current;
            current->previous = newItem;

            inserted = true;
        } else {
            continue;
        }
    }
}

void doublyLinkedList::append(doublyLinkedList *appendingList) {
    if(appendingList->head != nullptr && appendingList->tail != nullptr) {
        this->tail->next = appendingList->head;
        appendingList->head->previous = this->tail;
        this->tail = appendingList->tail;

        // "emptying" the appendingList by setting both head and tail to nullptr
        appendingList->head = nullptr;
        appendingList->tail = nullptr;
    }
}

void doublyLinkedList::splice(doublyLinkedList *insertingList, int position) {
    if(insertingList->head != nullptr & insertingList->tail != nullptr) {
        ExtendedListItem* current = nullptr;
        current = this->head;
        // find the correct position to start spliceing
        for(int i = 0; i < position; i++) {
            current = current->next;
        }
        // set the pointers correctly
        current->previous->next = insertingList->head;
        insertingList->head->previous = current->previous;
        insertingList->tail->next = current;
        current->previous = insertingList->tail;

        // clear the inserting list
        insertingList->head = nullptr;
        insertingList->tail = nullptr;
    }
}

void doublyLinkedList::insertAtStart(int key) {
    ExtendedListItem* temp = new ExtendedListItem(key);

    if(this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else {
        this->head->previous = temp;
        temp->next = this->head;
        this->head = temp;
    }
}

void doublyLinkedList::insertAtEnd(int key) {
    ExtendedListItem* temp = new ExtendedListItem(key);

    if(this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else {
        this->tail->next = temp;
        temp->previous = this->tail;
        this->tail = temp;
    }
}

void doublyLinkedList::deleteItem(int key) {
    ExtendedListItem* current = this->head;

    while(current != nullptr) {
        if(key == current->key) {
            if(current->previous == nullptr) { // item to delete is head
                current->next->previous = nullptr;
                this->head = current->next;
            } else {
                current->previous->next = current->next;
            }

            if(current->next == nullptr) { // item to delete is tail
                current->previous->next = nullptr;
                this->tail = current->previous;
            } else {
                current->next->previous = current->previous;
            }

            delete current;
            return;
        }
        current = current->next;
    }
    std::cout << "Item not found!" << std::endl;
    return;
}

void doublyLinkedList::print() {
    ExtendedListItem* temp = this->head;

    if(temp == nullptr) {
        std::cout << "<Empty List>" << std::endl;
        return;
    }

    while(temp != nullptr) {
        std::cout << temp->toString();
        temp = temp->next;
    }
    std::cout << "===========================" << std::endl;
}

