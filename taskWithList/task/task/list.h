#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct ListElement ListElement;

typedef ListElement* Position;

typedef int Value;

List* createList(void);

Position first(List* list);

Position next(Position position);

void add(List* list, Position position, Value value);

Value getValue(List* list, Position position);

void setValue(List* list, Position position, Value value);

bool removeFromList(List* list, Position position);

bool isLast(List* list, Position position);

bool isValid(List* list, Position position);