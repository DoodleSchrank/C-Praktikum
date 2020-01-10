#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int dimension;
	int** data;
} matrix;

matrix* newMatrix(int matrixDim)
{
    srand(time(0));
	matrix* mat;
    mat = malloc(sizeof(int) + sizeof(int**));
	mat->dimension = matrixDim;
    mat->data = malloc(sizeof(int*) * matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{ 
		mat->data[i] = malloc(sizeof(int) * matrixDim);
		for(int j = 0; j < matrixDim; j++)
			mat->data[i][j] = rand() % 10;
	}
	return mat;
}

matrix* addMatrices(matrix* ma, matrix* mb, int matrixDim)
{
	matrix* result = newMatrix(matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
			result->data[i][j] = ma->data[i][j] + mb->data[i][j];
	}	
	return result;
}

matrix* mulMatrices(matrix* ma, matrix* mb, int matrixDim)
{
	matrix* result = newMatrix(matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
		{
			result->data[i][j] = 0.0;
			for(int k = 0; k < matrixDim; k++) 
                result->data[i][j] += ma->data[i][k] * mb->data[k][j];
		}
	}
	return result;
}

void printCalculation(matrix* ma, matrix* mb,  matrix* mres, char *operation)
{
	char *symb;
	for(int i = 0; i < ma->dimension; i++)
	{
        //1. Operand:
		for(int j = 0; j < ma->dimension; j++)
		{
			printf("%4d", ma->data[i][j]);
		}
        //Operator:
		if(i == ma->dimension / 2) symb = operation;
		else symb = "";
		printf("%4s", symb);
		printf("  ");
        //2. Operand
		for(int j = 0; j < ma->dimension; j++)
		{
			printf("%4d", mb->data[i][j]);
		}
        //Gleichheitszeichen:
		if(i == ma->dimension / 2) symb = "=";
		else symb = "";
		printf("%4s", symb);
		printf("  ");
        //Ergebnis:
		for(int j = 0;
        j < ma->dimension; j++)
		{
			printf("%4d", mres->data[i][j]);
		}
		printf("\n");
	}
    printf("\n");
}

void freeMatrix(matrix* mat)
{
	for(int i = 0; i < mat->dimension; i++)
	{
		free(mat->data[i]);
	}
	free(mat->data);
    free(mat);
}
