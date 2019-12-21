#include <assert.h>

int divide(int a, int b, int *rest)
{
	if (rest) *rest = a % b; // if rest != NULL save modulo of a and b into give address, else do nothing
	return (a/b);            // returns a/b as integer -> result gets floored
}

int main() {
	int b = 53;
	int a = 7*b + 42;
	int rest = 0;
	int c = divide(a, b, &rest);
	assert(c == 7);
	assert(rest == 42);
}
