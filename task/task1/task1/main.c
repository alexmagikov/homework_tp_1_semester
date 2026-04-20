#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdio.h>
#include "tests.h"

int main() {
    if (!areTestsCompleted()) {
        return -1;
    }

    List* listForNumFromSegment = createList();
    Position positionForListForNumFromSegment = first(listForNumFromSegment);
    
    List* listForNumMoreThenB = createList();
    Position positionForListForNumMoreThenB = first(listForNumMoreThenB);

    int a = 0;
    int b = 0;
    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);

    FILE* f = fopen("f.txt", "r");
    if (f == NULL) {
        printf("file open error");
        return -1;
    }

    FILE* g = fopen("g.txt", "w");
    if (g == NULL) {
        printf("file open error");
        return -1;
    }

    int currentNum = 0;
    fprintf(g, "nums less then %d:\n", a);
    while (fscanf(f, "%d", &currentNum) == 1) {
        if (currentNum < a) {
            fprintf(g, "%d\n", currentNum);
        }

        else if (currentNum > b) {
            add(listForNumMoreThenB, positionForListForNumMoreThenB, currentNum);
            positionForListForNumMoreThenB = next(positionForListForNumMoreThenB);
        }
        else {
            add(listForNumFromSegment, positionForListForNumFromSegment, currentNum);
            positionForListForNumFromSegment = next(positionForListForNumFromSegment);
        }
    }

    positionForListForNumFromSegment = first(listForNumFromSegment);
    positionForListForNumFromSegment = next(positionForListForNumFromSegment);

    positionForListForNumMoreThenB = first(listForNumMoreThenB);
    positionForListForNumMoreThenB = next(positionForListForNumMoreThenB);

    fprintf(g, "nums in interval from %d to %d:\n", a, b);
    for (int i = 0; i < getLength(listForNumFromSegment); i++) {
        fprintf(g, "%d\n", getValue(listForNumFromSegment, positionForListForNumFromSegment));
        positionForListForNumFromSegment = next(positionForListForNumFromSegment);
    }

    fprintf(g, "nums more then %d:\n", b);
    for (int i = 0; i < getLength(listForNumMoreThenB); i++) {
        fprintf(g, "%d\n", getValue(listForNumMoreThenB, positionForListForNumMoreThenB));
        positionForListForNumMoreThenB = next(positionForListForNumMoreThenB);
    }

    freeList(listForNumFromSegment);
    freeList(listForNumMoreThenB);
    fclose(f);
    fclose(g);
    return 0;
}