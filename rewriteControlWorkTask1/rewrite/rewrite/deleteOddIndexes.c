#include "list.h"

void deleteOddIndexes(List* list, int* errorCode) {
    Position position = first(list);
    int length = getLength(list);
    for (int index = 0; index < length; index++) {
        if (index % 2 != 0) {
            removeFromList(list, position, errorCode);
            if (*errorCode == -1) {
                return;
            }
        }
        else {
            position = next(position);
        }
    }
}