#include <stddef.h>

#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct data
{
    char is_string;
    unsigned int length;
    unsigned int ref_count;
    char* const content;
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
    struct data* data;

    data->is_string = malloc(sizeof(char));
    data->is_string = 0;
    data->length = strlen(content);

    char* not_const = malloc(data->length*sizeof(char));
    not_const = (char*) content;

    memcpy(data->content, &not_const, sizeof(char*));
    data->ref_count = 0;

	return data;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
    struct data* data;

    data->is_string = 1;
    data->length = length;

    char* not_const = malloc(data->length*sizeof(char));
    not_const = (char*) content;

    memcpy(data->content, &not_const, sizeof(char*));
    data->ref_count = 0;

	return data;
    /*
	struct data* data;

    data->is_string = 0;
    data->length = length;
    data->content = malloc(length*sizeof(char));
    data->ref_count = 0;
    data->content = content;

    return data;*/
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
	return 0;
}

int data_cmp (data const* a, data const* b)
{
	return 0;
}
