#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ELÝF MERTOÐLU 19011065

typedef struct node{
	char sorgu[50];
	int sorguno;
	struct node* next;
}node;

typedef struct graph{
	
	int dugumno;
	struct node** adjlist;
}graph;

node *createNode(char * , int );
graph *createGraph(int );
graph *mergeGraphs(graph *, graph *);
void komsuDugumListeleme(graph *, graph *, graph *);
void sorgulama(graph *, graph *, graph *, char *);

int main(){
	
	int i;
	int topdugumsay, topdugumsay2;
	printf("1.graf icin ilgili aramalarla birlikte toplam sorgu sayisini giriniz.\n");//kullanýcýdan grafýn toplam düðüm sayýsý istenir.
	scanf("%d",&topdugumsay);
	graph *graf1 = createGraph(topdugumsay);
	for(i=0;i<topdugumsay;i++){
		graf1->adjlist[i]=(node*)malloc(sizeof(node));
	}
	printf("1.graf icin sorgu stringini ve sorgulanma adedini giriniz.\n");//sadece ilk grafýn ana düðümü istenir. (pdf'teki 'a')
	scanf("%s %d",graf1->adjlist[0]->sorgu,&graf1->adjlist[0]->sorguno);
	graf1->adjlist[0]->next=NULL;
	printf("'ilgili aramalar'in sorgu stringini ve sorgulanma adedini giriniz.\n"); //ilk grafýn kalan düðümleri istenir. (pdf'teki b, c, d)
	for(i=1;i<graf1->dugumno;i++){
		scanf("%s %d",&graf1->adjlist[i]->sorgu,&graf1->adjlist[i]->sorguno);
		graf1->adjlist[i]->next=NULL;
	}
	node *head=graf1->adjlist[0];
	node *iter=head;
	i=1;
	while(i<graf1->dugumno){
		iter->next=createNode(graf1->adjlist[i]->sorgu,graf1->adjlist[i]->sorguno);
		iter=iter->next;
		i++;
	}
	for(i=1;i<graf1->dugumno;i++){
		graf1->adjlist[i]->next=graf1->adjlist[0];
	}
	
	
	printf("2.graf icin ilgili aramalarla birlikte toplam sorgu sayisini giriniz.\n");//kullanýcýdan grafýn toplam düðüm sayýsý istenir.
	scanf("%d",&topdugumsay2);
	graph *graf2 = createGraph(topdugumsay2);
	for(i=0;i<topdugumsay2;i++){
		graf2->adjlist[i]=(node*)malloc(sizeof(node));
	}
	printf("2.graf icin sorgu stringini ve sorgulanma adedini giriniz.\n");//sadece ikinci grafýn ana düðümü istenir. (pdf'teki 'f')
	scanf("%s %d",&graf2->adjlist[0]->sorgu,&graf2->adjlist[0]->sorguno);
	graf2->adjlist[0]->next=NULL;
	printf("'ilgili aramalar'in sorgu stringini ve sorgulanma adedini giriniz.\n");//ilk grafýn kalan düðümleri istenir. (pdf'teki c, h, i, b)
	for(i=1;i<graf2->dugumno;i++){
		scanf("%s %d",&graf2->adjlist[i]->sorgu,&graf2->adjlist[i]->sorguno);
		graf2->adjlist[i]->next=NULL;
	}
	
	node *head2=graf2->adjlist[0];
	node *iter2=head2;
	i=1;
	while(i<graf2->dugumno){
		iter2->next=createNode(graf2->adjlist[i]->sorgu,graf2->adjlist[i]->sorguno);
		iter2=iter2->next;
		i++;
	}
	for(i=1;i<graf2->dugumno;i++){
		graf2->adjlist[i]->next=graf2->adjlist[0];
	}
	graph *fgraph=mergeGraphs(graf1,graf2);
	komsuDugumListeleme(fgraph,graf1,graf2);
	
	int kontrol=1;
	char query[50];
	while(kontrol==1){
		printf("bir sorgu giriniz veya cikis icin 'quit' yaziniz.\n");
		scanf("%s",query);
		if(strcmp(query,"quit")==0){
			kontrol=-1;
		}else{
			sorgulama(fgraph, graf1, graf2, query);
		}

	}
	
	return 0;
}


