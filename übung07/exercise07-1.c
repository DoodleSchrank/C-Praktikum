#include<stdio.h>

voidprint2dArray(size_t height, size_t width, double data[height][width])
{
	for(size_t x=0; x < width; x++)
	{
		for(size_t y = 0; y < height; y++)
		{
			printf("%f", data[y][x]);
		}
		printf("\n");
	}
}

int main(void){
	const size_t width = 4, height = 3;
	double data[height][width];
	for(size_t y = 0; y < height; y++){
		for(size_t x = 0; x < width; x++){
			data[y][x] = 0;
			if(y == 1 && x == 1) data[y][x] = 4;
			if(y == 1 && x == 2) data[y][x] = 2;
		}
	}
	print2dArray(height, width, data);
}
