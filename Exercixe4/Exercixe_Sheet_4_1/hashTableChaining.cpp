//#include "hashTable.h"
#include <iostream>
#include "Ware.h"
#include "hashTableChaining.h"
#include <limits>
#include "list"
#include "vector"
#include <string>
#include <utility>


HashTable::HashTable() {
    this->size = 0;
    this->entries = nullptr;
    this->setHashFunction("firstTwoChars");
}

HashTable::HashFunction::HashFunction(std::string name, hashFunctionPtr algorithm, int size) {
    this->name = name;
    this->algorithm = algorithm;
    this->size = size;
}


void HashTable::insert(Ware* ware){
    int hashValue = this->hashFunction(ware->getBezeichnung());
    if(hashValue == -1) {
        return;
    }
    hashValue = hashValue % this->size;
    HashNode node;
    node.key = ware->getBezeichnung();
    node.waren = ware;
    this->entries[hashValue].push_back(node);
/*
 *
    if(this->entries[hashValue].key == "" || this->entries[hashValue].key == "deleted") {
        this->entries[hashValue].key = entry->getBezeichnung();
        this->entries[hashValue].waren = entry;
    } else {
        bool inserted = false;
        int i = (hashValue + 1) % this->size;
        while(!inserted) {
            if(i == hashValue) {
                std::cout << "HashTable full!" << std::endl;
                return;
            }
            if(this->entries[i].key.empty() || this->entries[i].key == "deleted") {
                this->entries[i].key = entry->getBezeichnung();
                this->entries[i].waren = entry;
                inserted = true;
            }
            i = (i + 1) % this->size;
        }
    }*/
}

void HashTable::print() const {
    std::cout << "=====================================" << std::endl;
    for(int i = 0; i < this->size; i++) {
        std::cout << i << " :\t";
        std::list<HashNode>::iterator listIterator;
        for (listIterator = this->entries[i].begin(); listIterator != this->entries[i].end(); ++listIterator)
        {
            std::cout << listIterator->key << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "=====================================" << std::endl;
}

void HashTable::setHashFunction(const std::string& algorithmName) {
    for(int i = 0; i < 5; i++) {
        if(this->availableAlgorithms[i].name == algorithmName) {
            this->hashFunction = this->availableAlgorithms->algorithm;
            this->size = this->availableAlgorithms->size;
            if(this->entries != nullptr) {
                delete[] this->entries;
            }
            this->entries = new std::list<HashNode>[this->size];
            return;
        }
    }

    std::cerr << "The Hash Function provided was not found!" << std::endl;
}

const Ware* HashTable::search(std::string key) {
    int hashValue = this->hashFunction(key);    //  key is "hashed" and stored in the variable int hashValue
    hashValue = hashValue % this->size;

    std::list<HashNode>::iterator listIterator;
    for (listIterator = this->entries[hashValue].begin(); listIterator != this->entries[hashValue].end(); listIterator++){
        if(listIterator->key == key){
            return listIterator->waren;
        }
    }
   return nullptr;
}

bool HashTable::deleteItem(std::string key) {
    int hashValue = this->hashFunction(key);
    hashValue = hashValue % this->size;

    std::list<HashNode>::iterator listIterator;
    for (listIterator = this->entries[hashValue].begin(); listIterator != this->entries->end(); listIterator++){
        if (listIterator->key == key){
            this->entries[hashValue].erase(listIterator);
            return true;
        }
    }
    return false;
}


/*  algorithm that "hashes" the last digit of a number  */
/*int lastNumber(std::string telNr) {
    if(telNr.length() <=0) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 1 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-1, telNr.end()));
}

*//*  algorithm that "hashes" the first three digits of a number  *//*
int firstThreeNumbers(std::string telNr) {
    if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.begin(), telNr.begin()+3));
}

*//*  algorithm that "hashes" the last three digits of a number  *//*
int lastThreeNumbers(std::string telNr) {
    if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-3, telNr.end()));
}

*//*  algorithm that "hashes" the through mod17  *//*
int mod17(std::string telNr) {
    return (int)(std::stol(telNr)%17);
}*/

int firstTwoChars(std::string Bezeichnung) {
    int char1 = (int) Bezeichnung[0];
    int char2= (int) Bezeichnung[1];
    return char1+char2;
    }



