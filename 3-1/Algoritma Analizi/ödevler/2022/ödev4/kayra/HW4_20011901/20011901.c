#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KISISIZE 12
typedef struct id{
int currID;
struct id * nextID; 	
}ID;
typedef struct kisi{
char * isim;
char * soyisim;
int id;
ID * next;
}KISI;
int dequeue(int *front,int * queue)
{
	*front = (*front + 1) % KISISIZE;
    int data = queue[*front];
    return data;
}
int enqueue(int data,int *rear,int * queue)
{
    *rear = (*rear + 1) % KISISIZE;
    queue[*rear] = data;
    return 1;
}
void kisiOlustur(int id,char * isim, char * soyisim,KISI * kisi){
	kisi->id = id;
	kisi->isim= (char*)malloc(50*sizeof(char));
	kisi->soyisim= (char*)malloc(50*sizeof(char));
	strcpy(kisi->isim,isim);
	strcpy(kisi->soyisim,soyisim);
	kisi->next=(ID*)malloc(sizeof(ID));
}
void kisiYazdir(KISI * kisi){
	ID * id;
	printf("ID->%d--ISIM->%s--SOYISIM->%s\n",kisi->id,kisi->isim,kisi->soyisim);
	id = kisi->next;
}
KISI ** readFile(){
	FILE * fp;
	fp = fopen("socialNET.txt","r");
	int id,i,tmpID;
	KISI ** kisi;
	ID * tmp=NULL,*tmpPrev=NULL,*tmp2Prev=NULL;
	char * isim, *soyisim,*charID;
	charID= (char*)malloc(5*sizeof(char));
	isim= (char*)malloc(50*sizeof(char));
	soyisim= (char*)malloc(50*sizeof(char));
	kisi = (KISI **)malloc(KISISIZE*sizeof(KISI*));
	for(i=0;i<KISISIZE;i++){
		kisi[i]=(KISI*)malloc(sizeof(KISI));
	}
	i=0;
	fscanf(fp,"%d,",&id);
	while(fscanf(fp,"%[^,],%s\n",isim,soyisim)==2){
		kisiOlustur(i+1,isim,soyisim,kisi[i]);
		tmp = kisi[i]->next;
		fscanf(fp,"%d,",&tmpID);
		tmp->currID=tmpID;
		tmp->nextID = (ID*)malloc(sizeof(ID));
		tmpPrev=tmp;
		tmp=tmp->nextID;
		while(fscanf(fp,"%d,",&tmpID)==1){
			tmp->currID=tmpID;
			tmp->nextID = (ID*)malloc(sizeof(ID));
			tmp2Prev=tmpPrev;
			tmpPrev=tmp;
			tmp=tmp->nextID;
		}
		if(tmpPrev!=NULL)
			tmpPrev->nextID = NULL;
		tmp2Prev->nextID=NULL;
		free(tmp);
		free(tmpPrev);
		tmp =kisi[i]->next;
		i++;
	}

	fclose(fp);
	return kisi;
}
int * indegreeHesapla(ID * id,int * indegree){
	while(id!=NULL){
		indegree[id->currID-1]++;
		id=id->nextID;
	}
	return indegree;
}
int * indegreeEksilt(int index, int * indegree,int M,KISI ** kisi,int * flag){
	if(flag[index]!=0)
		return indegree;
	flag[index]=1;
	ID * id =kisi[index]->next;
	while(id!=NULL){
		indegree[id->currID-1]--;
		if(indegree[id->currID-1]<M)
			indegree=indegreeEksilt(id->currID-1,indegree,M,kisi,flag);
		id=id->nextID;
	}
	return indegree;
}
int * initilizeArray(int N,int *array){
	int i;
	array=(int *)malloc(KISISIZE*sizeof(int));
	for(i=0;i<N;i++){
		array[i]=0;
	}
	return array;
}
int ** initilizeMatrix(int **array){
	int i,j;
	array=(int **)malloc(KISISIZE*sizeof(int*));
	for(i=0;i<KISISIZE;i++){
		array[i]=(int *)malloc(KISISIZE*sizeof(int));
		for(j=0;j<KISISIZE;j++){
			array[i][j]=0;
		}
	}
	return array;
}
void BFS(int *rear,int * front,int * queue,int start,int * visited,KISI ** kisi){
	enqueue(start,rear,queue);
	visited[start]=1;
	int v;
	ID * id;
	while(*rear>*front){
		v = dequeue(front,queue);
		id=kisi[v]->next;
		while(id!=NULL){
			if(visited[id->currID-1]==0){
				visited[id->currID-1]=1;
				enqueue(id->currID-1,rear,queue);
			}
							id=id->nextID;
		}
	}
}
int main(){
	KISI ** kisi;
	float m;
	int i,j,X,Y,*indegreeArray,*afterindegreeArray,*flag,**visited,*queue,front=0,rear=0,*komsuSayisi;
	int mod;
	do{
		printf("M degerini giriniz\n");
		scanf("%f",&m);
		printf("X degerini giriniz\n");
		scanf("%d",&X);
		printf("Y degerini giriniz\n");
		scanf("%d",&Y);	
		if(X<=m)
			printf("X degerini M degerinden buyuk gir\n");
	}while(X<=m);
	
	indegreeArray =initilizeArray(KISISIZE,indegreeArray);
	queue =initilizeArray(KISISIZE,indegreeArray);
	flag=initilizeArray(KISISIZE,indegreeArray);
	visited=initilizeMatrix(visited);
	afterindegreeArray=initilizeArray(KISISIZE,indegreeArray);;
	komsuSayisi=initilizeArray(KISISIZE,indegreeArray);
	kisi = readFile();
	for(i=0;i<KISISIZE;i++){
		indegreeArray=indegreeHesapla(kisi[i]->next,indegreeArray);
	}
	for(i=0;i<KISISIZE;i++)
		afterindegreeArray[i]=indegreeArray[i];
	for(i=0;i<KISISIZE;i++){
		if(afterindegreeArray[i]<m)
			afterindegreeArray=indegreeEksilt(i,afterindegreeArray,m,kisi,flag);
	}
	for(i=0;i<KISISIZE;i++){
		BFS(&rear,&front,queue,i,visited[i],kisi);
		front=0;
		rear=0;
	}
	for(i=0;i<KISISIZE;i++){
		for(j=0;j<KISISIZE;j++){
			komsuSayisi[j]+=visited[i][j];
		}
			komsuSayisi[i]--;
	}
	do{
		printf("Normal Mod Icin 1\nDetay Mod Icin 2\nCikis icin 0\n");
		scanf("%d",&mod);
		switch(mod){
		case 1:
			for(i=0;i<KISISIZE;i++){
				if(afterindegreeArray[i]>=X && komsuSayisi[i]>=Y)
					kisiYazdir(kisi[i]);
					}
			break;
		case 2:
			printf("Baslangic in-degree degerleri\n");
			for(i=0;i<KISISIZE;i++){
				printf("%d. id -> %d\n",i+1,indegreeArray[i]);
			}
			printf("Elenmeyen dugumlerin in-degree degerleri\n");
			for(i=0;i<KISISIZE;i++){
				if(afterindegreeArray[i]>=m)
					printf("%d. id -> %d\n",i+1,afterindegreeArray[i]);
			}
			printf("Influencer  Bilgileri\n");
			for(i=0;i<KISISIZE;i++){
				if(afterindegreeArray[i]>=X && komsuSayisi[i]>=Y){
					kisiYazdir(kisi[i]);
					printf("Indegree -> %d --- Komsu Sayisi--->%d\n",afterindegreeArray[i],komsuSayisi[i]);
				}
					}
			
			break;
		case 0:
			printf("Cikis yapildi\n");
			break;
		default:
			printf("Duzgun sayi gir!!!\n");	}
	}while(mod);		
	free(kisi);
	return 0;
}
