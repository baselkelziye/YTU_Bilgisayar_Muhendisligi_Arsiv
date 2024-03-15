#include "Stack.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int getRequiredBitCountForUnsigned(unsigned long value)
{
    if (value <= 255)
        return 8;

    if (value <= 65535)
        return 16;

    if (value <= 16777215)
        return 24;

    return 32;
}

int getRequiredBitCountForSigned(signed long value)
{
    if (value >= -128)
        return 8;

    if (value >= -32768)
        return 16;

    if (value >= -8388608)
        return 24;

    return 32;
}

/* It is responsibility to free the memory caller side  */
const char* convertToString(unsigned long value, int bitCount)
{
    int index = bitCount - 1;
    char* string = (char*)malloc(sizeof(char) * (bitCount + 1));
    string[bitCount] = NULL;

    if (string == NULL) {
        printf("In function convertToString(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    while (value != 0) {
        if (value % 2)
            string[index--] = '1';
        else
            string[index--] = '0';

        value /= 2;
    }

    while (index >= 0)
        string[index--] = '0';

    return string;
}

void compareZeroAndOne(Stack_t* stack, const char* pString)
{
    int index = 0;
    int value = 0;

    while (pString[index] != NULL) {
        if (isStackEmpty(stack))
            pushToStack(stack, pString[index]);
        else {
            peekValueFromStack(stack, &value);
            if (value == pString[index])
                pushToStack(stack, pString[index]);
            else
                popFromStack(stack, &value);
        }

        ++index;
    }

    if (isStackEmpty(stack))
        printf("0 and 1 count is equal.\n");
    else {
        int valuesInStack = 0;
        peekValueFromStack(stack, &valuesInStack);

        if (valuesInStack == '1')
            printf("The number of Ones' (1) is more than Zero (0). %d additional 0 required.\n", stack->top);
        else
            printf("The number of Zeros' (0) is more than One (1). %d additional 1 required.\n", stack->top);
    }

    free((void*)pString);
}

int main(void)
{
    Stack_t stack = { 0 };
    int value = 0;
    unsigned long bitCount = 0;
    const char* pString = NULL;
    unsigned long positiveValue = 0;
    signed long negativeValue = 0;

    printf("isStackEmpty: %d\n", isStackEmpty(&stack));

    pushToStack(&stack, 10);
    pushToStack(&stack, 15);
    pushToStack(&stack, 20);
    printValuesInStack(&stack);

    popFromStack(&stack, &value);
    printValuesInStack(&stack);

    peekValueFromStack(&stack, &value);
    printf("Peek value: %d\n", value);

    printf("Input: 15\n");
    positiveValue = 15;
    bitCount = getRequiredBitCountForUnsigned(positiveValue);
    printf("Required Bit Count: %u\n", bitCount);
    pString = convertToString(positiveValue, bitCount);
    printf("Value %u in bits: %s\n", positiveValue, pString);
    stack.top = 0;
    compareZeroAndOne(&stack, pString);

    printf("Input: 1\n");
    positiveValue = 1;
    bitCount = getRequiredBitCountForUnsigned(positiveValue);
    printf("Required Bit Count: %u\n", bitCount);
    pString = convertToString(positiveValue, bitCount);
    printf("Value %u in bits: %s\n", positiveValue, pString);
    stack.top = 0;
    compareZeroAndOne(&stack, pString);

    printf("Input: 259\n");
    positiveValue = 259;
    bitCount = getRequiredBitCountForUnsigned(positiveValue);
    printf("Required Bit Count: %u\n", bitCount);
    pString = convertToString(positiveValue, bitCount);
    printf("Value %u in bits: %s\n", positiveValue, pString);
    stack.top = 0;
    compareZeroAndOne(&stack, pString);

    printf("Input: -1\n");
    negativeValue = -1;
    bitCount = getRequiredBitCountForSigned(negativeValue);
    printf("Required Bit Count: %u\n", bitCount);
    pString = convertToString((uint8_t)negativeValue, bitCount);
    printf("Value %d in bits: %s\n", -1, pString);
    stack.top = 0;
    compareZeroAndOne(&stack, pString);

    printf("Input: -128\n");
    negativeValue = -128;
    bitCount = getRequiredBitCountForSigned(negativeValue);
    printf("Required Bit Count: %u\n", bitCount);
    pString = convertToString((uint8_t)negativeValue, bitCount);
    printf("Value %d in bits: %s\n", -128, pString);
    stack.top = 0;
    compareZeroAndOne(&stack, pString);

    printf("Input: 85\n");
    positiveValue = 85;
    bitCount = getRequiredBitCountForUnsigned(positiveValue);
    printf("Required Bit Count: %u\n", bitCount);
    pString = convertToString(positiveValue, bitCount);
    printf("Value %u in bits: %s\n", positiveValue, pString);
    stack.top = 0;
    compareZeroAndOne(&stack, pString);

    return 0;
}
