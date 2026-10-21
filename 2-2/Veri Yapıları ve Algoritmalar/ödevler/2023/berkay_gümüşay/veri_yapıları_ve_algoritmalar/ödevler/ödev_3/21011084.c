#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int id;
    int precond;
    int isVisited;
    int tmpPreCond;
    struct Node* next;
} node;
int endControl(node* adjList[],int size);

int main() {
  	int adjMatrix[10][10];
  	node* adjList[10];
  	int i,j,N;
  	node* tmpNode;
  	node* adjTmp[10];
  	printf("Komsuluk Matrisinin Boyutunu Giriniz (NxN) N : ");
  	scanf("%d",&N);
  	for(i=0;i<N;i++){
  		for(j=0;j<N;j++){
  			printf("%dx%d ",i+1,j+1);
  			scanf("%d",&adjMatrix[i][j]);
  			while((adjMatrix[i][j] == 1) && (i == j)){
  				printf("Hatali Deger Girdiniz Tekrar Deger Giriniz %dx%d : ",i+1,j+1);
  				scanf("%d",&adjMatrix[i][j]);
			  }
		  }
		  printf("\n");
	}
	system("cls");
	printf("Adjacency Matrix\n");
  	for(i=0;i<N;i++){
  		for(j=0;j<N;j++){
  			printf("%d ",adjMatrix[i][j]);
		  }
		  printf("\n");
	}
	printf("\n----------------------------------\n");
	for(i= 0;i < N; i++) {
        node* head = NULL;
        for (j = 0; j < N; j++) {
            if (adjMatrix[i][j] == 1){
                node* newNode = (node*)malloc(sizeof(node));
                newNode->id = j;
                newNode->precond = 0;
                newNode->tmpPreCond = 0;
                newNode->isVisited = 0;
                newNode->next = head;
                head = newNode;
            }
        }
        adjList[i] = head;
    }
    for(i= 0;i < N; i++) {
        node* head = NULL;
        for (j = 0; j < N; j++) {
            if (adjMatrix[j][i] == 1){
                node* newNode = (node*)malloc(sizeof(node));
                newNode->id = j;
                newNode->precond = 0;
                newNode->tmpPreCond = 0;
                newNode->isVisited = 0;
                newNode->next = head;
                head = newNode;
            }
        }
        adjTmp[i] = head;
    }
	printf("Adjacency List\n");
	for (i = 0; i < N; i++) {
    	printf("Dugum %d: ", i+1);
    	node* ptr = adjList[i];
    	while(ptr != NULL){
    		printf("%d ->",ptr->id+1);
    		adjList[i]->precond++;
    		adjList[i]->tmpPreCond++;
    		ptr = ptr->next;
		}
		printf("(-)\n");    	
    }
    printf("\n----------------------------------\n");
    printf("Reverse Adjacency List\n");
	for (i = 0; i < N; i++) {
    	printf("Dugum %d: ", i+1);
    	node* ptr = adjTmp[i];
    	while(ptr != NULL){
    		printf("%d ->",ptr->id+1);
    		adjTmp[i]->precond++;
    		adjTmp[i]->tmpPreCond++;
    		ptr = ptr->next;
		}
		printf("(-)\n");    	
    }
    printf("\n----------------------------------\n");
    printf("Precondition List\n");
    for(i=0;i<N;i++){
    	printf("%d : ",i+1);
    	if(adjTmp[i] != NULL){
    		printf("%d\n",adjTmp[i]->precond);
		}
		else{
			adjTmp[i] = (node*)malloc(sizeof(node));
			adjTmp[i]->id = -1;
			adjTmp[i]->isVisited = 0;
			adjTmp[i]->precond = 0;
			printf("%d\n",adjTmp[i]->precond);
			
		}
	}
	printf("\n----------------------------------\n");
    int donem=1;
	while(endControl(adjTmp,N) == 0){
		printf("\n%d. Donem : ",donem);
		for(i=0;i<N;i++){
			if((adjTmp[i]->precond == 0) && (adjTmp[i]->isVisited == 0)){
				printf("Course-%d  ",i+1);
				adjTmp[i]->isVisited = 1;
			}
		}
		for(i=0;i<N;i++){
			tmpNode = adjTmp[i];
			if(tmpNode->id != -1){
				while(tmpNode != NULL){
					if((adjTmp[tmpNode->id]->isVisited == 1) && (adjTmp[i]->precond != 0)){
						adjTmp[i]->precond = adjTmp[i]->precond -1;
						adjTmp[tmpNode->id]->isVisited = -1;
					}
					tmpNode = tmpNode->next;
				}
			}
		}
		donem++;
	}
 	return 0;
}

int endControl(node* adjList[],int size){
	int end=1,i;
	for(i=0;i<size;i++){
		if(adjList[i]->isVisited == 0){
			end = 0;
			return end;
		}
	}
	return end;
}
