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
	size_t bytesize = strlen(content) * sizeof(char);
  char* not_const = malloc(bytesize);
  not_const = (char*) content;

  data dat = {0, bytesize, 0, not_const};
	data *data = &dat;
	return data;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	size_t bytesize = length * sizeof(char);
  char* not_const = malloc(bytesize);
  not_const = (char*) content;

  data dat = {1, bytesize, 0, not_const};
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
	if(data->is_string) printf("String: %s\n", data->content);
    else printf("Blob: %p\n", (void*) &data->content);
}

unsigned int data_hash (data const* data)
{
    unsigned int hash = 0;
    for (unsigned  int i = 0; i < data->length; i++) hash += (unsigned int) data->content[i];
    return hash;
}

int data_cmp (data const* a, data const* b)
{
	return 0;
}
