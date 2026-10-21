#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME 31

/*Struct Defination Section*/
typedef struct Node {
	int val;
	struct Node *next;
}Node;
typedef struct Queue{
	int rear;
    int front;
	int *parents; //Stores parents
    int *queue;	//Stores the queue
}Queue;
typedef struct Hash_T{
	Node *node;
	char *str;
}Hash_T;

/*Prototype Section*/

/*Queue Section*/
void initQueue(Queue *q, unsigned long long int size){
	q->rear = 0;
    q->front = 0;
	q->queue = (int*)calloc(size, sizeof(int));
	q->parents = (int*)calloc(size, sizeof(int));
}

void enqueue(Queue *q, int data){
    q->queue[q->rear++] = data;
}

int dequeue(Queue *q){
    return q->queue[q->front++];
}
/*Hash Section*/

void initHash(Hash_T* ht, unsigned long long int size){
	int i = 0;	
	while(i < size){
		ht[i].str = (char*)calloc(256,sizeof(char));
		ht[i].str[0] = '\0';
		i++;
	}
}

//Double hashing is used
int hash(int i,unsigned long long int key,  unsigned long long int size){
	int hash1 = key % size;
	int hash2 = (key % (size - 1)) + 1;
	return (hash1 + (hash2*i) ) % size;
}

unsigned long long int generateKey(char *data){
	int i = 0;
	unsigned long long int key = 0;
	int length = strlen(data);
	
	while (i < length) {
		key += data[i] * pow(PRIME, length - i - 1);
		i++;
	}
	return key;
}
//Inserting the Hash table
int insertHT(Hash_T *ht, char *token, int *cnt, unsigned long long int key, unsigned long long int N){
	int val, i = 0;
	int sign = 0;
	val = hash(i, key, N);
	
	while( (!sign) && (ht[val].str[0] != '\0')  && (i < N) ) {
		if (strcmp(token, ht[val].str) == 0)
			sign = 1;
		else {
			i++;
			val = hash(i, key, N);
		}
	}
	if (sign) {
		return val;
	}
	else if (ht[val].str[0] == '\0') {
		*cnt = *cnt + 1;
		strcpy(ht[val].str, token);
		ht[val].node = NULL;
		return val;
	} 
	else if (ht[val].str[0] != '\0') {
		printf("Cannot acces to the table \n");
		return -1;
	}
	return -1;
}
//Inserting node to Hash table
void insertNode (Hash_T* ht, int val1, int val2){
	Node* tmp = (Node*)calloc(1,sizeof(Node));
	tmp->next = NULL;
	tmp->val = val2;
	Node* curr;
	if(ht[val1].node){		//Eger null degil ise
		curr = ht[val1].node;
		//Traversal
		while(curr->next)
			curr = curr->next;
		curr->next = tmp;
	}
	else
		ht[val1].node = tmp;
}
//Tokenizer tool
void tokenHelper(Hash_T* ht, char* line, int *m_cnt, int *a_cnt,unsigned long long int N){
	int i,j, lenTok, actor, movie;
	unsigned long long int key = 0;
	char ch1[256], ch2[256];
	char *token;
	//Tokenizing
	for (token = strtok(line, "/"); token!= NULL; token=strtok(NULL, "/")){
		if (strcmp(token,"S\n")){
			i = 0;
			lenTok = strlen(token);
			while((((token[i] < '0') || (token[i] > '9')))  && i < lenTok)
				i++;
	
			if (i<lenTok){
				key = generateKey(token);
				movie = insertHT(ht,token,m_cnt,key,N);
			}				
			else{
				i = 0;
				while (token[i] != ','){
					ch1[i] = token[i];
					i++;
				} 
				ch1[i] = '\0';
				j = 0;
				i = i + 2;
				lenTok = strlen(token);
				while ((i < lenTok) && (token[i] != '\n'))
					ch2[j++] = token[i++];
				ch2[j] = '\0';
				strcat(ch2, " ");
				strcat(ch2, ch1);
				key = generateKey(ch2);
				actor = insertHT(ht,ch2,a_cnt,key,N);
				if (actor != -1) {
					insertNode(ht, movie, actor);
					insertNode(ht, actor, movie);
				}
			}
		}
	}
}
//finds from hash table
int find(Hash_T* ht,char* name, unsigned long long int N) {
	int i = 0;
	
	while ((strcmp(name,ht[i].str) != 0) && (i < N))
		i++;
	
	if (i > N){
		printf("%s named actor/actress does not exists\n", name);
		return -1;
	}	
	else { //Does exists
		return i;
	}
}
//implementing bfs
int breadthFirstSearch(Hash_T *ht, Queue *q, int src, int dest, int sign, unsigned long long int N){
    int i, x, j, cnt;
	int xyz = src;
	
    int *prev = (int*)calloc(N, sizeof(int));
	int *path = (int*)calloc(N, sizeof(int));
	//BFS Algorithm 
	q->front = 0;
	q->rear = 0;
	q->parents[xyz] = -1;
	i = 0; j = 0;  cnt = 0; x = 0;
    path[xyz] = 1;
	Node* curr;
	enqueue(q, xyz);
    while((q->front < q->rear) && (!x)){
        xyz = dequeue(q);
        if(ht[xyz].node) {
			curr = ht[xyz].node;
			while(curr){
				if(path[curr->val] != 1) {
					q->parents[curr->val] = xyz;
					path[curr->val] = 1;
					enqueue(q, curr->val);
					if(curr->val == dest)  
						x = 1;
				}
				curr = curr->next;
			}
        }
    }
	if(x){
		i = 0;
		j = dest;
		while(j != src){
			prev[i] = j;
			j = q->parents[j];
			i++;
		}
		prev[i] = src;
		int num = 1;
		if(i>0)
			printf("---Path to Kevin Bacon---\n");
		while (i > 0){
			printf("%d ",num++);
			printf("%s ", ht[prev[i]].str);
			i = i - 2;
			printf("%s ", ht[prev[i++]].str);
			printf("%s\n", ht[prev[i--]].str);
			cnt++;
		} 
		if(sign == 0){
			printf("---Result---\n");
			if (cnt > 6)   //not possible more than six degrees
				printf("Kevin Bacon Number is %d so we cannot associated with Kevin Bacon \n", cnt);
			else{
				printf("%s's Kevin Bacon Number is %d\n", ht[dest].str, cnt);
				return cnt; //if kevin bacon found
			}
				
		}
		else if(sign == 1)
			printf("%s  %s: %d\n", ht[src].str, ht[dest].str, cnt);
	}
	
	return 0;
}
//find bacon numbers 
int findBacon(Hash_T *ht, Queue *q, char *name, int sign, unsigned long long int N){
	char kevin[32];
	strcpy(kevin, "Kevin Bacon");
	int src = find(ht,kevin,N);
	int dest = find(ht,name,N);
	if ((src == -1) || (dest == -1)){
		printf("Not FOUND!!!\n");
		return 0;
	}
	return breadthFirstSearch(ht,q,src,dest,sign,N); 
}



