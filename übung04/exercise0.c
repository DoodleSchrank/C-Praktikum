#include <stdio.h>
#include <stdlib.h>

void printPointer (int *i)
{
	printf("Wert: %d\n", *i);
	printf("Zeiger-Adresse: %p\n", i);
}

int main (void)
{
	int *heap = malloc(sizeof(int));
	if(heap == NULL)
	{ 
		printf("Error beim Speicherzuweisen.");
		exit(EXIT_FAILURE);
	}
	*heap = 42;

	printf("Heap:\n--------------------------------\n");
	printPointer(heap);

	free(heap);

	int stack = 1337;
	printf("\nStack:\n--------------------------------\n");
	printPointer(&stack);

	return EXIT_SUCCESS;
}
