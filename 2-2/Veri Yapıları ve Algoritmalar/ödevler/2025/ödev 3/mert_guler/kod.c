#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@brief Struct that contains employee information with limited name length
*/
typedef struct Employee {
    char name[100];
    int age;
    int wage;
} Employee;


/*
@brief Node of a n-ary tree, queueNext is necessary for using a queue
*/
typedef struct Node {
    Employee* data;
    struct Node *firstChildren;
    struct Node *nextSibling;
    struct Node *queueNext; /* Necessary for queue operations, memory is controlled.*/
} Node;

/*
@brief struct queue, not in linked list format, nodes are connected internally
*/
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/*
@brief struct for containing necessary tree info. Preferred for a clean code
*/
typedef struct TreeInfo {
    double averageAge;
    int totalWage;
    int totalLevels;
} TreeInfo;

/*
@brief Creates a empty queue

@return Created queue
*/
Queue* createQueue(void){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/*
@brief Checks if a queue is empty
 
@param queue  The queue to be checked

@return queue's emptyness in 1 or 0 format. Checked like a boolean.
*/
int isQueueEmpty(Queue* queue){
    return (queue->front == NULL);
}

/*
@brief Enqueues a item to a queue
 
@param queue  The queue to be enqueued into
@param item The item to be enqueued
*/
void enqueue(Queue* queue, Node* item){
    item->queueNext = NULL;
    
    if (isQueueEmpty(queue)){
        queue->front = item;
        queue->rear = item;
        return;
    }
    
    queue->rear->queueNext = item;
    queue->rear = item;
}

/*
@brief Dequeues queue's front item and returns the item
 
@param queue  The queue to be dequeued

@return The dequeued item (in front of the queue)
*/
Node* dequeue(Queue* queue){
    Node* temp;
    
    if (isQueueEmpty(queue)){
        return NULL;
    }
    
    temp = queue->front;
    queue->front = queue->front->queueNext;
    
    if (queue->front == NULL){
        queue->rear = NULL;
    }
    
    return temp;
}

/*
@brief Finds a node by name. Using BFS
 
@param root The root node of the tree
@param searchName The name to be searched

@return If searched Node is found returns the Node, else returns NULL
*/
Node* findNode(Node* root, char searchName[]){
    Queue* queue = createQueue();
    Node* current;
    Node* iterator;
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)){
        current = dequeue(queue);
        
        if (strcmp(current->data->name, searchName) == 0){
            return current;
        }
        
        iterator = current->firstChildren;
        
        while (iterator != NULL) {
            enqueue(queue, iterator);
            iterator = iterator->nextSibling;
        }
    }
    return NULL;
}


/*
@brief Finds and return the queue's node count (size)
 
@param queue The Queue to calculate its size

@return Returns size of the queue
*/
int queueSize(Queue* queue){
    Queue iterator = *queue;
    int size = 0;
    
    while (iterator.front != NULL) {
        size++;
        iterator.front = iterator.front->queueNext;
    }
    
    return size;
}

/*
@brief Frees memory of the queue, Using BFS with a extra queue.
 
@param root The root of the queue
*/
void freeMemoryOfTree(Node* root){
    Node* current;
    Node* iterator;
    int levelSize;
    int i;
    
    Queue* iterateQueue = createQueue();
    Queue* freeQueue = createQueue(); /* Contains all the nodes in the end */
    enqueue(freeQueue, root);
    enqueue(iterateQueue, root);
    
    /* BFS */
    while (!isQueueEmpty(iterateQueue)){
        levelSize = queueSize(iterateQueue);
        
        for (i = 0; i < levelSize; i++) {
            current = dequeue(iterateQueue);
            
            iterator = current->firstChildren;
            while (iterator != NULL) {
                enqueue(iterateQueue, iterator);
                enqueue(freeQueue, iterator);
                iterator = iterator->nextSibling;
            }
        }
    }
    
    while (!isQueueEmpty(freeQueue)){
        current = dequeue(freeQueue);
        free(current->data);
        free(current);
    }
    
    free(iterateQueue);
    free(freeQueue);
}

