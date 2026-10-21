#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct Node{
	char ssn[20];
	char name[20];
	char surname[20];
	int birthDate;
	char address[20]; 
	struct Node *next;
}Node;

typedef struct HashTable{
	char ssn[20];
	int no;
	int flag; //1=full,0=empty,-1=deleted
}HashTable;

typedef struct Cache{
	struct Node *head;
	int numberOfElements;
}Cache;

int Horner(char *);
Node *createNode(char *, char *, char *, int , char*);
int calculateHashIndex(int , int , char *, HashTable *);
int isNotInHashTableAtAll(HashTable *, char *, int );
int isInHashTableButDeleted(HashTable *, char *, int );
Cache *addToCache(Cache *, Node *);
HashTable *addToHashTable(HashTable *, Node *, int );
HashTable *changeHashTableInfo(HashTable *, Cache *, int );
char *findTheLastElementInCache(Cache *);
Cache *deleteFromCache(Cache *, char *);
HashTable *deleteFromHashTable(HashTable *, char *, int );
HashTable *updateHashTable(HashTable *, Cache *, int );
int findInCacheAndPrint(Cache *, Node *, HashTable *, int );
Cache *replaceInCache(Cache *, int );
HashTable *updateHashTable2(HashTable *, Cache *, int );
//19011065
int main(){
	
	FILE *fp;
	char ssn[20];
	char name[20];
	char surname[30];
	int birthDate;
	char address[20];
	int tableSize;
	int cacheSize;
	int k; //for dongusu icin
	HashTable *hashTable;
	Cache *cache;
	Node *newNode=NULL;
	
	fp=fopen("test.txt","r");
	if(fp==NULL){
		printf("Error.\n");
		return;
	}
	
	printf("Enter the cache size.\n");
	scanf("%d",&cacheSize);
	printf("Enter the hash table size.\n");
	scanf("%d",&tableSize);
	
	hashTable=(HashTable*)malloc(tableSize*sizeof(HashTable));
	if(hashTable==NULL){
		printf("Allocation Error.\n");
		return;
	}
	for(k=0;k<tableSize;k++){
		hashTable[k].flag=0; 				//baslangicta hashTable'daki butun yerler "empty" olarak isaretlendi cunku hashTable bos
	}
	for(k=0;k<tableSize;k++){
		strcpy(hashTable[k].ssn,"00000");	///baslangicta hashTable'daki butun kimlik numaralari "00000" olarak isaretlendi cunku hashTable bos
	}
	for(k=0;k<tableSize;k++){
		hashTable[k].no=-1;					//baslangicta kisilerin cache'teki sira numaralari -1'e esitlendi, cunku cache'te kimse yok
	}
	
	cache=(Cache*)malloc(sizeof(Cache));
	if(cache==NULL){
		printf("Allocation Error.\n");
		return;
	}
	cache->head=NULL;						//cache'in baslangicta head'ini NULL yapiyoruz
	cache->numberOfElements=0;				//cache'teki eleman sayisi basta 0'landi
	
	while(!feof(fp)){
		fscanf(fp,"%s %s %s %d %s\n",ssn,name,surname,&birthDate,address); //dosyadan her satir okunuyor ve satir satir isleme aliniyor
		newNode=createNode(ssn,name,surname,birthDate,address);	//dosyadan okunan kisi icin node yaratiliyor
		if(isNotInHashTableAtAll(hashTable,ssn,tableSize)){ //ilgili kisi hashTable'a hic eklenmemis
			//printf("%s ssn'li kisi direkt hash table'da yok.\n",ssn);
			
			if(cache->numberOfElements<cacheSize){	//cache'te yer varsa
				cache=addToCache(cache,newNode);	//linkli listenin basina kisi eklenir
				hashTable=addToHashTable(hashTable,newNode,tableSize);	//hashTable'a eklenir
				if(cache->numberOfElements>1){
					changeHashTableInfo(hashTable,cache,tableSize); //eger cache'te 1'den fazla kisi varsa hashTable'daki sira kaymis demektir, yeni sira yazilir
				}
			}else{
				char ssnOfDeleted[20]; //cache'te yer yoksa
				strcpy(ssnOfDeleted,findTheLastElementInCache(cache)); 	//cache'teki en son elemanin ssn'i alinir
				cache=deleteFromCache(cache,ssnOfDeleted);	//cache'teki son eleman ssn uzerinden bulunur ve cache'ten silinir 
				hashTable=deleteFromHashTable(hashTable,ssnOfDeleted,tableSize); //cache'teki son elemanin flagi ve no'su hashTable'da -1 yapilir
				cache=addToCache(cache,newNode); //newNode cache'in basina eklenir
				hashTable=addToHashTable(hashTable,newNode,tableSize);	//newNode hashTable'a eklenir
				hashTable=updateHashTable(hashTable,cache,tableSize); //cache[1].elemandan itibaren update yapar
			}
		}else if(isInHashTableButDeleted(hashTable,ssn,tableSize)){ //hashtableda var ama cache'ten silinmis
			//printf("%s ssn'li kisi hash table'da var ama silinmis.\n",ssn);
			
			char ssnOfDeleted[20];
			strcpy(ssnOfDeleted,findTheLastElementInCache(cache)); //cache'teki en son elemanin ssn'i alinir
			cache=deleteFromCache(cache,ssnOfDeleted);	//cache'teki son eleman ssn uzerinden bulunur ve cache'ten silinir 
			hashTable=deleteFromHashTable(hashTable,ssnOfDeleted,tableSize); //cache'teki son elemanin flagi ve no'su hashTable'da -1 yapilir
			cache=addToCache(cache,newNode);	//newNode cache'in basina eklenir
			hashTable=updateHashTable2(hashTable,cache,tableSize); //cache'teki elemanlarin siralarini hashTable'da gunceller
				
		}else{ 														//hash tableda ve cache'te var
			//printf("%s ssn'li kisi hash table'da ve cache'te var.\n",ssn);
			
			int placeInCache;
			placeInCache=findInCacheAndPrint(cache,newNode,hashTable,tableSize); //kisi hashTable'da ve cache'te varsa kisiyi cache'ten bulup bilgilerini yazdirir
			cache=replaceInCache(cache,placeInCache); //ilgili kisiyi cache'te en basa alir
			hashTable=updateHashTable2(hashTable,cache,tableSize); //cachte[0]'dan itibaren update yapar
			
		}
	}
	
	/*printf("\n SSN    cacheNo  flag\n");
	for(k=0;k<tableSize;k++){
		printf("%s %5d %7d\n",hashTable[k].ssn,hashTable[k].no,hashTable[k].flag);
	}
	Node *tmp=NULL;
	tmp=cache->head;	
	
	printf("\nCache:\n");
	while(tmp!=NULL){
		printf("%s %s %s %d %s\n",tmp->ssn,tmp->name,tmp->surname,tmp->birthDate,tmp->address);
		tmp=tmp->next;
	}*/
		
	
	return 0;
}

