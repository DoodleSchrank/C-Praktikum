#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct point_t {
	double x;
	double y;
};

double distance (struct point_t *p1, struct point_t *p2) {
	return hypot(p2->x - p1->x, p2->y - p1->y);
}

int main (int argc, char ** argv) {
	if (argc < 5)
	{
		printf("Error, zu wenig Input.");
		return 1;
	}
	struct point_t p1 = {atof(argv[1]), atof(argv[2])};
	struct point_t p2 = {atof(argv[3]), atof(argv[4])};
	printf("Distanz: %f\n", distance(&p1, &p2));
	return 0;
}
