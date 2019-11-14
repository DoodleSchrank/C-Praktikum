#include <stdio.h>
#include <stdlib.h>

typedef struct intArray
{
	int *pointer;
	size_t length;
} intArray;


void expandArray(intArray *array)
{
	array->length++;
	array->pointer = realloc(array->pointer, array->length * sizeof(int));
	array->pointer[array->length - 1] = 0;
}

void printArray(intArray array)
{
	for (int i = 0; i < array.length; i++)
	{
		printf("%d ", array.pointer[i]);
	}
	printf("\n");
}


int main (void)
{
	// initialize array with 1 element
	intArray array = {
		pointer: calloc(1, sizeof(int)),
		length: 1
	};
	
	expandArray(&array);
	expandArray(&array);
	
	printArray(array);
	
	free(array.pointer);
	return 0;
}
