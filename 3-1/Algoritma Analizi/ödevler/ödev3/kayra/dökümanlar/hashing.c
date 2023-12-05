#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct key_or_url{
	char url[255];
	char key[255];
	struct key_or_url * next;
}keyOrUrl;
typedef struct parse{
	char first[50];
	char second[50];
	int islem;
}PARSE;
typedef struct link{
	char thisLink[50];
	struct link * next;
}LINK;
typedef struct key{
	char key[255];
	int elemanSayisi;
	struct key * next;
}KEY;
typedef struct hash_element{
	LINK * links;
	char key[50];
	int flag;
	int kacinciDeneme;
}hashElement;
unsigned long long int stringToDecimal(char * str){
	int k = 31,i;
	int tmp;
	int hashkey = 0;
	int length = strlen(str);
	for(i = 0; i<length;i++){
		tmp = str[i];
		hashkey = k*hashkey+tmp;
	}
	return hashkey;
}

int hashAra(unsigned long long int key,int i,hashElement * dizi,int size,char * str){
	int newKey = (key+i)%size;
	if(dizi[newKey].flag!=0 && strcmp(dizi[newKey].key,str)!=0)
		return hashAra(key,i+1,dizi,size,str);
	if(strcmp(dizi[newKey].key,str)==0)
		return newKey;
	return -1;
}
int findElement(hashElement * dizi,char * key,int hashUzunlugu){
	int  newKey;
	newKey=	hashAra(stringToDecimal(key),0,dizi,hashUzunlugu,key);
	return newKey;	
}
LINK *  addLink(hashElement* dizi,char * str,int index){
	LINK * thisLink = (LINK*)malloc(sizeof(LINK));
	strcpy(thisLink->thisLink,str);
	thisLink->next=NULL;
	hashElement element = dizi[index];
	if(element.links==NULL)
	{
		element.links=thisLink;
		element.links->next=NULL;
	}
	else{
	LINK * curr = element.links;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=thisLink;
	}
	return element.links;
}
int hash(unsigned long long int key,int i,hashElement * dizi,int size,char * str){
	int newKey = (key+i)%size;
	if(dizi[newKey].flag!=0 && strcmp(dizi[newKey].key,str)!=0)
		return hash(key,i+1,dizi,size,str);
	if(strcmp(dizi[newKey].key,str)==0)
		return -1;
	strcpy(dizi[newKey].key,str);
	dizi[newKey].flag=1;
	dizi[newKey].kacinciDeneme=i+1;
	return newKey;
	}
	
		
void print(keyOrUrl * head){
	keyOrUrl * curr;
	curr = head;
	while(curr->next!=NULL){
		printf("words -> %s\nlinks ->%s\n",curr->key,curr->url);
		curr=curr->next;
	}
}
keyOrUrl * readFile(){
	FILE * fp;
	fp = fopen("Sample.txt","r");
	keyOrUrl * curr,* head,*tmp;
	head=(keyOrUrl*)malloc(sizeof(keyOrUrl));
	int i;
	curr =head;
	
	while(fscanf(fp,"%[^\n]\n%[^\n]\n",curr->url,curr->key)==2){
		curr->next = (keyOrUrl*)malloc(sizeof(keyOrUrl));
		tmp=curr;
		curr=curr->next;
	}
	tmp->next=NULL;
	fclose(fp);
	return head;
}

int findPrimeNumber(int minSize){
	int i=minSize;
	while (!checkPrimeNumber(i) ) {
		i++;
  }
  	return i;
}
int checkPrimeNumber(int n) {
  int j, flag = 1;
  j=2;
  while (j <= n / 2 && flag!=0) {

    if (n % j == 0) {
      flag = 0;
    }
    j++;
  }

  return flag;
}

KEY * elemanEkle(char * str,KEY * head){
	KEY * curr = head;
	if(!strcmp(curr->key,"?")){
		strcpy(head->key,str);
		head->elemanSayisi=1;
		return head;
	}
		
	while(curr->next!= NULL && strcmp(curr->key,str))
		curr = curr->next;
	if(!strcmp(curr->key,str)){
		return head;
	}
	curr->next = (KEY*)malloc(sizeof(KEY));
	curr->next->next=NULL;
	strcpy(curr->next->key,str);
	head->elemanSayisi++;
	return head;
}
KEY* delimeter(keyOrUrl * head,KEY * keys){
	
	char * str;
	char cmp[50];
	while(head!=NULL){
		strcpy(str,head->key);
		int i=0,j,length=strlen(str);
		while(i<length){
			j=0;
			while(str[i]!='\0' && str[i]!=' ' && str[i]!='\r'){
				cmp[j]=str[i];
				j++;
				i++;
			}
			cmp[j]='\0';
			i++;	
			keys=elemanEkle(cmp,keys);
			}
			head=head->next;
		}
		return keys;
	}
