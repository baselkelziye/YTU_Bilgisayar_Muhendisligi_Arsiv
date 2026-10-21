//FEYZA ÞAHÝN - 18011019
//VYA ÖDEV-3


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char sorgu[20];
	int sorguSayisi;
	struct node *next;
}NODE;

typedef struct graph{
	int numVertices;
	struct node **adjLists;
}GRAPH;

NODE *createNode(char *, int);
GRAPH *createGraph(int);
GRAPH *mergeGraph(int, GRAPH *, GRAPH *, int *);
void printGraph(GRAPH *, int);
void sorgula(GRAPH *, char *);

int main(){
	int devam=1, i, num1, num2;
	char sor[20];
	NODE *tmp;
	
	//GRAPH 1
	printf("\nGRAPH-1 bilgilerini giriniz:");
	printf("\nGraph-1 nod sayisi: ");
	scanf("%d", &num1);
	GRAPH *graph1 = createGraph(num1);	
	printf("\nGRAPH-1:\n");
	printGraph(graph1, num1);
	
	//GRAPH 2
	printf("\n\nGRAPH-2 bilgilerini giriniz:");
	printf("\nGraph-2 nod sayisi: ");
	scanf("%d", &num2);
	GRAPH *graph2 = createGraph(num2);
	printf("\nGRAPH-2:\n");
	printGraph(graph2, num2);
	
	////////////////////////////////////////////////////
	GRAPH *graph3;
	int sayac = graph1->numVertices;
	graph3 = mergeGraph(graph1->numVertices + graph2->numVertices, graph1, graph2, &sayac);
	printf("\n\nGRAPH-3:\n");
	printGraph(graph3, sayac);
	
	printf("\n\nSORGULAMA\n\nSorgulamak icin 1'e basiniz\nCikmak icin 0'a basiniz'\n");
	while(devam){
		scanf("%d", &devam);
		if(devam){
			printf("\nSorgulamak istediginiz sorgu'yu giriniz: ");
			scanf("%s", sor);
			sorgula(graph3, sor);
			
			//sorgu sayýsýný artýrma
			for(i=0; i<graph3->numVertices; i++){
				tmp = graph3->adjLists[i];
				while(tmp!=NULL && strcmp(tmp->sorgu, sor)!=0){
					tmp = tmp->next;
				}
				if(tmp!=NULL){
					(tmp->sorguSayisi)++;
				}
			}
		}
		printf("\n\ndevam: (1/0) ");
	}

	return 0;
}

void sorgula(GRAPH *g, char sor[]){
	NODE *max1, *max2, *max3;
	NODE *tmp;
	
	int i=0;	
	tmp = g->adjLists[0];
	while(tmp!=NULL && strcmp(g->adjLists[i]->sorgu, sor)!=0){
		i++;
		tmp = g->adjLists[i];
	}
	//printf("SORGU: %s", tmp->sorgu);
	if(tmp == NULL){
		printf("\nsorgu mevcut degil\n");
		return;
	}
	
	printf("Ilgili aramalar -sorgulanma sayilarina gore-:\n");
	max1 = g->adjLists[i]->next;
	if(max1->next == NULL){
		printf("\nmax1: %s", max1->sorgu);
		return;
	}
	max2 = max1->next;
	if(max2->next == NULL){
		if(max1->sorguSayisi < max2->sorguSayisi){
			tmp = max1;
			max1 = max2;
			max2 = tmp;
		}
		printf("\nmax1: %s    sorgu sayisi: %d", max1->sorgu, max1->sorguSayisi);
		printf("\nmax2: %s    sorgu sayisi: %d", max2->sorgu, max2->sorguSayisi);
		return;
	}
	max3 = max2->next;
	if(max3->next == NULL){
		if(max1->sorguSayisi < max2->sorguSayisi && max1->sorguSayisi < max3->sorguSayisi){
			tmp = max1;
			max1 = max3;
			max3 = tmp;
		}
		if(max1->sorguSayisi < max2->sorguSayisi){
			tmp = max1;
			max1 = max2;
			max2 = tmp;
		}
		if(max2->sorguSayisi < max3->sorguSayisi){
			tmp = max2;
			max2 = max3;
			max3 = tmp;
		}
		printf("\nmax1: %s    sorgu sayisi: %d", max1->sorgu, max1->sorguSayisi);
		printf("\nmax2: %s    sorgu sayisi: %d", max2->sorgu, max2->sorguSayisi);
		printf("\nmax3: %s    sorgu sayisi: %d", max3->sorgu, max3->sorguSayisi);
		return;
	}
	//ilgili eleman sayýsý 3'ten fazlaysa
	tmp = g->adjLists[i]->next->next;
	while(tmp!=NULL){
		if(tmp->sorguSayisi > max1->sorguSayisi){
			max3 = max2;
			max2 = max1;
			max1 = tmp;
		}
		else if(tmp->sorguSayisi > max2->sorguSayisi){
			max3 = max2;
			max2 = tmp;
		}
		else if(tmp->sorguSayisi > max3->sorguSayisi){
			max3 = tmp;
		}
		tmp = tmp->next;
	}
	printf("\nmax1: %s    sorgu sayisi: %d", max1->sorgu, max1->sorguSayisi);
	printf("\nmax2: %s    sorgu sayisi: %d", max2->sorgu, max2->sorguSayisi);
	printf("\nmax3: %s    sorgu sayisi: %d", max3->sorgu, max3->sorguSayisi);

}

