#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct ListElement {
	Value value;
	ListElement* next;
} ListElement;

typedef struct List {
	ListElement* head;
} List;

List* createList() {
	List* list = malloc(sizeof(List));
	ListElement* head = calloc(1, sizeof(ListElement));
	list->head = head;
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

bool removeFromList(List* list, Position position) {
	if (position->next == NULL) {
		return false;
	}
	List* tmp = position->next->next;
	free(position->next);
	position->next = tmp;
	return true;
}

Position next(Position position) {
	return position->next;
}
