#pragma once

#include <stdbool.h>

typedef struct Stack Stack;

// add element to stak 
void push(Stack* stack, int value, int* errorCode);

// remove element from head of stak
void pop(Stack* stack, int* errorCode);

// peek the element on head 
int peek(Stack* stack, int* errorCode);

// return true if stak is empty. else false 
bool isEmpty(Stack* stack);

// initialize stack 
Stack* createStack();

// remove Stack
void clearStack(Stack** stack, int* errorCode);