#include <assert.h>
#include <stdio.h>
int divide(int a, int b, int *rest)
{
	if (rest) *rest = a % b;
	return (a/b);
}

int main() {
	int b = 53;
	int a = 7*b + 42;
	int rest = 0;
	int c = divide(a, b, &rest);
	assert(c == 7);
	assert(rest == 42);
	printf("%d, %d, %d, %d\n", a, b, c, rest);
}
