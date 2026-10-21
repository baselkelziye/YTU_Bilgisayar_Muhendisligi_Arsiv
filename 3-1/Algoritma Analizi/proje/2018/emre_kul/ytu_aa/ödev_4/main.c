#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 256//Kelime uzunluğu
#define HASH_MAP_SIZE 10000//Hash Map boyutu
#define LINE_SIZE 4096//Dosyadan okuma yapılırken kullanılacak satır uzunluğu
#define ADJ_LIST_SIZE 200000//Adjacency List uzunluğu

typedef struct WordList WordList;
typedef struct HashMap HashMap;
typedef struct Node Node;
typedef struct AdjList AdjList;
typedef struct InputData InputData;
/*Kelimeleri Linkli List şeklinde tutan yapı.*/
struct WordList{
    unsigned long id;//kelimenin ileride kullanılması için oluşturulan unquie id
    char *word;//kelimeyi tutacak 
    WordList *next;//sıradaki kelimenin adresi
};
/*Kelimeleri linkli liste hash map şeklinde tutan yapı*/
struct HashMap{
    char **wordArr;//Random access için eklendi yolu id'si verilen kelimeye direk ulaşmak için kullanılcak.
    WordList **wordList;//Her hash için kelime listesinin bulunduğu liste.
    unsigned long long count;//eklenen kelime sayısını tutar aynı zamanda yeni eklenen kelimenin id'si bu değer ile verilir.
};
/*Adjacency List'te kullanılacak Linkli liste yapısı*/
struct Node{
    unsigned long actorId;//aktörün id'si
    unsigned long movieId;//filmin id'si
    Node *next;//sonraki Node'u gösterir.
};
/*Adjacency List yapısı*/
struct AdjList{
    long long *parents;//Tekrar BFS uygulamamak için her aktörün ebebeyn id'sini tutar.
    long long *distances;//Tekrar BFS uygulamamk için her aktörün Kevin Bacon uzaklığını tutar.
    long long *movies;//Tekrar BFS uygulamamk için her aktörün ebebyn ile oynadığı film bilgisini tutar.
    Node **node;//Linkli liste lerden oluşan liste
};
/*Veri deposu olarak kullanılacak yapı film ve aktörleri tutar*/
struct InputData{
    HashMap *movies;//Film isimlerinin tutulduğu HashMap.Burada hashmap gerekmiyordu ama kullanmamın bir sakıncsı yok.
    HashMap *actors;//Aktör isimlerinin tutulduğu HashMap.
};
/*
    Boş bir HashMap yaratır gerekli hafıza işlemlerini yapar.
    @return HashMap* : yaratılan HashMap'i döndürür.
*/
HashMap *createHashMap();
/*
    Verilen HashMap'e istenen kelimeyi ekler.Geriye başarılı olup olmadığı bilgisini döndürür.
    @param1 HashMap * : Ekleme işlemi yapılacak HashMap.
    @param2 char * : HashMap'e eklenmek istenen kelime.
    @return char : ekleme başarılıysa 1 başarısızsa 0 döndürür.
*/
char addToHashMap(HashMap *,char *);
/*
    Verilen HashMap'de istenen kelimeyi arar ve bulunması durumunda o kelimenin id değerini döndürür.
    @param1 HashMap : Arama işleminin yapılacağı HashMap.
    @param2 char * : HashMap'de aranacak kelime.
    @return long long : Kelime bulunduysa id değerini bulunamadıysa -1 döndürür.
*/
long long searchInHashMap(HashMap,char *);
/*
    Verilen kelimeye özgü bir sayı üretir ve geri döndürür.
    //Reference : http://www.cse.yorku.ca/~oz/hash.html
    @param1 char * : Hash sonucu istenen kelime.
    @return unsigned long : Kelime için oluşturulan Hash değeri
*/
unsigned long getHashOfString(char *);
/*
    Adjacency List yaratır ve gerekli hafıza ayarlamalarını yapar.
    @return AdjList* : Oluşturulan boş Adjacency List yapısını döndürür.
*/
AdjList* createAdjList();
/*
    Aynı filmde yer alan aktörleri alır ve listeye ekler.
    @param1 AjList* : Bağlantıların ekleneceği Adjancency List.
    @param2 unsigned long : Filim Id'si.
    @param3 unsigned long * : Verilen filmde yer alan aktörlerin Id dizisi.
    @param4 unsigned long : Aktörlerin dizisinin uzunluğu.
*/
void addToAdjList(AdjList*,unsigned long,unsigned long *,unsigned long);
/*
    Tüm filim ve aktör bilgilerinin bulunduğu dosya ismini okuyarak HashMap'leri ve 
    Adjancency Liste'sini oluşturur.
    @param1 char * : Film ve aktör bilgilerinin bulunduğu dosya ismi.
    @param2 InputData * : Film ve aktör isimlerinin ekleneceği HashMap'leri bulunduran yapı. 
    @return AdjList * : Bağlantıları oluşturulmuş Adjancency List.
*/
AdjList *readMovieInputs(char *,InputData *);
/*
    Kevin Bacon ilişkisi istenen aktörlerin isimlerini okur ve BFS uygular.
    @param1 char * : Aktör isimlerinin bulunduğu dosya ismi.
    @param2 AdjList * : Bağlantıların bulunduğu Adjancency List.
    @param3 InputData *: Film ve aktör isimlerinin bulunduğu yapı. 
*/
void readActorInput(char *,AdjList *,InputData *);
/*
    Film ve aktör bilgilerinin okunması sırasında kullanılan bu fonksiyon verilen stringi istenen 
    karaktere kadar okuyarak geri döndürür.
    @param1 char * : Bölme işleminin yapılacağı string.
    @param2 char : Bölme işleminin hangi karaktere kadar yapılacağı bilgisini alan parametre.
    @param3 int * : Bölme işlemi yapıldıktan sonra stringde kaldığı indexi geri döndürür.
    @param4 int :String boyutu.String boyutunu tekrar tekrar hesaplamamak için bu parametre 
    üzerinden iletiyorum.
    @return char* : Bölüm sonucu oluşan string.
*/
char * getStringUntil(char *,char,int *,int);
/*
    Adjanency Liste üzerinde BFS uygular.
    @param1 AdjList * : BFS uygulanacak Adjanency Listesi.
    @param2 InputData : Başlangıç indexinin(actorName : Kevin Bacon) bulunması için kullanılmıştır.
    @param3 unsigned long : Aramanın hangi aktöre kadar yapılacağı bilgisini tutan parametre.
    @param4 long long : Aramanın hangi uzaklığa kadar yapılacağı bilgisini tutan parametre.
*/
void runBFS(AdjList *,InputData,unsigned long,long long);
/*
    Distance dizisini alır ve bu liste üzerinde hangi değerden kaç adet olduğu bilgisini 
    hesaplayıp ekrana yazdırır.
    @param1 long long * : Kevin Bacon uzaklıklarının tutulduğu dizi.
    @param2 long long : Dizinin boyutu.
*/
void countAndPrintDistances(long long *,long long);
/*
    Verilen aktörün Kevin Bacon'a olan bağlantısını ekrana yazdırır.
    @param1 AdjList *: Bağlantıların(distance,parents) bulunduğu Adjanency List.
    @param2 InputData : Film ve aktör isimlerinin bulunduğu yapı. 
    @param3 long long : Bağlantısı ekrana yazdırılacak actör Id'si.
*/
void printBFSPath(AdjList *,InputData,long long);

