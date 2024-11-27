#pragma once

typedef struct Dictionary Dictionary;

typedef struct Value {
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
void insert(Dictionary** dictionary, const char* key, const char* value, int height);