#include "Ware.h"

#include <iostream>

Ware::Ware(std::string bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis) {
    this->bezeichnung = bezeichnung;
    this->seriennummer = seriennummer;
    this->gewicht = gewicht;
    this->einkaufspreis = einkaufspreis;
    this->verkaufspreis = verkaufspreis;
}

void Ware::setBezeichnung(std::string bezeichnung) {
    this->bezeichnung = bezeichnung;
}

std::string Ware::getBezeichnung() const {
    return this->bezeichnung;
}


void Ware::setSeriennummer(int seriennummer) {
    if(seriennummer <= 0) {
        std::cerr << "Seriennummer muss positiv sein!" << std::endl;
        return;
    }
    this->seriennummer = seriennummer;
}
int Ware::getSeriennummer() {
    return this->seriennummer;
}

void Ware::setGewicht(double gewicht) {
    if(gewicht <= 0) {
        std::cerr << "Gewicht muss positiv sein!" << std::endl;
        return;
    }
    this->gewicht = gewicht;
}
double Ware::getGewicht() {
    return this->gewicht;
}

void Ware::setEinkaufspreis(double einkaufspreis) {
    if(einkaufspreis <= 0) {
        std::cerr << "Einkaufspreis muss positiv sein!" << std::endl;
        return;
    }
    this->einkaufspreis = einkaufspreis;
}
double Ware::getEinkaufspreis() {
    return this->einkaufspreis;
}

void Ware::setVerkaufspreis(double verkaufspreis) {
    if(verkaufspreis <= 0) {
        std::cerr << "Verkaufspreis muss positiv sein!" << std::endl;
        return;
    }
    this->verkaufspreis = verkaufspreis;
}
double Ware::getVerkaufspreis() {
    return this->verkaufspreis;
}