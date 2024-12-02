#define _CRT_SECURE_NO_WARNINGS

#include "hashTable.h"
#include <stdio.h>
#include "list.h"
#include "tests.h"

int main() {
    if (!isCompleted()) {
        return -1;
    }
    HashTable* hashtable = createHashTable(100);
    insert(hashtable, "abobus");
    printHashTable(hashtable);
    return 0;
}