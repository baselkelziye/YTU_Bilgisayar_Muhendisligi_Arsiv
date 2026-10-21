#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node
{
    int value;
    int strength;
    struct node *left, *right;
} NODE;

typedef struct bucket
{
    int *array;
    int top;

} BUCKET;
void insert(NODE **root, int value);
NODE *createNode(int value);
NODE *createBinaryTree(int fruitCount, int maxFruitWeight);
void printTree(NODE *root, int fruitCount);
int search(NODE *root, int value);
void fire(NODE *root, int value, int power, int *fruitCount, BUCKET *bucket);
NODE *deletion(NODE *root, int value);
NODE *findMin(NODE *root);
NODE *findMax(NODE *root);
void printStack(BUCKET *s, int length);
void push(BUCKET *s, int value);
int pop(BUCKET *s);
void stackInitialize(BUCKET *bucket, int length);

int main()
{
    int maxFruitWeight, fruitCount;
    int value, power, length;
    NODE *root;
    BUCKET *bucket;
    do
    {
        printf("Enter the maximum fruit weight and fruit quantity.");
        scanf(" %d %d", &maxFruitWeight, &fruitCount);
    } while (maxFruitWeight < fruitCount || fruitCount <= 0 || maxFruitWeight <= 0);

    bucket = (BUCKET *)malloc(sizeof(BUCKET));
    stackInitialize(bucket, fruitCount);
    length = fruitCount;
    root = createBinaryTree(fruitCount, maxFruitWeight);
    printf("for N:%d, M:%d,\n", maxFruitWeight, fruitCount);
    printTree(root, fruitCount);
    while (fruitCount != 0)
    {
        printf("enter the number you will hit on the tree and your hitting power: ");
        scanf(" %d %d", &value, &power);
        printf("for k:%d, p:%d,\n", value, power);
        fire(root, value, power, &fruitCount, bucket);
        printTree(root, fruitCount);
    }
    printf("...\n");
    printStack(bucket, length);
    return 0;
}
void printStack(BUCKET *s, int length)
{
    printf("Output: ");
    int i, value;
    BUCKET *tmp;
    tmp = (BUCKET *)malloc(sizeof(BUCKET));
    stackInitialize(tmp, length);

    while (s->top != 0) // until the stack is empty
    {
        value = pop(s);
        push(tmp, value);
    }
    while (tmp->top != 0) // until the stack is empty
    {
        value = pop(tmp);
        printf("%d ", value);
    }
}
void push(BUCKET *s, int value)
{
    s->array[s->top] = value;
    s->top++;
}
int pop(BUCKET *s)
{
    s->top--;
    return s->array[s->top];
}
void stackInitialize(BUCKET *bucket, int length)
{
    bucket->top = 0;
    bucket->array = (int *)calloc(length, sizeof(int));
}

NODE *findMin(NODE *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

NODE *findMax(NODE *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
NODE *deletion(NODE *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->value == value)
    {
        if (root->left == NULL && root->right == NULL) // no children, do itself null
        {
            free(root);
            return NULL;
        }
        if (root->right != NULL) // has right child, write the min value on the right subtree over this number, delete that min value's old node
        {
            root->value = findMin(root->right)->value;
            root->strength = findMin(root->right)->strength;
            root->right = deletion(root->right, findMin(root->right)->value);
            return root;
        }
        else //  has left child, write the max value on the left subtree over this number, delete that max value's old node
        {
            root->value = findMax(root->left)->value;
            root->strength = findMax(root->left)->strength;
            root->left = deletion(root->left, findMax(root->left)->value);
            return root;
        }
    }
    // number finding operations
    if (root->value < value)
    {
        root->right = deletion(root->right, value);
        return root;
    }
    else
    {
        root->left = deletion(root->left, value);
        return root;
    }
}
void fire(NODE *root, int value, int power, int *fruitCount, BUCKET *bucket)
{
    NODE *parent, *current;
    current = root;
    while (current != NULL && current->value != value)
    {
        if (value < current->value)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }
    if (current != NULL) // the number was found
    {
        current->strength = current->strength - power;
        if (current->strength <= 0) // meyve dusecek
        {
            current = deletion(root, value);
            push(bucket, value);
            (*fruitCount)--;
        }
    }
    else // the number was not found
    {
        printf("This number is not on the tree.\n");
    }
}

void printTree(NODE *root, int fruitCount)
{
    NODE **queue = (NODE **)malloc(sizeof(NODE *) * fruitCount);
    int front = 0, rear = 0;
    int i;
    NODE *iter, *parent;

    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    if (fruitCount == 0)
    {
        return;
    }

    queue[front] = root;
    rear++;
    printf("Tree:\n");
    while (front < rear)
    {
        int count = rear - front;
        while (count > 0)
        {
            iter = queue[front];
            front++;
            printf("%d ", iter->value);
            if (iter->value != iter->strength && iter->strength > 0)
            {
                printf("(%d)", iter->strength);
            }

            if (iter->left != NULL)
            {

                queue[rear] = iter->left;
                rear++;
            }
            if (iter->right != NULL)
            {
                queue[rear] = iter->right;
                rear++;
            }

            count--;
        }
        printf("\n");
    }
    free(queue);
}

NODE *createNode(int value)
{
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    tmp->value = value;
    tmp->strength = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void insert(NODE **root, int value)
{
    NODE *current, *parent;
    int stop;
    NODE *tmp = createNode(value);
    if (*root == NULL)
    {
        *root = tmp;
    }
    else
    {
        current = *root;
        stop = 0;
        while (!stop)
        {
            if (value < current->value)
            {
                parent = current;
                current = current->left;
                if (current == NULL)
                {
                    parent->left = tmp;
                    stop = 1;
                }
            }
            else
            {
                parent = current;
                current = current->right;
                if (current == NULL)
                {
                    parent->right = tmp;
                    stop = 1;
                }
            }
        }
    }
}
NODE *createBinaryTree(int fruitCount, int maxFruitWeight)
{
    int i, number, isSame;
    NODE *root = NULL;
    srand(time(NULL));
    for (i = 0; i < fruitCount; i++)
    {
        number = rand() % maxFruitWeight + 1;
        isSame = search(root, number);
        if (!isSame) // this number already exists
        {
            insert(&root, number);
        }
        else
        {
            i--;
        }
    }
    printf("\n");
    return root;
}

int search(NODE *root, int value)
{
    NODE *current = root;
    while (current != NULL && current->value != value)
    {
        if (value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current != NULL)
    {
        return 1; // this number already exists
    }
    else
    {
        return 0; // there is no such number
    }
}