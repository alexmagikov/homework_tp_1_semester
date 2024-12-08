#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "tests.h"

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

int binSearch(int array[],int numOfElements, int searchNum) {
	int leftIndex = 0;
	int rightIndex = numOfElements - 1;
	while (leftIndex <= rightIndex) { 
		int mid = (leftIndex + rightIndex) / 2;
		if (array[mid] < searchNum) {
			leftIndex = mid + 1;
		}
		if (array[mid] > searchNum) {
			rightIndex = mid - 1;
		}
		if (array[mid] == searchNum) {
			return mid;
		}
	}
	return -1;
}

bool testForNormalValue() {
	int testArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	return binSearch(testArray, 10, 5) == 4;
}

bool testForBoundaryValues1() {
	int testArray[5] = { 1,2,3,4,5 };
	return binSearch(testArray, 5, 3) == 2; 
}

bool testForBoundaryValues2() {
	int testArray[5] = { 1,2,3,4,5 };
	return binSearch(testArray, 5, 1) == 0;
}

bool testForBoundaryValues3() {
	int testArray[5] = { 1,2,3,4,5 };
	return binSearch(testArray, 5, 5) == 4;
}

bool testForBadValues() {
	int testArray[5] = { 1,2,3,4,5 };
	return binSearch(testArray, 5, 6) == -1;
}

int* createArray(int numOfElements) {
	int* array = (int*)malloc(numOfElements * sizeof(int));
	if (array == NULL) {
		return NULL;
	}
	return array;
}

void main(void) {
	srand(time(0));
	int n;
	int k;
	printf("Input n ");
	scanf("%d", &n);
	printf("Input k ");
	scanf("%d", &k);

	int* arrayN = createArray(n);
	for (int i = 0; i < n; i++) {
		arrayN[i] = rand() % 11;
		printf("%d ", arrayN[i]);
	}
	printf("    ");
	int* arrayK = createArray(k);
	for (int i = 0; i < k; i++) {
		arrayK[i] = rand() % 11;
		printf("%d ", arrayK[i]);
	}
	printf("\n");
	qSort(arrayN, 0, n - 1);
	if (isNormalNum(n) && isNormalNum(k) && testForBoundaryValues1() && testForNormalValue() && testForBadValues() && testForBoundaryValues2() && testForBoundaryValues3()) {
		for (int i = 0; i < k; i++) {
			if (binSearch(arrayN, n, arrayK[i]) == -1) {
				printf("%d isn t contained in array \n", arrayK[i]);
			}
			else {
				printf("%d is contained in array \n", arrayK[i]);
			}
		}
	}
	else {
		printf("not normal num");
	}
}