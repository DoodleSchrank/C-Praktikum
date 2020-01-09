#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	int **data;
	int dimension;
} matrix;


matrix *newMatrix(int matrixDim)
{
	matrix mat = {
		malloc(sizeof(int*) * matrixDim),
		matrixDim
	};
	for(int i = 0; i < matrixDim; i++)
	{
		mat.data[i] = malloc(sizeof(int) * matrixDim);
	}
	srand(time(NULL));
	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
			mat.data[i][j] = rand() % 10;
	}
	return mat;
}

matrix *addMatrices(matrix ma, matrix mb, int matrixDim)
{
	matrix *result = newMatrix(matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
			result.data[i][j] = ma.data[i][j] + mb.data[i][j];
	}	
	return *result;
}

matrix *mulMatrices(matrix ma, matrix mb, int matrixDim)
{
	matrix *result = newMatrix(matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
		{
			result.data[i][j] = 0.0;
			for(int k = 0; k < matrixDim; k++)
			{
				result.data[i][j] += ma.data[i][k] * mb.data[k][j];
			}
		}
	}
	return *result;
}

void printCalculation(matrix ma, matrix mb, matrix mres, char *operation)
{
	char *symb;
	for(int i = 0; i < ma.dimension; i++)
	{
		for(int j = 0; j < ma.dimension; j++)
		{
			printf("%4d", ma.data[i][j]);
		}
		if(i == ma.dimension / 2 + 1) symb = operation;
		else symb = "";
		printf("%3s", symb);
		printf("  ");
		for(int j = 0; j < ma.dimension; j++)
		{
			printf("%4d", mb.data[i][j]);
		}
		if(i == ma.dimension / 2 + 1) symb = "=";
		else symb = "";
		printf("%3s", symb);
		printf("  ");
		for(int j = 0; j < ma.dimension; j++)
		{
			printf("%4d", mres.data[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(matrix mat)
{
	for(int i = 0; i < mat.dimension; i++)
	{
		free(mat.data[i]);
	}
	free(mat.data);
}
