#include <stddef.h>

#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct data
{
	short is_string;
	size_t length;
	unsigned int ref_count;
	char* const content;
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
	size_t bsize = strlen(content);
	data *dat = malloc(sizeof(data) + sizeof(char) * (bsize - 1));

	dat->is_string = 1;
	dat->length = bsize;
	dat->ref_count = 1;
	strcpy((char*) &dat->content, (char*) &content);

	return dat;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	data *dat = malloc(sizeof(data) + sizeof(char) * (length - 1));

	dat->is_string = 1;
	dat->length = length;
	dat->ref_count = 1;
	strcpy((char*) &dat->content, (char*) &content);

	return dat;
}

data* data_ref (data* data)
{
	data->ref_count++;
	printf("ref: %p\n", data);
	return data;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
	data->ref_count--;
	if(data->ref_count == 0) free(data);
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
	char* prefix = data->is_string ? "String: " : "Blob: ";
	char* data_string = malloc((strlen(prefix)+data->length + 2)*sizeof(char));
	if(data->is_string)
		sprintf(data_string,"%s%s", prefix, data->content);
	else
		sprintf(data_string,"%s%p", prefix, &data->content);
	printf("string pointer: %p\nstring: %s\n", data, data->content);
	return data_string;
}

unsigned int data_hash (data const* data)
{
	unsigned int hash = 0;
	for (int i = 0; i < (int) data->length;	hash += i * (int) data->content[++i]);
	return hash;
}

int data_cmp (data const* a, data const* b)
{
	return 0;
}