int main(){
    InputData *inputData = (InputData *)malloc(sizeof(InputData));//Film ve Aktör isimlerini tutan değişken.
    AdjList *adjList;//Adjacency List bilgisini tutan değişken.
    inputData->actors = createHashMap();
    inputData->movies = createHashMap();
    adjList = readMovieInputs("movies/input-3.txt",inputData);
    runBFS(adjList,*inputData,-1,12);
    countAndPrintDistances(adjList->distances,inputData->actors->count);
    readActorInput("actor-input.txt",adjList,inputData);
    return 0;
}

/*--------------------------HashMap Funcs-----------------------*/
HashMap *createHashMap(){
    HashMap *hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->count = 0;
    hashMap->wordList = (WordList**)malloc(sizeof(WordList*)*HASH_MAP_SIZE);
    hashMap->wordArr = (char**)malloc(sizeof(char*)*ADJ_LIST_SIZE);
    for(int i = 0;i < HASH_MAP_SIZE;i++){
        hashMap->wordList[i] = 0;
    }
    return hashMap;
}

char addToHashMap(HashMap *hashMap,char *str){
    if(searchInHashMap(*hashMap,str) != -1)
        return 0;
    unsigned long hash = getHashOfString(str);//Eklenecek stringin hash değeri.
    WordList *tmp = (WordList *)malloc(sizeof(WordList));//Eklenecek kelimenin linkli list parçası. 
    tmp->next = 0;
    tmp->word = (char*)malloc(sizeof(char)*STR_SIZE);
    strcpy(tmp->word,str);
    tmp->id = hashMap->count;
    hashMap->wordArr[hashMap->count] = tmp->word;
    hashMap->count++;  
    if(hashMap->wordList[hash] == 0){
        hashMap->wordList[hash] = tmp;
    }
    else{
        tmp->next = hashMap->wordList[hash];
        hashMap->wordList[hash] = tmp;            
    }
    return 1;
}

