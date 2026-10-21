#include <stdio.h>
#include <stdlib.h>

typedef struct node{//to store the nodes of the graph
	int vertex; 
	int weight;
	struct node* next;
}NODE;

typedef struct graph{
	int numOfNodes;
	NODE** adjList;
}GRAPH;

typedef struct stack{ //to store the path of a polygon (cycle)
	int top;
	int maxSize;
	int* nodes;
}STACK;

typedef struct polygon{//to store a polygon's nodes and weight etc.
	int size;
	int length;
	int* nodes;
	struct polygon* next;
}POLYGON;

typedef struct{ //to store all the polygons found in the graph
	int size;
	int numOfPolygons;
	int* counter; //histogram of polygons
	POLYGON** polygonsList;//to store the polygons similar to adjList in the graph
	POLYGON** polygonTails;//to add a polygon to tail of the list instead of head to make it alphabetically 
}POLYGONS;

GRAPH* createGraph(int n);
NODE* createNode(int vertex, int weight);
void addEdge(GRAPH* graph, int src, int dest, int weight);
void freeGraph(GRAPH* graph);
int readFromFile(GRAPH* graph);
STACK* createStack(int size);
int isEmpty(STACK* stack);
int isFull(STACK* stack);
void push(STACK* stack, int data);
int pop(STACK* stack);
void freeStack(STACK* stack);
POLYGONS* createPolygons(int n);
POLYGON* createPolygon(STACK stack, int totalWeight);
void addPolygonToList(POLYGONS* polygons, STACK stack, int totalWeight);
void freePolygons(POLYGONS* polygons);
int isDuplicateCycle(POLYGON* polygon, STACK stack);
void printPolygons(POLYGONS* polygons);
void printPolygon(POLYGON* polygon);
void DFS(GRAPH* graph, int* isCalled, int i, int parent, int target, int* totalWeight, STACK* stack, POLYGONS* polygons);
void findAllCycles(GRAPH* graph, POLYGONS* polygons);

int main(){
	int n;
	GRAPH* graph;
	POLYGONS* polygons;
	
	printf("the number of nodes in the graph: ");
	scanf("%d", &n);
			
	graph = createGraph(n);
	polygons = createPolygons(n);
	
	if(readFromFile(graph)) return 1;

	findAllCycles(graph, polygons);
	
	printPolygons(polygons);
	
	freePolygons(polygons);
	freeGraph(graph);
	
	return 0;
}

/*
@brief it simply calls DFS for each node in the graph. it finds all the cycles including first node in the first call, finds all the cycles excluding first node in the second call and so on. 

@param graph: pointer to graph.
@param polygons: pointer to the polygons.

@return
*/

void findAllCycles(GRAPH* graph, POLYGONS* polygons){
	int i, totalWeight = 0; //used to store the length of the current cycle
	STACK* stack = createStack(graph->numOfNodes); //used to store the path of the current cycle (polygon)
	int* isVisited = (int*) calloc(graph->numOfNodes, sizeof(int));
	
	for(i=0;i<graph->numOfNodes;i++){
		DFS(graph, isVisited, i, -1,  i, &totalWeight, stack, polygons);
		isVisited[i] = 1; //to exclude this node from the next DFS calls
	}
}

/*
@brief it simply calls DFS for each node in the graph. it finds all the cycles including first node in the first call, finds all the cycles excluding first node in the second call and so on. 

@param graph: pointer to graph.
@param isVisited: integer array for nodes to know whether they are visited.
@param i: the node for which this DFS is called.
@param parent: parent of the node i. this is used to prevent creating a cycle that has two nodes :) 
@param target: the node which is included in all the cycles this DFS call will find.
@param totalWeight: pointer to the variable that will store the lenght of the current cycle.
@param stack: pointer to the stack that will store the path of the current cycle.
@param polygons: pointer to the polygons.

@return
*/

void DFS(GRAPH* graph, int* isVisited, int i, int parent, int target, int* totalWeight, STACK* stack, POLYGONS* polygons){
	NODE* temp = graph->adjList[i]; //head of the neighbors of node i. (first neighbor)
	
	isVisited[i] = 1; //to make sure this node wont be called in the dfs calls of its neighbors or their neighbors.
	push(stack, i); //to add this node to the path
	
	while(temp != NULL){ //iterate over all the neighbors
		if(temp->vertex != parent && temp->vertex == target){ //if current neighbor is not the parent of node i and it is target, then we may find a valid cycle
			push(stack, target); //adding the target to the path and completing the path of this cycle
			*totalWeight += temp->weight; //adding the weight of the edge between i and this node
			if(!isDuplicateCycle(polygons->polygonsList[stack->top], *stack)){ //if it is not the reverse of an already added cycle, we can add it to the list
				addPolygonToList(polygons, *stack, *totalWeight); //adding the cycle to the polygonsList
			}
			pop(stack); //popping the target from stack to make the path valid for the next DFS calls
			*totalWeight -= temp->weight; //substracting the weight of the edge between i and this node
		}
		if(!isVisited[temp->vertex]){ //if it is not visited (if it is not the node of a parent DFS call or not a node for which all the cycles are found), then we can call DFS for this node
			*totalWeight += temp->weight; //adding the weight of the edge between node i and this node
			DFS(graph, isVisited, temp->vertex, i, target, totalWeight, stack, polygons);
			*totalWeight -= temp->weight; //substracting the weight of the edge between i and this node
		}
		
		temp = temp->next;
	}
	
	pop(stack); //popping the node i from the path since all the calls are done from it to find a cycle
	isVisited[i] = 0; //to make sure it can be called if there is a cycle that includes target node with a different path that reaches node i
}

