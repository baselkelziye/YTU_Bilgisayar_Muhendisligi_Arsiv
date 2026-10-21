#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node
{
    int value;
    int freq;
    struct node *prev;
    struct node *next;
} NODE;

NODE *createNode();
NODE *createWheel(int size);
void printWheel(int size, NODE *wheel);
void generateAllNumbers(int size, NODE **wheel1, NODE **wheel2, NODE **wheel3, int range);
int onTheWheel(NODE *wheel, int number);
int freqOnTheOtherWheel(NODE *otherWheel, int number);
void addNumberToWheel(NODE *wheel, int number, int extraFreq);
void placeCommonNumber(NODE **wheel, int commonNumber, int place);
int findCommonNumber(NODE *wheel);
int findDistance(int size, int base, int location);
void rotateWheel(int length, NODE **head);

int main()
{
    int size, range;
    int base, location1, location2, length1, length2;
    NODE *wheel1, *wheel2, *wheel3;
    do
    {
        printf("Enter the end of your number range and the wheel size.");
        scanf("%d %d", &range, &size);

    } while (size < 3 || range < 3 || range < size || size / 2 + size >= range);

    printf("\nN=%d, M=%d, the numbers on the three wheels:\n", range, size);
    wheel1 = createWheel(size);
    wheel2 = createWheel(size);
    wheel3 = createWheel(size);
    generateAllNumbers(size, &wheel1, &wheel2, &wheel3, range);
    printf("\nWheel 1: ");
    printWheel(size, wheel1);
    printf("\nWheel 2: ");
    printWheel(size, wheel2);
    printf("\nWheel 3: ");
    printWheel(size, wheel3);

    printf("\nIts position on wheel 1 is:");
    base = findCommonNumber(wheel1);
    printf("\nIts position on wheel 2 is:");
    location1 = findCommonNumber(wheel2);
    printf("\nIts position on wheel 3 is:");
    location2 = findCommonNumber(wheel3);

    printf("\n\nWheel 2: ");
    length1 = findDistance(size, base, location1);
    printf("\nWheel 3: ");
    length2 = findDistance(size, base, location2);

    rotateWheel(length1, &wheel2);
    rotateWheel(length2, &wheel3);
    printf("\n\nThe final state of the wheels:\n");
    printf("\nWheel 1: ");
    printWheel(size, wheel1);
    printf("\nWheel 2: ");
    printWheel(size, wheel2);
    printf("\nWheel 3: ");
    printWheel(size, wheel3);
    return 0;
}

NODE *createNode()
{
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    if (tmp == NULL)
    {
        printf("Memory Allocation Error");
        exit(-1);
    }
    tmp->next = tmp->prev = NULL;
    tmp->value = -1;
    tmp->freq = 0;
    return tmp;
}

NODE *createWheel(int size)
{
    int i;
    NODE *head, *tmp, *iter;
    head = createNode();
    iter = head;
    for (i = 0; i < size - 1; i++)
    {
        tmp = createNode();
        iter->next = tmp;
        tmp->prev = iter;
        iter = iter->next;
    }
    iter->next = head;
    head->prev = iter;
    return head;
}

void printWheel(int size, NODE *wheel)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", wheel->value);
        wheel = wheel->next;
    }
    printf("\n");
}