hashElement* delimeterAndAddArray(keyOrUrl * head,hashElement * dizi,int hashUzunlugu){
	
	char str[50];
	char cmp[50];
	while(head!=NULL){
		strcpy(str,head->key);
		int i=0,j,length=strlen(str);
		while(i<length){
			j=0;
			while(str[i]!='\0' && str[i]!=' ' && str[i]!='\r'){
				cmp[j]=str[i];
				j++;
				i++;
			}
			cmp[j]='\0';
			i++;
			int diziIndex = findElement(dizi,cmp,hashUzunlugu);
			dizi[diziIndex].links = addLink(dizi,head->url,diziIndex);
			
		
		}
			head=head->next;
		}
		return dizi;
	}
void printKeys(KEY * keys){
	while(keys!=NULL){
		printf("%s\n",keys->key);
		keys=keys->next;
		
	}
}
void printHeads(keyOrUrl * head){
	while(head!=NULL){
		printf("%s\n",head->url);
		head=head->next;
		
	}
}

void printHash(hashElement* hashDizi,int size){
	int i=0;
	for(i=0;i<size;i++){
		if(hashDizi[i].flag==1){
			printf("INDEX NUMARASI -> %d\tKEY DEGERI -> %s\tDENEME SAYISI -> %d\n",i,hashDizi[i].key,hashDizi[i].kacinciDeneme);
			LINK * curr= hashDizi[i].links;
			while(curr!=NULL){
				printf("%s\n",curr->thisLink);
				curr=curr->next;
			}
		}
			
	}
}
void diziyiOlustur(hashElement * hashDizi,int hashUzunlugu,KEY * curr){
	while(curr!=NULL){	                                                            
		hash(stringToDecimal(curr->key),0,hashDizi,hashUzunlugu,curr->key);	
		curr=curr->next;
		}                                                   
}
void initilizeHashDizi(hashElement* hashDizi,int hashUzunlugu){
	int i;
	for(i=0;i<hashUzunlugu;i++){
		hashDizi[i].flag=0;
		hashDizi[i].links=NULL;
		strcpy(hashDizi[i].key,"?");
	}
}
keyOrUrl * copyHead(keyOrUrl * head){
	keyOrUrl * currHead =(keyOrUrl *)malloc(sizeof(keyOrUrl));
	keyOrUrl * realHead = currHead,*beforeHead;
	
	while(head!=NULL){
		strcpy(currHead->url,head->url);
		strcpy(currHead->key,head->key);
		currHead->next = (keyOrUrl*)malloc(sizeof(keyOrUrl));
		beforeHead = currHead;
		currHead = currHead->next;
		head = head->next;
	}
	beforeHead->next=NULL;
	return realHead;
}
int menu(){
	int n;
	printf("===========================\nNormal mod icin 1\nDetay mod icin2\nCikis icin 3'e basiniz\n================================'");
	do{
	scanf("%d",&n);
	if(n>3 || n<1)
		printf("Duzgun sayi gir\n");	
	}while(n>3 || n<1);
	return n;
}
PARSE parseText(char * str){
	int i=0,j,length=strlen(str);char cmp[50];
	PARSE parsed;
	while(i<length){
			j=0;
			while(str[i]!='\0' && str[i]!=' ' && str[i]!='\r'){
				cmp[j]=str[i];
				j++;
				i++;
			}
			cmp[j]='\0';
		strcpy(parsed.first,cmp);
		if(i==length){
			parsed.islem=-1;
		}
		else{
			i++;
			j=0;
			while(str[i]!='\0' && str[i]!=' ' && str[i]!='\r'){
				cmp[j]=str[i];
				j++;
				i++;
			}
			cmp[j]='\0';
			i++;
			if(strlen(cmp)==4){
				parsed.islem=1;	
			}
			else{
				parsed.islem=2;
			}
			j=0;
			while(str[i]!='\0' && str[i]!=' ' && str[i]!='\r'){
				cmp[j]=str[i];
				j++;
				i++;
			}
			cmp[j]='\0';
			strcpy(parsed.second,cmp);
		}
		}
		return parsed;
}
int varsaMi(char * str,LINK * link){
	while(link!=NULL && strcmp(link->thisLink,str)){
		link = link->next;
	}
	if(link==NULL){
		return 0;
	}
	else{
		return 1;
	}
	
}
int main(int argC, char *argV[]){

	FILE * fp;
	KEY * keys,*curr;
	keys = (KEY*)malloc(sizeof(KEY));
	keys->next=NULL;
	keys->elemanSayisi=0;
	int choice;
	strcpy(keys->key,"?");
	hashElement *hashDizi;
	int i,loadFactor;
	do{
		printf("Load Factor'u yuzde seklinde giriniz\n");
		scanf("%d",&loadFactor);
		if(loadFactor<=0)
			printf("Duzgun gir\n");
	}while(loadFactor<=0);
	fp = fopen("Sample.txt","r");
	if(fp!=NULL){
	keyOrUrl * head;
	head = readFile();
	keyOrUrl * currHead=copyHead(head);
	keys = delimeter(currHead,keys);
	int hashUzunlugu = findPrimeNumber(((float)100/loadFactor)*keys->elemanSayisi);
	hashDizi = (hashElement *)malloc(hashUzunlugu*sizeof(hashElement));
	initilizeHashDizi(hashDizi,hashUzunlugu);
	diziyiOlustur(hashDizi,hashUzunlugu,keys);
	hashDizi = delimeterAndAddArray(head,hashDizi,hashUzunlugu);
	//printHash(hashDizi,hashUzunlugu);    
	fclose(fp);
	do{
	choice = menu();
	switch(choice){
		case 1:
			printf("Aradiginiz keyleri giriniz\n");
			char keywords[15];
			int flag;
			do{
			printf("1 sorgu mu yapacaksiniz (1) yoksa 2 mi (2) ?\n");
			scanf("%d",&flag);	
			if(flag!=1 && flag!=2)
				printf("Duzgun gir\n");
			}while(flag!=1 && flag!=2);
			printf("Sorguyu giriniz:  ");
			if(flag == 1){
				scanf("%s",keywords);
			}
			else{
				char c[5],kas[15];
				scanf("%s %s %s",keywords,c,kas);
				strcat(keywords," ");
				strcat(keywords,c);
				strcat(keywords," ");
				strcat(keywords,kas);	
			}
			PARSE parsed = parseText(keywords);
			if(parsed.islem==-1){
				int newKey=findElement(hashDizi,parsed.first,hashUzunlugu);
				LINK * currLink = hashDizi[newKey].links;
				while(currLink!=NULL)
					{
						printf("%s\n",currLink->thisLink);
						currLink=currLink->next;
					}	
			}
			else if(parsed.islem==1){
				int newKey1=findElement(hashDizi,parsed.first,hashUzunlugu);
				LINK * currLink1 = hashDizi[newKey1].links;
				int newKey2=findElement(hashDizi,parsed.second,hashUzunlugu);
				LINK * currLink2 = hashDizi[newKey2].links;
				while(currLink1!=NULL)
					{
						printf("%s\n",currLink1->thisLink);
						currLink1=currLink1->next;
					}
				while(currLink2!=NULL){
					if(!varsaMi(currLink2->thisLink,hashDizi[newKey1].links)){
						printf("%s\n",currLink2->thisLink);
					}
					currLink2=currLink2->next;
				}
			}
			else{
				int newKey1=findElement(hashDizi,parsed.first,hashUzunlugu);
				LINK * currLink1 = hashDizi[newKey1].links;
				int newKey2=findElement(hashDizi,parsed.second,hashUzunlugu);
				LINK * currLink2 = hashDizi[newKey2].links;
				while(currLink2!=NULL){
					if(varsaMi(currLink2->thisLink,hashDizi[newKey1].links)){
						printf("%s\n",currLink2->thisLink);
					}
					currLink2=currLink2->next;
				}
			}
			break;
		case 2:
			printf("Hash tablosunun uzunlugu->%d\n",hashUzunlugu);
			printHash(hashDizi,hashUzunlugu);
			break;	
	}
			
		
	}while(choice!=3);}
	else{
		printf("Dosya Bulunamadi");
	}
	
	
	return 0;
}                                  