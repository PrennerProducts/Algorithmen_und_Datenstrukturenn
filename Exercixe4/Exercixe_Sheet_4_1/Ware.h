#include <string>

#pragma once

class Ware {
    private:
        std::string bezeichnung;
        int seriennummer;
        double gewicht;
        double einkaufspreis;
        double verkaufspreis;

    public:
        Ware(std::string bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis);
        
        void setBezeichnung(std::string bezeichnung);

        std::string getBezeichnung() const;

        void setSeriennummer(int seriennummer);
        int getSeriennummer();

        void setGewicht(double gewicht);
        double getGewicht();

        void setEinkaufspreis(double einkaufspreis);
        double getEinkaufspreis();

        void setVerkaufspreis(double verkaufspreis);
        double getVerkaufspreis();
};
