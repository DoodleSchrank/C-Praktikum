#include <assert.h>
#include <stdlib.h>

int findCharPosition(char* string, char searchCharacter, char** out_pointer) {

	// loop through string and compare each character to searchCharacter
	for (size_t i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == searchCharacter)
		{
			// when out_pointer is given and the character has been found its address is written to out_pointer
			if (out_pointer) *out_pointer = &string[i];
			return i;
		}
	}

	if (out_pointer) *out_pointer = NULL;
	return -1;
}

int main() {
	char* string1 = "foo";
	char* string2 = "bananas and ananas";

	int result = findCharPosition(string1, 'a', NULL);
	assert(result == -1);

	result = findCharPosition(string2, ' ', NULL);
	assert(result == 7);

	char* charPosition;

	// give address of charPosition for returning the address of searched char
	result = findCharPosition(string2, 'd', &charPosition);
	assert(result == 10);
	assert(charPosition);
	assert(*charPosition == 'd');
	assert(charPosition == string2 + result);

	result = findCharPosition(string1, 'a', &charPosition);
	assert(result == -1);
	assert(!charPosition);
}
