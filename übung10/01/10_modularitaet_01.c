#include "10_matrixOps.h"
#include <stdio.h>

int main()
{

	const int matrixDim = 3;

	// Matrix Initialisierung
	matrix* mA = newMatrix(matrixDim);
    //printf("%d\n", mA->data);
    //printf("Sizeof struct:%d\n", sizeof(mA));
	matrix* mB = newMatrix(matrixDim);

	// Addition
	matrix* mc1 = addMatrices(mA, mB, matrixDim);
	printCalculation(mA, mB, mc1, "+");

	// Multiplikation
	// // Addition
	matrix* mc2 = mulMatrices(mA, mB, matrixDim);
	printCalculation(mA, mB, mc2, "*");

	// Gib Matrix-Speicher wieder frei
	freeMatrix(mA);
	freeMatrix(mB);
	freeMatrix(mc1);
	freeMatrix(mc2);
}

