#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5000
#define TABLESIZE 190000

/* Fonksiyonlar icin gerekli aciklamalar declaration kýsmýnda yapilmistir. Daha detayli
bilgiler, fonksiyon satirlarinda bulunabilir.
Ayrica, kodun calisma mantigini daha iyi anlamak adina, comment durumuna 
alinmis printf satirlari kullanilabilir. */

typedef struct NODE{
	char *name;
	char type; //aktor veya film
	struct NODE *next; //baglantilari
	int key;
	char isVisited; //bfs icin
	int r; //sadece bfs'de kullanmasi icin. Queue'ya kimin komsusu oldugu icin eklendigi bilgisi. 
}NODE;

typedef struct GRAPH{
	int nodeCount; //filmler + aktorler
	int hashSize; //veriler hashtable duzeninde saklanacak.
	struct NODE **AdjList;
}GRAPH;

typedef struct QUEUE { //BFS icin
    int items[TABLESIZE]; //node'larin key'larini tutar.
    int front;
    int rear;
}QUEUE;




NODE* createNode();
GRAPH* createGraph(int);
QUEUE* createQueue();
int isQEmpty(QUEUE*); //Queue fonksiyonlari
void enqueue(QUEUE*, int, GRAPH*);
int dequeue(QUEUE*, GRAPH*);
void printQueue(QUEUE*, GRAPH*);
void callTheBfs(GRAPH*); //iki aktorun uzakligi 
void callKB(GRAPH*); //kevin bacon sayisi
int bfs(GRAPH*, NODE*, NODE*);
void readFile(char*,GRAPH*); //Dosya okuma ve graf doldurma fonksiyonlari
void locateElements(char*, GRAPH*); //okunan satirdaki verileri ayirip fonksiyonlara gonderir
int addList(NODE*,  GRAPH*); //veri unique ise hashtable'a ekler
void connect(NODE*, NODE*, GRAPH*); //film-aktor baglantisini yapar
NODE* getTheNode(char* ,  GRAPH*); //name verilince ayni name'e sahip node'u dondurur
int getKey(char*, GRAPH*); //name'den key degerini hesaplar




int main(int argc, char *argv[]) {
	int i=1, j;
	static char fileName[] = "input-mpaa.txt";
	GRAPH *gr = createGraph(TABLESIZE);
		
	printf("\nProcessing, please wait...");
	readFile(fileName,gr);
	printf("\n\nCompleted! Total node count (Movies and Actors): %d", gr->nodeCount);
	
	while (i){ //kullanici istedigi kadar bfs sorgusu yapabilir
		printf("\n\nPlease insert one value from below:");
		printf("\n0 for finding the Kevin Bacon number of an actor you will insert.");
		printf("\n1 (or some other) for finding the distance between two actors you will insert.\n>");
		scanf("%d", &j);
		if (j) callTheBfs(gr); else callKB(gr);
		printf("\n\n\nWould you like to try again? (1/0)\n>");
		scanf("%d",&i);
		system("cls");
	}
	
	
	//bu alaný kullanarak ismini girdiginiz her node'un baglantilarini listeleyebilirsiniz.
	//kullanmak icin ustteki while'i commente donusturmelisiniz.
	/*char name[MAXSIZE]; printf("\n\n\nGive a name... "); gets(name); NODE* tmp = createNode();
	tmp->next=getTheNode(name, gr); printf("\nGot the node: '%s'",tmp->next->name);
	while (tmp->next->next!=NULL){ tmp->next = tmp->next->next; printf("\n%s",tmp->next->name); }*/
	
	return 0;
}


NODE* createNode(){
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->next = NULL;
	tmp->name = (char*)malloc(MAXSIZE*sizeof(char));
	tmp->key = 0;
	tmp->r = -1;
	tmp->isVisited = '0';
	return tmp;
}

GRAPH* createGraph(int size){
	//printf("\n\nThe graph has been created...");
	int i;
	
	GRAPH *tmp = (GRAPH*)malloc(sizeof(GRAPH));
	tmp->nodeCount = 0;
	tmp->hashSize = size;
	
	tmp->AdjList=(NODE**)malloc(size*sizeof(NODE*));
	for (i=0;i<size;i++){
		tmp->AdjList[i] = createNode();
		tmp->AdjList[i]->key = -1;		
	} 
	return tmp;
}

QUEUE* createQueue(){
	QUEUE *tmp = (QUEUE*)malloc(sizeof(QUEUE));
    tmp->front = -1;
    tmp->rear = -1;
    return tmp;
}

int isQEmpty(QUEUE* q){ 
	if(q->rear == -1) 
        return 1;
    else 
        return 0;	
}

void enqueue(QUEUE* q, int key, GRAPH *gr){ //enqueue ve dequeue'nin graph almasinin tek sebebi printQueue'ye gonderebilmektir
	if(q->rear == TABLESIZE-1)
        printf("\nQueue is full!");
    else {
        if(q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = key;
    }
    //istendigi takdirde kullanilabilir
    //printQueue(q, gr); 
    //printf("\n");
}

int dequeue(QUEUE *q, GRAPH *gr){
	int dKey;
    if(isQEmpty(q)){
        //printf("\nQUEUE IS EMPTY");
        dKey = -1;
    }
    else{
        dKey = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            //printf("\nResetting queue");
            q->front = -1;
			q->rear = -1;
        }
    }
    //istendigi takdirde kullanilabilir
    //printQueue(q, gr);
    //printf("\n");
    return dKey;
}

