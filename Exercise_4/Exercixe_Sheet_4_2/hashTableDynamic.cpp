
#include "hashTableDynamic.h"
#include <iostream>

HashTable::HashTable() {
    this->size = 0;
    this->entries = nullptr;
    this->setHashFunction("mod17");
}

HashTable::HashFunction::HashFunction(std::string name, hashFunctionPtr algorithm, int size) {
    this->name = name;
    this->algorithm = algorithm;
    this->size = size;
}


void HashTable::insert(PbEntry* entry) {
    int hashValue = this->hashFunction(entry->telephoneNumber);
    hashValue = hashValue % this->size;

    if(this->entries[hashValue].key == "" || this->entries[hashValue].key == "deleted") {
        this->entries[hashValue].key = entry->telephoneNumber;
        this->entries[hashValue].phonebookEntry = entry;
        this->numberOfEntries++;
    } else {
        bool inserted = false;
        int i = (hashValue + 1) % this->size;
        while(!inserted) {
            if(i == hashValue) {
                std::cout << "HashTable full!" << std::endl;
                return;
            }
            if(this->entries[i].key == "" || this->entries[i].key == "deleted") {
                this->entries[i].key = entry->telephoneNumber;
                this->entries[i].phonebookEntry = entry;
                this->numberOfEntries++;
                inserted = true;
            }
            i = (i + 1) % this->size;
        }
    }
    std::cout << "current NumberOfEntries: " << this->numberOfEntries << ", current LoadFactor: " << (double)this->getLoadFactor() << std::endl;
    if(this->getLoadFactor() > 2.0 / 3.0) {
        if(this->size <= 17) {
            std::cout << "Now we use mod37!" << std::endl;
            this->setHashFunction("mod37");
        } else if(this->size <= 37) {
            std::cout << "Now we use mod71!" << std::endl;
            this->setHashFunction("mod71");
        } else {
            if(this->numberOfEntries == this->size) {
                std::cout << "Hashtable ist full, go home!" << std::endl;
                return;
            }
        }
    }
}

void HashTable::print() {
    std::cout << "=====================================" << std::endl;
    for(int i = 0; i < this->size; i++) {
        std::cout << i << " :\t" << this->entries[i].key << std::endl;

    }
    std::cout << "=====================================" << std::endl;
}

void HashTable::setHashFunction(std::string algorithmName) {
    for(int i = 0; i < 6; i++) {
        if(this->availableAlgorithms[i].name == algorithmName) {
            this->hashFunction = this->availableAlgorithms[i].algorithm;
            HashNode* tempNode = this->entries;
            int tempsize = this->size;
            this->hashFunction = this->availableAlgorithms[i].algorithm;
            this->size = this->availableAlgorithms[i].size;
            this->numberOfEntries = 0;
            this->entries = new HashNode[this->size];
            if(tempNode != nullptr){
                for (int j = 0; j < tempsize ; ++j) {
                    if (tempNode[i].phonebookEntry != nullptr){
                        this->insert(tempNode[i].phonebookEntry);
                    }
                }
                delete[] tempNode;
            }
            return;
        }
    }

    std::cerr << "The Hash Function provided was not found!" << std::endl;
}

const PbEntry* HashTable::search(std::string key) {
    int hashValue = this->hashFunction(key);    //  key is "hashed" and stored in the variable int hashValue
    hashValue = hashValue % this->size;
    int i = 0;
    while(this->entries[hashValue].key != key && this->entries[hashValue].key != "" && i <= this->size) {
        hashValue = (hashValue + 1) % this->size;
        i++;
    }

    if(this->entries[hashValue].key == key) {
        return this->entries[hashValue].phonebookEntry;
    } else {
        std::cout << "Entry with telephone number " << key << " not found!" << std::endl;
        return nullptr;
    }
}

bool HashTable::deleteItem(std::string key) {
    int hashValue = this->hashFunction(key);
    hashValue = hashValue % this->size;

    while(this->entries[hashValue].key != key && this->entries[hashValue].key != "") {
        hashValue = (hashValue + 1) % this->size;
    }

    if(this->entries[hashValue].key == key) {
        this->entries[hashValue].key = "deleted";
        this->entries[hashValue].phonebookEntry = nullptr;
        delete this->entries[hashValue].phonebookEntry;
        this->numberOfEntries--;
        return true;
    } else {
        return false;
    }
}

float HashTable::getLoadFactor() const {
    return (float) (float)this->numberOfEntries / (float ) this->size;
}



/*  algorithm that "hashes" the last digit of a number  */

int lastNumber(std::string telNr) {
    if(telNr.length() <=0) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 1 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-1, telNr.end()));
}


/*  algorithm that "hashes" the first three digits of a number  */

int firstThreeNumbers(std::string telNr) {
        if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.begin(), telNr.begin()+3));
}


/*  algorithm that "hashes" the last three digits of a number  */

int lastThreeNumbers(std::string telNr) {
    if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-3, telNr.end()));
}


/*  algorithm that "hashes" the through mod17  */

int mod17(std::string telNr) {
    return (int)(std::stol(telNr)%17);
}


/*  algorithm that "hashes" the through mod37 */

int mod37(std::string telNr) {
    return (int)(std::stol(telNr)%37);
}


/*  algorithm that "hashes" the through mod71  */

int mod71(std::string telNr) {
    return (int)(std::stol(telNr)%71);
}
