//
// Created by McRebel on 26.05.2022.
//

#ifndef EXERCISE_1_WARE_H
#define EXERCISE_1_WARE_H

#include <string>
#include <iostream>
#include <string>



class Ware {
public:
    std::string bezeichnung;
    int seriennummer;
    double gewicht;
    double einkaufspreis;
    double verkaufspreis;
    int warenItemsAnzahl = 5;

    Ware(const std::string bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis);
    ~Ware(){
        std::cout << "Calling Destructor Ware" << std::endl;
    }

    const std::string &getBezeichnung() const;

    void setBezeichnung(const std::string &bezeichnung);

    int getSeriennummer() const;

    void setSeriennummer(int seriennummer);

    double getGewicht() const;

    void setGewicht(double gewicht);

    double getEinkaufspreis() const;

    void setEinkaufspreis(double einkaufspreis);

    double getVerkaufspreis() const;

    void setVerkaufspreis(double verkaufspreis);




};



#endif //EXERCISE_1_WARE_H