int Horner(char *ssn){
	
	int lengthOfSSN=strlen(ssn);
	int R=31;
	int sum=0;
	int i;
	
	for(i=0;i<lengthOfSSN;i++){
		sum+=pow(R,i)*ssn[lengthOfSSN-1-i];
	}
	
	return sum;
};

Node *createNode(char *ssn, char *name, char *surname, int birthDate, char*address){
	
	Node *newNode=NULL;
	
	newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("Allocation Error.\n");
		return;
	}
	
	strcpy(newNode->ssn,ssn);
	strcpy(newNode->name,name);
	strcpy(newNode->surname,surname);
	newNode->birthDate=birthDate;
	strcpy(newNode->address,address);
	newNode->next=NULL;
	
	return newNode;

}

int calculateHashIndex(int key, int m, char *ssn, HashTable *hashTable){
	
	int m2=m-1;
	int h1key=key%m;
	int h2key=1+(key%m2);
	int hashIndex=h1key%m; //i=0 gelecek.
	int i=1;
	int counter=0;
	
	while(hashTable[hashIndex].flag==1){
		hashIndex=(h1key+(i*h2key))%m;
		i++; //i icin sinir lazimsa koy
	}
	//printf("%s ssn'li kisinin hashtable index'i = %d\n",ssn,hashIndex);
	
	return hashIndex;
}

