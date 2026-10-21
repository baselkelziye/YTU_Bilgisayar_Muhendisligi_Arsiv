#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_VERTICES_COUNT 30

void printCycles(int cycleCount, int cycles[][MAX], int cycleLengths[], int maxCycleLength, int perimeter[]);

// Structure to represent an adjacency list node
typedef struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
} AdjListNode;

// Structure to represent an adjacency list
typedef struct AdjList
{
    struct AdjListNode *head;
} AdjList;

// Structure to represent a graph
typedef struct Graph
{
    int vertexCount;
    struct AdjList *array;
} Graph;

// Function to create a new adjacency list node
AdjListNode *newAdjListNode(int dest, int weight)
{
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

/*
@brief: Function to create a graph with V vertices
@param: V: number of vertices
@return: Graph: pointer to the created graph
*/
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(struct Graph));
    graph->vertexCount = V;

    // Create an array of adjacency lists
    graph->array = (AdjList *)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}
/*
@brief: Function to add an edge to an undirected graph
@param: graph: pointer to the graph, src: source vertex, dest: destination vertex, weight: weight of the edge
*/
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // Adding an edge from src to dest. A new node is added to the adjacency list of src.
    AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, we add an edge from dest to src too
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

/*
@brief: Function to check if a cycle is new or not
@param: cycle: array of vertices in the cycle, cycleSize: number of vertices in the cycle, cycles: array of cycles, cycleLengths: array of cycle lengths, cycleCount: number of cycles
*/
int isNewCycle(int *cycle, int cycleSize, int cycles[][MAX], int cycleLengths[], int cycleCount)
{
    int i, j, k;
    for (i = 0; i < cycleCount; i++)
    {
        if (cycleLengths[i] == cycleSize)
        {
            int match = 1;
            for (j = 0; j < cycleSize; j++)
            {
                int found = 0;
                for (k = 0; k < cycleSize; k++)
                {
                    if (cycle[j] == cycles[i][k])
                    {
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                {
                    match = 0;
                    break;
                }
            }
            if (match == 1)
                return 0;
        }
    }
    return 1;
}

/*
@brief: Function to perform Depth First Search (DFS) on the graph to find cycles
@param: graph: pointer to the graph, u: current vertex, visited: array to keep track of visited vertices,
stack: array to keep track of vertices in the current path,
stackSize: size of the stack, cycles: array of cycles, cycleLengths: array of cycle lengths,
cycleCount: number of cycles, perimeters: array of perimeters of cycles
*/
void DFS(Graph *graph, int u, int *visited, int *stack, int *stackSize, int cycles[][MAX], int *cycleLengths, int *cycleCount, int *perimeters)
{
    visited[u] = 1;
    stack[(*stackSize)++] = u;

    AdjListNode *node = graph->array[u].head;
    int cycleSize, perimeter;
    int i;

    while (node != NULL)
    {
        int v = node->dest;

        if (visited[v] != 1)
        {
            DFS(graph, v, visited, stack, stackSize, cycles, cycleLengths, cycleCount, perimeters);
        }

        else if (v == stack[0])
        {
            cycleSize = *stackSize;
            if (isNewCycle(stack, cycleSize, cycles, cycleLengths, *cycleCount) == 1)
            {

                memcpy(cycles[*cycleCount], stack, cycleSize * sizeof(int));
                cycleLengths[*cycleCount] = cycleSize;
                perimeter = 0;

                for (i = 0; i < cycleSize; i++)
                {
                    AdjListNode *temp = graph->array[stack[i]].head;
                    while (temp != NULL)
                    {
                        if (temp->dest == stack[(i + 1) % cycleSize])
                        {
                            perimeter = perimeter + temp->weight;
                            break;
                        }
                        temp = temp->next;
                    }
                }
                perimeters[*cycleCount] = perimeter;
                (*cycleCount)++;
            }
        }

        node = node->next;
    }

    visited[u] = 0;
    (*stackSize)--;
}
/*
@brief: Function to find cycles in the graph
@param: graph: pointer to the graph
*/
void findCycles(Graph *graph)
{
    int i;
    int stackSize = 0, cycleCount = 0, numberOfRealCycles = 0;
    int visited[MAX] = {0};
    int stack[MAX];
    int cycles[MAX][MAX];
    int cycleLengths[MAX];
    int perimeters[MAX];
    int shape_frequency[MAX] = {0};

    for (i = 0; i < graph->vertexCount; i++)
    {
        if (visited[i] == 0)
        {
            DFS(graph, i, visited, stack, &stackSize, cycles, cycleLengths, &cycleCount, perimeters);
        }
    }
    for (i = 0; i < cycleCount; i++)

    {
        if (cycleLengths[i] > 2)
        {
            numberOfRealCycles++;
            shape_frequency[cycleLengths[i]]++;
        }
    }

    printf("Sekil sayisi: %d\n", numberOfRealCycles);
    for (i = 0; i < MAX; i++)
    {
        if (shape_frequency[i] > 0)
        {
            printf("%d'gen sayisi: %d\n", i, shape_frequency[i]);
        }
    }
    printf("\n");

    int maxCycleLength = 0;
    for (i = 0; i < cycleCount; i++)
    {
        if (cycleLengths[i] > maxCycleLength)
        {
            maxCycleLength = cycleLengths[i];
        }
    }

    printCycles(cycleCount, cycles, cycleLengths, maxCycleLength, perimeters);
}

/*
@brief: Function to print cycles ordered by their lengths.
@param: cycleCount: number of cycles, cycles: array of cycles, cycleLengths: array of cycle lengths,
maxCycleLength: maximum cycle length, perimeter: array of perimeters of cycles
*/
void printCycles(int cycleCount, int cycles[][MAX], int cycleLengths[], int maxCycleLength, int perimeter[])
{
    int i, j, k;
    for (i = 3; i <= maxCycleLength; i++)
    {
        int n = 1;
        for (j = 0; j < cycleCount; j++)
        {

            if (cycleLengths[j] == i)
            {
                printf("%d. %d'gen: ", n, i);
                for (k = 0; k < i; k++)
                {
                    printf("%c ", cycles[j][k] + 'A');
                }
                printf("%c", cycles[j][0] + 'A');
                printf(" Uzunluk: %d\n", perimeter[j]);
                n++;
            }
        }
        printf("\n");
    }
}

/*
@brief: Function to read edges from a file and add them to the graph
@param: graph: pointer to the graph, filename: name of the our input file
*/
void readEdgesFromFile(Graph *graph, char *filename)
{
    char to, from;
    int weight;
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("File error! : %s\n", filename);
        return;
    }

    while (fscanf(file, " %c %c %d", &to, &from, &weight) == 3)
    {
        // Adding edge to the graph. Vertices are represented as chars. We need to convert them to ints.
        addEdge(graph, to - 'A', from - 'A', weight);
    }

    fclose(file);
}

/*
@brief: Main function. It reads edges from a file and finds cycles in the graph
@return: 0 if the program runs successfully
*/
int main()
{
    // input file name. You can change the file name to test the program with different inputs.
    char *filename = "Sample3.txt";

    Graph *graph = createGraph(MAX_VERTICES_COUNT);

    printf("Cycles in: %s\n", filename);

    // Reading edges from the file and adding to the graph
    readEdgesFromFile(graph, filename);

    findCycles(graph);

    return 0;
}
