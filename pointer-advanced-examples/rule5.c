#include <stdio.h>

size_t getSizeof(int arr[5]) {
	return sizeof(arr);
}

size_t sizeof2(int arr[5]);

int main() {
	int arr[5];    //some array
	printf("int arr[5];\n\n");

	//sizeof does not *use* the object,
	//it just inspects its type
	//=> no array-pointer-decay
	printf("sizeof(arr) == %zd == %zd == sizeof(int[5])\n", sizeof(arr), sizeof(int[5]));

	//pointer arithmetic is a use
	//=> decay into pointer of type `int*`
	printf("sizeof(arr + 0) == %zd == %zd == sizeof(int*)\n", sizeof(arr + 0), sizeof(int*));

	//passing as an argument is also a use
	printf("getSizeof(arr) == %zd == %zd == sizeof(int*)\n", getSizeof(arr), sizeof(int*));
	printf("sizeof2(arr) == %zd == %zd == sizeof(int*)\n\n", sizeof2(arr), sizeof(int*));

	//dereferencing the resulting pointer yields a single array element
	printf("sizeof(*(arr + 0)) == %zd == %zd == sizeof(int)\n", sizeof(*(arr + 0)), sizeof(int));
	printf("sizeof(arr[0]) == %zd == %zd == sizeof(int)\n", sizeof(arr[0]), sizeof(int));

	//types of array expressions:
	&arr;     //`int(*)[5]` = pointer to full array
	arr;      //`int[5]` = full array (wants to decay!)
	arr + 0;  //`int*` = pointer to element
	arr[0];   //`int` = element
}

//*Same* function signature as in forward declaration:
//The argument array type truly decays into a pointer type!
size_t sizeof2(int *arr) {
	return sizeof(arr);
}
