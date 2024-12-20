#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool testForCreateList(void) {
	List* list = createList();
	bool result = createList() != NULL;
	freeList(list);
	return result;
}

bool testForAdd(void) {
	List* list = createList();
	Position position = first(list);
	add(list, position, 1);
	bool result = position != NULL;
	freeList(list);
	return result;
}

bool testForGetValueForNormalValue(void) {
	List* list = createList();
	Position position = first(list);
	add(list, position, 1);
	position = next(position);
	bool result = getValue(list, position) == 1;
	freeList(list);
	return result;
}

bool testForGetValueForNullValue(void) {
	List* list = createList();
	Position position = first(list);
	bool result = getValue(list, position) == NULL;
	freeList(list);
	return result;
}

bool testForRemoveForNormalValue(void) {
	List* list = createList();
	Position position = first(list);
	add(list, position, 1);
	removeFromList(list, position);
	bool result = isLast(list, position);
	freeList(list);
	return result;
}

bool testForSetValue(void) {
	List* list = createList();
	Position position = first(list);
	add(list, position, 1);
	position = next(position);
	add(list, position, 2);
	setValue(list, position, 3);
	bool result = getValue(list, position) == 3;
	freeList(list);
	return result;
}

bool testForGetLength(void) {
	List* list = createList();
	Position position = first(list);
	add(list, position, 1);
	position = next(position);
	add(list, position, 2);
	bool result = getLength(list) == 2;
	freeList(list);
	return result;
}

bool areTestsCompleted(void) {
	bool tests[7] = {
		testForAdd(),
		testForCreateList(),
		testForGetValueForNormalValue(),
		testForGetValueForNullValue(),
		testForRemoveForNormalValue(),
		testForSetValue(),
		testForGetLength()
	};
	
	for (int i = 0; i < 7; i++) {
		
		if (!tests[i]) {
			printf("test %d failed", i);
			return false;
		}
	}
	return true;
}