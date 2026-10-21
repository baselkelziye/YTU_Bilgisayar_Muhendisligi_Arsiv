#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node* next;
};

struct graph{
	int numVertex;
	struct node** adjList;
};

typedef struct node NODE;
typedef struct graph GRAPH;

NODE* createNode(int);
GRAPH* create(int);
void addEdge(GRAPH*,int,int);

int main(int argc, char** argv){

	int nVertex = 4,i;
	GRAPH* _graph = create(nVertex);
	addEdge(_graph,0,2);
	addEdge(_graph,0,3);
	addEdge(_graph,0,1);
	addEdge(_graph,2,3);

	for(i=0; i<nVertex; i++) {
		printf("%d-> ",i);
		while(_graph->adjList[i]->next != NULL) {
			printf("%d, ",_graph->adjList[i]->vertex);
			_graph->adjList[i] = _graph->adjList[i]->next;
		}
		printf("%d\n",_graph->adjList[i]->vertex);
	}


	return 0;
}

NODE* createNode(int vertex) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

GRAPH* create(int nVertex) {
	int i;
	GRAPH* _graph = (GRAPH*)malloc(sizeof(GRAPH));
	_graph->numVertex = nVertex;
	_graph->adjList = (NODE**)malloc(nVertex*sizeof(NODE*));
	for(i=0; i<nVertex; i++) {
		_graph->adjList[i] = NULL;
	}
	return _graph;
}
void addEdge(GRAPH* _graph, int dest, int src) {
	NODE* newNode = createNode(dest);
	newNode->next = _graph->adjList[src];
	_graph->adjList[src] = newNode;
	newNode = createNode(src);
	newNode->next = _graph->adjList[dest];
	_graph->adjList[dest] = newNode;

}