int onTheWheel(NODE *wheel, int number)
{
    while (wheel->value != -1 && wheel->value != number)
    {
        wheel = wheel->next;
    }
    if (wheel->value == number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int freqOnTheOtherWheel(NODE *otherWheel, int number)
{
    NODE *iter = otherWheel;
    while (iter->value != -1 && iter->value != number)
    {
        iter = iter->next;
    }

    if (iter->value == number)
    {
        if (iter->freq == 1)
        {
            iter->freq++;
            return 1; //  freq == 1 ? add to other list and increase the freq of this list
        }
        else
        {
            return 2; // freq == 2 ? can not add to list
        }
    }
    else
    {

        return 0; // this number is not on the list, so add it
    }
}
void addNumberToWheel(NODE *wheel, int number, int extraFreq)
{
    NODE *iter = wheel;
    while (iter->value != -1)
    {
        iter = iter->next;
    }

    iter->value = number;
    iter->freq++;
    if (extraFreq)
    {
        iter->freq++;
    }
}

void generateAllNumbers(int size, NODE **wheel1, NODE **wheel2, NODE **wheel3, int range)
{
    int i, j, commonNumber, placements[3], number, freq;
    NODE *head1, *head2, *head3;
    srand(time(NULL));
    head1 = *wheel1;
    head2 = *wheel2;
    head3 = *wheel3;
    commonNumber = rand() % range + 1; // generated common number
    for (i = 0; i < 3; i++)            // generated placementf of the common number in wheels
    {
        placements[i] = rand() % size + 1;
        for (j = 0; j < i; j++)
        {
            if (placements[i] == placements[j])
            {
                i--;
            }
        }
    }
    // first wheel
    for (i = 0; i < size - 1; i++) // generated all numbers except common number
    {
        number = rand() % range + 1;
        if (commonNumber != number && !onTheWheel(head1, number))
        {
            addNumberToWheel(head1, number, 0);
        }
        else
        {
            i--;
        }
    }
    // second wheel
    for (i = 0; i < size - 1; i++) //  generated all numbers except common number
    {
        number = rand() % range + 1;
        if (commonNumber != number && !onTheWheel(head2, number))
        {
            freq = freqOnTheOtherWheel(head1, number);
            if (freq == 2) // freq == 2 ? can not add to list, generate a number again
            {
                i--;
            }
            else if (freq == 1) // freq == 1 ? the freq in the other list has already been increased, now add it to this list.
            {
                addNumberToWheel(head2, number, 1); // extra freq is 1 because if I am going to add a number that is in another list to another wheel for the first time, I should make its frequency directly 2.
            }
            else
            {
                addNumberToWheel(head2, number, 0);
            }
        }
        else
        {
            i--;
        }
    }
    // third wheel
    for (i = 0; i < size - 1; i++)
    {
        number = rand() % range + 1;
        if (commonNumber != number && !onTheWheel(head3, number))
        {
            freq = freqOnTheOtherWheel(head1, number);
            if (freq == 2)
            {
                i--;
            }
            else if (freq == 1)
            {
                addNumberToWheel(head3, number, 1);
            }
            else
            {
                freq = freqOnTheOtherWheel(head2, number);
                if (freq == 1)
                {
                    addNumberToWheel(head3, number, 1);
                }
                else
                {
                    addNumberToWheel(head3, number, 0);
                }
            }
        }
        else
        {
            i--;
        }
    }
    placeCommonNumber(wheel1, commonNumber, placements[0]);
    placeCommonNumber(wheel2, commonNumber, placements[1]);
    placeCommonNumber(wheel3, commonNumber, placements[2]);
}

void placeCommonNumber(NODE **wheel, int commonNumber, int place)
{
    int i;
    NODE *iter = *wheel;
    iter = iter->prev; // end of the wheel
    iter->value = commonNumber;
    iter->freq = 3;
    for (i = 0; i < place; i++)
    {
        iter = iter->next;
    }
    *wheel = iter;
}

int findCommonNumber(NODE *wheel)
{
    NODE *iter = wheel;
    int i = 0;

    while (iter->freq != 3)
    {
        i++;
        iter = iter->next;
    }
    i++;
    printf(" %d\t The common number: %d", i, iter->value);

    return i;
}

int findDistance(int size, int base, int location)
{
    int way1, way2, way3;
    int sum, equal = 0;
    way1 = base - location;
    way2 = size - location + base;
    way3 = base - size - location;

    if (way1 * way1 < way2 * way2)
    {
        if (way1 * way1 < way3 * way3)
        {
            sum = way1;
        }
        else if (way1 * way1 > way3 * way3)
        {
            sum = way3;
        }
        else
        {
            sum = way1;
            equal = 1;
        }
    }
    else if (way1 * way1 > way2 * way2)
    {
        if (way2 * way2 < way3 * way3)
        {
            sum = way2;
        }
        else if (way2 * way2 > way3 * way3)
        {
            sum = way3;
        }
        else
        {
            sum = way2;
            equal = 1;
        }
    }
    else
    {
        sum = way1;
        equal = 1;
    }

    if (sum > 0)
    {

        printf("it should be turned %d steps in a clockwise direction.", sum);
        if (equal == 1)
        {
            printf(" (Note: It can also be turned %d steps in the opposite direction of the clock.)", sum);
        }
    }
    else
    {
        printf("it should be turned %d steps in the opposite direction of the clock.", sum * -1);
        if (equal)
        {
            printf(" (Note: The clock can also be turned by %d steps.)", sum * -1);
        }
    }
    return sum;
}

void rotateWheel(int length, NODE **head)
{
    int i;
    NODE *iter = *head;
    if (length < 0)
    {
        for (i = 0; i < length * -1; i++)
        {
            iter = iter->next;
        }
        *head = iter;
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            iter = iter->prev;
        }
        *head = iter;
    }
}