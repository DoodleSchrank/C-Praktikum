typedef struct
{
    int dimension;
	int data;
} matrix;

matrix* newMatrix(int matrixDim);
matrix* addMatrices(matrix* ma, matrix* mb, int matrixDim);
void printCalculation(matrix* ma, matrix* mb, matrix* mc1, char* operation);
matrix* mulMatrices(matrix* ma, matrix* mb, int matrixDim);
void freeMatrix(matrix* mat);