int findHashIndex(HashTable *hashTable, char *ssn, int tableSize){ //ssn'i verilenin hashtablosunda nerde oldugunu bulur.
	
	int key;
	int i=0;
	key=Horner(ssn);
	int m2=tableSize-1;
	int h1key=key%tableSize;
	int h2key=1+(key%m2);
	int hashIndex=h1key%tableSize;
	
	while( strcmp(hashTable[hashIndex].ssn,ssn)!=0 && i<tableSize){
		hashIndex=(h1key+(i*h2key))%tableSize;
		i++;
	}
	
	if(i==tableSize){
		hashIndex=-1;
	}
	
	return hashIndex;

}

int isNotInHashTableAtAll(HashTable *hashTable, char *ssn, int tableSize){ 
	
	int i=0,control,control2=1;
	
	while(i<tableSize && control2==1){
		if( strcmp(hashTable[i].ssn,ssn)!=0 ){
			i++;
		}else{
			control2=0;
		}
	}
	
	if(control2==1){
		control=1; //hashtableda o ssn hic yok
	}else{
		control=0; //hashtableda o ssn var ama durumunun bilmiyoruz silinmis mi silinmemis mi
	}
	
	return control;
	
}

int isInHashTableButDeleted(HashTable *hashTable, char *ssn, int tableSize){
	
	int i=0,control,control2=1;
	
	while(i<tableSize && control2==1){
		if( strcmp(hashTable[i].ssn,ssn)==0 && hashTable[i].flag==-1 ){
			control2=0;	
		}else{
			i++;
		}
	}
	
	if(i!=tableSize){
		control=1;	//hashtable'da var ama cache'ten silinmis
	}else{
		control=0; //hashtable'da var ve cache'te de var 
	}
	
	return control;
	
}

Cache *addToCache(Cache *cache, Node *newNode){
	
	Node *temp=NULL;
	if(cache->head==NULL){
		cache->head=newNode;
		cache->head->next=NULL;
		cache->numberOfElements++;
	}else{
		newNode->next=cache->head;
		cache->head=newNode;
		cache->numberOfElements++;
	}
	temp=cache->head;
	
	/*printf("\ncache:\n");
	while(temp!=NULL){
		printf("%s %s %s %d %s\n",temp->ssn,temp->name,temp->surname,temp->birthDate,temp->address);
		temp=temp->next;
	}
	printf("\n");*/
	return cache;
		
}

HashTable *addToHashTable(HashTable *hashTable, Node *newNode, int tableSize){
	
	char ssn[20];
	int key;
	int hashIndex;
	int j;
	
	strcpy(ssn,newNode->ssn);
	key=Horner(ssn);
	hashIndex=calculateHashIndex(key,tableSize,ssn,hashTable);
	
	strcpy(hashTable[hashIndex].ssn,newNode->ssn);
	hashTable[hashIndex].no=0;
	hashTable[hashIndex].flag=1;
	
	/*if(strcmp(newNode->ssn,"12345")==0){
		printf(" SSN    cacheNo  flag\n");
		for(j=0;j<tableSize;j++){
			printf("%s %5d %7d\n",hashTable[j].ssn,hashTable[j].no,hashTable[j].flag);
		}
	}*/
	
	
	return hashTable;
	
}

HashTable *changeHashTableInfo(HashTable *hashTable, Cache *cache, int tableSize){
	
	Node *temp=NULL;
	temp=cache->head->next;
	char ssn[20];
	int key;
	int hashIndex;
	int j;
	
	while(temp!=NULL){
		strcpy(ssn,temp->ssn);
		hashIndex=findHashIndex(hashTable,ssn,tableSize);
		hashTable[hashIndex].no++;
		temp=temp->next;
	}
	
	/*printf(" SSN    cacheNo  flag\n");
	for(j=0;j<tableSize;j++){
		printf("%s %5d %7d\n",hashTable[j].ssn,hashTable[j].no,hashTable[j].flag);
	}*/
	
	return hashTable;
	
}

char *findTheLastElementInCache(Cache *cache){
	
	Node *temp=NULL;
	temp=cache->head;
	Node *toBeDeleted=NULL;
	
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	toBeDeleted=temp->next;
	
	return toBeDeleted->ssn;
	
}

