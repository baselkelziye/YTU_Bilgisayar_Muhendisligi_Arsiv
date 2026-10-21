// Simple undirected adjecancy list implementation
#include <stdio.h>
#include <stdlib.h>

struct n{
    int vertex;
    struct n * next;
};
typedef struct n NODE;

struct g{
    int numVertices;
    struct n** adjLists;
};
typedef struct g GRAPH;

NODE * createNode(int);
GRAPH * createGraph(int);
void addEdge(GRAPH*, int, int);
void printGraph(GRAPH*);

int main(){
    GRAPH* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}

NODE * createNode(int v){
    NODE * newNode = (NODE*)malloc(sizeof(NODE));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}



GRAPH * createGraph(int vertices){
    GRAPH * graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(NODE*));

    int i;
    for(i=0; i<vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}


void addEdge(GRAPH * graph, int src, int des){
    // add edge from src to des
    NODE * newNode = createNode(des);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // add edge from des to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[des];
    graph->adjLists[des] = newNode;
}

void printGraph(GRAPH* graph){
    int v;
    for(v=0; v<graph->numVertices; v++){
        NODE * temp = graph->adjLists[v];
        printf("\n Vertex %d:", v);
        while(temp){
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

}