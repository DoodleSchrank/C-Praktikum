#include <stdio.h>
#include <stdlib.h>
int* allocSomeMemory()
{
	return malloc(sizeof(int));
}

int main (void)
{
	// 1. Speicherleck
	int *leak = allocSomeMemory(); // allocate some memory but never free => leak
	
	// 2. Variablennutzung nach free()
	int *useAfterFree = allocSomeMemory();
	free(useAfterFree);
	*useAfterFree = 42; // error, because memory is no longer allocated

	// 3. Freigabe vom nicht dynamisch reservierten Speicher
	static int freeNonHeap; // static allocation
	free(&freeNonHeap);		// trying to free statically allocated memory

	// 4. Zugriff auf nicht reservierten Speicher
	printf("%d\n", *(leak+64)); // trying to read from unallocated memory

	// 5. Mehrfacher Aufruf von free()
	int *alreadyFree = useAfterFree;
	free(alreadyFree); // trying to free memory that has already been freed

	return 0;
}
