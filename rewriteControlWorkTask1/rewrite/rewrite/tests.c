#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deleteOddIndexes.h"

bool testForCreateList(void) {
    List* list = createList();
    bool result = list != NULL;
    int errorCode = 0;
    if (result) {
        removeList(&list, &errorCode);
    }
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForAdd(void) {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, 1, &errorCode);
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
    add(list, position, 123, &errorCode);
    position = next(position);
    bool result = getValue(list, position, &errorCode) == 123;
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForGetValueForNullValue(void) {
    List* list = createList();
    Position position = first(list);
    position = next(position);
    int errorCode = 0;
    int value = getValue(list, position, &errorCode);
    bool result = errorCode == -1;
    removeList(&list, &errorCode);
    return result;
}

bool testForRemoveForNormalValue(void) {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;
    add(list, position, 123, &errorCode);
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
    add(list, position, 23, &errorCode);
    position = next(position);
    add(list, position, 23, &errorCode);
    bool result = getLength(list) == 2;
    removeList(&list, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForDeleteOddIndexesForNormalValue() {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;

    add(list, position, 1, &errorCode);
    position = next(position);
    add(list, position, 2, &errorCode);
    position = next(position);
    add(list, position, 3, &errorCode);
    position = next(position);
    add(list, position, 4, &errorCode);
    position = next(position);
    add(list, position, 5, &errorCode);
    position = next(position);
    add(list, position, 6, &errorCode);
    position = next(position);
    add(list, position, 7, &errorCode);
    position = next(position);
    add(list, position, 8, &errorCode);
    position = next(position);
    add(list, position, 9, &errorCode);

    deleteOddIndexes(list, &errorCode);
    
    int result[5] = { 1,3,5,7,9 };

    position = first(list);
    position = next(position);
    for (int i = 0; i < getLength(list); i++) {
        if (getValue(list, position, &errorCode) != result[i]) {
            removeList(&list, &errorCode);
            return false;
        }
        position = next(position);
    }
    removeList(&list, &errorCode);
    return errorCode == 0;
}

bool testForDeleteOddIndexesForBorderValue() {
    List* list = createList();
    Position position = first(list);
    int errorCode = 0;

    add(list, position, 1, &errorCode);

    deleteOddIndexes(list, &errorCode);

    int result = 1;

    position = first(list);
    position = next(position);
    
    if (getValue(list, position, &errorCode) != result) {
        removeList(&list, &errorCode);
        return false;
    }
    removeList(&list, &errorCode);
    return errorCode == 0;
}

bool areTestsCompleted(void) {
    bool tests[8] = {
        testForAdd(),
        testForCreateList(),
        testForGetValueForNormalValue(),
        testForGetValueForNullValue(),
        testForRemoveForNormalValue(),
        testForGetLength(),
        testForDeleteOddIndexesForNormalValue(),
        testForDeleteOddIndexesForBorderValue(),
    };

    for (int i = 0; i < 8; i++) {
        if (!tests[i]) {
            printf("test %d failed", i);
            return false;
        }
    }
    return true;
}