#include "hashTableChaining.h"
#include <string>
#include <iostream>
#include "Ware.h"
#include <exception>
#include <stdexcept>


int main() {
try {

    Ware Banane("Banana", 11, 19, 6.55, 25.64);
    Ware Apfel("Apfel", 8, 88, 1.57, 4.56);
    Ware Birne("Birne", 48, 55, 8.07, 7.16);
    Ware Avocado("Avocado", 4, 78, 9.57, 15.63);
    Ware Trauben("Trauben", 5, 654, 7.75, 10.46);
    Ware Zitronen("Zitronen", 78, 50, 4.55, 7.46);
    Ware Melonen("Melonen", 477, 4, 1.45, 2.36);
    Ware Nuesse("Nuesse", 38, 45, 4.45, 8.65);
    Ware Datteln("Datteln", 19, 8, 1.81, 2.96);
    Ware Feigen("Feigen", 10, 33, 1.70, 2.46);

    HashTable ht;
    //ht.setHashFunction("firstTwoChars");

    ht.insert(&Avocado);
    ht.insert(&Banane);
    ht.insert(&Birne);
    ht.insert(&Apfel);
    ht.insert(&Trauben);
    ht.insert(&Zitronen);
    ht.insert(&Melonen);
    ht.insert(&Nuesse);
    ht.insert(&Datteln);


    ht.print();
    ht.deleteItem("Banana");
    ht.deleteItem("Trauben");

    ht.print();

   }catch (const std::invalid_argument & e) {
       std::cerr << e.what()  << std::endl << " WTF! calling invalid_argument Exceptoin but i continue anyway!" << std::endl;
   } catch (const std::out_of_range & e) {     std::cerr << e.what() <<  " Out of Range " << std::endl;
  }catch (...){
    std::cerr << "WTF catch ALL block!! " << std::endl;
}
}