/*
@brief Prints a tree using Recursive DFS
 
@param node The root node of the tree
@param level Level of the current node. For printing spaces correctly. Must be entered 0 in function call
*/
void printTree(Node* node, int level){
    int i;
    Node* child;
    if (node == NULL){
        return;
    }
    
    printf("%s\n", node->data->name);
    
    child = node->firstChildren;

    while (child != NULL) {
        for (i = 0 ; i < level; i++) {
            printf("    ");
        }
        
        printf("|");
        level++;
        printf("---");
        printTree(child, level++);
        child = child->nextSibling;
        level -= 2;
    }
}


/*
@brief Iterates through a tree and calculates & gathers necessary informations. Using BFS
 
@param root  The root node of the tree
@param treeInfo  The empty treeInfo struct for writing information
@param N  The size of the queue for average age calculation
*/
void calculateTreeInfo(Node* root, TreeInfo* treeInfo, int N){
    Node* current;
    Node* iterator;
    int level = 0;
    int levelSize;
    int totalAge = 0;
    int totalWage = 0;
    int i;
    
    /* BFS */
    Queue* queue = createQueue();
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)){
        levelSize = queueSize(queue);
        level++;
        printf("\nSeviye %d: %d", level, levelSize);
        
        for (i = 0; i < levelSize; i++) {
            current = dequeue(queue);
            
            totalAge += current->data->age;
            totalWage += current->data->wage;
            
            iterator = current->firstChildren;
            while (iterator != NULL) {
                enqueue(queue, iterator);
                iterator = iterator->nextSibling;
            }
        }
    }
    
    treeInfo->totalLevels = level;
    treeInfo->averageAge = (double) totalAge / N;
    treeInfo->totalWage = totalWage;
    free(queue);
}


/*
@brief Find the node with max child count in a tree level. Using single level iteration BFS. Basically looped BFS. Acts like DFS without going back. Not uses stack but uses queue.
 
@param queue The queue which is on the tree's specified level
@param levelSize The level's size
@param searchLevel The level to be printed (only for print purposes)
*/
void printNodeWithMaxChildOfLevel(Queue* queue, int levelSize, int searchLevel){
    int i, j, count, nextSize;
    int max = 0;
    Node* current;
    Node* iterator;
    Node* maxNode = NULL;
    Node* child;
    
    Queue* childQueue = createQueue(); /* To iterate through*/
    for (i = 0; i < levelSize; i++) { /* level size is equals to node count of level*/
        count = -1;
        current = dequeue(queue);
        
        enqueue(childQueue, current); /* Currents children will be counted*/
        
        nextSize = queueSize(childQueue);
        /* Do normal bfs for childQueue*/
        for (j = 0; j < nextSize; j++) {
            child = dequeue(childQueue);
            count++;
            iterator = child->firstChildren;
            while (iterator != NULL) {
                enqueue(queue, iterator);
                iterator = iterator->nextSibling;
                count++;
            }
        }
        
        if (max < count){
            max = count;
            maxNode = current;
        }
    }
    
    if (maxNode != NULL){
        printf("%d. seviyede en fazla calisana sahip kisi %d kisi ile %s'dir",
               searchLevel, max, maxNode->data->name);
    } else {
        printf("Bu seviyede alt calisani olan kisi yok");
    }
    
    free(childQueue);
    /* queue param is freed on the caller */
}


/*
@brief Finds search level and connect the queue that includes level's nodes to
 printNodeWithMaxChildOfLevel function. Using BFS
 
@param root  The root node of the tree
@param searchLevel  The level to be finded in the tree
*/
void findLevelAndNodeWithMaxChild(Node* root, int searchLevel){
    Queue* queue = createQueue();
    Node* current;
    Node* iterator;
    int level = 0;
    int i;
    int levelSize;
    enqueue(queue, root);
    
    /* BFS */
    while (!isQueueEmpty(queue)){
        levelSize = queueSize(queue);
        level++;
        
        if (level == searchLevel){
            printNodeWithMaxChildOfLevel(queue, levelSize, searchLevel);
            return;
        }
        
        for (i = 0; i < levelSize; i++) {
            current = dequeue(queue);
            iterator = current->firstChildren;
            while (iterator != NULL) {
                enqueue(queue, iterator);
                iterator = iterator->nextSibling;
            }
        }
    }
    free(queue);
}

