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
	char* not_const = malloc(bsize * sizeof(char));
	not_const = (char*) content;

	data dat = {1, bsize, 0, not_const};
	data *data = &dat;
	return data;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	char* not_const = malloc(length  * sizeof(char));
	not_const = (char*) content;

	data dat = {0, length, 0, not_const};
	data *data = &dat;
	return data;
}

data* data_ref (data* data)
{
	data->ref_count++;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
	data->ref_count--;
	if(data->ref_count == 0) free(data->content);
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
    char* prefix = data->is_string ? "String: " : "Blob: ";
    char* data_string = malloc((strlen(prefix)+data->length + 2)*sizeof(char));
	sprintf(data_string,"%s%s", prefix, data->content);
	return data_string;
}

unsigned int data_hash (data const* data)
{
	unsigned int hash = 0;
	for (unsigned  int i = 0; i < data->length; i++)
		hash += (unsigned int) data->content[i];
    printf("Hash:%d\n", hash);
	return hash;
}

int data_cmp (data const* a, data const* b)
{
	return 0;
}
