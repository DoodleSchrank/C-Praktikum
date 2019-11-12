#include <stdio.h>
#include <stdlib.h>

struct arrdata
{
	int *pointer;
	int size;
};


void expandArray(struct arrdata *arrdata)
{
	arrdata->size++;
	arrdata->pointer = realloc(arrdata->pointer, arrdata->size * sizeof(int));
	arrdata->pointer[arrdata->size - 1] = 0;
}


int main (void)
{
	struct arrdata *arrdata = malloc(sizeof(arrdata));
	arrdata->pointer = malloc(sizeof(int));
	arrdata->size = 1;
	
	expandArray(arrdata);
	expandArray(arrdata);
	
	for(int i = 0; i < arrdata->size; i++)
	{
		printf("%d ", arrdata->pointer[i]);
	}
	
	free(arrdata->pointer);
	free(arrdata);
	return 0;
}
