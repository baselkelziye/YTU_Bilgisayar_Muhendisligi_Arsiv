#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* arr,int size);
void printKeysAndLocks(int* key,int* lock,int size);
void quickSort(int* sortLock,int* sortKey,int* key,int* lock,int size,int totalSize);

int main(){
	int i,j;
	int size;
	
	FILE* file= fopen("veri.txt","r");
	if(!file){
		printf("dosyaya erisilemedi");
		return 1;
	}
	fscanf(file,"%d",&size);
	if(size<1){ return 1;}
	
	printf("---Baslangic Durumu---\n");
	printf("size=%d",size);
	
	int* Key=(int*)malloc(size*sizeof(int)); 
	int* Lock=(int*)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++){
		fscanf(file,"%d",&Key[i]);
	}
	for(i=0;i<size;i++){
		fscanf(file,"%d",&Lock[i]);
	}fclose(file); 
	
	printKeysAndLocks(Key,Lock,size);
	
	srand(time(NULL));
	
	quickSort(Lock,Key,Key,Lock,size,size);
	
	printf("\n---siralama---");
	printKeysAndLocks(Key,Lock,size);
	
	free(Lock);
	free(Key);
	
	return 0;
}
void quickSort(int* sortLock,int* sortKey,int* key,int* lock,int size,int totalSize){
	if(size<=1){return;	}
	
	int randomIndex=rand()% size;
	int pivot,tmp;
	int i=1,j=size-1,k,x=1,y=size-1;
	
	pivot= sortLock[randomIndex];
	printf("\n--------------\nSecilen = %d\n",pivot);
		
	printKeysAndLocks(sortKey,sortLock,size);
	sortLock[randomIndex]=sortLock[0];
	sortLock[0]=pivot;
	
	k=0;
	while(k<totalSize&&sortKey[k]!=pivot){
		k++;
	}
	if(sortKey[k]==pivot){
		sortKey[k]=sortKey[0];
		sortKey[0]=pivot;
	}
	
	printf("\n-pivot basa aliniyor-");
	printKeysAndLocks(sortKey,sortLock,size);
	
	while(i<=j){ 
		while(i<=size-1 && sortLock[i]<pivot){
			i++;
		}
		while(j>=0 && pivot<sortLock[j]){
			j--;
		}
		
		if(i<j){
			tmp=sortLock[i];
			sortLock[i]=sortLock[j];
			sortLock[j]=tmp;
		}	
	}
	sortLock[0]=sortLock[j];
	sortLock[j]=pivot;
	
	
	while(x<=y){
		while(x<=size-1&& sortKey[x]<pivot){
			x++;
		}
		while(y>=0&& pivot<sortKey[y]){
			y--;
		}
		if(x<y){
			tmp=sortKey[x];
			sortKey[x]=sortKey[y];
			sortKey[y]=tmp;
		}
	}
	sortKey[0]=sortKey[y];
	sortKey[y]=pivot;
	
	printf("\n%d ile duzenlenme sonucu",pivot);
	printKeysAndLocks(sortKey,sortLock,size);
	
	printf("\nTum dizi");
	printKeysAndLocks(key,lock,totalSize);
	
	//printf("\nsizeSol=%d",j);
	quickSort(sortLock,sortKey,key,lock,j,totalSize);
	
	//printf("\nsizeSag=%d",size-j-1);
	quickSort(sortLock+j+1,sortKey+y+1,key,lock,size-j-1,totalSize);
}

void printKeysAndLocks(int* key,int* lock,int size){
	printf("\nKeys:");
	printArray(key,size);
	printf("\nLocks:");
	printArray(lock,size);
	printf("\n");
}

void printArray(int* arr,int size){
	int i;
	printf("\n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