void printQueue(QUEUE* q, GRAPH* gr){ //program icin gerekliligi yoktur ama istenirse kullanilabilir
    if(isQEmpty(q))
        printf("\nQueue is Empty! Could not print.");
    else{
        int i;
        printf("\nQueue elements are:\n");
        for(i=q->front; i<=q->rear; i++){
        printf(" ; ");
        printf("%s",gr->AdjList[q->items[i]]->name);
    	}
    }
}

void callTheBfs(GRAPH *gr){ //BFS fonksiyonu icin kullanicidan input alan ve bfs outputunu degerlendiren fonksiyon
	getchar();
	int i, distance;
	char name[30],name2[30];
	
	printf("\n\nPlease insert an actor name (surname, name) > ");
	gets(name);
	//printf("\nGiven name: '%s'",name);
	printf("\nPlease insert the second actor name (surname, name) > ");
	gets(name2);
	//printf("\nGiven name: '%s'",name2);
		
	distance = bfs(gr, getTheNode(name2, gr), getTheNode(name, gr));
		
	if (distance==-1) printf("\n\nCould not find any path between '%s' and '%s'...", name, name2);
	else if (distance == 0) printf("\n\nYou have given the same actor twice. Distance: %d", distance);
	else if (distance == -2) printf("\n\nWARNING: Invalid input. Please try again and insert actors...");
	else printf("\n\nDistance between '%s' and '%s': %d", name, name2, distance);
	
	for (i = 0; i< gr->hashSize; i++){ //node'lar yeni bfs sorgusu icin hazir hale getiriliyor
		gr->AdjList[i]->r = -1;
		gr->AdjList[i]->isVisited = '0';
	} 
}

void callKB(GRAPH *gr){ //Kevin Bacon modu
	getchar();
	int i, distance;
	char name[30];
	
	printf("\n\nPlease insert an actor name (surname, name) > ");
	gets(name);
	//printf("\nGiven name: '%s'",name);
		
	distance = bfs(gr, getTheNode("Bacon, Kevin", gr), getTheNode(name, gr));
		
	if (distance==-1) printf("\n\nCould not find the Kevin Bacon number for '%s'...", name);
	else if (distance == -2) printf("\n\nWARNING: Invalid input. Please try again and insert an actor...");
	else 
	{
		if (distance > 6) printf("\n\nCould not find the Kevin Bacon number for '%s' (Distance value is too high)...", name);
		else printf("\n\nKevin Bacon value for '%s': %d", name, distance);
	}
	for (i = 0; i< gr->hashSize; i++){ //node'lar yeni bfs sorgusu icin hazir hale getiriliyor
		gr->AdjList[i]->r = -1;
		gr->AdjList[i]->isVisited = '0';
	} 
	
}

int bfs(GRAPH *gr, NODE *start, NODE *dest){ //distance degeri dondurur
	if((start->type == 'm') || (dest->type == 'm')) return -2; //ikisi de aktor mu?
	
	int count = 0;
	char prev, cur;
	QUEUE *q = createQueue();
	
	prev = 'n';
    cur = 'n';
    printf("\nCalculating the distance...\n");
    start->isVisited = '1';
    enqueue(q, start->key, gr);
    
    while(!isQEmpty(q)){
		int current = dequeue(q, gr);
		//printf("\nVisited %s", gr->AdjList[current]->name);
		//dequeue edilen verinin turu (film->aktor gibi) degisiyorsa count++
		prev = cur; 
		cur = gr->AdjList[current]->type;
        if ((prev != 'n')&&(prev != cur)) count++;
        
        if (dest->key == current) //BULUNDU
		{
			if (count == 0) return count;
			NODE* result = createNode();
			printf("\n\n%s > ",gr->AdjList[current]->name); //Path ekrana yazdirilir
			result -> next = gr->AdjList[gr->AdjList[current]->r];
			printf(" %s ",result -> next -> name);
			while (result->next->key != start->key){
				result -> next = gr->AdjList[result->next->r];
				printf(" >  %s ",result -> next -> name);
			}
			return count/2; //distance dondurulur
		} 
    
       NODE *tmp = createNode();
	   tmp->next = gr->AdjList[current];
    
       while(tmp->next->next!=NULL) { //current'in komsularini kuyruga alalim
       		tmp->next = tmp->next->next;
            if(gr->AdjList[tmp->next->key]->isVisited == '0'){
                gr->AdjList[tmp->next->key]->isVisited = '1';
                gr->AdjList[tmp->next->key]->r = current;
                enqueue(q, tmp->next->key, gr);
            }
       }
       free(tmp);
    }
    return -1; //bulunamadi
}

