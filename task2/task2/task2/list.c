#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

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
    if (list == NULL) {
        return NULL;
    }
    ListElement* head = calloc(1, sizeof(ListElement));
    if (head == NULL) {
        return NULL;
    }
    list->head = head;
    list->length = 0;
    return list;
}

Position first(List* list) {
    return list->head;
}

void add(List* list, Position position, Value value, int* errorCode) {
    ListElement* element = malloc(sizeof(ListElement));
    element->value = malloc((strlen(value) + 1) * sizeof(char));

    if (element->value == NULL) {
        *errorCode = -1;
        return;
    }

    strcpy(element->value, value);
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

bool isLast(List* list, Position position) {
    return position->next == NULL;
}

void removeFromList(List* list, Position position, int* errorCode) {
    if (position->next == NULL) {
        *errorCode = -1;
        return;
    }
    ListElement* tmp = position->next->next;
    free(position->next->value);
    free(position->next);
    position->next = tmp;
    list->length--;
}

Position next(Position position) {
    return position->next;
}

void removeList(List** list, int* errorCode) {
    Position position = first(*list);
    while (!isLast(*list, position)) {
        removeFromList(*list, position, errorCode);
    }
    free(*list);
    *list = NULL;
}

int getLength(List* list) {
    return list->length;
}