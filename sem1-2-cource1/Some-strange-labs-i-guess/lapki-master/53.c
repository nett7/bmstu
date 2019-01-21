#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define mode 0
#define PRINTLF(a) printf("%lf\n", a);
int main(){
	double RADIAN, GRADUS;
	#if mode ==0
		printf("RADIAN_TO_GRADUS:\n");
		scanf("%lf", &RADIAN);
		PRINTLF(RADIAN*(180/3.141592));
	#elif mode == 1
		printf("GRADUS-TO-RADIAN:\n");
		scanf("%lf", &GRADUS);
		PRINTLF(GRADUS*(3.141592/180));
	#endif
return 0;
}
