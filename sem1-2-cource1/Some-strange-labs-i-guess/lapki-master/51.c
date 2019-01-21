#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "math.h"

double GRAD_TO_RADIAN(){
    double PI = 3.1415926535;
    double GRADUS, RADIAN;
    
    scanf("%lf", &GRADUS);
    RADIAN = GRADUS * (PI/ 180);
    return RADIAN;
}

