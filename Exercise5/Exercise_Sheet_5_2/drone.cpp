//
// Created by McRebel on 26.06.2022.
//

#include "drone.h"
#include <iostream>
#include <vector>
#include "cashInstance.h"

float Drone::calculateChange(float total, float paid) {
    if (total < paid){
        return paid-total;
    }
    else if (total > paid){
        std::cerr << "Zu wenig Bezahlt!" << std::endl;
        return -5;
    } else return 0;
}

void Drone::returnChange(float change) {
    if(change > 0){
        std::vector<CashInstance> tmpCashInstanceVec;
        float diff = change;
        while(diff > 0){
            int maximum = -1;
            int zero = 0;
            for(int i = 0; i < this->instances; i++){
                if(this->availableCashInstances[i].availableAmount <= 0){
                    zero++;
                }
                if(this->availableCashInstances[i].value <= diff && this->availableCashInstances[i].availableAmount > 0){
                    maximum = i;
                }
                if(i == this->instances - 1 && maximum == -1 && zero == this->instances){
                    std::cout << "kein Wechselgeld" << std::endl;
                }
            }
            if(maximum > -1){
                tmpCashInstanceVec.push_back(this->availableCashInstances[maximum]);
                this->availableCashInstances[maximum].availableAmount--;
                diff = diff * 1000;
                diff -= 1000*(this->availableCashInstances[maximum].value);
                diff = diff/1000;
                if(diff < 0.001){
                    diff = -1;
                }
            }
            else {
                int smallest_amount = -1;
                for(int i = 0; i < this->instances; i++){
                    if(this->availableCashInstances[i].availableAmount > 0){
                        smallest_amount = i;
                        break;
                    }
                }
                tmpCashInstanceVec.push_back(this->availableCashInstances[smallest_amount]);
                this->availableCashInstances[smallest_amount].availableAmount--;
                diff = diff * 1000;
                float over_price = (1000*this->availableCashInstances[smallest_amount].value) - diff;
                over_price = over_price / 1000;
                diff = -1;
                std::cout << "Warnung: Rückgeld kann nicht genau herausgegeben werden! "
                             "Ausbezahlter Betrag überschreitet den genauen Wert um "
                          << over_price << "!" << std::endl;
            }
        }

        auto* changeList = new CashInstance[tmpCashInstanceVec.size()];

        std::cout << "Ausgabe Wechselgeld: ";
        for(unsigned int i = 0; i < tmpCashInstanceVec.size(); i++){

            changeList[i] = tmpCashInstanceVec.at(i);
            std::cout << changeList[i].value << " Euro," "\t";
        }
        std::cout << std::endl;
    }else {
        std::cout << "Betrag ist genau, kein Wechselgend!" << std::endl;
    }

}
