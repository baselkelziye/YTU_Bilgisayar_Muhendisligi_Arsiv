#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// graph
struct Graph {
    int V;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
	int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            graph->adjMatrix[i][j] = false;

    return graph;
}

// add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true;
}

// DFS traversal of the graph
void DFS(struct Graph* graph, int v, bool* visited) {
    // mark the current node as visited
    visited[v] = true;
    printf("%d ", v);
    
	int i;
    // recur for all the vertices adjacent to this vertex
    for (i = 0; i < graph->V; i++)
        if (graph->adjMatrix[v][i] && !visited[i])
            DFS(graph, i, visited);
}

int main() {
    // create a graph
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // DFS traversal
    bool* visited = (bool*)malloc(V * sizeof(bool));
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;

    DFS(graph, 0, visited);
    printf("\n");

    return 0;
}

