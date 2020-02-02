#define _GNU_SOURCE

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "data.h"

struct data
{
	short is_string;
	size_t length;
	unsigned int ref_count;
	char* content;
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
	data* dat = data_new_blob(content, strlen(content)+1);
	dat->is_string = 1;
	return dat;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	data* dat = malloc(sizeof(data));

	dat->is_string = 0;
	dat->length = length;
	dat->ref_count = 1;
	dat->content = malloc(length);

	memcpy(dat->content, content, length);

	return dat;
}

data* data_ref (data* data)
{
	data->ref_count++;
	return data;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
	data->ref_count--;
	if (data->ref_count <= 0)
	{
		free(data->content);
		free(data);
	}
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
	char* str = NULL;

	if (data->is_string)
		asprintf(&str, "String: %s", data->content);
	else
		asprintf(&str, "Blob: %p", data->content);
	
	return str;
}

unsigned int data_hash (data const* data)
{
	unsigned int hash = 0;
	for (size_t i = 0; i < data->length; i++)
	{
		hash = data->content[i] + 31*hash;
	}
	return hash;
}

int data_cmp (data const* a, data const* b)
{
	if (a->length > b->length)
		return 1;
	else if (a->length < b->length)
		return -1;
	else
	{
		for (size_t i = 0; i < a->length; i++)
		{
			if (a->content[i] > b->content[i])
				return 1;
			else if (a->content[i] < b->content[i])
				return -1;
		}
	}

	return 0;
}
