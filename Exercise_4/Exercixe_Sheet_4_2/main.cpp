#include "hashTableDynamic.h"
#include "pbEntry.h"


int main() {


    PbEntry entry1("3277971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry2("9928657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry3("1674792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry4("4991459", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry5("1990539", "Carla Coe", "Lawrence Road 29");

    PbEntry entry6("7797251", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry7("9954657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry8("1454792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry9("4997859", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry10("1996539", "Carla Coe", "Lawrence Road 29");

    PbEntry entry11("3277541", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry12("9658657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry13("1674592", "Baby Doe", "North Lyme Street 34");
    PbEntry entry14("7825754", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry15("1978539", "Carla Coe", "Lawrence Road 29");

    PbEntry entry16("3277971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry17("9954257", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry18("1645792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry19("4945659", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry20("7878539", "Carla Coe", "Lawrence Road 29");

    PbEntry entry21("6954871", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry22("4538657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry23("1694745", "Baby Doe", "North Lyme Street 34");
    PbEntry entry24("4978939", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry25("459639", "Carla Coe", "Lawrence Road 29");

    PbEntry entry26("4569971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry27("4533657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry28("786492", "Baby Doe", "North Lyme Street 34");
    PbEntry entry29("4991459", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry30("1398524", "Carla Coe", "Lawrence Road 29");

    PbEntry entry31("3277971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry32("6956557", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry33("1674792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry34("4491459", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry35("3220539", "Carla Coe", "Lawrence Road 29");

    PbEntry entry36("2237971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry37("2335657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry38("3964792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry39("3891969", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry40("3999639", "Carla Coe", "Lawrence Road 29");
    HashTable ht;
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry4);
    ht.insert(&entry5);
    ht.print();

    ht.insert(&entry6);
    ht.insert(&entry7);
    ht.insert(&entry8);
    ht.insert(&entry9);
    ht.insert(&entry10);
    ht.insert(&entry11);
    ht.insert(&entry12);
    ht.insert(&entry13);
    ht.insert(&entry14);
    ht.insert(&entry15);
    ht.insert(&entry16);
    ht.insert(&entry17);
    ht.insert(&entry18);
    ht.insert(&entry19);
    ht.insert(&entry20);
    ht.insert(&entry21);
    ht.insert(&entry22);
    ht.insert(&entry23);
    ht.insert(&entry24);
    ht.insert(&entry25);
    ht.insert(&entry26);
    ht.insert(&entry27);
    ht.insert(&entry28);
    ht.insert(&entry29);
    ht.insert(&entry30);
    ht.insert(&entry31);
    ht.insert(&entry32);
    ht.insert(&entry33);
    ht.insert(&entry34);
    ht.insert(&entry35);
    ht.insert(&entry36);
    ht.insert(&entry37);
    ht.insert(&entry38);
    ht.insert(&entry39);
    ht.insert(&entry40);


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
