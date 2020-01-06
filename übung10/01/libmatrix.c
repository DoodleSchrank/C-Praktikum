#include <stdlib.h>
#include <time.h>

typedef int[][] matrix;

matrix newCleanMatrix(int matrixDim)
{
	matrix mat = alloc(matrixDim * matrixDim * sizeof(int));
	mat = matrix[matrixDim][matrixDim];
	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
			mat[i][j] = 0;
	}
	return mat;
}

matrix newMatrix(int matrixDim)
{
	matrix mat = alloc(matrixDim * matrixDim * sizeof(int));
	mat = matrix[matrixDim][matrixDim];
	srand(time(NULL));
	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
			mat[i][j] = rand() % 10;
	}
	return mat;
}

matrix addMatrices(matrix ma, matrix mb, int matrixDim)
{
	matrix result = newCleanMatrix(matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
			result[i][j] = ma[i][j] + mb[i][j];
	}	
}

matrix mulMatrices(matrix ma, matrix mb, int matrixDim)
{
	matrix result = newCleanMatrix(matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		for(int j = 0; j < matrixDim; j++)
		{
			for(int k = 0; k < matrixDim; k++)
			{
				result[i][j] += ma[i][k] * mb[k][j];
			}
		}
	}
}

void printCalculation(matrix ma, matrix mb, matric mres, *char operation)
{
	for(int i = 0; i < matrix
}
void freeMatrix(matrix mat);
