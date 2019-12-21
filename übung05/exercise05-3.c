#include <stdio.h>

void textTriangle(char* string)
{
	while(*string != '\0')
	{
		printf("%s\n", string);
		string++;
	}
}

int main (void)
{
	textTriangle("Abrakadabra");
	return 0;
}
