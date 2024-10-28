#pragma once

typedef struct Stack Stack;

void push(Stack* stack, int value);

void pop(Stack* stack);

int peek(Stack* stack);

Stack* createStack();