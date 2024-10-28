#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

bool testForCreateStack() {
	Stack* stack = createStack();
	return stack->head == NULL;
}

bool testForPush() {
	Stack* stack = createStack();
	push(stack, 1);
	return peek(stack) == 1;
}

void main(void) {
	if (!testForPush || !testForCreateStack()) {
		printf("tests are failed");
		exit(0);
	}
	Stack* stack = createStack();
	push(stack, 1);
	printf("%d", peek(stack));
	printf("%d ", peek(stack));
	free(stack);
}