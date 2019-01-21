#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define RADIAN(a) printf("%lf\n", a*(3.141592/180))

int main(){
    double GRAD;
    scanf("%lf", &GRAD);
    RADIAN(GRAD);
    return 0;
    
}
