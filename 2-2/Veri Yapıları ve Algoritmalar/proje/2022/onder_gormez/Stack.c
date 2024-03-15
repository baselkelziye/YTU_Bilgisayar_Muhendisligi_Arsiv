#include "Stack.h"

#include <stdio.h>

bool isStackEmpty(Stack_t* stack)
{
    if (stack == NULL) {
        printf("In function isStackEmpty(): Stack pointer null!");
        return false;
    }

    return stack->top == 0;
}

bool isStackFull(Stack_t* stack)
{
    if (stack == NULL) {
        printf("In function isStackFull(): Stack pointer null!");
        return false;
    }

    return stack->top == MAX_ELEMENT_COUNT;
}

bool pushToStack(Stack_t* stack, int value)
{
    if (stack == NULL) {
        printf("In function pushToStack(): Unable to push data to stack. Stack pointer null!");
        return false;
    }

    if (isStackFull(stack)) {
        printf("In function pushToStack(): Unable to push data to stack. Stack full!");
        return false;
    }

    stack->item[stack->top++] = value;

    return true;
}

bool popFromStack(Stack_t* stack, int* pValue)
{
    if (stack == NULL) {
        printf("In function popFromStack(): Unable to pop data from the stack. Stack pointer null!");
        return false;
    }

    if (pValue == NULL) {
        printf("In function popFromStack(): Unable to pop data from the stack. Value pointer null!");
        return false;
    }

    if (isStackEmpty(stack)) {
        printf("In function popFromStack(): Unable to pop data from the stack. Stack empty!");
        return false;
    }

    *pValue = stack->item[--stack->top];

    return true;
}

bool peekValueFromStack(Stack_t* stack, int* pValue)
{
    if (stack == NULL) {
        printf("In function peekValueFromStack(): Unable to peek data from the stack. Stack pointer null!");
        return false;
    }

    if (pValue == NULL) {
        printf("In function peekValueFromStack(): Unable to peek data from the stack. Value pointer null!");
        return false;
    }

    if (isStackEmpty(stack)) {
        printf("In function peekValueFromStack(): Unable to peek data from the stack. Stack empty!");
        return false;
    }

    *pValue = stack->item[stack->top - 1];

    return true;
}

void printValuesInStack(Stack_t* stack)
{
    int index = 0;

    if (stack == NULL) {
        printf("In function printValuesInStack(): Unable to print values in the stack. Stack pointer null!");
        return;
    }

    if (isStackEmpty(stack)) {
        printf("In function printValuesInStack(): Unable to print values in the stack.  Stack empty!");
        return;
    }

    printf("Values in stack: \n");
    for (index = 0; index < stack->top; ++index)
        printf("%d. index: %d\n", index, stack->item[index]);
}
