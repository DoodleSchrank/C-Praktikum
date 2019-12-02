#include <stdio.h>

struct foo {
	const char* hello;
	const char* world;
};

int main() {
	printf("Hello %s\n", &7["Stupid World"]);

	struct foo bar = {
		.hello = "Hallo",
		.world = "Welt!"
	};
	struct foo *bar_ptr = &bar;
	printf("%s %s\n", bar_ptr->hello, (*bar_ptr).world);
};
