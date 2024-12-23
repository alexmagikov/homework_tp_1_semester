#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include  "addElementsStartedFromA.h"

bool testForCreateList(void) {
    List* list = createList();
    bool result = createList() != NULL;
    int errorCode = 0;
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForAdd(void) {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "1", &errorCode);
    position = next(position);
    bool result = position != NULL;
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForGetValueForNormalValue(void) {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "123", &errorCode);
    position = next(position);
    bool result = !strcmp(getValue(list, position), "123");
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForGetValueForNullValue(void) {
    List* list = createList();
    Position position = first(list);
    bool result = getValue(list, position) == NULL;
    int errorCode = 0;
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForRemoveForNormalValue(void) {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "123", &errorCode);
    removeFromList(list, position, &errorCode);
    bool result = isLast(list, position);
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForGetLength(void) {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "123", &errorCode);
    position = next(position);
    add(list, position, "234", &errorCode);
    bool result = getLength(list) == 2;
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForAddElementStartedFromAForNormalValue() {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "a", &errorCode);
    position = next(position);
    add(list, position, "b", &errorCode);
    position = next(position);
    add(list, position, "a", &errorCode);
    addElementsStartedFromA(list, &errorCode);
    position = first(list);
    position = next(position);
    char result[5] = "abaaa";
    for (int i = 0; i < getLength(list); i++) {
        if (getValue(list, position)[0] != result[i]) {
            removeList(&list, &errorCode);
            return false;
        }
        position = next(position);
    }
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return true;
}

bool testForAddElementStartedFromAForBorderValue() {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "a", &errorCode);
    addElementsStartedFromA(list, &errorCode);
    position = first(list);
    position = next(position);
    char result[2] = "aa";
    for (int i = 0; i < getLength(list); i++) {
        if (getValue(list, position)[0] != result[i]) {
            removeList(&list, &errorCode);
            return false;
        }
        position = next(position);
    }
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return true;
}

bool testForAddElementStartedFromAForBorderValueForNoElementStartFromA() {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, "b", &errorCode);
    addElementsStartedFromA(list, &errorCode);
    position = first(list);
    position = next(position);
    char result = 'b';
    if (getValue(list, position)[0] != result) {
        removeList(&list, &errorCode);
        return false;
    }
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return true;
}

bool areTestsCompleted(void) {
    bool tests[9] = {
        testForAdd(),
        testForCreateList(),
        testForGetValueForNormalValue(),
        testForGetValueForNullValue(),
        testForRemoveForNormalValue(),
        testForGetLength(),
        testForAddElementStartedFromAForNormalValue(),
        testForAddElementStartedFromAForBorderValue(),
        testForAddElementStartedFromAForBorderValueForNoElementStartFromA(),
    };

    for (int i = 0; i < 9; i++) {

        if (!tests[i]) {
            printf("test %d failed", i);
            return false;
        }
    }
    return true;
}