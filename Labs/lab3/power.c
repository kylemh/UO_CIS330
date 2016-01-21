#include <stdio.h>

double power(double a, double b){
	double i; /* Variable for loop */
	double number = 1;
	for (i = 0.0; i < b; ++i){
		number *= a;
	}
	return number;
}
