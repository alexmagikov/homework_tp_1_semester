#pragma once

typedef struct HashItem HashItem;

typedef struct HashTable HashTable;

// create HashTable with size (size) and initialzie them NULL value
HashTable* createHashTable(int size);

// createHashItem and initialize them value
HashItem* createHashItem(int hash, char* value);

// insert value in hashtable. If value consist then count of value increases
HashTable* insert(HashTable* hashtable, char* value);

// seatch number of occurences of value in text. If there is no value return -1
int getCount(HashTable* hashtable, char* value);

// print hashTable in the key - value - count format
void printHashTable(HashTable* hashTable);

// free hashTableElement. Nothing return if there is no value
HashTable* removeFromHashTable(HashTable* hashTable, char* value);

// free hashTable
HashTable* removeHashTable(HashTable* hashTable);

// return fill factor
int returnFillFactor(HashTable* hashTable);