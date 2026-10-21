#include<stdio.h>
#include<stdlib.h>


struct node{
	int vertex;
	struct node* next;
};

struct graph{
	int nVertex;
	struct node** adjList;
};

struct edge{
	int src,dest;
};

typedef struct node NODE;
typedef struct graph GRAPH;

NODE* createNode(int);
GRAPH* create(int);
void addEdge(GRAPH*,int,int,int);


int main(int argc, char** argv) {

	int nVertex = 4,i;
	GRAPH* _graph = create(nVertex);
	addEdge(_graph,0,2,0);
	addEdge(_graph,0,1,0);
	addEdge(_graph,2,3,1);

	for(i=0; i<nVertex; i++) {
		printf("%d-> ",i);
		while(_graph->adjList[i]!= NULL) {
			printf("%d, ",_graph->adjList[i]->vertex);
			_graph->adjList[i] = _graph->adjList[i]->next;
		}
		printf("\n");
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
	GRAPH* _graph = (GRAPH*)malloc(sizeof(GRAPH));
	int i;
	_graph->nVertex=nVertex;
	_graph->adjList = (NODE**)malloc(sizeof(NODE*)*nVertex);
	for(i=0; i<nVertex; i++) {
		_graph->adjList[i] = NULL;
	}
}

void addEdge(GRAPH* _graph, int src, int dest, int sym) {
	NODE* newNode = createNode(dest);
	newNode->next = _graph->adjList[src];
	_graph->adjList[src] = newNode;
	if(sym) {
		newNode = createNode(src);
		newNode->next = _graph->adjList[dest];
		_graph->adjList[dest] = newNode;
	}
}



