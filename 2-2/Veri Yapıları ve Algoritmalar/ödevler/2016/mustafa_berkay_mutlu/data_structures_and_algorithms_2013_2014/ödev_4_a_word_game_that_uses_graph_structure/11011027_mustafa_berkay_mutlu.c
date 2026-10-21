/****************************************************************************
 * main.c                                                                   *
 * Modified in 12 June 2014                                                 *
 * Written by Mustafa Berkay Mutlu                                          *
 * http://www.berkaymutlu.com/                                              *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION:                                                             *
 *                                                                          *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef enum { not_visited, visiting, visited } status;
// not_visited: siradan gecmemis ve o anda sirada degil (henuz siraya girmemis)
// visiting: siradan gecmemis ancak o an sirada (o an sirada bulunuyor)
// visited: siradan gecmis ve o anda sirada degil (siradan cikmis ve tekrar siraya giremez)

// Dairesel kuyruk uyarlamasi:
typedef struct Queue
{
    int capacity; // Kuyrugun kapasitesini tutar.
    int count; // Kuyruktaki eleman sayisini tutar.
    int front; // Kuyrugun bas indexini tutar.
    int rear; // Kuyrugun son indexini tutar.
    unsigned short int *elements; // Kuyruktaki elemanlarin tutuldugu dizi. Bu dizinin alani createQueue fonksiyonunda dynamic memory allocation ile acilir.
    unsigned short int *pathId; // Kuyruktaki her bir eleman icin elemanin ait oldugu pathId. Yani elements ve pathId degiskenleri kuyruga enqueue fonksiyonu icinde birlikte girerler.
} Queue;

// Genel tanimlamalar:
#define ERROR -1 // Hata olması durumunda kullanilan donus degeridir.

// Programa özel degistirilebilir tanimlamalar:
#define WORDS_FILE_NAME "kelime.txt" // kelime.txt dosyasının adını ifade eder.
#define SHOW_DEBUG false // Bu etiket acik olursa ekrana Debug ciktilari da yazdirilir.
#define PRINT_PATHS_TO_THE_END false // Bu etiket acik olursa ekrana yazdirilan path'ler son kelimede bitmez, butun path yazdirilir.
#define WORD_COUNT 2400 // Toplam kelime sayisini ifade eder.
#define LETTER_COUNT_OF_EACH_WORD 5 // Her kelimenin harf uzunlugunu ifade eder.
#define UNNECESSARY_LETTER_COUNT_OF_EACH_WORD 2 // Her bir satırda, kelimeden sonra bulunan 2 karakterlik \r\n 'yi ifade eder.
#define MAXIMUM_DIFFERENT_LETTER_COUNT_FOR_CONNECTED_WORDS 1 // Iki kelimenin birbirine bagli olabilmesi icin aralarindaki maximum farkli harf sayisini ifade eder.
#define QUEUE_CAPACITY 100000

// PATHS
#define MAX_PATH_ROWS 20000
#define MAX_PATH_COLUMNS 10000

void BreadthFirstSearch(int, status [], bool [WORD_COUNT][WORD_COUNT], unsigned short int[], short int [MAX_PATH_ROWS][MAX_PATH_COLUMNS]);
void CreateAdjacencyMatrix(char[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD], bool[WORD_COUNT][WORD_COUNT], unsigned short int[]);
int areThooseWordsShouldConnected(char [], char []);
int ReadFromFile(char[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD]);
void init(status [], short int [MAX_PATH_ROWS][MAX_PATH_COLUMNS]);
char* getWord(int, char [WORD_COUNT][LETTER_COUNT_OF_EACH_WORD]);

// Queue fonksiyonları
Queue* createQueue(int);
void enqueue(Queue *, int, int);
unsigned short int dequeue(Queue *);
unsigned short int getFrontPathId(Queue *);

// Ekrana yazdirma fonksiyonlari:
void PrintAdjacencyMatrix(bool [WORD_COUNT][WORD_COUNT], char[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD]);
void PrintVisit(status  []);
void PrintEdgeCounts(unsigned short int []);
void PrintQueue(Queue *);
void PrintPaths(short int [MAX_PATH_ROWS][MAX_PATH_COLUMNS]);
void FindPathInPaths(short int [MAX_PATH_ROWS][MAX_PATH_COLUMNS], char [WORD_COUNT][LETTER_COUNT_OF_EACH_WORD], int);
void PrintSinglePath(short int [MAX_PATH_ROWS][MAX_PATH_COLUMNS], int, char [WORD_COUNT][LETTER_COUNT_OF_EACH_WORD], int);


int main()
{
    static char words[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD] = {0};
    static unsigned short int  edgeCountOfVertices[WORD_COUNT] = {0};
    static bool adjacency_matrix [WORD_COUNT][WORD_COUNT] = {false};
    unsigned short int word1_index, word2_index;
    status visit[WORD_COUNT];
    static short int paths[MAX_PATH_ROWS][MAX_PATH_COLUMNS] = {-1};

    getchar();

    init(visit, paths);
    ReadFromFile(words);
    CreateAdjacencyMatrix(words, adjacency_matrix, edgeCountOfVertices);
    if(SHOW_DEBUG) PrintAdjacencyMatrix(adjacency_matrix, words);
    if(SHOW_DEBUG) PrintEdgeCounts(edgeCountOfVertices);

    printf("Enter the first word's index based on zero> ");
    scanf("%d", &word1_index);
    printf("You have choosen '%s' \n", getWord(word1_index, words));
    printf("Enter the second word's index based on zero> ");
    scanf("%d", &word2_index);
    printf("You have choosen '%s' \n",getWord(word2_index, words));

    BreadthFirstSearch(word1_index, visit, adjacency_matrix, edgeCountOfVertices, paths);


    switch (visit[word2_index])
    {
    case not_visited:
        printf("Exit is unreachable. \n");
        break;
    case visited:
        FindPathInPaths(paths, words, word2_index);
        break;
    }

    if(SHOW_DEBUG)
    {
        printf("\n");
        PrintVisit(visit);
        printf("\n");
        PrintPaths(paths);
    }

    getchar();
    return 0;
}


void BreadthFirstSearch(int startVertice, status visit[], bool adjacency_matrix [WORD_COUNT][WORD_COUNT], unsigned short int edgeCountOfVertices[], short int paths[MAX_PATH_ROWS][MAX_PATH_COLUMNS])
{
    Queue *q = createQueue(QUEUE_CAPACITY);
    int i; // Dongu degiskeni.
    int v; // Kuyruktan alinan noktanin tutuldugu degisken.
    int iter; // Dongu degiskeni.
    int adjacentVertice = 0;
    int pathCount = 0; // Toplam path sayisini tutar.
    int pathId = 0; // Kuyruktan alinan elemana ait pathId'yi tutar.
    int pathNodeCounts[MAX_PATH_ROWS] = {0}; // Her Path'in sahip oldugu node sayisini tutar. Bu sayede her pathId icin paths dizisinde nerede kaldigimizi biliriz.

    enqueue(q, startVertice, 0);
    if(SHOW_DEBUG) printf("[DEBUG] enqueue(q, %d);\n", startVertice);
    visit[startVertice] = visiting;

    while (q->count > 0)
    {
        pathId = getFrontPathId(q);
        if(SHOW_DEBUG) printf("[DEBUG] pathId = %d \n", pathId);
        v = dequeue(q);
        if(SHOW_DEBUG) printf("[DEBUG] v = dequeue(q) = %d \n", v);
        visit[v] = visited;
        paths[pathId][pathNodeCounts[pathId]++] = v;

        if(SHOW_DEBUG )printf("[DEBUG] %d = edgeCountOfVertices[%d]\n", edgeCountOfVertices[v], v);

        adjacentVertice = -1;
        for(iter = 0; iter < edgeCountOfVertices[v]; iter++) // v'nin komsu sayisi kadar dongude kaliniyor.
        {
            do
            {
                adjacentVertice++;
            }
            while((!adjacency_matrix[v][adjacentVertice] || v == adjacentVertice || visit[adjacentVertice] == visited) && adjacentVertice < WORD_COUNT);   // Komsu kelimenin indexini bulmak icin while dongusu kullanildi.

            if(adjacentVertice < WORD_COUNT)
            {

                if(visit[adjacentVertice] == not_visited || visit[adjacentVertice] == visiting)
                {
                    visit[adjacentVertice] = visiting;

                    if(iter)
                    {
                        enqueue(q, adjacentVertice, ++pathCount);
                        if(SHOW_DEBUG) printf("[DEBUG] enqueue(q, %d, %d);\n", adjacentVertice, pathId);

                        for(i=0; i<pathNodeCounts[pathId]; i++)
                        {
                            paths[pathCount][i] = paths[pathId][i];
                        }

                        pathNodeCounts[pathCount] = pathNodeCounts[pathId];
                    }
                    else
                    {
                        enqueue(q, adjacentVertice, pathId);
                        if(SHOW_DEBUG) printf("[DEBUG] enqueue(q, %d, %d);\n", adjacentVertice, pathId);
                    }
                }
            }
        }
    }
}

Queue* createQueue(int maxElements)
{
    Queue *q;
    q = (Queue *) malloc(sizeof(Queue));

    q->elements = (unsigned short int *) malloc(sizeof(unsigned short int) * maxElements);
    q->pathId = (unsigned short int *) malloc(sizeof(unsigned short int) * maxElements);
    q->count = 0;
    q->capacity = maxElements;
    q->front = 0;
    q->rear = 0;

    if(q->elements == NULL || q->pathId == NULL)
    {
        printf("Error occured while allocating memory to the queue. Aborting. \n");
        exit(ERROR);
    }
    return q;
}

void enqueue(Queue *q, int element, int pathId)
{
    if(q->count == q->capacity)
    {
        printf("Error. Queue is full. Aborting. ");
        exit(ERROR);
    }
    else
    {
        q->elements[q->rear] = element;
        q->pathId[q->rear] = pathId;
        q->rear = (q->rear + 1) % q->capacity;
        q->count++;
    }
}

unsigned short int dequeue(Queue *q)
{
    if(q->count == 0)
    {
        printf("Error. Queue is empty. Aborting. ");
        exit(ERROR);
    }
    else
    {
        int item = q->elements[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->count--;
        return item;
    }
}

unsigned short int getFrontPathId(Queue *q)
{
    return q->pathId[q->front];
}

void PrintQueue(Queue *q)
{
    int i = q->front;
    int itemCount = q->count;

    printf("Queue: ");
    while(itemCount > 0)
    {
        printf("%d ", q->elements[i]);
        i = (i + 1) % q->capacity;
        itemCount--;
    }
    printf("\n");
}

void init(status visit[], short int paths[MAX_PATH_ROWS][MAX_PATH_COLUMNS])
{
    int i, j;

    for(i=0; i<WORD_COUNT; i++)
    {
        visit[i] = not_visited;
    }

    for(i=0; i<MAX_PATH_ROWS; i++)
    {
        for(j=0; j<MAX_PATH_COLUMNS; j++)
        {
            paths[i][j] = -1;
        }
    }
}

void CreateAdjacencyMatrix(char words[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD], bool adjacency_matrix[WORD_COUNT][WORD_COUNT], unsigned short int edgeCountOfVertices[WORD_COUNT])
{
    char word1[LETTER_COUNT_OF_EACH_WORD], word2[LETTER_COUNT_OF_EACH_WORD];
    int i, j, k;

    for(i=0; i<WORD_COUNT; i++)
    {
        for(k=0; k<LETTER_COUNT_OF_EACH_WORD; k++)
            word1[k] = words[i][k];

        for(j=i+1; j<WORD_COUNT; j++)
        {
            for(k=0; k<LETTER_COUNT_OF_EACH_WORD; k++)
                word2[k] = words[j][k];

            if(areThooseWordsShouldConnected(word1, word2))
            {
                adjacency_matrix[i][j] = true;
                adjacency_matrix[j][i] = true;

                edgeCountOfVertices[i]++;
                edgeCountOfVertices[j]++;
            }
        }
        adjacency_matrix[i][i] = true; // Kosegendeki elemanlar icin.
    }
}

int areThooseWordsShouldConnected(char word1[LETTER_COUNT_OF_EACH_WORD], char word2[LETTER_COUNT_OF_EACH_WORD])
{
    int i, differentLetterCount = 0;
    for(i=0; i<LETTER_COUNT_OF_EACH_WORD; i++)
    {
        if(word1[i] != word2[i])
        {
            differentLetterCount++;
        }
    }

    if(differentLetterCount <= MAXIMUM_DIFFERENT_LETTER_COUNT_FOR_CONNECTED_WORDS)
        return true;
    else
        return false;
}

void PrintAdjacencyMatrix(bool adjacency_matrix[WORD_COUNT][WORD_COUNT], char words[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD])
{
    int i, j;

    for(i=0; i<WORD_COUNT; i++)
    {
        printf("%d: %s - ",i, getWord(i,words));

        for(j=0; j<WORD_COUNT; j++)
        {
            adjacency_matrix[i][j] ? printf("1 ") : printf("0 ");

            if((j+1) % 10 == 0) printf("| "); // Her 10 sayidan sonra belirtec ekler.
        }
        printf("END_LINE \n");
    }
}

int ReadFromFile(char kelimeler[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD])
{
    FILE *words;
    long words_size;
    int word_count;
    int i;

    words = fopen (WORDS_FILE_NAME,"r");
    if (words == NULL)
    {
        printf("Error occured while opening %s file. Aborting. ", WORDS_FILE_NAME);
        exit(ERROR);
    }

    fseek (words , 0 , SEEK_END);
    words_size = ftell (words);
    word_count = words_size / (LETTER_COUNT_OF_EACH_WORD + UNNECESSARY_LETTER_COUNT_OF_EACH_WORD);
    rewind (words);

    for(i=0; i<WORD_COUNT; i++)
    {
        fscanf(words,"%s",kelimeler[i]);
    }

    fclose(words);
    return word_count;
}

char* getWord(int index, char words[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD])
{
    int i;
    char singleWord[LETTER_COUNT_OF_EACH_WORD + 1] = {0};

    for(i=0; i<LETTER_COUNT_OF_EACH_WORD; i++)
        singleWord[i] = words[index][i];

    singleWord[LETTER_COUNT_OF_EACH_WORD + 1] = '\0';

    return singleWord;
}

void PrintVisit(status visit [])
{
    int i;

    printf("Visit: ");
    for(i=0; i<WORD_COUNT; i++)
    {
        printf("%d ", visit[i]);
        if((i+1) % 10 == 0) printf("| "); // Her 10 sayidan sonra belirtec ekler.
    }
    printf("\n");
}

void PrintEdgeCounts(unsigned short int edgeCountOfVertices [])
{
    int i;

    printf("Edge Counts: ");

    for(i=0; i<WORD_COUNT; i++)
    {
        printf("%d ",edgeCountOfVertices[i]);
        if((i+1) % 10 == 0) printf("| "); // Her 10 sayidan sonra belirtec ekler.
    }
    printf("\n");
}

void PrintPaths(short int paths[MAX_PATH_ROWS][MAX_PATH_COLUMNS])
{
    int i, j;
    int step;

    printf("Paths: \n");
    for(i=0; i<MAX_PATH_ROWS; i++)
    {
        step = 0;
        printf("%d -- ", i);
        for(j=0; j<MAX_PATH_COLUMNS; j++)
        {
            printf("%d ", paths[i][j]);
            if(paths[i][j] != -1)
                step++;
        }
        printf(" -- %d steps \n", step == 0 ? step : step-1);
    }
}

void PrintSinglePath(short int paths[MAX_PATH_ROWS][MAX_PATH_COLUMNS], int pathId, char words[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD], int endVertice)
{
    int i;
    int step = 0;

    printf("Path #%d -", pathId);

    if(PRINT_PATHS_TO_THE_END)
    {
        for(i=0; i<MAX_PATH_COLUMNS; i++)
        {
            if(paths[pathId][i] != -1)
            {
                printf("%s(%d) - ",getWord(paths[pathId][i], words), paths[pathId][i]);
                step++;
            }
        }
    }
    else
    {
        i = 0;
        while(i<MAX_PATH_COLUMNS && paths[pathId][i] != endVertice)
        {
            if(paths[pathId][i] != -1)
            {
                printf("- %s(%d) ",getWord(paths[pathId][i], words), paths[pathId][i]);
                step++;
            }
            i++;
        }
        printf("- %s(%d) ",getWord(paths[pathId][i], words), paths[pathId][i]);
        step++;
    }
    printf("-- %d steps \n", step == 0 ? step : step-1);
}

void FindPathInPaths(short int paths[MAX_PATH_ROWS][MAX_PATH_COLUMNS], char words[WORD_COUNT][LETTER_COUNT_OF_EACH_WORD], int endVertice)
{
    int i, j; // Dongu degiskenleri.
    int finalPaths[MAX_PATH_ROWS] = {-1}; // Icerisinde endVertice'in oldugu path'leri tutar.
    int finalPathCount = 0;

    // Bazen finalPaths initialize'i duzgun calismadigi icin asagidaki donguyu ekledim.
    // Daha fazla bilgi icin: http://stackoverflow.com/questions/2890598/how-to-initialize-all-elements-in-an-array-to-the-same-number-in-c
    for(i=0; i<MAX_PATH_ROWS; i++)
        finalPaths[i] = -1;

    for(i=0; i<MAX_PATH_ROWS; i++)
    {
        for(j=0; j<MAX_PATH_COLUMNS; j++)
        {
            if(paths[i][j] == endVertice)
                finalPaths[finalPathCount++] = i;
        }
    }

    for(i=0; i<MAX_PATH_ROWS; i++)
    {
        if(finalPaths[i] != -1)
        {
            PrintSinglePath(paths, finalPaths[i], words, endVertice);
        }
    }
}

