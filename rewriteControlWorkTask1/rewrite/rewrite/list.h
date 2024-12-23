#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct ListElement ListElement;

typedef ListElement* Position;

typedef int Value;

// init list
List* createList(void);

// return first position(null head)
Position first(List* list);

// return next position
Position next(Position position);

// add element to list
void add(List* list, Position position, Value value, int* errorCode);

// return value by position
Value getValue(List* list, Position position, int* errorCode);

// remove element from list
void removeFromList(List* list, Position position, int* errorCode);

// return true if position is the last element, else - false
bool isLast(List* list, Position position);

// free memory of List and set them NULL
void removeList(List** list, int* errorCode);

// get length of list 
int getLength(List* list);
