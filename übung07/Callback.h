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
//    fillMatrixWithResults(3, 0.0, 1.0,
//                          4, -1.0, 5.0,
//                          matrix, &callback)
//
//will call the callback with the coordinates
//
//    (0.0, -1.0) (0.0, 1.0) (0.0, 3.0) (0.0, 5.0)
//    (0.5, -1.0) (0.5, 1.0) (0.5, 3.0) (0.5, 5.0)
//    (1.0, -1.0) (1.0, 1.0) (1.0, 3.0) (1.0, 5.0)
void fillMatrixWithResults(int height, double y_min, double y_max,
						   int width, double x_min, double x_max,
						   double data[height][width], double (*function)(double, double)) 
{
	// Calculate stepheight for x and y axis
	double width_step = (x_max - x_min) / (width - 1);
	double height_step = (y_max - y_min) / (height - 1);

	// Loop through every entry in the array
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			// Set datapoint to result of callback function
			// Some additional math for correct stepping was required
			// We couldn't live with trampling on innocent data :(
			data[y][x] = function(x_min + x * width_step, y_min + y * height_step);
		}
	}
}
