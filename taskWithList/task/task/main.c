#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include "list.h"
#include "tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printList(List* list) {
	Position position = next(first(list));
	for (int i = 0; i < getLength(list); i++) {
		printf("%s\n", getValue(list, position));
		position = next(position);
	}
}

char* getName(char* string) {
	int index = 0;
	char* name = NULL;
	while (string[index] != ' ') {
		name = (char*)realloc(name, index + 1);
		if (name == NULL) {
			printf("mem fail");
			exit(0);
		}
		name[index] = string[index];
		index++;
	}
	name[index] = '\0';
	return name;
}

char* getPhone(char* string) {
	char* phone = NULL;
	int index = 0;
	while (string[index] != '-') {
		index++;
	}
	index += 2;
	int lenValue = 0;
	while (string[index] != '\n') {
		phone = (char*)realloc(phone, lenValue + 1);
		if (phone == NULL) {
			printf("mem fail");
			exit(0);
		}
		phone[lenValue] = string[index];
		index++;
		lenValue++;
	}
	phone[lenValue] = '\0';
	return phone;
}

void initializationList(List* list) {
	Position position = first(list);

	FILE* file = fopen("file.txt", "r");
	if (file == NULL) {
		printf("file didnt open");
		return;
	}

	size_t stringLength = 100;
	char* buffer = malloc(stringLength);
	if (buffer == NULL) {
		printf("mem fail");
		fclose(file);
		return;
	}

	while (fgets(buffer, stringLength, file) != NULL) {
		char* value = malloc(strlen(buffer));
		if (value == NULL) {
			printf("mem fail");
			fclose(file);
			return;
		}
		value = strcpy(value, buffer);
		value[strlen(value) - 1] = '\0';
		add(list, position, value);
		position = next(position);
	}
	free(buffer);
	fclose(file);
}	

List* merge(List* firstList, List* secondList, int command) {
	List* resultList = createList();
	Position resultListPosition = first(resultList);

	Position firstListPosition = first(firstList);
	firstListPosition = next(firstListPosition);

	Position secondListPosition = first(secondList);
	secondListPosition = next(secondListPosition);

	int firstListIndex = 0;
	int secondListIndex = 0;

	while (firstListIndex < getLength(firstList) && secondListIndex < getLength(secondList)) {
		if (command == 1) {
			char* firstString = getValue(firstList, firstListPosition);
			char* secondString = getValue(secondList, secondListPosition);
			if (strcmp(getName(firstString), getName(secondString))	 < 0) {
				add(resultList, resultListPosition, getValue(firstList, firstListPosition));
				firstListPosition = next(firstListPosition);
				firstListIndex++;
			}
			else {
				add(resultList, resultListPosition, getValue(secondList, secondListPosition));
				secondListPosition = next(secondListPosition);
				secondListIndex++;
			}
			resultListPosition = next(resultListPosition);
		}
		else if (command = 2) {
			char* firstString = getValue(firstList, firstListPosition);
			char* secondString = getValue(secondList, secondListPosition);
			if (strcmp(getPhone(firstString), getPhone(secondString)) < 0) {
				add(resultList, resultListPosition, getValue(firstList, firstListPosition));
				firstListPosition = next(firstListPosition);
				firstListIndex++;
			}
			else {
				add(resultList, resultListPosition, getValue(secondList, secondListPosition));
				secondListPosition = next(secondListPosition);
				secondListIndex++;
			}
			resultListPosition = next(resultListPosition);
		}
	}

	while (firstListIndex < getLength(firstList)) {
		add(resultList, resultListPosition, getValue(firstList, firstListPosition));
		firstListIndex++;
		resultListPosition = next(resultListPosition);
		firstListPosition = next(firstListPosition);
	}

	while (secondListIndex < getLength(secondList)) {
		add(resultList, resultListPosition, getValue(secondList, secondListPosition));
		secondListIndex++;
		resultListPosition = next(resultListPosition);
		secondListPosition = next(secondListPosition);
	}

	return resultList;
}

List* createListByIndexes(List* list, int leftIndex, int rightIndex) {
	Position positionList = first(list);
	positionList = next(positionList);

	List* resultList = createList();
	Position resultListPosition = first(resultList);

	for (int i = leftIndex; i < rightIndex; i++) {
		add(resultList, resultListPosition, getValue(list, positionList));
		resultListPosition = next(resultListPosition);
		positionList = next(positionList);
	}
	return resultList;
}

void mergeSort(List* list, int command) {
	if (getLength(list) <= 1) {
		return;
	}

	int midIndex = getLength(list) / 2;
	
	Position positionList = first(list);
	positionList = next(positionList);

	List* leftList = createList();
	Position leftListPosition = first(leftList);

	List* rightList = createList();
	Position rightListPosition = first(rightList);

	for (int i = 0; i < midIndex; i++) {
		add(leftList, leftListPosition, getValue(list, positionList));
		leftListPosition = next(leftListPosition);
		positionList = next(positionList);
	}

	for (int i = midIndex; i < getLength(list); i++) {
		add(rightList, rightListPosition, (getValue(list, positionList)));
		rightListPosition = next(rightListPosition);
		positionList = next(positionList);
	}
	/*
	List* leftList = createListByIndexes(list, 0, midIndex);
	List* rightList = createListByIndexes(list, midIndex, getLength(list));
	*/
	mergeSort(leftList, command);
	mergeSort(rightList, command);
	List* resultList = merge(leftList, rightList, command);
	Position resultListPosition = first(resultList);
	resultListPosition = next(resultListPosition);
	Position resultPosition = first(list);
	resultPosition = next(resultPosition);
	for (int i = 0; i < getLength(list); i++) {
		setValue(list, resultPosition, getValue(resultList, resultListPosition));
		resultListPosition = next(resultListPosition);
		resultPosition = next(resultPosition);
	}
}

bool testForMerge() {

}

bool testForMergeSort() {

}

bool testForInitializationList() {

}

int main(void) {
	if (!testForSetValue() || !testForCreateList() || !testForAdd() || !testForGetValueForNormalValue() || !testForGetValueForNullValue() || !testForRemoveForNormalValue()) {
		printf("tests are not completed");
		return -1;
	}
	List* list = createList();

	int command = 2;
	printf("input command of sorting parameter(1 - sorting for names, 2 - sorting for phones): ");
	scanf("%d", &command);
	initializationList(list);
	mergeSort(list, command);
	printList(list);
	return 0;
}