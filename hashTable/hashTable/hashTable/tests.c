#include "tests.h"
#include "hashTable.h"
#include <stdio.h>


bool isCompleted() {
    bool* tests[1] = {1};
    for (int i = 0; i < 1; i++) {
        if (!tests[i]) {
            printf("test %d failed", i);
            return false;
        }
    }
    return true;
}