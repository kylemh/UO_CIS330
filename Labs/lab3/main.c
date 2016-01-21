#include <stdio.h>
#include "power.h"

int main(int argc, const char * argv[]) {
	double a;
	double b;
	printf("Type the number you will be exponentiating (i.e. 'A' in 'A^B'): ");
	scanf("%lf", &a);
	printf("Now, type in the number you'd like to exponentiate by (i.e. 'B' in 'A^B'): ");
	scanf("%lf", &b);
	printf("\n %lf ^ %lf is: ", a, b);
	printf("%lf", power(a, b));
	return 0;
}
