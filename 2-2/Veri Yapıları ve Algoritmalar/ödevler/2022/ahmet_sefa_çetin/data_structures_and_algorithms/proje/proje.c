#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int vertex;
	int w;
	struct node *next;
} NODE;

typedef struct graph {
	struct node **adjList;
	int N;
} GRAPH;

typedef struct stack {
    int *items;
    int top;
} STACK;

typedef struct polygon {
	int numVertex;
	int *vertices;
	int perimeter;
} POLYGON;

typedef struct polygonList {
	POLYGON *list;
	int numPolygons;
	int *polygonCounter;	
} POLYGON_LIST;

NODE* createNode(int vertex);
GRAPH* createGraph(int N);
void addEdge(GRAPH* graph, int dest, int src, int w);
GRAPH* readGraphFromFile(GRAPH *graph, int N);
void push(STACK *stack, int item);
int pop(STACK *stack);
void writeArray(int *array, int N);
void addPolygon(POLYGON_LIST *polygons, STACK *stack, int perimeter);
void copyArray(int *array1, int *array2, int N);
int isCycleUnique(STACK *stack, POLYGON_LIST *polygons);
void DFS(GRAPH* graph, int vertex, int *visited, STACK *stack, int root, int *perimeter, POLYGON_LIST *polygons);
void sortPolygons(POLYGON_LIST *polygons);
void outputPolygons(POLYGON_LIST *polygons, int N);

int main() {
	int i; // index
	int N; // number of vertices
	GRAPH* graph; // the graph structure which is implemented by an adjacency list
	STACK *stack = (STACK*)malloc(sizeof(STACK)); // the stach which is implemented by an array
	stack->top = -1;
	int *visited; // visited label array which can be 0 or 1
	int perimeter = 0; // perimeter of a polygon
	POLYGON_LIST *polygons = (POLYGON_LIST*)malloc(sizeof(POLYGON_LIST)); // polygon list 
	polygons->numPolygons = 0; // number of polygons
	
    printf("Number of vertices: ");
    scanf("%d", &N);
    
    stack->items = (int*)malloc(N * sizeof(int));
    polygons->polygonCounter = (int*)calloc(N + 1, sizeof(int));
    visited = (int*)calloc(N, sizeof(int));
	
	graph = readGraphFromFile(graph, N);
	
	for(i = 0; i < graph->N; i++) { // for all vertices in the graph, it calls DFS function and marks it as 1 in visited array
		DFS(graph, i, visited, stack, i, &perimeter, polygons);
		visited[i] = 1;
	}
	
	outputPolygons(polygons, N);
	
	return 0;
}

/*
@brief the function which takes a vertex number and creates a node with this number.

@param vertex an integer which is vertex number.

@return return a new node structure with the vertex parameter.
*/
NODE* createNode(int vertex) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

/*
@brief the function which creates a graph which is implemented by adjacency list.

@param N an integer which is number of nodes.

@return return a new graph structure which is implemented by an adjacency list.
*/
GRAPH* createGraph(int N) {
	int i;
	GRAPH *graph = (GRAPH*)malloc(sizeof(GRAPH));
	graph->N = N;
	graph->adjList = (NODE**)malloc(N * sizeof(NODE*));
	for(i = 0; i < N; i++) { // it initializes NULL adjacents of nodes
		graph->adjList[i] = NULL;
	}
	return graph;
}

/*
@brief the function which adds a new edge to graph which is implemented by an adjacency list.

@param graph a graph structure which is implemented by an adjacency list.
@param dest an integer which is one of vertices numbers of the new edge.
@param src an integer which is one of vertices numbers of the new edge.
@param w the weight of the new edge.

@return
*/
void addEdge(GRAPH* graph, int dest, int src, int w) {
	NODE* newNode = createNode(dest);
	newNode->w = w;
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;
	newNode = createNode(src);
	newNode->w = w;
	newNode->next = graph->adjList[dest];
	graph->adjList[dest] = newNode;
}