//Reads from file to Hash Table with tokenizing
void readFile(Hash_T* ht, unsigned long long int N){
	FILE *fp;
	char line[4096];
	int m_cnt = 0, a_cnt = 0;
	fp = fopen("input-3.txt", "r"); //Path to input file
	if (fp == NULL) {
		printf("File could not open\n");
		return;
	}
	while (fgets(line, 4095, fp))
		tokenHelper(ht,line,&m_cnt, &a_cnt,N);
}
//2. Soru icin 
//Istenilen sayida insanin kevin bacon sayilarinin yazilmasi
void writeBacons(Hash_T *ht, Queue *q,int sign, unsigned long long int N){
	printf("Finding some Kevin Bacon values...\n\n");
	int i = 0;
	while(i<40){
		findBacon(ht,q,ht[i].str,sign,N);
		i++;
		printf("\n");
	}
}

//3. Soru icin
//Gecmis aramalar icin kontrol
int pastCompare(char remember[][64],char actor[],int size){
	int i = size;
	for(i=0;i<size;i++){
		if(strcmp(remember[i],actor) == 0)
			return i; //Bulunan indis gonderilir
	}
	return -1;
}

int main(int argc, char *argv[]){
	int i = 0,j = 0, flag = 0;
	char actor[128];
	char remember[64][64];
	int values[64];
	int sign;
	unsigned long long int N = 323567;
	Hash_T* ht = (Hash_T*) calloc(N, sizeof(Hash_T));
	Queue q;
	initHash(ht, N);
	initQueue(&q, N);
	readFile(ht, N);
	
	int fun;
	while(1){
		printf("INFO: Your past searches are stored in the list.\n");
		printf("Please select the function you want.\n");
		printf("PRESS 1 -   Show Kevin Bacon numbers of actors\n");
		printf("PRESS 2 -   Find Kevin Bacon number of selected actor. \n");
		printf("PRESS 0 -   For Clearing the screen...\n");
		printf("-> ");
		scanf("%d",&fun);

		if(fun == 1)
			writeBacons(ht,&q,0,N);

		if(fun == 2){
		
			printf("Please <Enter> the <Name Surname> of the actor.\n");
			scanf(" %[^\n]s", actor);
			flag = pastCompare(remember,actor,i); //Eger daha once arma yapildiysa bfs yapilmadn listeden cekmede yardimci gosterge.
			
			if(flag != -1){
				printf("\n");
				printf("Query's been already took place...\n");
				printf("Result taken from the previous queries table\n");
				printf("Actor or Actress: %s 's, Kevin Bacon Number is %d\n",remember[flag],values[flag]);
			}else{
				sign = findBacon(ht,&q,actor,0,N);
				if(sign>0 && sign<6){ //Eger 0 ile altý arasýnda bir kevin bacon sayisi varsa
					strcpy(remember[i],actor);
					values[i] = sign;
					i++;
				}			
			}
			printf("\n");
	
		}
		if(fun==0)
			system("cls");
		else{
			return 0; //Programdan cik
		}
		
	}

	return 0;
}
