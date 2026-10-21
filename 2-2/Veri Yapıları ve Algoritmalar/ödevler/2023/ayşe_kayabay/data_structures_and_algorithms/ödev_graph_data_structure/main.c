#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int vertex;
    struct node *next;
} NODE;

typedef struct graph
{
    int numberOfVertices;
    struct node **adjList;
} GRAPH;

void initCountArray(int **array, int size);
void initArray(char ***array, int size);
void initMatrix(int ***matrix, int size, int numberOfConditions);
NODE *createNode(int v);
GRAPH *createGraph(int numberOfVertices);
void convertToAdjListFromAdjMatrix(int **matrix, GRAPH *graph);
void decreaseConditions(GRAPH *graph, int **countArray);
void takeAndPrintLessons(GRAPH *graph, int **countArray, char **lessons, int term, int *count);
void calculateConditions(GRAPH *graph, int *countArray);
void freeAll(char **lessons, int **adjMatrix, int *countArray, GRAPH *graph);
int main()
{
    int term, count;
    int N, E; // N:Number of lessons | E:Number of conditions
    char **lessons;
    int **adjMatrix;
    int *countArray;
    GRAPH *graph;
    printf("Enter the number of courses and prerequisites: ");
    scanf("%d %d", &N, &E);
    initArray(&lessons, N);
    initMatrix(&adjMatrix, N, E);
    graph = createGraph(N);
    convertToAdjListFromAdjMatrix(adjMatrix, graph);
    initCountArray(&countArray, N);
    calculateConditions(graph, countArray);
    term = 0;
    count = 0;
    while (count < N)
    {
        takeAndPrintLessons(graph, &countArray, lessons, term, &count);
        decreaseConditions(graph, &countArray);
        term++;
    }
    printf("\nThe student finishes the department in %d terms", term);
    freeAll(lessons, adjMatrix, countArray, graph);
    return 0;
}

void initCountArray(int **array, int size)
{
    int i;
    *array = (int *)(malloc(sizeof(int) * size));
    if (*array == NULL)
    {
        printf("Memory Alloc Error");
    }
    for (i = 0; i < size; i++)
    {
        (*array)[i] = 0;
    }
}

void initArray(char ***array, int size)
{
    int i;
    *array = (char **)(malloc(sizeof(char *) * size));
    if (*array == NULL)
    {
        printf("Memory Alloc Error");
    }

    for (i = 0; i < size; i++)
    {
        (*array)[i] = (char *)(malloc(sizeof(char) * 20));
        if ((*array)[i] == NULL)
        {
            printf("Memory Alloc Error");
        }
        printf("Enter the lesson %d ", i + 1);
        scanf("%s", (*array)[i]);
    }
}

void initMatrix(int ***matrix, int size, int numberOfConditions)
{
    int i, v, w;
    *matrix = (int **)malloc(size * sizeof(int *));
    if (*matrix == NULL)
    {
        printf("Memory Alloc Error");
        return;
    }
    for (i = 0; i < size; i++)
    {
        (*matrix)[i] = (int *)calloc(size, sizeof(int));
        if ((*matrix)[i] == NULL)
        {
            printf("Memory Alloc Error");
            return;
        }
    }
    for (i = 0; i < numberOfConditions; i++)
    {
        printf("Enter prerequisite %d in the form <v w> (v:the lesson, w:the prerequisite of the lesson): ", i + 1);
        scanf("%d %d", &v, &w);
        if (v < size && w < size && v >= 0 && w >= 0)
        {
            (*matrix)[v][w] = 1;
        }
        else
        {
            printf("Please enter valid indices for the matrix!\n");
            i--;
        }
    }
}

NODE *createNode(int vertex)
{
    NODE *newVertex = (NODE *)malloc(sizeof(NODE));
    if (newVertex == NULL)
    {
        printf("Memory Alloc Error");
    }
    newVertex->vertex = vertex;
    newVertex->next = NULL;
    return newVertex;
}

GRAPH *createGraph(int numberOfVertices)
{
    int i;
    GRAPH *newGraph = (GRAPH *)malloc(sizeof(GRAPH));
    if (newGraph == NULL)
    {
        printf("Memory Alloc Error");
    }
    newGraph->adjList = (NODE **)malloc(sizeof(NODE) * numberOfVertices);
    if (newGraph->adjList == NULL)
    {
        printf("Memory Alloc Error");
    }
    newGraph->numberOfVertices = numberOfVertices;
    for (i = 0; i < numberOfVertices; i++)
    {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void convertToAdjListFromAdjMatrix(int **matrix, GRAPH *graph)
{
    int i, j;
    for (i = 0; i < graph->numberOfVertices; i++)
    {
        for (j = 0; j < graph->numberOfVertices; j++)
        {
            if (matrix[i][j] == 1)
            {
                NODE *newNode = createNode(j);

                if (graph->adjList[i] == NULL)
                {
                    graph->adjList[i] = newNode;
                }
                else
                {
                    newNode->next = graph->adjList[i];
                    graph->adjList[i] = newNode;
                }
            }
        }
    }
}

void calculateConditions(GRAPH *graph, int *countArray)
{
    int i, count;
    NODE *iter;
    for (i = 0; i < graph->numberOfVertices; i++)
    {
        count = 0;
        iter = graph->adjList[i];
        while (iter != NULL)
        {
            count++;
            iter = iter->next;
        }
        countArray[i] = count;
    }
}
void decreaseConditions(GRAPH *graph, int **countArray)
{
    int i, j;
    NODE *iter;
    for (i = 0; i < graph->numberOfVertices; i++)
    {

        if ((*countArray)[i] == -1)
        {
            (*countArray)[i]--;

            for (j = 0; j < graph->numberOfVertices; j++)
            {
                iter = graph->adjList[j];
                while (iter != NULL && iter->vertex != i)
                {
                    iter = iter->next;
                }
                if (iter != NULL)
                {
                    (*countArray)[j]--;
                }
            }
        }
    }
}
void takeAndPrintLessons(GRAPH *graph, int **countArray, char **lessons, int term, int *count)
{
    int i, j;
    NODE *iter;
    printf("\nTerm %d: ", term + 1);
    for (i = 0; i < graph->numberOfVertices; i++)
    {
        if ((*countArray)[i] == 0)
        {
            printf("%s ", lessons[i]);
            (*count)++;
            (*countArray)[i]--;
        }
    }
}
void freeAll(char **lessons, int **adjMatrix, int *countArray, GRAPH *graph)
{
    free(lessons);
    free(adjMatrix);
    free(countArray);
    free(graph);
}