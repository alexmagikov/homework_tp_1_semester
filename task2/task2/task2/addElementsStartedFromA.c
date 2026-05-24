#include "addElementsStartedFromA.h"

void addElementsStartedFromA(List* list, int* errorCode) {
    Position positionEnd = first(list);
    int lengthOfInputList = getLength(list);

    for (int i = 0; i < lengthOfInputList; i++) {
        positionEnd = next(positionEnd);
    }

    Position position = first(list);
    position = next(position);
    int errorCodeFunc = 0;

    for (int i = 0; i < lengthOfInputList; i++) {
        if (getValue(list, position)[0] == 'a') {
            add(list, positionEnd, getValue(list, position), &errorCodeFunc);
            positionEnd = next(positionEnd);

            if (errorCodeFunc == -1) {
                *errorCode = -1;
                return;
            }
        }
        position = next(position);
    }
}