#include <stdio.h>
#include <stdlib.h>

void expandArray(int *array)
{
	int arrsize = sizeof(array)/sizeof(int);
	array = realloc(array, sizeof(int) * (1 + arrsize));
	arrsize = sizeof(array)/sizeof(int);
	array[arrsize] = *array + 5;
	printf("size: %d\n", arrsize);
}


int main (void)
{
	int *array = calloc(5, sizeof(int));
	*array = 20;
	printf("Arraysize: %d\n", sizeof(array)/sizeof(int));
	expandArray(array);
	expandArray(array);
	expandArray(array);
	expandArray(array);
	expandArray(array);
	printf("ArraySize: %d\n", sizeof(array)/sizeof(int));
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
