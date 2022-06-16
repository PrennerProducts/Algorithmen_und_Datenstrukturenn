#include "hashTable.h"
#include "pbEntry.h"
#include <string>
#include <iostream>

int main() {
    PbEntry entry1("3277971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry2("9928657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry3("1674792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry4("4991459", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry5("1990539", "Carla Coe", "Lawrence Road 29");
    HashTable ht;
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry4);
    ht.insert(&entry5);
    ht.print();

    // ht.setHashFunction("mod17");
    // ht.insert(&entry1);
    // ht.insert(&entry2);
    // ht.insert(&entry3);
    // ht.insert(&entry4);
    // ht.insert(&entry5);
    // ht.print();

    // const PbEntry* s1 = ht.search("3277971");
    // std::cout << s1->toString();
    
    // bool test = ht.deleteItem("3277971");
    // std::cout << test << std::endl;
    // bool test2 = ht.deleteItem("3277971");
    // std::cout << test2 << std::endl;
}
