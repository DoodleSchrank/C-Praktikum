#include <stdint.h>

struct array2d {
	int width, height;
	void* _data;      //actually a `uint8_t (*)[me->width];`
	#define array2d_typedData(me) ((uint8_t (*)[me->width])(me)->_data)
};

void array2d_init(struct array2d* me, int width, int height, uint8_t data[height][width]) {
	me->width = width;
	me->height = height;
	me->_data = data;
}

uint8_t array2d_getElementAt(struct array2d* me, int x, int y) {
	uint8_t (*data)[me->width] = array2d_typedData(me);
	return data[y][x];
}
