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
	data *dat = malloc(sizeof(data) + sizeof(char) * bsize);
	//char* not_const = malloc(bsize * sizeof(char));
	//memcpy(not_const, content, bsize * sizeof(char));

	dat->is_string = 1;
	dat->length = bsize;
	dat->ref_count = 1;
	memcpy(dat->content, content, bsize * sizeof(char));
	//dat->content = &not_const;

	printf("%s\n", dat->content);
	return dat;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	char* not_const = malloc(length  * sizeof(char) + sizeof(char));
	memcpy(not_const, content, length + 1);
	//not_const = (char*) content;
	printf("%s\n", not_const);

	data dat = {0, length, 0, not_const};
	data *data = &dat;
	return data;
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
	int hash = 1;
	for (int i = 0; i < (int) data->length;	hash += (int) data->content[++i]);
	printf("Hash:%d\n", hash);
	return hash;
}

int data_cmp (data const* a, data const* b)
{
	return 0;
}
