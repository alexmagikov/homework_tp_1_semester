#pragma once
#include <stdbool.h>

typedef struct Dictionary Dictionary;

typedef struct Value {
    int balance;
    int height;
    const char* key;
    const char* value;
} Value;

Dictionary* leftRotation(Dictionary* dictionary);

Dictionary* rightRotation(Dictionary* dictionary);

Dictionary* BigLeftRotation(Dictionary* dictionary);

Dictionary* BigRightRotation(Dictionary* dictionary);

//Dictionary* balance(Dictionary* dictionary);

//insert value by key in dictionary. 
void insert(Dictionary** dictionary, const char* key, const char* value);

//
bool find(Dictionary* dictionary, const char* key);

//
char* getValue(Dictionary* dictionary, const char* key);

void removeFromDictionary(Dictionary** dictionary, int key);

void freeDictionary(Dictionary** dictionary);

void print(Dictionary* dictionary);