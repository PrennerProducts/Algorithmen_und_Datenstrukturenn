//
// Created by McRebel on 26.06.2022.
//

#ifndef EXERCISE_SHEET_5_2_DRONE_H
#define EXERCISE_SHEET_5_2_DRONE_H

class CashInstance;

class Drone {
public:
    // Constructor
    Drone(CashInstance* myCashInstances, int amount){
        this->availableCashInstances = myCashInstances;
        this->instances = amount;
    }


    CashInstance* availableCashInstances;                   // ein Array, welches die verfügbaren CashInstances ("Geldeinheiten") speichert (siehe unten).
    float calculateChange(float total, float paid);          // Errechnen des Rückgeldbetrags
    void returnChange(float change);                        // Return

private:
    int instances;


};


#endif //EXERCISE_SHEET_5_2_DRONE_H
