#include <stdio.h>
#include <stdlib.h>

struct arrdata
{
	int *pointer;
	size_t length;
};


void expandArray(struct arrdata *arrdata)
{
	arrdata->length++;
	arrdata->pointer = realloc(arrdata->pointer, arrdata->length * sizeof(int));
	arrdata->pointer[arrdata->length - 1] = 0;
}


int main (void)
{
	struct arrdata *arrdata = malloc(sizeof(arrdata));
	arrdata->pointer = malloc(sizeof(int));
	arrdata->length = 1;
	
	expandArray(arrdata);
	expandArray(arrdata);
	
	for(int i = 0; i < arrdata->length; i++)
	{
		printf("%d ", arrdata->pointer[i]);
	}
	
	free(arrdata->pointer);
	free(arrdata);
	return 0;
}
