#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int* num1, int* num2) {
    int swapVariable = *num1;
    *num1 = *num2;
    *num2 = swapVariable;
}

int hoarSort(int array[], int leftIndex, int rightIndex) {
    int pivot = array[rand() % (rightIndex - leftIndex) + leftIndex];
    int endIndex = rightIndex;
    int startIndex = leftIndex;
    while (startIndex <= endIndex) {
        while (array[startIndex] < pivot) {
            startIndex++;
        }
        while (array[endIndex] > pivot) {
            endIndex--;
        }
        if (startIndex <= endIndex) {
            swap(&array[startIndex], &array[endIndex]);
            startIndex++;
            endIndex--;
        }
    }
    return startIndex;
}

void qSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int separator = hoarSort(array, leftIndex, rightIndex);
        qSort(array, leftIndex, separator - 1);
        qSort(array, separator, rightIndex);
    }
}

int searchMostFreaquentElement(int array[], int numOfElements) {
    int mostFreaquent = -1;
    int countOfFreaquentMax = 0;
    int countOfFreaquent = 0;
    for (int i = 0; i < numOfElements - 1; i++) {
        countOfFreaquent++;
        if (array[i] != array[i + 1]) {
            if (countOfFreaquentMax < countOfFreaquent) {
                countOfFreaquentMax = countOfFreaquent;
                mostFreaquent = array[i];
            }
            countOfFreaquent = 0;
        }
    }
    countOfFreaquent++;
    if (countOfFreaquent > countOfFreaquentMax) {
        mostFreaquent = array[numOfElements - 1];
    }
    return mostFreaquent;   
}   

bool testForStandartValue1() {
    int array[5] = { 1,2,3,4,5 };
    return searchMostFreaquentElement(array, 5) == 1;
}

bool testForEqualLastValue() {
    int array[20] = { 0,0,1,3,4,4,6,6,6,7,8,9,9,9,9,10,10,10,10,10};
    return searchMostFreaquentElement(array, 20) == 10;
}

bool testForSrandartValue2() {
    int array[5] = { 1,1,2,2,3};
    return searchMostFreaquentElement(array, 5) == 1;
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
    printf("Array ");
	for (int i = 0; i < numOfElements; i++) {
		array[i] = rand() % (11);
		printf("%d ", array[i]);
	}
	printf("\n");
	return array;
}

void main(void) {
    srand(time(0));
	int* array = createArray(20);
    qSort(array, 0, 19);
    if (testForSrandartValue2() && testForEqualLastValue() && testForStandartValue1()) {
        printf("The most Freaquent element %d", searchMostFreaquentElement(array, 20));
    }
    else {
        printf("tests were not performed");
    }
}
