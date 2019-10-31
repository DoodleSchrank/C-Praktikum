#include <stdio.h>

void fib_while()
{
	int current = 0;
	int last = 0;
	int temp;
	while(current < 21)
	{
		temp = current + last;
		last = current;
		current = temp;
		printf("%d ", current);
		if(current == 0) last = 1;
	}
	printf("\n");
}

void fib_do_while()
{
	int current = 0;
	int last = 0;
	int temp;
	do
	{
		temp = current + last;
		last = current;
		current = temp;
		printf("%d ", current);
		if(current == 0) last = 1;
	} while(current < 21);
	printf("\n");
}

void fib_for()
{
	int last = 0;
	int temp;
	for(int current = 0; current < 21; current = temp)
	{
		temp = current + last;
		last = current;
		printf("%d ", temp);
		if(temp == 0) last = 1;
	}
	printf("\n");
}

int main()
{
    fib_while();
    fib_do_while();
    fib_for();

    return 0;
}
