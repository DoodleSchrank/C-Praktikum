#include <stdio.h>
#include <stdlib.h>

typedef struct
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


int main (void)
{
	intArray *array = malloc(sizeof(intArray));
	array->pointer = malloc(sizeof(int));
	array->length = 1;
	
	expandArray(array);
	expandArray(array);
	
	for(int i = 0; i < array->length; i++)
	{
		printf("%d ", array->pointer[i]);
	}
	
	free(array->pointer);
	free(array);
	return 0;
}
