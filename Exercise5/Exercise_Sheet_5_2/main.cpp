#include "item.h"
#include "drone.h"
#include "cashInstance.h"
#include <iostream>
#include <vector>

int main() {
    CashInstance instanceArray[10];

    CashInstance einCent(0.01, 38);
    instanceArray[0] = einCent;
    CashInstance zweiCent(0.02, 81);
    instanceArray[1] = zweiCent;
    CashInstance fuenfCent(0.05, 91);
    instanceArray[2] = fuenfCent;
    CashInstance zehnCent(0.10, 15);
    instanceArray[3] = zehnCent;
    CashInstance zwanzigCent(0.20, 8);
    instanceArray[4] = zwanzigCent;
    CashInstance fuenfzigCent(0.50, 3);
    instanceArray[5] = fuenfzigCent;
    CashInstance einEuro(1.0, 14);
    instanceArray[6] = einEuro;
    CashInstance zweiEuro(2.0, 5);
    instanceArray[7] = zweiEuro;
    CashInstance fuenfEuro(5, 12);
    instanceArray[8] = fuenfEuro;
    CashInstance zehnEuro(10, 15);
    instanceArray[9] = zehnEuro;


    Drone drone(instanceArray, 8);

    float retval = drone.calculateChange(6.71, 10);

    drone.returnChange(retval);


}