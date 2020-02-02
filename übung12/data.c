#define _GNU_SOURCE

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "data.h"

/* data stores either a string or blob. */
struct data
{
	// 1 in case of string, 0 for blob
	short is_string;
	// content length; does not include null-terminator in case of string
	size_t length;
	// reference count
	unsigned int ref_count;
	// string/blob
	char* content;
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
	// allocate space for data struct
	data* dat = malloc(sizeof(data));

	// initialize
	dat->is_string = 1;
	dat->length = strlen(content);
	dat->ref_count = 1;
	// allocate space for content;
	// length + 1 because we also copy null-terminator
	dat->content = malloc(dat->length + 1);

	// copy content to data struct
	memcpy(dat->content, content, dat->length + 1);

	return dat;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	// allocate space for data struct
	data* dat = malloc(sizeof(data));

	// initialize
	dat->is_string = 0;
	dat->length = length;
	dat->ref_count = 1;
	// allocate space for content
	dat->content = malloc(length);

	// copy content to data struct
	memcpy(dat->content, content, length);

	return dat;
}

/* Increments the reference count. */
data* data_ref (data* data)
{
	data->ref_count++;
	return data;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
	data->ref_count--;
	// free content and data if not referenced anymore
	if (data->ref_count == 0)
	{
		free(data->content);
		free(data);
	}
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
	char* str = NULL;

	if (data->is_string) // "String: "-prefix + content
		asprintf(&str, "String: %s", data->content);
	else // "Blob: "-prefix + address
		asprintf(&str, "Blob: %p", data->content);
	
	return str;
}

/* Returns a hash for the content of data. */
unsigned int data_hash (data const* data)
{
	unsigned int hash = 0;
	for (size_t i = 0; i < data->length; i++)
	{
		// adding the char makes sure that the value affects the hash
		// and to ensure the position also has an effect we multiply the hash
		hash = 31*hash + data->content[i];
	}
	return hash;
}

/* Compares two data structs. */
int data_cmp (data const* a, data const* b)
{
	// compare by length
	if (a->length < b->length)
		return -1; // a is shorter than b
	else if (a->length > b->length)
		return 1; // a is longer than b
	else
	{
		// length is equal, compare lexicographically
		for (size_t i = 0; i < a->length; i++)
		{
			if (a->content[i] < b->content[i])
				return -1; // a comes before b
			else if (a->content[i] > b->content[i])
				return 1; // a comes after b
		}
	}

	// otherwiese, both length and content are equal
	return 0;
}
