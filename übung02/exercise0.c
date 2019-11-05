#include <stdio.h>

void string_concat (char out[], char string1[], char string2[])
{
	// i stores the current index for out
	int i = 0;

	char *curr = string1;
	// copy string1 to out until null-byte is reached
	while (*curr != '\0')
	{
		out[i] = *curr;
		curr++;
		i++;
	}

	curr = string2;
	// copy string2 to out until null-byte is reached
	while (*curr != '\0')
	{
		out[i] = *curr;
		curr++;
		i++;
	}

	// add null-byte at the end
	out[i] = '\0';
}

int main (void)
{
	char out[128] = { '\0' };
	string_concat(out, "Hello", "World");
	printf("%s\n", out);
	return 0;
}
