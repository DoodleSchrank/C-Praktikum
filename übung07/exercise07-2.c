#include <assert.h>
#include <stdlib.h>
#include "2dArrayCall.h"
#include "Callback.h"

double foo(double x, double y)
{
	return x*x + y;
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
	print2dArray(height, width, data);

	assert(data[0][0] == 2);
	assert(data[0][1] == 1);
	assert(data[0][2] == 2);
	assert(data[1][0] == 4);
	assert(data[1][1] == 3);
	assert(data[1][2] == 4);
}
