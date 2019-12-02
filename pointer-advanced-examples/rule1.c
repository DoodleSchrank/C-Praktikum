#include <math.h>
#include <stdio.h>

struct foo {
	double bim;
};

double myFunc() {
	return M_E;
};

int main() {
	int bar = 42;
	int *bar_ptr;
	bar_ptr = &bar;
	printf("*bar_ptr = %d\n", *bar_ptr);

	int **bar_ptr_ptr = &bar_ptr;
	printf("**bar_ptr_ptr = %d\n", **bar_ptr_ptr);

	int baz = 13;
	*bar_ptr_ptr = &baz;
	printf("**bar_ptr_ptr = %d\n", **bar_ptr_ptr);
	printf("*bar_ptr = %d\n", *bar_ptr);
	printf("bar = %d\n", bar);

	struct foo bam = {.bim = M_PI};
	struct foo *bam_ptr = &bam;
	printf("only half perfection: %f\n", (*bam_ptr).bim);
	printf("the other half: %f\n", bam_ptr->bim);

	char bum[10] = "9876543210";
	char (*bum_ptr)[10];	//extra parentheses needed
	bum_ptr = &bum;
	printf("the answer is %c%c\n", (*bum_ptr)[5], (*bum_ptr)[7]);

	double (*myFunc_ptr)();	//extra parentheses needed
	myFunc_ptr = &myFunc;
	printf("the basis of power: %f\n", (*myFunc_ptr)());
}
