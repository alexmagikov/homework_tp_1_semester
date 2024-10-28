
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

void push(Stack* stack, int value) {
	if (stack == NULL) {
		printf("not initialized");
	}
	StackElement* element = malloc(sizeof(StackElement));
	element->value = value;
	element->next = stack->head;
	stack->head = element;
}

void pop(Stack* stack) {
	if (stack == NULL || stack->head == NULL) {
		return -1;
	}
	Stack* tmp = stack->head;
	stack->head = stack->head->next;
	free(tmp);
}

int peek(Stack* stack) {
	if (stack == NULL || stack->head == NULL) {
		return -1;
	}
	return stack->head->value;
}

Stack* createStack() {
	return (Stack*)calloc(1, sizeof(Stack));
}
