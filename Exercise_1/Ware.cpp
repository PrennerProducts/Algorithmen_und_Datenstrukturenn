//
// Created by McRebel on 26.05.2022.
//

#include "Ware.h"
#include <string>


Ware::Ware(const std::string bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis)
        : bezeichnung(bezeichnung), seriennummer(seriennummer), gewicht(gewicht), einkaufspreis(einkaufspreis), verkaufspreis(verkaufspreis) {}

const std::string &Ware::getBezeichnung() const {
    return this->bezeichnung;
}

void Ware::setBezeichnung(const std::string &bezeichnung) {
        this->bezeichnung = bezeichnung;
    }


int Ware::getSeriennummer() const {
        return this->seriennummer;
}

void Ware::setSeriennummer(int seriennummer) {
    this->seriennummer = seriennummer;
}

double Ware::getGewicht() const {
        return this->gewicht;
}

void Ware::setGewicht(double gewicht) {
    this->gewicht = gewicht;
}

double Ware::getEinkaufspreis() const {
    return this->einkaufspreis;
}

void Ware::setEinkaufspreis(double einkaufspreis) {
    this->einkaufspreis = einkaufspreis;
}

double Ware::getVerkaufspreis() const {
    return this->verkaufspreis;
}

void Ware::setVerkaufspreis(double verkaufspreis) {
    this->verkaufspreis = verkaufspreis;
}
