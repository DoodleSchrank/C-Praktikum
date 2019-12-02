#include <stdio.h>

void print2dArray(size_t height, size_t width, double data[height][width]) {
	for(size_t x = 0; x < width; x++)
	{
	    for(size_t y = 0; y < height; y++)
        {
	        printf("%f ", data[y][x]);
        }
	    printf("\n");
	}
}

