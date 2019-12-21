#include <stdint.h>

void init2dArray_1(int width, int height, uint8_t* data) {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			data[y*width + x] *= -1;
		}
	}
}

void init2dArray_2(int width, int height, uint8_t** data) {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			data[y][x] *= -1;
		}
	}
}

void init2dArray_3(int width, int height, uint8_t (*data)[width]) {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			data[y][x] *= -1;
		}
	}
}

void init2dArray_4(int width, int height, uint8_t data[height][width]) {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			data[y][x] *= -1;
		}
	}
}




































































































void call_1(int width, int height) {
	uint8_t data[height][width];
	init2dArray_1(width, height, &data[0][0]);
}

void call_2(int width, int height) {
	uint8_t data[height][width];
	uint8_t* pointers[height];
	for(int y = 0; y < height; y++) {
		pointers[y] = &data[y][0];
	}
	init2dArray_2(width, height, pointers);
}

void call_3(int width, int height) {
	uint8_t data[height][width];
	init2dArray_3(width, height, data);
	init2dArray_4(width, height, data);
}