GRAPH *mergeGraph(int v, GRAPH *g1, GRAPH *g2, int *sayac){
	NODE *tmp, *tmp2, *tmp3, *newNode;
	int i, j, k;	
	
	GRAPH *g3 = (GRAPH*)malloc(sizeof(GRAPH));
	g3->numVertices = v;
	g3->adjLists = (NODE**)malloc(v*sizeof(NODE*));
	for(i=0; i<v; i++){
		g3->adjLists[i] = NULL;
	}
	
	//BÝRLEÞTÝRME
	for(i=0; i<g1->numVertices; i++){
		tmp = g1->adjLists[i];
		g3->adjLists[i] = createNode(tmp->sorgu, tmp->sorguSayisi);
		tmp3 = g3->adjLists[i];
		while(tmp->next != NULL){
			tmp = tmp->next;
			newNode = createNode(tmp->sorgu, tmp->sorguSayisi);
			tmp3->next = newNode;
			tmp3 = newNode;
		}
	}
	
	for(i=0; i<g1->numVertices; i++){
		j=0;
		while(j < g2->numVertices  &&  strcmp(g1->adjLists[i]->sorgu, g2->adjLists[j]->sorgu) != 0){
			j++;
		}
		//g1'deki elemaný g2'de bulmuþsak
		if(j < g2->numVertices){
			tmp = g2->adjLists[j]->next; //F
			k=0;
			while(k < *sayac  &&  strcmp(g3->adjLists[k]->sorgu, tmp->sorgu) != 0){
				k++;
			}
			//g2'nin komþusu g1'de varsa
			if(k < *sayac){
				//n1-n2
				newNode = createNode(tmp->sorgu, tmp->sorguSayisi); //F
				newNode->next = g3->adjLists[i]->next;
				g3->adjLists[i]->next = newNode;
				
				//n2-n1
				newNode = createNode(g1->adjLists[i]->sorgu, g1->adjLists[i]->sorguSayisi); //C
				newNode->next = g3->adjLists[k]->next;
				g3->adjLists[k]->next = newNode;	
				
			}
			//yeni nod listeye eklenecek
			else{
				//yeni list ekleme
				newNode = createNode(tmp->sorgu, tmp->sorguSayisi); //F
				g3->adjLists[*sayac] = newNode;
				
				//n2-n1
				newNode = createNode(g1->adjLists[i]->sorgu, g1->adjLists[i]->sorguSayisi); //B
				newNode->next = g3->adjLists[*sayac]->next;
				g3->adjLists[*sayac]->next = newNode;
				
				//n1-n2
				newNode = createNode(tmp->sorgu, tmp->sorguSayisi); //F
				newNode->next = g3->adjLists[i]->next;
				g3->adjLists[i]->next = newNode;
				(*sayac)++;	
			}
		}
	}
	//g2'de ortak olmayan elemanlarý da dahil etme
	int s = *sayac;
	for(i=g1->numVertices; i<s; i++){
		if(g3->adjLists[i]!= NULL){ //G3-F
			j=0;
			//G2'deki indisini bulma
			while(strcmp(g3->adjLists[i]->sorgu, g2->adjLists[j]->sorgu) != 0){ // F-C-H-I-B kesin var bu yüzden j'yi kontrol etmiyoruz
				j++;
			}
			tmp = g2->adjLists[j]->next; //G2-C
			
			while(tmp!=NULL){
				tmp2 = g3->adjLists[i]->next;
								
				while(tmp2!=NULL && strcmp(tmp->sorgu, tmp2->sorgu) != 0){
					tmp2 = tmp2->next;
				}
				
				if(tmp2==NULL){
					newNode = createNode(tmp->sorgu, tmp->sorguSayisi); //H
					g3->adjLists[*sayac] = newNode; //A-B-C-D + H
					
					newNode = createNode(g3->adjLists[i]->sorgu, g3->adjLists[i]->sorguSayisi); //F
					newNode->next = g3->adjLists[*sayac]->next;
					g3->adjLists[*sayac]->next = newNode; //H-F
					
					newNode = createNode(tmp->sorgu, tmp->sorguSayisi);
					newNode->next = g3->adjLists[i]->next; 
					g3->adjLists[i]->next = newNode; //F-H
					(*sayac)++;
				}
				tmp = tmp->next;
			}
		}
		else return g3;
	}
	return g3;
}

