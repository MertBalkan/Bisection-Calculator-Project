//author: Mert Balkan

#include <iostream>
#include "BisectionHeader.h"

int main() {
    //EXAMPLE FUNC => f(x) = 10*e^-x/2*(cos6x+sin8x) I USED THIS FUNCTION FOR THIS PROGRAM

    BisectionCalculator* bisectionCalculator = new BisectionCalculator();
    
    bisectionCalculator->StartProgram();


    return 0;
}