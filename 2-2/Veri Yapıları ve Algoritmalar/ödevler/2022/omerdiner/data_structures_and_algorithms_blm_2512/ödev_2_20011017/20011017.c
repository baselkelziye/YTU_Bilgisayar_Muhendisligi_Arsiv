#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct stack
{
    int top;
    char **word;
} stack;

typedef struct queue
{
    int front, rear, size;
    int capacity;
    stack **stacks;
} queue;

stack *createStack(int capacity);

/*
@brief  initializes the queue with the given capacity
@param  capacity: the capacity of the queue
@return the initialized queue
*/
queue *createQueue(int capacity)
{
    int i;
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->stacks = (stack **)malloc(capacity * sizeof(stack *));

    return q;
}

/*
@brief  checks if the queue is empty
@param  q: the queue
@return 1 if the queue is empty, 0 otherwise
*/
int isQueueEmpty(queue *q)
{
    return q->size == 0;
}

/*
@brief adds a stack to the queue if the queue is not full
@param  q: the queue
@param  s: the stack to be added
@return 1 if the stack is added, 0 otherwise

*/
int enqueue(queue *q, stack *s)
{
    if (q->size == q->capacity)
    {
        return 0;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->stacks[q->rear] = s;
    q->size = q->size + 1;
    return 1;
}

/*
@brief  removes a stack from the queue if the queue is not empty
@param  q: the queue
@return the removed stack if the queue is not empty, NULL otherwise
*/
stack *dequeue(queue *q)
{
    if (isQueueEmpty(q))
    {
        return NULL;
    }
    stack *s = q->stacks[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return s;
}

/*
@brief  initializes the stack with the given capacity
@param  capacity: the capacity of the stack
@return the initialized stack
*/
stack *createStack(int capacity)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->word = (char **)malloc(capacity * sizeof(char *));
    return s;
}

/*
@brief  checks if the stack is empty
@param  s: the stack
@return 1 if the stack is empty, 0 otherwise
*/
int isEmpty(stack *s)
{
    return s->top == -1;
}

/*
@brief  adds a word to the stack if the stack is not full
@param  s: the stack
@param  word: the word to be added
@return 1 if the word is added, 0 otherwise
*/
int push(stack *s, char *word)
{
    s->top++;
    s->word[s->top] = word;
    return 1;
}

/*
@brief  removes a word from the stack if the stack is not empty
@param  s: the stack
@return the removed word if the stack is not empty, NULL otherwise
*/
char *pop(stack *s)
{
    if (isEmpty(s))
    {
        return NULL;
    }
    // returns the top word and decrements the top
    return s->word[s->top--];
}

/*
@brief  returns the top word of the stack if the stack is not empty
@param  s: the stack
@return the top word of the stack if the stack is not empty, NULL otherwise
*/
char *peek(stack *s)
{
    if (isEmpty(s))
    {
        return NULL;
    }
    return s->word[s->top];
}

/*
@brief  reads the words from the file and returns them as an array of strings
@param  fileName: the name of the file
@param  wordCount: the number of words in the file
@return the array of words
@return wordCount: the number of words in the file -- updated by reference
*/
char **readWords(char *fileName, int *wordCount)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return NULL;
    }

    char line[50];
    int wordCounter = 0;
    char **words = NULL;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Splitting the line into words
        char *word = strtok(line, " \t\n");
        while (word != NULL)
        {
            words = realloc(words, (wordCounter + 1) * sizeof(*words));
            words[wordCounter] = malloc(strlen(word) + 1);
            strcpy(words[wordCounter], word);
            wordCounter++;
            word = strtok(NULL, " \t\n");
        }
    }

    fclose(file);

    // updating the wordCount by reference, because we cannot return two values
    *wordCount = wordCounter;
    return words;
}

