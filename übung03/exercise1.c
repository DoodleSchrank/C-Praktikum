#include <stdio.h>

enum dataType
{
	FOO,
	BAR
};

struct foo
{
	int a;
	int b;
};

struct bar
{
	float a;
	float b;
};

struct foobar
{
	enum dataType type;
	union data
	{
		struct foo foo;
		struct bar bar;
	} data;
};

int main (void)
{
	struct foobar a = { FOO,  { .foo = { 42, 23 } } };
	printf("foo: %d %d\n", a.data.foo.a, a.data.foo.b);
	
	struct foobar b = { BAR,  { .bar = { 42.0, 23.0 } } };
	printf("bar: %f %f\n", b.data.bar.a, b.data.bar.b);

	printf("sizeof(struct foobar) = %d\n", sizeof(struct foobar));

	return 0;
}
