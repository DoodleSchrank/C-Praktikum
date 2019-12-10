#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t curCount, allocatedSize;
	double* data;
} Stack;

void Stack_construct(Stack* me)
{
	me = malloc(sizeof(Stack));
	me->curCount = 0;
	me->allocatedSize = sizeof(Stack);
}
bool Stack_isEmpty(Stack* me)
{
	return me->curCount == 0;
}
void Stack_push(Stack* me, double value)
{
	me->curCount++;
	if((void *) *(&me->data + me->curCount + 1) == (void *) *(&me + me->allocatedSize))
	{
		me = realloc(me, 2 * sizeof(size_t) + 2 * me->curCount * sizeof(double));
		me->allocatedSize = 2 * sizeof(size_t) + 2 * me->curCount * sizeof(double);
	}
	*(&me->data + me->curCount + 1) =  value;
}
double Stack_pop(Stack* me)
{
	me->curCount--;
	double tos = (double) *(&me + 2 * sizeof(size_t) + me->curCount * sizeof(double));
	*((&me + 2 * sizeof(size_t) + me->curCount * sizeof(double))) = NULL;
	return tos;
}
void Stack_destruct(Stack* me)
{
	free(me);
}

double calculate(char* expression) {
	Stack myStack;
	Stack_construct(&myStack);
	while(*expression) {
		switch(*expression) {
			case ' ': {
				expression++;
			} break;

			case '+':
			case '-':
			case '*':
			case '/': {
				assert(!Stack_isEmpty(&myStack));
				double argB = Stack_pop(&myStack);
				assert(!Stack_isEmpty(&myStack));
				double argA = Stack_pop(&myStack);
				Stack_push(&myStack, *expression == '+' ? argA + argB :
				                     *expression == '-' ? argA - argB :
				                     *expression == '*' ? argA * argB :
				                                          argA / argB);
				expression++;
			} break;

			default: {
				char* nextToken;
				double value = strtod(expression, &nextToken);
				assert(nextToken != expression);
				Stack_push(&myStack, value);
				expression = nextToken;
			} break;
		}
	}
	assert(!Stack_isEmpty(&myStack));
	double result = Stack_pop(&myStack);
	assert(Stack_isEmpty(&myStack));
	return result;
}

int main() {
	printf("%f\n", calculate("1 1 1 1 + + + 1 - 1 1 1 1 + + + 1 1 + / * 1 1 + 1 1 + * 1 1 + * 1 - *"));
}
