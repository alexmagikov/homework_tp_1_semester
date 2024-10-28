#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

bool testForCreateStack() {
	Stack* stack = createStack();
	return stack != NULL;
}

bool testForPeek() {
	Stack* stack = createStack();
	push(stack, 1);
	return peek(stack) == 1;
}

bool testForPop() {
	Stack* stack = createStack();
	push(stack, 1);
	push(stack, 2);
	pop(stack);
	return peek(stack) == 1;
}

void main(void) {
	if (!testForPeek || !testForCreateStack() || !testForPop()) {
		printf("tests are failed");
		exit(0);
	}
	Stack* stack = createStack();
	push(stack, 1);
	printf("%d", peek(stack));
	printf("%d ", peek(stack));
	free(stack);
}