#include <assert.h>
#include <stdlib.h>

double foo(double x, double y)
{
	return x*x + y;
}

	//Fills a 2D matrix with the results of the given callback function.
	//The coordinates that are passed to the callback
	//range from (y_min, x_min) to (y_max, x_max), inclusive.
	//
	//I.e. the call
	//
	//fillMatrixWithResults(3, 0.0, 1.0,
	//4, -1.0, 5.0,
	//matrix, &callback)
	//
	//will call the callback with the coordinates
	//
	//(0.0, -1.0) (0.0, 1.0) (0.0, 3.0) (0.0, 5.0)
	//(0.5, -1.0) (0.5, 1.0) (0.5, 3.0) (0.5, 5.0)
	//(1.0, -1.0) (1.0, 1.0) (1.0, 3.0) (1.0, 5.0)
void fillMatrixWithResults(size_t height, double y_min, double y_max,
						   size_t width, double x_min, double x_max,
						   double data[height][width], double (*function)(double, double)) 
{
	// Calculate stepheight for x and y axis
	double width_step = (x_max - x_min) / (width - 1);
	double height_step = (y_max - y_min) / (height - 1);

	// Loop through every entry in the array
	for(size_t y = 0; y < height; y++)
	{
		for(size_t x = 0; x < width; x++)
		{
			// Set datapoint to result of callback function
			// Some additional math for correct stepping was required
			// We couldn't live with trampling on innocent data :(
			data[y][x] = function(x_min + x * width_step, y_min + y * height_step);
		}
	}
}

int main() {
	const size_t height = 2, width = 3;
	double data[height][width];
	const double x_min = -1, x_max = 1;
	const double y_min = 1, y_max = 3;

	fillMatrixWithResults(height, y_min, y_max,
	width, x_min, x_max,
	data, &foo);

	//may be used, is not required for grading
	//print2dArray(height, width, data);

	assert(data[0][0] == 2);
	assert(data[0][1] == 1);
	assert(data[0][2] == 2);
	assert(data[1][0] == 4);
	assert(data[1][1] == 3);
	assert(data[1][2] == 4);
}
