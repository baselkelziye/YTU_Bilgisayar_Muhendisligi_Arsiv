#pragma once

#include <stdbool.h>

#define MAX_ELEMENT_COUNT 1000

typedef struct Stack {
    int item[MAX_ELEMENT_COUNT];
    int top;
} Stack_t;

bool isStackEmpty(Stack_t* stack);

bool isStackFull(Stack_t* stack);

/* Returns true: success */
/* Returns false: failure */
bool pushToStack(Stack_t* stack, int value);

/* Returns true: success */
/* Returns false: failure */
bool popFromStack(Stack_t* stack, int* pValue);

/* Returns true: success */
/* Returns false: failure */
bool peekValueFromStack(Stack_t* stack, int* pValue);

void printValuesInStack(Stack_t* stack);