/*
@brief it simply prints the polygons according to the output in the homework description

@param polygons: pointer to the polygons.

@return
*/

void printPolygons(POLYGONS* polygons){
	int i, n = polygons->size;
	POLYGON* temp;
	
	printf("\nsekil sayisi: %d\n", polygons->numOfPolygons);
	
	for(i=3;i<=n;i++){
		if(polygons->counter[i]) printf("%d'gen sayisi: %d\n", i, polygons->counter[i]); //printing the number of the polygons with i nodes
	}
	
	printf("\n");
	
	for(i=3;i<=n;i++){ //printing all the polygons
		temp = polygons->polygonsList[i];
		while(temp != NULL){//printing all the polygons with i nodes
			printPolygon(temp);
			temp = temp->next;
		}
		printf("\n");
	}
}

/*
@brief it simply prints the polygon according to the output in the homework description

@param polygon: pointer to the polygon.

@return
*/

void printPolygon(POLYGON* polygon){
	int i, n = polygon->size;
	printf("%d'gen: ", n);
	
	for(i=0;i<=n;i++) printf("%c ", polygon->nodes[i] + 'A'); //casting the node to a char
	
	printf(" uzunluk: %d\n", polygon->length);
}

/*
@brief it reads the file that has all the edges and adds the edges to the graph

@param graph: pointer to the graph.

@return
*/

int readFromFile(GRAPH* graph){
	char filename[20];
	FILE* file;
	int w;
	char u, v; //they are char since vertices are char in the file
	
	printf("enter the filename: ");
	scanf("%s", filename);
	
	file = fopen(filename, "r");
    if (file == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, " %c %c %d", &u, &v, &w) == 3){
        addEdge(graph, u - 'A', v - 'A', w); //casting u and v to int to store them in the adjList
    }

    fclose(file);
    return 0;
}

/*
@brief it looks all the polygons with the equal number of nodes in the list to find whether stack has a path of a cycle that is the reverse of one of them  

@param polygon: pointer to the polygon which stores the head of the list of the polygons with i nodes.
@param stack: stack that stores the path of the current cycle. (since I don't pass the address of the stack, original stack won't be affected from pop operations)

@return 1 if it is duplicate, or 0 if it is not
*/

int isDuplicateCycle(POLYGON* polygon, STACK stack){
	int i, ctrl, size = stack.top + 1;
	int* foundPolygon = (int*) malloc(size * sizeof(int));
	
	i = 0;
	while(!isEmpty(&stack)){//the path of the found polygon is copied to an array
		foundPolygon[i++] = pop(&stack); 
	}
	
	while(polygon != NULL){//traversing all the polygons with size stack.top  
		ctrl = 1;
		for(i=0;i<size;i++){
			if(polygon->nodes[i] != foundPolygon[size - 1 - i]) ctrl = 0;
		}
		if(ctrl){//if ctrl is not changed then current polygon is reverse of found polygon
			free(foundPolygon);
			return 1;
		}
		polygon = polygon->next;	
	}
	free(foundPolygon);
	return 0;
}

/*
@brief it creates polygons structure that will store all the details about the polygons DFS will find

@param n: the number of the polygons (the number of nodes in the graph)

@return pointer to the polygons that is just created
*/

POLYGONS* createPolygons(int n){
	POLYGONS* polygons = (POLYGONS*) malloc(sizeof(POLYGONS));
	polygons->size = n;
	polygons->numOfPolygons = 0;
	polygons->counter = (int*) calloc(polygons->size + 1, sizeof(int));
	polygons->polygonsList = (POLYGON**) calloc(polygons->size + 1, sizeof(POLYGON*));
	polygons->polygonTails = (POLYGON**) calloc(polygons->size + 1, sizeof(POLYGON*));
	return polygons;
}

/*
@brief it creates polygon that will store the path, length etc.

@param stack: stack that stores the path of the polygon that will be created
@param totalWeight: length of the polygon

@return pointer to the polygon that is just created
*/

POLYGON* createPolygon(STACK stack, int totalWeight){
	int i;
	POLYGON* polygon = (POLYGON*) malloc(sizeof(POLYGON));
	polygon->size = stack.top;
	polygon->nodes = (int*) malloc((polygon->size + 1) * sizeof(int));
	for(i=0;i<=polygon->size;i++){
		polygon->nodes[i] = pop(&stack);
	}
	polygon->length = totalWeight;
	polygon->next = NULL;
	return polygon;
}

