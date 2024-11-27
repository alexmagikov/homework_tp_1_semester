#define _CRT_SECURE_NO_WARNINGS

#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

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
    return rightChild;
    
}

Dictionary* rightRotation(Dictionary* dictionary) {
    Dictionary* leftChild = dictionary->leftChild;
    Dictionary* leftChildRightChild = dictionary->leftChild->rightChild;
    leftChild->rightChild = dictionary;
    dictionary->leftChild = leftChildRightChild;
    return leftChild;
}

Dictionary* BigLeftRotation(Dictionary* dictionary) {
    
}

Dictionary* BigRightRotation(Dictionary* dictionary) {

}

int getBalance(Dictionary* dictionary) {
    int balanceDictionary = 0;
    int balanceRightChildDictionary = 0;
    int balanceLeftChildDictionary = 0;
    if (dictionary->leftChild == 0)
}

Dictionary* balance(Dictionary* dictionary) {
    int balanceDictionary = dictionary->rightChild->value.height - dictionary->leftChild->value.height;
    int balanceRightChildDictionary = dictionary->rightChild->rightChild->value.height - dictionary->rightChild->leftChild->value.height;
    int balanceLeftChildDictionary = dictionary->rightChild->rightChild->value.height - dictionary->rightChild->leftChild->value.height;
    if (balanceDictionary == 2) {
        if (balanceRightChildDictionary >= 0) {
            return leftRotation(dictionary);
        }
        return BigLeftRotation(dictionary);
    }
    if (balanceDictionary == -2) {
        if (balanceLeftChildDictionary <= 0) {
            return rightRotation(dictionary);
        }
        return BigRightRotation(dictionary);
    }
}

void insert(Dictionary** dictionary, const char* key, const char* value, int height) {
    Value dictionaryValue = { .height = height, .key = malloc(strlen(key) * sizeof(char) + 1), .value = malloc(strlen(value) * sizeof(char) + 1) };
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
        (*dictionary)->value.height = dictionaryValue.height;
        (*dictionary)->value.key = dictionaryValue.key;
        (*dictionary)->value.value = dictionaryValue.value;
        (*dictionary)->leftChild = NULL;
        (*dictionary)->rightChild = NULL;
        return;
    }
    if (strcmp(dictionaryValue.key, (*dictionary)->value.key) < 0) {
        insert(&(*dictionary)->leftChild, key, value, (*dictionary)->value.height + 1);
    }
    else if (strcmp(dictionaryValue.key, (*dictionary)->value.key) > 0) {
        insert(&(*dictionary)->rightChild, key, value, (*dictionary)->value.height + 1);
    }
    else if (!strcmp(dictionaryValue.key, (*dictionary)->value.key)) {
        free((*dictionary)->value.value);
        free((*dictionary)->value.key);
        (*dictionary)->value = dictionaryValue;
    }
    *dictionary =  balance(*dictionary);
}