Cache *deleteFromCache(Cache *cache, char *ssn){
	
	Node *temp=NULL;
	temp=cache->head;
	
	Node *toBeDeleted=NULL;
	
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	
	toBeDeleted=temp->next;
	strcpy(ssn,toBeDeleted->ssn);
	temp->next=NULL;
	
	return cache;
	
}

HashTable *deleteFromHashTable(HashTable *hashTable, char *ssn, int tableSize){
	
	int hashIndex;
	int j;
	hashIndex=findHashIndex(hashTable,ssn,tableSize);
	hashTable[hashIndex].flag=-1;
	hashTable[hashIndex].no=-1;
	
	/*printf(" SSN    cacheNo  flag\n");
	for(j=0;j<tableSize;j++){
		printf("%s %5d %7d\n",hashTable[j].ssn,hashTable[j].no,hashTable[j].flag);
	}*/
	
	return hashTable;
	
}

HashTable *updateHashTable(HashTable *hashTable, Cache *cache, int tableSize){
	
	char ssn[20];
	int j;
	int hashIndex;
	Node *temp=NULL;
	temp=cache->head->next;
	
	while(temp!=NULL){
		strcpy(ssn,temp->ssn);
		hashIndex=findHashIndex(hashTable,ssn,tableSize);
		hashTable[hashIndex].no++;
		temp=temp->next;
	}
	
	/*printf(" SSN    cacheNo  flag\n");
	for(j=0;j<tableSize;j++){
		printf("%s %5d %7d\n",hashTable[j].ssn,hashTable[j].no,hashTable[j].flag);
	}*/
	
	return hashTable;

}

int findInCacheAndPrint(Cache *cache, Node *newNode, HashTable *hashTable, int tableSize){
	
	char ssn[20];
	strcpy(ssn,newNode->ssn);
	Node *temp=NULL;
	temp=cache->head;
	int no;
	int counter=0;
	int hashIndex;
	
	hashIndex=findHashIndex(hashTable,ssn,tableSize);
	
	no=hashTable[hashIndex].no;
	
	while(counter!=no){
		temp=temp->next;
		counter++;
	}
	
	printf("\n%s %s %s %d %s\n",temp->ssn,temp->name,temp->surname,temp->birthDate,temp->address);
	
	return no;
	
}

Cache *replaceInCache(Cache *cache, int placeInCache){
	
	Node *temp=NULL;
	Node *temp2=NULL;
	Node *nodeToHead=NULL;
	temp=cache->head;
	int counter=0;
	temp2=cache->head;
	
	if(placeInCache!=0){
		while(counter!=placeInCache-1){
			temp=temp->next;
			counter++;
		}
		nodeToHead=temp->next;
		if(temp->next->next!=NULL){
			temp->next=temp->next->next;
			nodeToHead->next=temp2;
			cache->head=nodeToHead;
		}else{
			nodeToHead->next=temp2;
			cache->head=temp->next;
			temp->next=NULL;
		}
		
	}else{
		
	}
	Node *temp3=NULL;
	temp3=cache->head;
	
	/*printf("\ncache:\n");
	while(temp3!=NULL){
		printf("%s %s %s %d %s\n",temp3->ssn,temp3->name,temp3->surname,temp3->birthDate,temp3->address);
		temp3=temp3->next;
	}*/
	
	return cache;
	
} 

HashTable *updateHashTable2(HashTable *hashTable, Cache *cache, int tableSize){
	
	Node *temp=NULL;
	temp=cache->head;
	int j=0;
	char ssn[20];
	int hashIndex;
	
	while(temp!=NULL){
		strcpy(ssn,temp->ssn);
		hashIndex=findHashIndex(hashTable,ssn,tableSize);
		hashTable[hashIndex].no=j;
		j++;
		temp=temp->next;
	}
	
	/*printf(" SSN    cacheNo  flag\n");
	for(j=0;j<tableSize;j++){
		printf("%s %5d %7d\n",hashTable[j].ssn,hashTable[j].no,hashTable[j].flag);
	}*/
	
	return hashTable;
}