void readFile(char* fileName, GRAPH* gr){
	printf("\n\nReading the file '%s'...", fileName);
	FILE *file = fopen ( fileName, "r" );
	
   if ( file != NULL )
   {
   	  printf("\n\nScanning elements...");
	  char line[MAXSIZE]; 
      while ( fgets ( line, sizeof line, file ) != NULL ) 
      {	      
	  	//printf("\nLine found:\n%s",line);
		locateElements(line,gr); //her satir bu fonksiyona gonderilir
      }
      fclose ( file );
   }
   else
   {
      perror ( fileName );
   }
}

void locateElements(char* str, GRAPH* gr){ //gelen satirdaki oyuncu ve filmler ayrýlýp ilgili fonksiyonlar cagiriliyor
	int i;
	const char *delim = "/";
	NODE *tmpM = createNode();
	tmpM->type='m';
	NODE *tmpA;
	
	
	char *element = (char*)malloc(MAXSIZE*sizeof(char));
	element = strtok(str, delim); //ilk element her zaman filmdir
	strcpy(tmpM->name,element);
	tmpM->key = getKey (tmpM->name, gr);
	tmpM->key = addList(tmpM,gr);
	//printf("\nMovie: %s",tmpM->name);
	
	while(1)
	{	
		element = strtok(NULL, delim);
		if (element != NULL)
		{
			//printf("\nActor found: %s",element);
			i = 0;
			while (element[i] != '\0')
			{
				if (element[i] == '\n') element[i] = '\0';
				i++;
			}
			tmpA = createNode();
			tmpA->type = 'a';
			strcpy(tmpA->name,element);
			tmpA->key = getKey (tmpA->name, gr);
			
			//bulunan aktor listeye eklenir, daha sonra film ile baglanir
			tmpA->key = addList(tmpA,gr);
			connect(tmpM, tmpA, gr);
			connect(tmpA, tmpM, gr);
			free(tmpA);
		}
		else break;	
	}
}

int addList(NODE* node,  GRAPH* gr){ //bulunan elementler hashtable'a ekleniyor
	int tmpKey = node->key, i = 0;
	if (node->type == 'a'){ //aktorse unique mi diye bakilir, filmse zaten uniquetir
		while ((gr->AdjList[tmpKey]->key!=-1)  &&  (strcmp(node->name, gr->AdjList[tmpKey]->name)))
		{
			i++;
			tmpKey = tmpKey + (i * i); //ben bu basit probing yonteminin efektif calistigini gozlemledim
			tmpKey = tmpKey % (gr->hashSize);			
		} 
		//printf("\ncheck DONE");
		if (gr->AdjList[tmpKey]->key!=-1){
			//unique degil, zaten mevcut
			//printf("\nALREADY EXISTS: %s",node->name);
			return tmpKey;
		}
		else
		{	
		//unique, ekleniyor
		strcpy(gr->AdjList[tmpKey]->name,node->name);
		gr->AdjList[tmpKey]->type = node -> type;
		gr->AdjList[tmpKey]->key = tmpKey;
		gr->nodeCount++;
		//printf("\nADDED: %s",gr->AdjList[tmpKey]->name);
		return tmpKey;
		}
	}
	
	//filmler burada ekleniyor. sadece probing yapýlýyor
	while (gr->AdjList[tmpKey]->key!=-1){
		i++;
		tmpKey = tmpKey + (i * i);
		tmpKey = tmpKey % (gr->hashSize);
	}
	strcpy(gr->AdjList[tmpKey]->name,node->name);
	gr->AdjList[tmpKey]->type = node -> type;
	gr->AdjList[tmpKey]->key = tmpKey;
	gr->nodeCount++;
	//printf("\nADDED: %s",gr->AdjList[tmpKey]->name);
	return tmpKey;	
}

void connect(NODE* a, NODE* b, GRAPH *gr){ //verilen a node'undan b node'una baglanti kurar
	//printf("\nCONNECTING: '%s' ve '%s'",a->name,b->name);
	NODE *tmp, *tmp2;

	tmp = createNode();
	tmp->type = b->type;
	strcpy(tmp->name,b->name);
	tmp->key = b->key;
	
	tmp2 = createNode();
	tmp2->next = gr->AdjList[a->key];
	while (tmp2->next->next != NULL) tmp2->next = tmp2->next->next;
	tmp2->next->next = tmp;
}

NODE* getTheNode(char* name,  GRAPH* gr){ //verilen isme sahip node'u dondurur
	int i = 0;
	int key = getKey(name, gr);
	if (gr->AdjList[key]->key==-1){
		printf("\n\nCould not find: '%s'. Press any to terminate...", name);
		getch();
		exit(0);
	}
	while (strcmp(name,gr->AdjList[key]->name))
	{
		i++;
		key = key + (i * i);
		key = key % (gr->hashSize);
		if (gr->AdjList[key]->key==-1){
			printf("\n\nCould not find: '%s'. Press any to terminate...", name);
			getch();
			exit(0);
		}		
	}
	return (gr->AdjList[key]);	
}

int getKey(char* name, GRAPH *gr){
	int i = 0, key = 0;
	while (name[i]!='\0'){
		key = key + (int)name[i];
		i++;		
	} 
	key = key % (gr->hashSize);
	return key;
}
