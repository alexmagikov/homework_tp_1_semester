#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct ListElement {
	Value value;
	ListElement* next;
} ListElement;

typedef struct List {
	ListElement* head;
	int length;
} List;

List* createList() {
	List* list = malloc(sizeof(List));
	ListElement* head = calloc(1, sizeof(ListElement));
	list->head = head;
	list->length = 0;
	return list;
}

Position first(List* list) {
	return list->head;
}

void add(List* list, Position position, Value value) {
	ListElement* element = malloc(sizeof(ListElement));
	element->value = value;
	element->next = position->next;
	position->next = element;
	list->length++;
}

Value getValue(List* list, Position position) {
	if (position == NULL) {
		return NULL;
	}
	return position->value;
}

void setValue(List* list, Position position, Value value) {
	position->value = value;
}

bool isLast(List* list, Position position) {
	return position->next == NULL;
}

bool isValid(List* list, Position position) {
	return position != NULL;
}

void removeFromList(List* list, Position position) {
	if (position->next == NULL) {
		printf("pointer to NULL");
		exit(0);
	}
	List* tmp = position->next->next;
	free(position->next);
	position->next = tmp;
	list->length -= 1;
}

Position next(Position position) {
	return position->next;
}

void freeListElements(List* list) {
	Position position = first(list);
	while (!isLast(list, position)) {
		removeFromList(list, position);
	}
}

int getLength(List* list) {
	return list->length;
}