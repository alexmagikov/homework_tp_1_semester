
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct StackElement {
	int value;
	struct StackElement* next;
} StackElement;

typedef struct Stack {
	StackElement* head;
} Stack;

void push(Stack* stack, int value, int* errorCode) {
	if (stack == NULL) {
		*errorCode = -1;
		return;
	}
	StackElement* element = malloc(sizeof(StackElement));
	if (element == NULL) {
		*errorCode = -1;
		return;
	}
	element->value = value;
	element->next = stack->head;
	stack->head = element;
}

void pop(Stack* stack, int* errorCode) {
	if (stack == NULL || stack->head == NULL) {
		*errorCode = -1;
		return;
	}
	Stack* tmp = stack->head;
	stack->head = stack->head->next;
	free(tmp);
}

int peek(Stack* stack, int* errorCode) {
	if (stack == NULL || stack->head == NULL) {
		*errorCode = -1;
		return;
	}
	return stack->head->value;
}

bool isEmpty(Stack* stack) {
	return stack->head == NULL;
}

Stack* createStack() {
	return (Stack*)calloc(1, sizeof(Stack));
}

void clearStack(Stack** stack, int* errorCode) {
	while (!isEmpty(*stack)) {
		pop(*stack, errorCode);
	}
	free(*stack);
	*stack = NULL;
}