/*
@brief the function which reads a file which has the edges and their weights and adds these edges to the graph.

@param graph a graph structure which is implemented by an adjacency list.
@param N an integer which is number of nodes.

@return return the graph with new edges which were read form file.
*/
GRAPH* readGraphFromFile(GRAPH *graph, int N) {
    FILE *file;
    char fileName[100];
    char dest, src;
    int w;
    
    graph = createGraph(N);
    
    do { // until file name is valid
		printf("File name: ");
		scanf("%s", fileName);
		file = fopen(fileName, "r");
		if (!file) { // if file cannot be opened
			printf("File could not be opened!, ");
		}
	} while (!file);

    while (fscanf(file, " %c %c %d", &dest, &src, &w) != EOF) { // it reads every row of file adds these edges to graph
        int destIndex = dest - 'A';
        int srcIndex = src - 'A';
        addEdge(graph, destIndex, srcIndex, w);
    }
    
    fclose(file);
    return graph;
}

/*
@brief the function which pushes new integer to integer stack which is implemented by an array

@param stack an integer stack structure which is implemented by an array.
@param item an integer value to push to stach.

@return
*/
void push(STACK *stack, int item) {
    stack->items[++stack->top] = item;
}

/*
@brief the function which removes the top element of stack from stack.

@param stack an integer stack structure which is implemented by an array.
@param item an integer value to push to stach.

@return return the stack after removing the top element.
*/
int pop(STACK *stack) {
    return stack->items[stack->top--];
}

/*
@brief the function which prints the integer array.

@param array an integer array.
@param N the length of array.

@return
*/
void writeArray(int *array, int N) {
	int i;
    for (i = 0; i < N - 1; i++) {
        printf("%c-", array[i] + 'A');
    }
    printf("%c", array[i] + 'A');
}

/*
@brief the function which creates a new polygon, copies the stack to this polygon and adds it to polygon list.

@param polygons a structure which has an array that holds polygon structures.
@param stack an integer stack structure which is implemented by an array.
@param perimeter perimeter value of a polygon.

@return
*/
void addPolygon(POLYGON_LIST *polygons, STACK *stack, int perimeter) {
	POLYGON *polygon = (POLYGON*)malloc(sizeof(POLYGON));
	polygon->numVertex = stack->top;
	polygon->perimeter = perimeter;
	polygon->vertices = (int*)malloc((polygon->numVertex + 1) * sizeof(int));
	copyArray(stack->items, polygon->vertices, polygon->numVertex + 1);
	if (polygons->numPolygons == 0) { // if polygon list is empty, it allocates the list
		polygons->list = (POLYGON*)malloc(sizeof(POLYGON));
	}
	else { // else it allocates one more area to add new polygon
		polygons->list = (POLYGON*)realloc(polygons->list, (polygons->numPolygons + 1) * sizeof(POLYGON));
	}
	polygons->list[polygons->numPolygons] = *polygon;
	polygons->polygonCounter[stack->top]++;
	polygons->numPolygons++;
}

/*
@brief the function which copies an array to another array.

@param array1 an integer array.
@param array2 an integer array.
@param N length of the arrays.

@return
*/
void copyArray(int *array1, int *array2, int N) {
	int i;
	for (i = 0; i < N; i++) {
		array2[i] = array1[i];
	}
}

/*
@brief the function which compares the stack with polygons which are in polygon list to ensure there is a matching cycle.

@param stack an integer stack structure which is implemented by an array.
@param polygons a structure which has an array that holds polygon structures.

@return return 1 if there is no matching cycle. return 0 if there is a matching cycle.
*/
int isCycleUnique(STACK *stack, POLYGON_LIST *polygons) {
    int i, j, match;

    for (i = 0; i < polygons->numPolygons; i++) {
        if (stack->top == polygons->list[i].numVertex) { // if number of vertices same
            match = 1;
            for (j = 0; j < stack->top + 1; j++) {
                if (stack->items[stack->top - j] != polygons->list[i].vertices[j]) { // if it doesnt match the vetex numbers
                    match = 0;
                }
            }
            if (match == 1) { // if match is 1 the polygon is included in polygon list
                return 0;
            }
        }
    }

    return 1;
}

