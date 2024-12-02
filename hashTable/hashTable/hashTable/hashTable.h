#pragma once

typedef struct HashItem HashItem;

typedef struct HashTable HashTable;

// create HashTable with size (size) and initialzie them NULL value
HashTable* createHashTable(int size);

// createHashItem and initialize them value
HashItem* createHashItem(int hashValue, char* value);

// insert value in hashtable. If value consist then count of value increases
HashTable* insert(HashTable* hashtable, char* value);

// return new hashTable with size * 2
HashTable* updateHashTable(HashTable* hashTable);

// seatch number of occurences of value in text. If there is no value return -1
int getCount(HashTable* hashtable, char* value);

// print hashTable in the key - value - count format
void printHashTable(HashTable* hashTable);

// free hashTableElement. Nothing return if there is no value
HashTable* removeFromHashTable(HashTable* hashTable, char* value);

// free hashTable
void removeHashTable(HashTable* hashTable);

// return fill factor. return 0 if hashTable is empty
int returnFillFactor(HashTable* hashTable);

// return avarage length of lists of buckets. return 0 if hashTable is empty
int returnAvarageLengthOfListsOfBuckets(HashTable* hashTable);