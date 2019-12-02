#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

void bubbleSort(void* data, size_t objectSize, size_t objectCount, bool(*isGreater)(void*, void*), void(*swapObjects)(void*, void*)) {
	char (*typedData)[objectSize];
	typedData = data;

	for(size_t round = objectCount; round--;) {
		for(size_t i = 0; i < round; i++) {
			if((*isGreater)(typedData[i], typedData[i+1])) {
				(*swapObjects)(typedData[i], typedData[i+1]);
			}
		}
	}
}

bool isGreater_stringPtr(const char** a_ptr, const char** b_ptr) {
	const char* a = *a_ptr;
	const char* b = *b_ptr;

	for(; *a && *a == *b; a++, b++) ;
	if(!*a) return false;
	return *a > *b;
}

void swap_stringPtr(const char** a_ptr, const char** b_ptr) {
	const char* temp = *a_ptr;
	*a_ptr = *b_ptr;
	*b_ptr = temp;
}

int main() {
	char* strings[] = {
		"C", "has", "only", "a", "handful", "of", "keywords", "and", "is", "a", "bit", "rough", "around", "the", "edges", "and", "it", "rocks",
		"Ben", "Klemens", "21st", "Century", "C"
	};
	size_t stringCount = sizeof(strings)/sizeof(*strings);
	bubbleSort(strings, sizeof(*strings), stringCount, &isGreater_stringPtr, &swap_stringPtr);

	for(size_t i = 0; i < stringCount; i++) {
		printf("%s\n", strings[i]);
	}
}
