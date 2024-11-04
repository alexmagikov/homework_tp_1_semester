#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include "list.h"
#include <stdio.h>
#include "tests.h"

void printList(List* list) {
	Position position = first(list);
	position = next(position);
	while (position != NULL) {
		printf("%d ", getValue(list, position));
		position = next(position);
	}
	printf("\n");
}

void addToSortingList(List* list, Value value) {
	Position position = first(list);
	while (!isLast(list, position) && getValue(list, next(position)) <= value) {
		position = next(position);
	}
	add(list, position, value);
}

void removeFromeSortingList(List* list, Value value) {
	Position position = first(list);
	while (!isLast(list, position)) {
		if (getValue(list, next(position)) == value) {
			if (removeFromList(list, position)) {
				printf("success\n");
				break;
			}
		}
		position = next(position);
	}
}

int main(void) {
	if (!testForSetValue() || testForRemoveForNullValue() || !testForCreateList() || !testForAdd() || !testForGetValueForNormalValue() || !testForGetValueForNullValue() || !testForRemoveForNormalValue()) {
		printf("tests are not completed");
		return -1;
	}

	int numOfCommand = -1;
	List* list = createList();
	Position position = first(list);

	while (true) {
		printf("input command: ");
		scanf("%d", &numOfCommand);
		switch (numOfCommand) {
		    case 0: {
				cleanList(list);
				return 0;
				break;
			}
			case 1: {
				Value value = 0;
				printf("input a num to add: ");
				scanf("%d", &value);
				addToSortingList(list, value);
				break;
			case 2: {
				Value value = 0;
				printf("input a num to remove ");
				scanf("%d", &value);
				removeFromeSortingList(list, value);
				break;
			}
			case 3: {
				printList(list);
				break;
			}
			}
		}
	}

	return 0;
}