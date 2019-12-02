#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Callback.h"
#include "2dArrayCall.h"

double multiply(double x, double y)
{
	return x * y;
}
double sinufy(double x, double y)
{
	return sin(x) * sin(y);
}
double maxify(double x, double y)
{
	return (x > y) ? x : y;
}

void func(double schrittweite, double min, double max, double (*function)(double, double))
{
int size = (max - min) / schrittweite + 1;
double data[size][size];
fillMatrixWithResults(size, min, max, size, min, max, data, function);
print2dArray(size, size, data);
}

int main(void)
{
	printf("Beginning Function f:\n");
	func(0.5, -1, 1, &multiply);
	
	printf("\nBeginning Function g:\n");
	func(M_PI/4, 0, M_PI, &sinufy);
	
	printf("\nBeginning Function h:\n");
	func(1, 0, 10, &maxify);
	
	return 0;
}
