#define _CRT_SECURE_NO_WARNINGS

#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Dictionary {
    Value value;
    Dictionary* leftChild;
    Dictionary* rightChild;
};

Dictionary* leftRotation(Dictionary* dictionary) {
    Dictionary* rightChild = dictionary->rightChild;
    Dictionary* rightChildLeftChild = dictionary->rightChild->leftChild;
    rightChild->leftChild = dictionary;
    dictionary->rightChild = rightChildLeftChild;

    int dictLeftHeight = (dictionary->leftChild == NULL) ? 0 : dictionary->leftChild->value.height;
    int dictRightHeight = (dictionary->rightChild == NULL) ? 0 : dictionary->rightChild->value.height;
    dictionary->value.height = 1 + (dictLeftHeight > dictRightHeight ? dictLeftHeight : dictRightHeight);

    int rightRightHeight = (rightChild->rightChild == NULL) ? 0 : rightChild->rightChild->value.height;
    rightChild->value.height = 1 + (dictionary->value.height > rightRightHeight ? dictionary->value.height : rightRightHeight);

    dictionary->value.balance = dictRightHeight - dictLeftHeight;
    rightChild->value.balance = rightRightHeight - dictionary->value.height;

    return rightChild;
}

Dictionary* rightRotation(Dictionary* dictionary) {
    Dictionary* leftChild = dictionary->leftChild;
    Dictionary* leftChildRightChild = dictionary->leftChild->rightChild;
    leftChild->rightChild = dictionary;
    dictionary->leftChild = leftChildRightChild;
    int dictLeftHeight = (dictionary->leftChild == NULL) ? 0 : dictionary->leftChild->value.height;
    int dictRightHeight = (dictionary->rightChild == NULL) ? 0 : dictionary->rightChild->value.height;
    dictionary->value.height = 1 + (dictLeftHeight > dictRightHeight ? dictLeftHeight : dictRightHeight);

    int leftLeftHeight = (leftChild->leftChild == NULL) ? 0 : leftChild->leftChild->value.height;
    leftChild->value.height = 1 + (dictionary->value.height > leftLeftHeight ? dictionary->value.height : leftLeftHeight);

    dictionary->value.balance = dictRightHeight - dictLeftHeight;
    leftChild->value.balance = dictionary->value.height - leftLeftHeight;

    return leftChild;
}

Dictionary* BigLeftRotation(Dictionary* dictionary) {
    dictionary->rightChild = rightRotation(dictionary->rightChild);
    return leftRotation(dictionary);
}

Dictionary* BigRightRotation(Dictionary* dictionary) {
    dictionary->leftChild = leftRotation(dictionary->leftChild);
    return rightRotation(dictionary);
}

Dictionary* balance(Dictionary* dictionary) {
    if (dictionary->value.balance == 2) {
        if (dictionary->rightChild->value.balance >= 0) {
            return leftRotation(dictionary);
        }
        return BigLeftRotation(dictionary);
    }
    if (dictionary->value.balance == -2) {
        if (dictionary->leftChild->value.balance <= 0) {
            return rightRotation(dictionary);
        }
        return BigRightRotation(dictionary);
    }
    return dictionary;
}

void insert(Dictionary** dictionary, const char* key, const char* value) {
    Value dictionaryValue = { .balance = 0, .height = 1, .key = malloc(strlen(key) * sizeof(char) + 1), .value = malloc(strlen(value) * sizeof(char) + 1) };
    strcpy(dictionaryValue.key, key);
    strcpy(dictionaryValue.value, value);

    if (dictionaryValue.value == NULL || dictionaryValue.key == NULL) {
        return;
    }
    if (*dictionary == NULL) {
        *dictionary = (Dictionary*)malloc(sizeof(Dictionary));
        if (*dictionary == NULL) {
            return;
        }
        (*dictionary)->value = dictionaryValue;
        (*dictionary)->leftChild = NULL;
        (*dictionary)->rightChild = NULL;
        return;
    }
    if (strcmp(dictionaryValue.key, (*dictionary)->value.key) < 0) {
        insert(&(*dictionary)->leftChild, key, value);
    }
    else if (strcmp(dictionaryValue.key, (*dictionary)->value.key) > 0) {
        insert(&(*dictionary)->rightChild, key, value);
    }
    else if (!strcmp(dictionaryValue.key, (*dictionary)->value.key)) {
        free((*dictionary)->value.value);
        free((*dictionary)->value.key);
        (*dictionary)->value = dictionaryValue;
    }

    int rightHeight = ((*dictionary)->rightChild == NULL) ? 0 : (*dictionary)->rightChild->value.height;
    int leftHeight = ((*dictionary)->leftChild == NULL) ? 0 : (*dictionary)->leftChild->value.height;

    (*dictionary)->value.height = (rightHeight > leftHeight ? rightHeight : leftHeight) + 1;
    (*dictionary)->value.balance = rightHeight - leftHeight;

    *dictionary =  balance(*dictionary);
}