node *createNode(char query[], int queryno){
	
	node *newnode=(node*)malloc(sizeof(node));
	strcpy(newnode->sorgu,query);
	newnode->sorguno=queryno;
	newnode->next=NULL;
	return newnode;
}

graph *createGraph(int verticesno){
	
	int i;
	graph *newgraph=(graph*)malloc(sizeof(graph));
	newgraph->dugumno=verticesno;
	newgraph->adjlist=(node**)malloc(verticesno*sizeof(node*)); 	
	
	for(i=0;i<verticesno;i++){
		newgraph->adjlist[i]=NULL;
	}
	return newgraph;
}

graph *mergeGraphs(graph *graph1, graph *graph2){
	
	char same[50][50];
	int sameno[50];
	int i,j,counter=0,dugumsay,sayac=0,yenidugumsay,sayac2=0,k;
	for(i=1;i<graph1->dugumno;i++){
		for(j=1;j<graph2->dugumno;j++){
			if(strcmp(graph1->adjlist[i]->sorgu,graph2->adjlist[j]->sorgu)==0){
				strcpy(same[counter],graph1->adjlist[i]->sorgu); 
				sameno[counter]=graph1->adjlist[i]->sorguno;
				counter++;
			}
		}
	}

	dugumsay=graph1->dugumno+graph2->dugumno-counter; 
	graph *mergedgraph = createGraph(dugumsay);
	for(i=0;i<dugumsay;i++){
		mergedgraph->adjlist[i]=(node*)malloc(sizeof(node));
	}
	node *mergehead=mergedgraph->adjlist[0];
	node *mergeiter=mergehead;
	graph *head=graph1;
	graph *iter=head;
	for(i=0;i<graph1->dugumno;i++){
		mergedgraph->adjlist[i]=iter->adjlist[i];
	}
	graph *head2=graph2;
	graph *iter2=head;
	yenidugumsay=dugumsay-graph1->dugumno; 
	for(j=0;j<graph2->dugumno;j++){ 
		sayac=0;
			for(k=0;k<counter;k++){
				if(sayac2<yenidugumsay && strcmp(same[k],graph2->adjlist[j]->sorgu)!=0){
					sayac++;
				}
				if(sayac2<yenidugumsay && sayac==counter){
					mergedgraph->adjlist[i]=graph2->adjlist[j];
					i++;
					sayac2++;
				}
			}
		}
	
	k=0;
	i=1;	
	while(i<graph1->dugumno){
		mergeiter->next=createNode(graph1->adjlist[i]->sorgu,graph1->adjlist[i]->sorguno);
		mergeiter=mergeiter->next;
		i++;
	}
	mergeiter->next=NULL;
	node *temp;
	int sayacc=0;
	for(i=1;i<graph1->dugumno;i++){
		sayacc=0;
		for(k=0;k<counter;k++){
			if(strcmp(same[k],mergedgraph->adjlist[i]->sorgu)==0){
				temp=mergedgraph->adjlist[i];
				temp->next=createNode(mergedgraph->adjlist[0]->sorgu,mergedgraph->adjlist[0]->sorguno);
				temp=temp->next;
				temp->next=createNode(mergedgraph->adjlist[graph1->dugumno]->sorgu,mergedgraph->adjlist[graph1->dugumno]->sorguno);
				temp=temp->next;
				temp->next=NULL;
			}else{
				sayacc++;
			}
		}
		if(sayacc==counter){
			temp=mergedgraph->adjlist[i];
			temp->next=createNode(mergedgraph->adjlist[0]->sorgu,mergedgraph->adjlist[0]->sorguno);
			temp=temp->next;
			temp->next=NULL;
		}
	}
	
	int kontrol=0;
	k=0;
	for(i=graph1->dugumno;i<dugumsay;i++){
		if(i==graph1->dugumno){
			temp=mergedgraph->adjlist[i];
			for(k=0;k<counter;k++){
				temp->next=createNode(same[k],sameno[k]);
				temp=temp->next;
			}
			j=i+1;
			for(;j<dugumsay;j++){
				temp->next=createNode(mergedgraph->adjlist[j]->sorgu,mergedgraph->adjlist[j]->sorguno);
				temp=temp->next;
			}
			temp->next=NULL;
		}else{
			temp=mergedgraph->adjlist[i];
			temp->next=createNode(mergedgraph->adjlist[graph1->dugumno]->sorgu,mergedgraph->adjlist[graph1->dugumno]->sorguno);
			temp=temp->next;
			temp->next=NULL;
		}
	}
	return mergedgraph;
} //mergeGraphs parantezi


