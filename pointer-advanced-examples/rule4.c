#include <stdio.h>

int main() {
	char foo[] = "some text";
	char *foo_ptr = &foo[0];
	printf("foo_ptr = %p, sizeof(*foo_ptr) = %zd\n", foo_ptr, sizeof(*foo_ptr));
	printf("foo_ptr + 7 = %p\n", foo_ptr + 7);

	int bar[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *bar_ptr = &bar[0];
	printf("bar_ptr = %p, sizeof(*bar_ptr) = %zd\n", bar_ptr, sizeof(*bar_ptr));
	printf("bar_ptr + 7 = %p\n", bar_ptr + 7);

	int (*bar_ptr2)[10];
	bar_ptr2 = &bar;
	printf("bar_ptr2 = %p, sizeof(*bar_ptr2) = %zd\n", bar_ptr2, sizeof(*bar_ptr2));
	printf("bar_ptr2 + 1 = %p\n", bar_ptr2 + 1);
}
