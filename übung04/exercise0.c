#include <stdio.h>
#include <stdlib.h>

void heapvstack (int zahl)
{
	int *heapint = malloc(sizeof(int));
	if(heapint == NULL)
  { 
		printf("Error beim Speicherzuweisen.");
		exit(0);
	}
  *heapint = zahl; 
	int stackint = zahl;

	printf("Heap:\n--------------------------------\n");
	printf("Wert: %d\n", *heapint);
	printf("Zeiger-Adresse: %p\n", heapint);
	
	printf("\n\nStack:\n--------------------------------\n");
	printf("Wert: %d\n", stackint);
	printf("Zeiger-Adresse: %p\n", &stackint);
	free(heapint);
}

int main (void)
{
	heapvstack(5);
	return 0;
}