/*
@brief  checks if a word exists in the array of words
@param  word: the word to be checked
@param  words: the array of words
@param  wordCount: the number of words in the array
@return 1 if the word exists, 0 otherwise
*/
int checkIfWordExists(char *word, char **words, int wordCount)
{
    int i;
    for (i = 0; i < wordCount; i++)
    {
        if (strcmp(word, words[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/*
@brief creates a copy of the given stack
@param s: the stack to be copied
@return the copied stack
*/
stack *copyStack(stack *s)
{
    stack *newStack = createStack(100);
    int i;
    for (i = 0; i <= s->top; i++)
    {
        push(newStack, s->word[i]);
    }
    return newStack;
}

/*
@brief checks the different characters between two words of the same length
@param word1: the first word
@param word2: the second word
@return the number of different characters between the two words
*/
int checkDifference(char *word1, char *word2)
{
    // if the words have different lengths, they cannot be converted into each other
    if (strlen(word1) != strlen(word2))
    {
        return -1;
    }
    int i;
    int difference = 0;
    for (i = 0; i < strlen(word1); i++)
    {
        if (word1[i] != word2[i])
        {
            difference++;
        }
    }
    return difference;
}

/*
@brief prints the current state of the queue
@param q: the queue
*/
void printTheQueue(queue *q)
{
    printf("\n");
    int i;
    for (i = 0; i < q->size; i++)
    {
        printf("Stack %d: ", i);
        int j;
        for (j = 0; j <= q->stacks[(q->front + i) % q->capacity]->top; j++)
        {
            printf("%s ", q->stacks[(q->front + i) % q->capacity]->word[j]);
        }
        printf("\n");
    }
    printf("\n-----------------");
}

int main()
{
    int wordCount = 0;
    int i, j;

    clock_t start, end;
    double total_time=0;

    char startingWord[50];
    char endingWord[50];
 
    int usedwordCount = 0;

    // taking the words from the file
    char **words = readWords("dictionary.txt", &wordCount);

    // this is the array that will keep the words that are used in the stacks to prevent using the same word more than once
    char **usedWords = (char **)malloc(wordCount * sizeof(char *));
    for (i = 0; i < wordCount; i++)
    {
        usedWords[i] = NULL;
    }

    printf("Starting word: ");
    scanf("%s", &startingWord);

    printf("Ending word: ");
    scanf("%s", &endingWord);

    if (strlen(startingWord) != strlen(endingWord))
    {

        printf("The starting and ending words must have the same length.\n");
        return 1;
    }

    start = clock();

    queue *q = createQueue(10000);
    stack *s = createStack(100);

    // pushing the starting word to the stack and enqueuing it
    push(s, startingWord);
    enqueue(q, s);

    // the main loop
    while (!isQueueEmpty(q))

    {
      //  printTheQueue(q);  // if this line is uncommented, the code will take a lot of time to run

        // dequeueing the current stack and getting the top word
        stack *currentStack = dequeue(q);
        char *currentWord = peek(currentStack);

        // if the top word is the ending word, the path is found
        if (strcmp(currentWord, endingWord) == 0)
        {
            printf("\n\nThe path is: ");
            for (i = 0; i <= currentStack->top; i++)
            {
                printf("%s ", currentStack->word[i]);
            }

            end = clock();
            total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            // printf("\nTime: %f\n", total_time);

            return 0;
        }

        for (i = 0; i < wordCount; i++)
        {
            if (checkDifference(currentWord, words[i]) == 1)
            {
                if (checkIfWordExists(words[i], usedWords, usedwordCount) == 0)
                {
                    // if the new word is only one character different from the current word and
                    // if it is not used before, we create a new stack, push the new word to it,
                    // and enqueue the new stack

                    stack *newStack = copyStack(currentStack);
                    push(newStack, words[i]);
                    enqueue(q, newStack);

                    // adding the new word to the usedWords array to prevent using it again
                    usedWords[usedwordCount] = words[i];
                    usedwordCount++;
                }
            }
        }
    }

    // if the loop ends, there is no path between the starting and ending words
    printf("\nThere is no path between the starting and ending words.\n");
    return 0;
}
