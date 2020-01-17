#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct array_element
{
	int age;
	char name[256];
};

struct array
{
	off_t size;
	off_t count;
	struct array_element element[];
};

void array_init(struct array* arr, off_t size)
{
	arr->size = size;
	arr->count = 0;
}

void array_reset(struct array* arr)
{
	arr->count = 0;
}

void array_append(struct array* arr, int age, char* name)
{
	if ((sizeof(*arr) + sizeof(struct array_element) * (arr->count + 1)) > arr->size)
	{
		return;
	}

	arr->element[arr->count].age = age;
	strncpy(arr->element[arr->count].name, name, 256);
	arr->count++;
}

struct array_element* array_get(struct array* arr, off_t index)
{
	if (index >= arr->count)
	{
		return NULL;
	}

	return &arr->element[index];
}

void array_print(struct array* arr)
{
	for (off_t i = 0; i < arr->count; i++)
	{
		struct array_element* e = array_get(arr, i);
		printf("arr[%lu] = { %d, %s }\n", i, e->age, e->name);
	}
}

int main(void)
{
	struct array* arr;
	int fd = open("myarray", O_RDWR | O_CREAT, 0644);
	
	off_t filesize = 1024;
	size_t readsize = pread(fd, &filesize, sizeof(filesize), 0);
	if (readsize != sizeof(filesize))
	{
		ftruncate(fd, filesize);
	}
	
	arr = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (arr == MAP_FAILED)
	{
		printf("mmap failed\n");
		return 1;
	}
	
	if (readsize != sizeof(filesize))
	{
		array_init(arr, filesize);
	}

	array_print(arr);

	array_reset(arr);
	array_append(arr, 18, "Max Mustermann");
	array_append(arr, 21, "Moritz Mustermann");
	array_append(arr, 18, "Petra Mustermann");
	array_append(arr, 21, "Paula Mustermann");
	array_print(arr);

	array_reset(arr);
	array_append(arr, 21, "Paula Mustermann");
	array_print(arr);

	munmap(arr, filesize);
	close(fd);

	return 0;
}