/*
@brief it creates a new polygon with given params and adds it to the tail of the list that has the same number of the nodes with new polygon

@param polygons: pointer to the polygons that stores all the polygons
@param stack: stack that stores the path of the polygon that will be created
@param totalWeight: length of the polygon

@return pointer to the polygon that is just created
*/

void addPolygonToList(POLYGONS* polygons, STACK stack, int totalWeight){
	POLYGON* polygon = createPolygon(stack, totalWeight);
	if(polygons->polygonsList[polygon->size] == NULL){
		polygons->polygonsList[polygon->size] = polygons->polygonTails[polygon->size] = polygon;
	}
	else{
		polygons->polygonTails[polygon->size]->next = polygon;
		polygons->polygonTails[polygon->size] = polygon;
	}
	polygons->counter[polygon->size]++;
	polygons->numOfPolygons++;
}

/*
@brief it frees the polygons

@param polygons: pointer to the polygons that stores all the polygons

@return
*/

void freePolygons(POLYGONS* polygons){
	int i, n = polygons->size;
	POLYGON *deleting, *temp;
    for (i=0;i<n;i++){
        temp = polygons->polygonsList[i];
        while(temp != NULL){
            deleting = temp;
            temp = temp->next;
            free(deleting->nodes);
            free(deleting);
        }
    }
    free(polygons->counter);
    free(polygons->polygonsList);
    free(polygons->polygonTails);
    free(polygons);
}

/*
@brief it creates the graph with an adjacency list

@param n: the number of nodes

@return pointer to the graph that is just created
*/

GRAPH* createGraph(int n){
	int i;
	GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
	graph -> numOfNodes = n;
	graph -> adjList = (NODE**) calloc(n, sizeof(NODE*));
	return graph;
}

/*
@brief it creates a node with given params

@param vertex: the vertex number of the new node
@param weight: the weight of the new node

@return pointer to the node that is just created
*/

NODE* createNode(int vertex, int weight){
	NODE* node = (NODE*) malloc(sizeof(NODE));
	node -> vertex = vertex;
	node -> weight = weight;
	node -> next = NULL;
	return node;
}

/*
@brief it adds the new node whose vertex is dest to the head of the adjacency list of src and vice versa.

@param graph: pointer to the graph.
@param src: the vertex number of the source node
@param dest: the weight of the the destination node
@param weight: the weight of the edge between src and dest

@return
*/

void addEdge(GRAPH* graph, int src, int dest, int weight){
	if(src == dest) return;
	if(src >= graph -> numOfNodes || dest >= graph -> numOfNodes) return;
	if(src < 0 || dest < 0) return;
	
	//edge from src to dest
	NODE* newNode = createNode(dest, weight);
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;
	
	//edge from dest to src
	newNode = createNode(src, weight);
	newNode->next = graph->adjList[dest];
	graph->adjList[dest] = newNode;
}

/*
@brief it frees the graph

@param polygons: pointer to the graph

@return
*/

void freeGraph(GRAPH* graph){
	int i;
	NODE *deleting, *temp;
    for(i=0;i<graph->numOfNodes;i++){
        NODE* temp = graph->adjList[i];
        while(temp!= NULL){
            NODE* deleting = temp;
            temp = temp->next;
            free(deleting);
        }
    }
    free(graph->adjList);
    free(graph);
}

/*
@brief it creates the graph with an adjacency list

@param n: max size of the stack (it can have at most all the nodes in the graph plus 1 for a cycle so it will be n + 1) 

@return pointer to the stack that is just created
*/

STACK* createStack(int size){
    STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->maxSize = size + 1;
    stack->top = -1;
    stack->nodes = (int*)malloc(stack->maxSize * sizeof(int));
    return stack;
}

/*
@brief it checks whether stack is empty

@param stack: pointer to the stack 

@return 1 if it is empty, or 0
*/

int isEmpty(STACK* stack){
    return stack->top == -1;
}

/*
@brief it checks whether stack is full

@param stack: pointer to the stack 

@return 1 if it is full, or 0
*/

int isFull(STACK* stack){
    return stack->top == stack->maxSize - 1;
}

/*
@brief it adds a new item to the stack if it is not full

@param stack: pointer to the stack 

@return 
*/

void push(STACK* stack, int data){
    if (!isFull(stack)){
        stack->nodes[++stack->top] = data;
    }
}

/*
@brief it deletes a new item from the stack if it is not empty

@param stack: pointer to the stack 

@return 
*/

int pop(STACK* stack){
    if (!isEmpty(stack)){
		return stack->nodes[stack->top--];
    }
}

/*
@brief it frees the stack

@param stack: pointer to the stack 

@return 
*/

void freeStack(STACK* stack){
    free(stack->nodes);
    free(stack);
}
