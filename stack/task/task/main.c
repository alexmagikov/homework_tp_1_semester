#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool testForCreateStack() {
    Stack* stack = createStack();
    bool result = stack != NULL;
    int errorCode = 0;
    clearStack(&stack, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForPeek() {
    Stack* stack = createStack();
    int errorCode = 0;
    push(stack, 1, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    int result = peek(stack, &errorCode);
    clearStack(&stack, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result == 1;
}

bool testForPop() {
    Stack* stack = createStack();
    int errorCode = 0;
    push(stack, 1, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    push(stack, 2, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    pop(stack, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    int result = peek(stack, &errorCode) == 1;
    if (errorCode == -1) {
        return false;
    }
    clearStack(&stack, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForIsEmpty() {
    Stack* stack = createStack();
    bool result = isEmpty(stack);
    int errorCode = 0;
    clearStack(&stack, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

int calculateInPostfix(const char* string, int* errorCode) {
    Stack* stack = createStack();
    for (int i = 0; string[i] != '\0'; i++) {
        if (isdigit(string[i])) {
            push(stack, string[i] - '0', errorCode);
        }
        else if (!isEmpty(stack)) {
            int tmp = peek(stack, errorCode);
            pop(stack, errorCode);
            if (string[i] == '-') {
                tmp = peek(stack, errorCode) - tmp;
            }
            else if (string[i] == '+') {
                tmp = peek(stack, errorCode) + tmp;
            }
            else if (string[i] == '/') {
                if (tmp == 0) {
                    printf("u cant divide by 0 ");
                    clearStack(stack, errorCode);
                    free(stack);
                    return -1;
                }
                tmp = peek(stack, errorCode) / tmp;
            }
            else if (string[i] == '*') {
                tmp = peek(stack, errorCode) * tmp;
            }
            else {
                *errorCode = -1;
                return;
            }
            pop(stack, errorCode);
            push(stack, tmp, errorCode);
        }
    }
    if (isEmpty(stack)) {
        return -1;
    }
    else {
        int result = peek(stack, errorCode);
        clearStack(&stack, errorCode);
        return result;
    }
 }

bool testForPostfixCalculatorForNormalValue() {
    int errorCode = 0;
    int result = calculateInPostfix("96-12+*", &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForPostfixCalculatorForBorderValue() {
    int errorCode = 0;
    int result = calculateInPostfix("1", &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForPostfixCalculatorForNULLValue() {
    int errorCode = 0;
    int result = calculateInPostfix(" ", &errorCode);
    if (errorCode == -1) {
        return false;
    }
    return result;
}

bool testForClearStack() {
    Stack* stack = createStack();
    int errorCode = 0;
    push(stack, 1, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    push(stack, 2, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    clearStack(&stack, errorCode);
    if (errorCode == -1) {
        return -1;
    }
    return stack == NULL;
}

int main(void) {
    if (!testForClearStack() || !testForPostfixCalculatorForNULLValue() || !testForPostfixCalculatorForBorderValue() || !testForPostfixCalculatorForNormalValue() || !testForIsEmpty() || !testForPeek || !testForCreateStack() || !testForPop()) {
        printf("tests are failed");
        exit(0);
    }
    Stack* stack = createStack();
    const char string[100];
    printf("input postfix expression ");
    scanf("%s", &string);
    int errorCode = 0;
    int result = calculateInPostfix(&string, &errorCode);
    if (errorCode == -1) {
        return -1;
    }
    printf("result %d", result);
    clearStack(&stack, &errorCode);
    if (errorCode == -1) {
        return -1;
    }
    return 0;
}