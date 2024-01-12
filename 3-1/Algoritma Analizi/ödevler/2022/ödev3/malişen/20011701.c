#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct list {
    struct node *head;
    int turn;
    struct list *next;
} list;

typedef struct node{
    char *key;
    char *value;
}node;

typedef struct uniqueNode{
     char *key;
     int count;
     struct uniqueNode *next;
 }uniqueNode;

typedef struct hash{
    int size;
    list **table;
}hash;

hash *create_hash(int size){
	int i;
    hash *new_hash = (hash*)malloc(sizeof(hash));
    new_hash->size = size;
    new_hash->table = (list**)malloc(sizeof(list*)*size);
    for(i=0;i<size;i++){
	new_hash->table[i] = NULL;
    }
    return new_hash;
}

unsigned int hash_function(char *key, int size){
    int i; 
	unsigned int sum=0;
    for(i=0;i<strlen(key);i++){
	sum = sum * 31 + key[i];
    }
    return sum%size;
}

void insert(hash *h, char *key, char *value){
    unsigned int index = hash_function(key, h->size);
    node *n = (node *)malloc(sizeof(node));
    n->key= (char *)malloc(sizeof(char)*strlen(key));
    strcpy(n->key, key);
    n->value = (char *)malloc(sizeof(char)*strlen(value));
    strcpy(n->value, value);
    list *l = (list *)malloc(sizeof(list));
    if(h->table[index] == NULL){
	l->head = n;
	l->turn = 1;
	l->next = NULL;
	h->table[index] = l;
 }	
    else{
	l = h->table[index];
	while(l->next != NULL){
	    l = l->next;
	}
	list *new_list = (list *)malloc(sizeof(list));
	new_list->head = n;
	new_list->turn = l->turn + 1;
	new_list->next = NULL;
	l->next = new_list;
    }
}

    


void search(hash *h, char *key){
    unsigned int index = hash_function(key, h->size);
    list *tmp = h->table[index];
    list *l = h->table[index];
    printf("Arama Sonucu =");
    while(l != NULL){
	if(strcmp(l->head->key, key) == 0){
	    printf("%s ", l->head->value);
	}
	l = l->next;
    }if(tmp == NULL){
	printf("Sonuc YOK");
    }
    printf("\n");
}

void print_hash(hash *h){
    int i;
    for(i=0;i<h->size;i++){
	list *l = h->table[i];
	while(l != NULL){
	    printf("%s ==> %s ==> %d ==> kacinci deneme %d \n", l->head->key, l->head->value, i, l->turn);
	    l = l->next;
	}
    }
}

void readAndCreateTable(hash *h, char x[])
{
	FILE* fp = fopen(x, "a+");
	char valuesArray[MAX];
	char webBuffer[MAX];
	char keyBuffer[MAX];
	char *web;
	char *word;
	char delimit[]= " \t\r\n\v\f";
	if (!fp) {
		printf("Unable to open/detect file");
		return;
	}
	fprintf(fp, "\n");
	fseek(fp, 0, 0);
	int check = 0;
	char buf[MAX];

	while (fgets(buf, sizeof(buf), fp)) {
		if (!(check % 2)) {
			strcpy(webBuffer, buf);
			//printf("%s", webBuffer);
			web = strtok(webBuffer, delimit);
			//printf("%s", web);
			//web = strtok(NULL, delimit);
		}else{
			strcpy(keyBuffer, buf);
			//printf("%s", keyBuffer);
			word = strtok(keyBuffer, delimit);
			//printf("%s\n", keyBuffer);
			while(word != NULL){
				//printf("%s\n", keyBuffer);
				//printf("%s\t", word);
				//add array for unique keys
				insert(h, word, web);
				word = strtok(NULL, delimit);
			}	
			//printf("\n");
		}
		check++;
	}

	// Close the file
	fclose(fp);

	return;
}
int countKeys(FILE *fp){
    char *line = (char*)malloc(sizeof(char)*MAX);
    char *word;
    int check = 0;
    uniqueNode *head = NULL;
    uniqueNode *temp;
    int keyCount = 0;
    int uniqueKeyCount = 0;
    char delimit[]=" \t\r\n\v\f";
    fseek(fp, 0, 0);
    while(fgets(line, MAX, fp)){
	if(check%2!=0){
	    word = strtok(line, delimit);
	    while(word != NULL){
		keyCount++;
		temp = head;
		while(temp != NULL){
		    if(strcmp(temp->key, word) == 0){
			temp->count++;
			break;
		    }
		    temp = temp->next;
		}
		if(temp == NULL){
		    uniqueKeyCount++;
		    uniqueNode *newNode = (uniqueNode*)malloc(sizeof(uniqueNode));
		    newNode->key = (char*)malloc(sizeof(char)*strlen(word)+2);
		    strcpy(newNode->key,word);
		    newNode->count = 1;
		    newNode->next = head;
		    head = newNode;
		}
		word = strtok(NULL, delimit);
	    }
	}
	check++;
    }
    temp = head; 
    return uniqueKeyCount;
}

 int findPrime(int n){
    int choice, i, j, flag;
    double lf;

    printf("select load factor\n ");
    printf("1. 0.1\t 2. 0.5\t 3. 0.9\n");
    scanf("%d", &choice);
    switch (choice) 
    {
    case 1:
    lf = 0.1;
	break;
    case 2:
	lf = 0.5;
	break;
    case 3:
	lf = 0.9;
	break;
    }

    n=n/lf;
    for(i = n+1; i < 2*n; i++){
	flag = 0;
	for(j = 2; j < i; j++){
	    if(i % j == 0){
		flag = 1;
	    }
	}
	if(flag == 0){
	    return i;
	}
    }
    return 0;
}


int main(){
    int i;
    FILE *fp;
    int flag = 0;
    char *key, *value;
    char line[MAX];
    int keyCount = 0;
    int hashSize = 0;
    int choice = 1;
    char srch[50];
    fp = fopen("Sample.txt", "r");
    keyCount = countKeys(fp);
    //printf("\n%d",keyCount);
    fclose(fp);
    hashSize = findPrime(keyCount);
    //printf("\n%d\n",hashSize);
    hash *h = create_hash(hashSize);
    char x[] = "Sample.txt";
    readAndCreateTable(h, x);
	printf("1. Normal\n2. Detay\n0. Exit\n");
	scanf("%d", &choice);
	switch (choice) 
	{
	case 1:
	printf("Aramadan cikmak icin 0 a basiniz \n");
	do{	
	    
	    if(flag == 0){
	    	printf("Aranacak Degerleri Giriniz: \n");
	    	scanf("%s", srch);
	    	strcpy(srch,strtok(srch, " "));
	    	search(h, srch);
	    	flag = 1;
		}else{
			scanf("%s", srch);
			flag = 0;
		}
	}while(strcmp(srch, "0") != 0);
	    
		flag = 0;
	    break;
	case 2:
	    printf("Hash Table uzunlugu: %d\n", h->size);
	    printf("Hash Tablosu \n");
	    print_hash(h);
	    break;
	case 0:
	    printf("Exiting...\n");
	    return 0;	
	    break;
	}


    //printf("Enter a key to search: ");
   //print(h);
   //search(h, "Entertainment");
    //printf("search AI %s", search(h, "AI"));
    return 0;
    }
