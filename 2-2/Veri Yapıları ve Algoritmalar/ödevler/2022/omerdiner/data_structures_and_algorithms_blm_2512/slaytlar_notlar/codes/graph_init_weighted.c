#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	int w;
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
void addEdge(GRAPH*,int,int,int);

int main(int argc, char** argv){

	int nVertex = 4,i;
	GRAPH* _graph = create(nVertex);
	addEdge(_graph,0,2,4);
	addEdge(_graph,0,3,15);
	addEdge(_graph,0,1,8);
	addEdge(_graph,2,3,16);

	for(i=0; i<nVertex; i++) {
		printf("%d-> ",i);
		while(_graph->adjList[i]->next != NULL) {
			printf("%d(%d), ",_graph->adjList[i]->vertex,_graph->adjList[i]->w);
			_graph->adjList[i] = _graph->adjList[i]->next;
		}
		printf("%d(%d)\n",_graph->adjList[i]->vertex,_graph->adjList[i]->w);
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
void addEdge(GRAPH* _graph, int dest, int src,int w) {
	NODE* newNode = createNode(dest);
	newNode->w = w;
	newNode->next = _graph->adjList[src];
	_graph->adjList[src] = newNode;
	newNode = createNode(src);
	newNode->w = w;
	newNode->next = _graph->adjList[dest];
	_graph->adjList[dest] = newNode;

}

