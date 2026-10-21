#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    int value;
    int end;
    char *word;
    struct NODE *child;
    struct NODE *sibling;
} NODE;

NODE *createNode(int index);
NODE *appendNode(NODE *parent, int value);
void readFileAndSetTree(NODE *root, char *fileName, int *maxLetterCount);
void insertTree(NODE *root, char *word);
void findWord(NODE *root, char *numberArray);
NODE *findNode(NODE *root, int target);
void freeNode(NODE *node);
int main()
{
    NODE *root;
    char *numberArray; // input
    int quit, maxLetterCount;
    quit = 0;
    maxLetterCount = 0;
    root = createNode(-1);
    readFileAndSetTree(root, "dictionary.txt", &maxLetterCount);
    numberArray = (char *)malloc(sizeof(char) * maxLetterCount + 1);
    if (numberArray == NULL)
    {
        printf("Memory Allocation Error");
        freeNode(root);
        return -1;
    }
    printf("Type 'q' to exit.\n");
    do
    {
        printf(">");
        scanf("%s", numberArray);
        if (strcmp(numberArray, "q") == 0)
        {
            quit = 1;
        }
        else if (numberArray)
        {
            findWord(root, numberArray);
        }

    } while (!quit);

    freeNode(root);
    free(numberArray);
    return 0;
}

NODE *createNode(int index)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Memory Allocation Error");
        return NULL;
    }
    newNode->value = index;
    newNode->end = 0;
    newNode->word = NULL;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

NODE *appendNode(NODE *parent, int value)
{
    NODE *iter, *newNode;
    if (parent->child == NULL)
    {
        newNode = createNode(value);
        parent->child = newNode;
        return newNode;
    }
    else
    {
        iter = parent->child;
        while (iter->sibling != NULL && iter->value != value)
        {
            iter = iter->sibling;
        }
        if (iter->value != value) // add
        {
            newNode = createNode(value);
            iter->sibling = newNode;
            iter = iter->sibling;
        }
        return iter;
    }
}

void readFileAndSetTree(NODE *root, char *fileName, int *maxLetterCount)
{
    FILE *file = fopen(fileName, "r");
    char word[100];
    if (file == NULL)
    {
        printf("Memory Allocation Error");
        return;
    }
    while (fgets(word, sizeof(word), file) != NULL)
    {
        word[strcspn(word, "\n")] = '\0'; // word = 'az\0' , 'gala\0'
        if (strlen(word) > *maxLetterCount)
        {
            *maxLetterCount = strlen(word);
        }
        insertTree(root, word);
    }
    fclose(file);
}

void insertTree(NODE *root, char *word)
{
    char currentChar;
    int i, index;
    NODE *newNode;
    NODE *iter = root;
    int length = strlen(word);
    for (i = 0; i < length; i++)
    {
        currentChar = word[i];
        switch (currentChar)
        {
        case 'a':
            index = 2;
            break;
        case 'b':
            index = 2;
            break;
        case 'c':
            index = 2;
            break;

        case 'd':
            index = 3;
            break;

        case 'e':
            index = 3;
            break;

        case 'f':
            index = 3;
            break;

        case 'g':
            index = 4;
            break;
        case 'h':
            index = 4;
            break;
        case 'i':
            index = 4;
            break;

        case 'j':
            index = 5;
            break;
        case 'k':
            index = 5;
            break;
        case 'l':
            index = 5;
            break;

        case 'm':
            index = 6;
            break;
        case 'n':
            index = 6;
            break;
        case 'o':
            index = 6;
            break;

        case 'p':
            index = 7;
            break;
        case 'q':
            index = 7;
            break;
        case 'r':
            index = 7;
            break;
        case 's':
            index = 7;
            break;

        case 't':
            index = 8;
            break;
        case 'u':
            index = 8;
            break;
        case 'v':
            index = 8;
            break;

        case 'w':
            index = 9;
            break;
        case 'x':
            index = 9;
            break;
        case 'y':
            index = 9;
            break;
        case 'z':
            index = 9;
            break;

        default:
            printf("\n***%s :unexpected character\n", word); // ı,ş,ö vb
            break;
        }
        iter = appendNode(iter, index);
    }
    if (iter->end == 1)
    {
        while (iter->child != NULL)
        {
            iter = iter->child;
            while (iter->sibling != NULL && iter->value != 0)
            {
                iter = iter->sibling;
            }
        }
        iter = appendNode(iter, 0);
    }
    iter->end = 1;
    iter->word = (char *)malloc(sizeof(char) * length);
    if (iter->word == NULL)
    {
        printf("Memory Allocation Error");
        return;
    }
    strcpy(iter->word, word);
}

NODE *findNode(NODE *root, int target)
{
    NODE *iter;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->child == NULL)
    {
        return NULL;
    }
    iter = root->child;
    while (iter->sibling != NULL && iter->value != target)
    {
        iter = iter->sibling;
    }
    if (iter->value == target) // found
    {
        return iter;
    }
    else
    {
        return NULL;
    }
}
void findWord(NODE *root, char *numberArray)
{
    int i, index;
    NODE *iter;
    int length = strlen(numberArray);
    if (root == NULL || numberArray == NULL)
    {
        return;
    }
    iter = root;
    for (i = 0; i < length; i++)
    {
        index = numberArray[i] - '0';
        iter = findNode(iter, index);
    }
    if (iter != NULL && iter->end == 1) // found
    {
        printf("%s\n", iter->word);
        while (iter->child != NULL) // # #
        {
            iter = iter->child;
            while (iter->sibling != NULL && iter->value != 0)
            {
                iter = iter->sibling;
            }
            if (iter->value == 0)
            {
                printf("%s\n", iter->word);
            }
        }
    }
    else
    {
        printf("There is no word in the dictionary that corresponds to this number.\n");
    }
}

void freeNode(NODE *node)
{
    if (node == NULL)
        return;
    freeNode(node->child);
    freeNode(node->sibling);
    free(node->word);
    free(node);
}