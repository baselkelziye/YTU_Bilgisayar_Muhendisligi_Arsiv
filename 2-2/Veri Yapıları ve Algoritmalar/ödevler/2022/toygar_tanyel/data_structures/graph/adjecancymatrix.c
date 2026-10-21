// Undirected Adjecancy Matrix Implementation

#include <stdio.h>
#define V 4  // Constant vertice size

void initialize(int arr[][V]);
void addEdge(int arr[][V], int , int );
void print(int arr[][V]);

int main(){
    int adjMatrix[V][V];
    initialize(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 3);

    print(adjMatrix);

    return 0;
}

void initialize(int arr[][V]){
    int i, j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][V], int i, int j){
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void print(int arr[][V]){
    int i, j;
    for (i = 0; i < V; i++) {
        printf("%d: ", i);
        for (j = 0; j < V; j++) {
        printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}