/*
@brief the function which .

@param graph a graph structure which is implemented by an adjacency list.
@param vertex the current vertex.
@param visited the label list which has 0s and 1s which shows a vertex is visited or not visited.
@param stack an integer stack structure which is implemented by an array.
@param prev the previous vertex of a current vertex.
@param root the vertex number which is starting and ending point of a polygon.
@param perimeter perimeter of polygons.
@param polygons a structure which has an array that holds polygon structures.

@return return 1 if there is no matching cycle. return 0 if there is a matching cycle.
*/
void DFS(GRAPH* graph, int vertex, int *visited, STACK *stack, int root, int *perimeter, POLYGON_LIST *polygons) {
    visited[vertex] = 1;
    push(stack, vertex);
 	
    NODE *currentNode = graph->adjList[vertex];
    while (currentNode) { // while current node is not NULL it traverses the graph
        if (!visited[currentNode->vertex]) { // if current node is not visited it calls DFS recursively
        	*perimeter += currentNode->w;
            DFS(graph, currentNode->vertex, visited, stack, root, perimeter, polygons);
            *perimeter -= currentNode->w;
        }
        else if (currentNode->vertex == root && stack->top >= 2) { // if it finds a polygon and it has more than 2 vertices, it adds it to polygon list
        	push(stack, root);
        	*perimeter += currentNode->w;
			
			if (isCycleUnique(stack, polygons)) { // it checks cycle is unique
				addPolygon(polygons, stack, *perimeter);
			}      	

	 		pop(stack);
	 		*perimeter -= currentNode->w;
		}
        currentNode = currentNode->next;
    }

	pop(stack);
    visited[vertex] = 0;
}

/*
@brief the function which implements bubble sort to sort polygons by their number of vertices by using comparePolygons function.

@param polygons a structure which has an array that holds polygon structures.

@return
*/
void sortPolygons(POLYGON_LIST *polygons) {
	int i, j;
	POLYGON temp;
    for (i = 0; i < polygons->numPolygons - 1; i++) { // bubble sorts by comparing every two elements
        for (j = 0; j < polygons->numPolygons - i - 1; j++) {
            if (polygons->list[j].numVertex > polygons->list[j + 1].numVertex) { // it compares the number of vertices of two polygons
                temp = polygons->list[j];
                polygons->list[j] = polygons->list[j + 1];
                polygons->list[j + 1] = temp;
            }
        }
    }
}

/*
@brief the function which prints the number of polygons, the polygons with their vertices and perimeters in the order of their number of vertices.

@param polygons a structure which has an array that holds polygon structures.
@param N an integer which is number of nodes.

@return
*/
void outputPolygons(POLYGON_LIST *polygons, int N) {
	int i, counter, prevNumVertices, currentNumVertices;
	
	sortPolygons(polygons);
	
	printf("\nNumber of polygons: %d\n", polygons->numPolygons);
	
	for (i = 3; i <= N; i++ ){
		if (polygons->polygonCounter[i] != 0) { // if there is polygons with i number of vertices it prints the number of polygons with i number of vertices
			printf("number of polygons with %d vertex: %d\n", i, polygons->polygonCounter[i]);
		}
	}
	
	counter = 0;
    prevNumVertices = -1;
    for (i = 0; i < polygons->numPolygons; i++) {// for all polygons in polygon list it prints them
        currentNumVertices = polygons->list[i].numVertex;
        if (currentNumVertices != prevNumVertices) { // if current polygon has another number of vertices
            counter = 0;
            printf("\n");
        }
        counter++;
        printf("%d. polygon with %d vertex: ", counter, currentNumVertices);
        writeArray(polygons->list[i].vertices, polygons->list[i].numVertex + 1);
        printf(" Perimeter: %d\n", polygons->list[i].perimeter);
        prevNumVertices = currentNumVertices;
    }
}