/*
@brief Adds a new node to tree. Finds its parent by using findNode function. Info is taken by params.
 
@param root  The root node of the tree
@param name  The name of the new employee
@param age  The age of the new employee
@param wage  The wage of the new employee
@param parentName  The name of the parent node
*/
void add(Node* root, char name[], int age, int wage, char parentName[]){
    Node* parent;
    Node* newChild;
    Employee* employee;
    Node* iterator;
    
    if (root->data == NULL){
        employee = (Employee*)calloc(1, sizeof(Employee));
        strcpy(employee->name, name);
        employee->age = age;
        employee->wage = wage;
        root->data = employee;
        return;
    }

    parent = findNode(root, parentName);
    
    if (parent == NULL){
        printf("RETURNING");
        return;
    }
    
    newChild = (Node*)calloc(1, sizeof(Node));
    employee = (Employee*)calloc(1, sizeof(Employee));
    
    strcpy(employee->name, name);
    employee->age = age;
    employee->wage = wage;
    
    newChild->data = employee;
    
    if (parent->firstChildren == NULL){
        parent->firstChildren = newChild;
    } else {
        iterator = parent->firstChildren;
        while (iterator->nextSibling != NULL) {
            iterator = iterator->nextSibling;
        }
        iterator->nextSibling = newChild;
    }
}

/*
@brief Reads tree data from file and creates nodes
 
@param root  The root node of the tree
@param N  The size of the tree
*/
void readFile(Node* root, int* N){
    char fileName[100];
    FILE *file = NULL;
    int validFile = 0;
    int i;
    char name[100];
    int age;
    int wage;
    char parentName[100];
    
    printf("\nEnter the name of the file you want to load (with .txt)\nEnter Q to Quit: ");
    
    while (validFile == 0) {
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = 0;
        
        if (strcmp(fileName,"q") == 0 || strcmp(fileName,"Q") == 0){
            printf("\nExiting...\n");
            exit(1);
        }

        file = fopen(fileName, "r");
        
        if (file != NULL) {
            validFile = 1;
        } else {
            printf("\nFile could not be opened or found. Please try again: ");
        }
    }
    
    /* Write data, assuming data is perfectly fits the specified template */
    
    fscanf(file, "%d", N);
    
    for (i = 0; i < *N; i++) {
        fscanf(file, "%s %d %d %s", name, &age, &wage, parentName);
        add(root, name, age, wage, parentName);
    }
    
    fclose(file);
    printf("Successfully Loaded File!\n\n");
}


int main(int argc, const char * argv[]) {
    int N, searchLevel;
    Node* root = (Node*)calloc(1, sizeof(Node));
    TreeInfo* treeInfo = (TreeInfo*)calloc(1, sizeof(TreeInfo));
    
    readFile(root, &N);
    printTree(root, 0);
    
    calculateTreeInfo(root, treeInfo, N);
    printf("\nPersonel agaci %d seviyeden olusmaktadir\n", treeInfo->totalLevels);
    printf("Tum calisanlarin yas ortalamasi: %0.2f\n", treeInfo->averageAge);
    printf("Sirketin odedigi aylik personel maas gideri: %d\n\n", treeInfo->totalWage);
    
    printf("Alt calisan sayisi en fazla olan kisiyi ogrenmek icin bir seviye girin: ");
    scanf("%d", &searchLevel);
    
    if (searchLevel > treeInfo->totalLevels){
        printf("Toplam seviye sayisinden daha yuksek deger girilemez!");
    } else {
        findLevelAndNodeWithMaxChild(root, searchLevel);
    }
    
    freeMemoryOfTree(root);
    free(treeInfo);

    return 0;
}
