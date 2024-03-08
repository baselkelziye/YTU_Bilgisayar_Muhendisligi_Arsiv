#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct edge{
	int u,v,w;
	}edge;
	
	typedef struct edge_list{
		edge data[MAX];
		int n;
		}edge_list;

void sort(edge_list *edges){
	edge tmp;
	int i,j;
	for(i=0; i<edges->n; i++){
		for(j=i+1; j<edges->n; j++){
			if(edges->data[i].w > edges->data[j].w){
				tmp=edges->data[i];
				edges->data[i]=edges->data[j];
				edges->data[j]=tmp;
				}
			}		
		}
			
}
		
						
void kruskal(int **graph, int n, edge_list *edges, edge_list *span_list){
		int i,j, belongs[MAX], cno1, cno2;
		edges->n=0;
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(graph[i][j]!=0){
					edges->data[edges->n].u=i;
					edges->data[edges->n].v=j;
					edges->data[edges->n].w=graph[i][j];
					edges->n++;
					}
				}
		}
		
		sort(edges);
		
		for(i=0; i<n; i++)
		belongs[i]=i;
		
		span_list->n=0;
		
		for(i=0; i<edges->n; i++){
			cno1=belongs[edges->data[i].u];
			cno2=belongs[edges->data[i].v];
			
			if(cno1!=cno2){
					span_list->data[span_list->n++]=edges->data[i];
					for(j=0; j<n; j++){
						if(belongs[j]==cno2){
							belongs[j]=cno1;	
						}	
					}	
				}
			}			
}

void printTree(edge_list span_list){
			int cost=0,i;
			
			for(i=0; i<span_list.n; i++){
				printf("%d - %d : %d\n",span_list.data[i].u,span_list.data[i].v,span_list.data[i].w);
				cost+=span_list.data[i].w;
				}
				
			printf("Tree Total Cost: %d",cost);
			
}
			
int main(){
	
	edge_list edges, span_list;
	int n,i,j;
	printf("Enter The Size Of Matrix: "); scanf("%d",&n);
	int **graph=(int**)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++)
	graph[i]=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter The graph[%d][%d]",i,j); scanf("%d",&graph[i][j]);
			}
		}
	
	kruskal(graph, n, &edges, &span_list);
	printTree(span_list);
	
	
	return 0;			
}