NODE *createNode(char s[], int sSay){ 
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	strcpy(newNode->sorgu, s);
	newNode->sorguSayisi = sSay;
	newNode->next = NULL;
	return newNode;
}

GRAPH *createGraph(int v){ //v: #ofVertice
	int i, j, n, sSay=1, devam=1;
	char sor[20], sor1[20], sor2[20];
	GRAPH *newGraph = (GRAPH*)malloc(sizeof(GRAPH));
	NODE *newNode, *nbour, *tmp, *tmp2;
	
	newGraph->numVertices = v;
	newGraph->adjLists = (NODE**)malloc(v*sizeof(NODE*));
	for(i=0; i<v; i++){
		newGraph->adjLists[i] = NULL;
	}
	for(i=0; i<v; i++){
		printf("\n%d. NOD: ", i+1);
		printf("\nsorgu: ");
		scanf("%s", sor);
		printf("sorgu sayisi: ");
		scanf("%d", &sSay);
		newNode = createNode(sor, sSay);
		newGraph->adjLists[i] = newNode;
	}
	while(devam){
				
		printf("\nBaglamak istediginiz iki nodu giriniz: ");
		scanf("%s %s", sor1, sor2);
		
		i=0;
		tmp = newGraph->adjLists[0];
		while(strcmp(sor1, newGraph->adjLists[i]->sorgu) !=0){
			i++;
		}
		j=0;
		tmp2 = newGraph->adjLists[0];
		while(strcmp(sor2, newGraph->adjLists[j]->sorgu) !=0){
			j++;
		}
		newNode = createNode(sor1, newGraph->adjLists[i]->sorguSayisi);
		newNode->next = newGraph->adjLists[j]->next;
		newGraph->adjLists[j]->next = newNode;
		
		newNode = createNode(sor2, newGraph->adjLists[j]->sorguSayisi);
		newNode->next = newGraph->adjLists[i]->next;
		newGraph->adjLists[i]->next = newNode;

		printf("\nBaglanti islemine devam?: (1/0) ");
		scanf("%d", &devam);
	}
	
	return newGraph;
}

void printGraph(GRAPH *graph, int v){
	int i;
	NODE *tmp;	
	printf("\n");
	for(i=0; i<v; i++){
		tmp = graph->adjLists[i];
		printf("%s", tmp->sorgu);
		while(tmp->next != NULL){
			tmp = tmp->next;
			printf(" -> %s", tmp->sorgu);
		}
		printf("\n");
	}
}
