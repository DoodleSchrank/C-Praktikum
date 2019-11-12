#include <stdio.h>
#include <stdlib.h>
int* allocSomeMemory()
{
	return malloc(sizeof(int));
}

int main (void)
{
	int *errone = allocSomeMemory();//allocate some memory, first error because it never gets freed -> lecken
	int *errtwo = allocSomeMemory();//allocate some more memory
	static int errthree;						//static allocation
	free(errtwo);										//frees memory too make 2nd and 4th error happen
	*errtwo = 5;										//2nd error, because memory is no longer allocated
	free(&errthree);								//3rd error, trying to free statically allocated memory
	int *errfour = errtwo;					//4th error, trying to read from unallocated memory
	free(errtwo);										//5th error, trying to free memory that has already been freed
	return 0;
}