long long searchInHashMap(HashMap hashMap,char *str){
    unsigned long hash = getHashOfString(str);//Aranacak kelimenin hash değeri.
    WordList *root = hashMap.wordList[hash];//Asıl HashMap'i bozmamak için kullanılan geçici pointer.
    while(root != 0 && strcmp(str,root->word) != 0)
        root = root->next;
    return (root == 0) ? -1 : root->id;
}

unsigned long getHashOfString(char *str){
    //Bu fonksiyon çakışmanın çok az olduğu hashler üretiyor ve nedeni tam olarak bilinmiyor.
    unsigned long hash = 5381;//Hash hesaplamasında kullanılacak başlangıç değeri.
    for(int i = 0;i < strlen(str);i++)
        hash = ((hash << 5)+hash)+str[i];
    return hash%HASH_MAP_SIZE;
}
/*-------------------------AdjList Funcs---------------------------*/
AdjList* createAdjList(){
    AdjList *adjList = (AdjList*)malloc(sizeof(AdjList));
    adjList->distances = (long long *)malloc(sizeof(long long)*ADJ_LIST_SIZE);
    adjList->parents = (long long *)malloc(sizeof(long long)*ADJ_LIST_SIZE);
    adjList->movies = (long long *)malloc(sizeof(long long)*ADJ_LIST_SIZE);
    adjList->node = (Node**)malloc(sizeof(Node*)*ADJ_LIST_SIZE);
    for(unsigned long i = 0;i < ADJ_LIST_SIZE;i++){        
        adjList->distances[i] = ADJ_LIST_SIZE;
        adjList->parents[i] = -1;
        adjList->movies[i] = -1;
        adjList->node[i] = 0;
    }
    return adjList;
}
void addToAdjList(AdjList *adjList,unsigned long movieId,unsigned long *actorList,unsigned long actorCount){
    Node *tmpNode;//Adjacency List ' e eklenecek yeni elemanı tutan geçici değişken.
    for(unsigned long i = 0;i < actorCount;i++){
        for(unsigned long j = 0;j < actorCount;j++){
            if(i != j){
                tmpNode = (Node *)malloc(sizeof(Node));
                tmpNode->actorId = actorList[j];
                tmpNode->movieId = movieId;
                tmpNode->next = 0;
                if(adjList->node[actorList[i]] == 0)
                    adjList->node[actorList[i]] = tmpNode;
                else{
                    tmpNode->next = adjList->node[actorList[i]];
                    adjList->node[actorList[i]] = tmpNode;
                }
            }
        }
    }
}
/*----------------------------Inputs Funcs-----------------------------*/
AdjList* readMovieInputs(char *filename,InputData *inputData){
    AdjList *adjList = createAdjList();//Bağlantıların oluşturulacağı Adjacency List
    unsigned long actorSize;//Aynı filmde bulunan aktörlerin sayısını tutan değişken.
    unsigned long *actorInMovie = (unsigned long *)malloc(sizeof(unsigned long)*256);//aynı filimde bulunan aktör idleri listesi.
    int bufferLen;//Dosyadan okunan satırın uzunluğunu tekrar tekrar strlen ile hesaplamamk için oluşturulmuştur.
    int offset;//GetStringUntil() fonksiyonunda bölünmenin yapıldığı stringin nerde kaldığı bilgisini takip etmek için kullanılan değişken.
    static char buffer[LINE_SIZE];//Okunan satırı tutan string
    char *tmpName;//Geçici aktör ismi.
    char *tmpSurname;//Geçici aktör soyismi
    FILE *inputFile = fopen(filename,"r");//Okumanın yapılacağı dosya.
    while(fgets(buffer,LINE_SIZE,inputFile)){
        bufferLen = strlen(buffer);
        offset = 0;    
        addToHashMap(inputData->movies,getStringUntil(buffer,'/',&offset,bufferLen));
        actorSize = 0;
        while(offset < bufferLen){
            tmpSurname = getStringUntil(buffer,',',&offset,bufferLen);
            free(getStringUntil(buffer,' ',&offset,bufferLen));
            tmpName = getStringUntil(buffer,'/',&offset,bufferLen);
            strcat(tmpName," ");
            strcat(tmpName,tmpSurname);
            free(tmpSurname); 
            if(!addToHashMap(inputData->actors,tmpName)){
                actorInMovie[actorSize] = searchInHashMap(*(inputData->actors),tmpName);
                free(tmpName);
            }else{
                actorInMovie[actorSize] = (inputData->actors->count)-1;
            }
            actorSize++;
        }
        addToAdjList(adjList,inputData->movies->count-1,actorInMovie,actorSize);
    }
    fclose(inputFile);
    free(actorInMovie);
    printf("Movie Inputs File : %s\n",filename);
    printf("Actor Count : %llu Movie Count : %llu\n",inputData->actors->count,inputData->movies->count);
    return adjList;
}
void readActorInput(char *filename,AdjList *adjList,InputData *inputData){
    FILE *inputFile = fopen(filename,"r");//Okumanın yapılacağı dosya
    static char actorName[STR_SIZE]; //Aktör ismini tutan değişken
    long long actorId;//Aktör Id'sini tutan değişken.
    
    while(fgets(actorName,LINE_SIZE,inputFile)){
        printf("\n---------------------------------------\n");
        actorName[strlen(actorName)-1] = '\0';// yeni satır okumasını engellmek için eklendi
        actorId = searchInHashMap(*(inputData->actors),actorName);
        if(actorId == -1)
            printf("%s isn't in hashMap\n",actorName);
        else{
            if(adjList->parents[actorId] != -1)
                printf("%s Finded Before \n",actorName);
            else
                runBFS(adjList,*inputData,actorId,ADJ_LIST_SIZE);
            printBFSPath(adjList,*inputData,actorId);    
        }
        printf("---------------------------------------\n");
    }
    
    fclose(inputFile);
}
/*----------------------------------String Funcs----------------------------------*/
char * getStringUntil(char *str,char destChar,int *offset,int size){
    char* data = (char*)malloc(STR_SIZE*sizeof(char));//Geriye döndürülecek yeni oluşan string.
    int dataIndex = 0;//Oluşturulan string için kullanılacak index değişkeni.
    while(*offset < size){
        if(str[*offset] == destChar){
            data[dataIndex] = '\0';
            (*offset)++;
            return data;
        }
        else{
            data[dataIndex] = str[*offset];
            dataIndex++;
        }
        (*offset)++;
    }
    data[dataIndex-1] = '\0';
    return data;
}
/*---------------------------BFS Funcs----------------------------------------*/
void countAndPrintDistances(long long *distances,long long distanceArrSize){
    int DISTANCE_MAX = 12;//Raporda uzaklıkların 12 ye kadar yazdırılması istenmiş.Bu değer onun için oluşturuldu.
    long long counts[DISTANCE_MAX];//Her uzaklıktan kaç adet olduğu bilgisini tutan dizi.
    long long count = 0;//Toplam hesaplanan uzaklık sayısını tutar.
    for(int i = 0;i < DISTANCE_MAX;i++) counts[i] = 0;
    for(long long i = 0;i < distanceArrSize;i++){
        if(distances[i] >= 0 && distances[i] < DISTANCE_MAX){
            count++;
            counts[distances[i]]++;
        }
    }
    for(int i = 0;i < DISTANCE_MAX;i++){
        if(counts[i] > 0)
            printf("Distance : %d , Count : %lld \n",i,counts[i]);
    }
    printf("Distance : INFINITE Count : %lld\n",distanceArrSize-count);
}
void runBFS(AdjList *adjList,InputData inputData,unsigned long targetId,long long stopDistance){
    Node *cNode;//Gezinme sırasında kullanılacak aktif Node bilgisini tutan değer.
    long long maxDistance = -1;//Gezinme srasında durma anı için uzaklığı tutan değer.
    long long queueStart = 0;//Kuyruğun başlangıç indexi
    long long queueEnd = 0;//Kuyruğun bitiş indexi
    long long currentIndex;//Kuyruktan alınan aktör Id'sini tutar.
    long long *queue = (long long *)malloc(sizeof(long long)*ADJ_LIST_SIZE);//Kuyruk dizisi.
    char *visited = (char *)malloc(sizeof(char)*ADJ_LIST_SIZE);//Aktörün daha önce ziyaret edilip edilmediği bilgisini tutan dizi.
    char *addedToQueue = (char *)malloc(sizeof(char)*ADJ_LIST_SIZE);//Aktörün kuyruğa daha önce eklenip eklenmediği bilgisini tutan dizi.
    for(long long i = 0;i < ADJ_LIST_SIZE;i++){
        visited[i] = 0;
        addedToQueue[i] = 0;
    }
    currentIndex = queue[queueEnd] = searchInHashMap(*(inputData.actors),"Kevin Bacon");    
    queueEnd++;
    adjList->distances[currentIndex] = 0;
    while(queueStart < queueEnd && targetId != currentIndex && maxDistance < stopDistance){
        currentIndex = queue[queueStart];
        queueStart++;
        visited[currentIndex] = 1;
        cNode = adjList->node[currentIndex];
        while(cNode != 0){
            if(!visited[cNode->actorId] && !addedToQueue[cNode->actorId]){  
                queue[queueEnd] = cNode->actorId;
                adjList->parents[cNode->actorId] = currentIndex;
                adjList->distances[cNode->actorId] = adjList->distances[adjList->parents[cNode->actorId]]+1;
                maxDistance = adjList->distances[cNode->actorId];
                adjList->movies[cNode->actorId] = cNode->movieId;
                addedToQueue[cNode->actorId] = 1;
                queueEnd++;        
            }
            cNode = cNode->next;
        }
    }
    free(queue);free(visited);free(addedToQueue);    
}

void printBFSPath(AdjList *adjList,InputData inputData,long long target){
    if(adjList->parents[target] == -1)
        printf("%s's Kevin Bacon number is INFINITE",inputData.actors->wordArr[target]);
    else{
        printf("%s's Kevin Bacon number is %lld\n",inputData.actors->wordArr[target],adjList->distances[target]);
        while(adjList->parents[target] != -1){
            printf("%s-%s ",inputData.actors->wordArr[target],inputData.actors->wordArr[adjList->parents[target]]);
            printf(" : %s \n",inputData.movies->wordArr[adjList->movies[target]]);
            target = adjList->parents[target]; 
        }
    }                                
}