void komsuDugumListeleme(graph *mergraph, graph *graph1, graph *graph2){
	
	int i,j,counter=0,dugumsay;
	for(i=1;i<graph1->dugumno;i++){
		for(j=1;j<graph2->dugumno;j++){
			if(strcmp(graph1->adjlist[i]->sorgu,graph2->adjlist[j]->sorgu)==0){
				counter++;
			}
		}
	}
	
	dugumsay=graph1->dugumno + graph2->dugumno - counter;
	for(i=0;i<dugumsay;i++){
			node *iter=mergraph->adjlist[i];
			printf("%s isimli sorgunun ilgili aramalari(komsulari) = ",iter->sorgu);
			while(iter->next!=NULL){
				iter=iter->next;
				printf("%s ",iter->sorgu);
			}
			printf("\n");
	}
	return;
}

void sorgulama(graph *mergraph, graph *graph1, graph *graph2, char aranan[]){
	
	int i,counter=0,topdugumsay,k=0,j,sayac=0,first=-1,second=-1,third=-1;
	int maxdizi[10];
	node *temp, *temp2, *temp3, *temp4;

	for(i=1;i<graph1->dugumno;i++){
		for(j=1;j<graph2->dugumno;j++){
			if(strcmp(graph1->adjlist[i]->sorgu,graph2->adjlist[j]->sorgu)==0){
				counter++;
			}
		}
	}
	topdugumsay=graph1->dugumno + graph2->dugumno - counter;
	
	for(i=0;i<topdugumsay;i++){
		if(strcmp(mergraph->adjlist[i]->sorgu,aranan)==0){
			mergraph->adjlist[i]->sorguno++; //sorgulananýn sorgulanma sayýsý 1 artýrýlýr.
			temp4=mergraph->adjlist[i];
			temp3=mergraph->adjlist[i];
			temp2=mergraph->adjlist[i];
			temp=mergraph->adjlist[i];
			while(temp->next!=NULL){
				temp=temp->next;
				sayac++;
			}
		}
	}
	if(sayac<3){
		printf("bu sorgunun zaten 3'ten az ilgili aramasi bulunmaktadir.\n");
		while(temp3->next!=NULL){
			temp3=temp3->next;
			printf("%s ",temp3->sorgu);
		}
		printf("\n");
	}else{
		while(temp2->next!=NULL){
			temp2=temp2->next;
			if(temp2->sorguno>first){
				third = second;
        		second = first;
        		first = temp2->sorguno;
			}else if(temp2->sorguno>second){
				third = second;
            	second = temp2->sorguno;
			}else if(temp2->sorguno>third){
				third=temp2->sorguno;
			}	
		}
		
		printf("en cok sorgulanan 3 komsu: ");
		while(temp4->next!=NULL){
			temp4=temp4->next;
			if((first==temp4->sorguno) || (second==temp4->sorguno) || (third==temp4->sorguno)){
				printf("%s ",temp4->sorgu);
			}
		}
		printf("\n");
		
	}
	
}
