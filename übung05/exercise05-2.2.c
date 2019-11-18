#include <assert.h>
#include <string.h>
#include <stdio.h>
int findCharPosition(char *string, char searchCharacter, char *out_pointer) {
	char *index = strchr(string, searchCharacter);
	printf("%p\n", out_pointer);
	if (out_pointer) out_pointer = (*index) ? index : NULL;
	return (index != NULL) ? index - string : -1;
}

int main() {
	char* string1 = "foo";
	char* string2 = "bananas and ananas";

	int result = findCharPosition(string1, 'a', NULL);
	assert(result == -1);

	result = findCharPosition(string2, ' ', NULL);
	assert(result == 7);

	char *charPosition = ' ';
	printf("%p\n", charPosition);
	result = findCharPosition(string2, 'd', charPosition);
	assert(result == 10);
	assert(charPosition);
	assert(*charPosition == 'd');
	assert(charPosition == string2 + result);

	result = findCharPosition(string1, 'a',  charPosition);
	assert(result == -1);
	assert(!charPosition);
}
