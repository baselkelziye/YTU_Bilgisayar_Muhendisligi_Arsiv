#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MIN_HASH_COUNT 100//Min hash algoritmasında kullanılacak hash sayısı
#define HASH_MAP_SIZE 10000//Hash map boyutu
#define SHINGLE_SIZE 1000//shingle sayısı

typedef struct ShingleList ShingleList;//shingle ların tutulduğu hash map 
typedef struct WordList WordList;//Kelime linkli listesi
typedef struct HashMap HashMap;//Hash map yapısı

struct ShingleList{
    int typeSize;//4,5,6,7,8
    HashMap *shingleHash;//Shingle ların tutulacağı hash tablosu
};
struct WordList{
    long long id;//kelime id si
    char *word;//kelime
    WordList *next;//sıradaki kelimenin adresi
};
struct HashMap{
    char **wordArr;//Random access için eklendi yolu id'si verilen kelimeye direk ulaşmak için kullanılcak.
    WordList **wordList;//Her hash için kelime listesinin bulunduğu liste.
    unsigned long long count;//eklenen kelime sayısını tutar aynı zamanda yeni eklenen kelimenin id'si bu değer ile verilir.
};
/*SHINGLE LIST FUNCS*/

/*
    Shingle listesi yaratır.
    @param1 int : Shingle boyutu örnek:4,5,6...
    @return : Yeni oluşturulan boş shingle listesini döndürür.  
*/
ShingleList *createShingleList(int);
/*
    Verilen stringi shingle'larına ayırır ve shingle listesine ekler.
    @param1 ShingleList * : Shingleların ekleneceği shingle listesi.
    @param2 char* : Shinglelarına ayırılacak veri(dosya içeriği olabilir).
*/
void addToShingleList(ShingleList *,char *);
/*HASHMAP FUNCS*/
/*
    Hash Map yaratır.
    @return : Yeni oluşan hashMap döndürülür.
*/
HashMap *createHashMap();
/*
    Verilen stringi hash mapa ekler.
    @param1 HashMap * : Eklemenin yapılacağı hashMap.
    @param2 char* : HashMap'e eklenicek kelime.
    @return : Ekleme başarılı ise 1 değilse 0 döndürür.
*/
char addToHashMap(HashMap *,char *);
/*
    Hash Map üzerinde verilen kelime için arama yapar.
    @param1 HashMap : Aramanın yapılacağı HashMap.
    @param2 char * : HashMap üzerinde aranacak kelime.
    @return : Kelime HashMap'de var ise o kelimenin indisi(id) döndürür yok ise -1 döndürür.
*/
long long searchInHashMap(HashMap,char *);
/*
    Verilen kelimenin hash değerini döndürür.
    @param1 char * : Hash değeri bulunacak kelime. 
    @return : Kelime için bulunan hash değeri döndürülür.
*/
unsigned long getHashOfString(char *);
/*DATA I/O FUNCS*/
/*
    İsmi verilen dosyayı okur ve tüm içeriğini geri döndürür.
    @param1 char* : Okunacak dosyanın ismi.
    @return : Tamamı okunan dosyanın içeriği döndürülür.
*/
char* readDocFile(char *);
/*ALGORITHM-CALCULATION FUNCS*/
/*
    Jaccard matrisini hesaplar.
    @param1 ShingleList ** : Döküman shingle içeriklerinin bulunduğu shingleListe dizisi.
    @param2 int : Döküman sayısı,Shingle liste dizisinin boyutu.
    @return : Hesaplanan Jaccard matrisi
*/
float** calculateJaccard(ShingleList **,int);
/*
    Minhash benzerlik matrisini hesaplar ve geri döndürür.
    @param1 ShingleList ** : Döküman shingle içeriklerinin bulunduğu shingleListe dizisi.
    @param2 int : Döküman sayısı,Shingle liste dizisinin boyutu.
    @return : Hesaplanan MinHash benzerliği matrisi
*/
float** minHash(ShingleList **,int);
/*
    Verilen eşik değerini kullanarak bu eşik değerinden büyük benzerliğe sahip dosya indislerini ekrana yazdırır.
    @param1 float** : MinHash similarity matrisi.
    @param2 int : Matris boyutu(sütun sayısı = satır sayısı)
    @param3 float : Eşik değeri
*/
void printDocSimByRate(float **,int,float);
/*GENERAL FUNCS*/
/*
    Matrisi ekrana düzenli bir şekilde yazdırır.
    @param1 float** : Ekrana yazılacak matris
    @param2 int : Matrisin satır sayısı.
    @param3 int : Matrisin sütun sayısı. 
*/
void printMtr(float **,int,int);
int main(){
    int shingleType;//shingle boyutu 4,5,6,7,8 ..
    int docCount;//Döküman sayısı
    char filename[128];//Dosya ismi 1.txt,2.txt ...
    char *doc;//Okunan dosyanın içeriği
    float **jaccardMtr;//Jaccard matrisi
    float **minHashMtr;//minHash similarity matrisi
    float rate;//Kullanıcıdan okunacak eşik değeri
    srand(time(0));
    printf("Document Count : ");
    scanf("%d",&docCount);
    printf("ShingleType : ");
    scanf("%d",&shingleType);
    
    ShingleList *sL[docCount];//döküman shinglelarının tutulacağı shingle listesi dizisi 
    printf("------------------------%d-Shingle Counts------------------------\n",shingleType);
    for(int i = 0;i < docCount;i++){
        sprintf(filename,"datas/%d.txt",i+1);
        doc = readDocFile(filename);
        sL[i] = createShingleList(shingleType);
        addToShingleList(sL[i],doc);
        printf("%d.Doc %lld\n",(i+1),sL[i]->shingleHash->count);
    }
    
    printf("---------------------------JACCARD MTR---------------------------\n");
    jaccardMtr = calculateJaccard(sL,docCount);
    printMtr(jaccardMtr,docCount,docCount);
    
    printf("---------------------------MIN HASH--------------------------------\n");
    minHashMtr = minHash(sL,docCount);
    printMtr(minHashMtr,docCount,docCount);

    while(1){
        printf("Threshold : ");
        scanf("%f",&rate);
        printDocSimByRate(minHashMtr,docCount,rate);
    }
    return 0;
}
/*SHINGLE LIST FUNCS*/
ShingleList *createShingleList(int typeSize){
    ShingleList *shingleList = (ShingleList*)malloc(sizeof(ShingleList));//Yeni oluşturulacak shingle listesi
    shingleList->typeSize = typeSize;
    shingleList->shingleHash = createHashMap();
    return shingleList;
}
void addToShingleList(ShingleList *sL,char *data){
    unsigned int shingleIndex;//Dosya(data) dan çıkartılacak shingle indisi
    unsigned int dataIndex;//Dosya(data) indisi
    unsigned int dataSize = strlen(data);//Dosya(data) boyutu
    char *shingle;//Oluşturulacak shingle
    int spaceCount = 0;
    for(unsigned int i = 0;i < dataSize-sL->typeSize;i++){
        shingle = malloc(sL->typeSize+1);
        shingleIndex = 0;
        dataIndex = i;
        while(shingleIndex < sL->typeSize && dataIndex < dataSize){
            data[dataIndex] = tolower(data[dataIndex]);
            if(data[dataIndex] == ' ')
                spaceCount++;
            else 
                spaceCount = 0;

            if((data[dataIndex] <= 'z' && data[dataIndex] >= 'a') || (data[dataIndex] == ' ' && spaceCount < 2)){
                    shingle[shingleIndex] = data[dataIndex];
                    shingleIndex++;
                }
            dataIndex++;
        }
        if(shingleIndex == sL->typeSize){
            shingle[sL->typeSize] = '\0';
            addToHashMap(sL->shingleHash,shingle);
        }
        else
            free(shingle);
    }
}
/*HASHMAP FUNCS*/
HashMap *createHashMap(){
    HashMap *hashMap = (HashMap*)malloc(sizeof(HashMap));//Yeni oluşturulan HashMap
    hashMap->count = 0;
    hashMap->wordList = (WordList**)malloc(sizeof(WordList*)*HASH_MAP_SIZE);
    hashMap->wordArr = (char**)malloc(sizeof(char*)*SHINGLE_SIZE);
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
    tmp->word = str;
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
/*DATA I/O FUNCS*/
char* readDocFile(char *filename){
    char *chunk;//Dosyanın tüm içeriğini tutacak değişken
    unsigned long int fileSize;//Dosya boyutu
    FILE *dataFile = fopen(filename,"r");
    fseek(dataFile,0,SEEK_END);
    fileSize = ftell(dataFile);
    chunk = (char*)malloc(fileSize+1);  
    fseek(dataFile,0,SEEK_SET);
    fread(chunk,fileSize,1,dataFile);
    chunk[fileSize] = '\0';
    fclose(dataFile);
    return chunk;
}
/*ALGORITHM-CALCULATION FUNCS*/
float ** calculateJaccard(ShingleList **sL,int listCount){
    float **jaccardMtr = (float**)malloc(sizeof(float*)*listCount);//Hesaplanacak jaccard matrisini tutacak değişken
    int intersectionCount = 0;//İki kümenin çakışma sayısını(ortak küme eleman sayısı) tutan değer
    for(int i = 0;i < listCount;i++){
        jaccardMtr[i] = (float*)malloc(sizeof(float)*listCount);
        jaccardMtr[i][i] = 1.0f;
    }

    for(int i = 0;i < listCount;i++){
        for(int j = i+1;j < listCount;j++){
            intersectionCount = 0;
            for(int si = 0;si < sL[j]->shingleHash->count;si++){
                if(searchInHashMap(*(sL[i]->shingleHash),sL[j]->shingleHash->wordArr[si]) != -1)
                    intersectionCount++;
            }
            jaccardMtr[i][j] = jaccardMtr[j][i] = (float)intersectionCount/(sL[i]->shingleHash->count+sL[j]->shingleHash->count-intersectionCount);
        }
    }
    return jaccardMtr;
}

float** minHash(ShingleList **sL,int listCount){
    ShingleList *unionSL = createShingleList(sL[0]->typeSize);//Tüm shingleların birleşimini tutan shingle listesi
    char **booleanMtr;//Min hash hesaplaması öncesi oluşturulacak shingle benzerliğini tutan matris 
    float **simMtr;//Min hash sonucu oluşan, döküman benzerlik oranlarını tutan matris 
    int intersectionCount;//Küme ortak eleman sayısını tutan değişken
    int minHashMtr[MIN_HASH_COUNT][listCount];//Hash uygulanması sonrası oluşan değerleri tutan matris
    int A;//Her hash fonksiyonu için kullanılacak rastgele A değeri
    int M;//Hash fonksiyonu için kullanılacak boyut değeri(Union Shingle sayısı)
    int hashVal;//Her adımda hesaplanan hash değerini tutan değişken
    memset(minHashMtr,0,sizeof(int)*MIN_HASH_COUNT*listCount);
    //SET UNION SHINGLELIST
    for(int i = 0;i < listCount;i++)
        for(int j = 0;j < sL[i]->shingleHash->count;j++)
            addToHashMap(unionSL->shingleHash,sL[i]->shingleHash->wordArr[j]);
    //CREATE BOOLEAN MTR
    booleanMtr = (char**)malloc(sizeof(char*)*unionSL->shingleHash->count);
    for(int i = 0;i < unionSL->shingleHash->count;i++){
        booleanMtr[i] = (char*)malloc(listCount);
        for(int j = 0;j < listCount;j++){
            booleanMtr[i][j] = (searchInHashMap(*(sL[j]->shingleHash),unionSL->shingleHash->wordArr[i]) != -1) ? 1 : 0;     
        }
    }
    //NOW FIND MINHASH MTR
    M = unionSL->shingleHash->count;
    /*
    printf("M : %d\n",M);
    for(int i = 0;i < M;i++)
        printf("%s\n",unionSL->shingleHash->wordArr[i]);
    */
    for(int h = 0;h < MIN_HASH_COUNT;h++){
        A = rand()%M;
        while(A == 0 || M%A == 0)
            A = (A+1)%M;
        for(int r = 1;r <= M;r++){
            hashVal = (r*A+1)%M;
            for(int c = 0;c < listCount;c++){
                if(booleanMtr[hashVal][c] == 1 && minHashMtr[h][c] == 0)
                    minHashMtr[h][c] = r;    
            }
        }
    }
    //NOW CALCULATE SIMILARITY MATRIX
    simMtr = (float**)malloc(sizeof(float*)*listCount);
    for(int i = 0;i < listCount;i++){
        simMtr[i] = (float*)malloc(sizeof(float)*listCount);
        simMtr[i][i] = 1.0f;
    }
    for(int doc1 = 0;doc1 < listCount;doc1++){
        for(int doc2 = doc1+1;doc2 < listCount;doc2++){
            intersectionCount = 0;
            for(int hc = 0;hc < MIN_HASH_COUNT;hc++){
                if(minHashMtr[hc][doc1] == minHashMtr[hc][doc2])
                    intersectionCount++;  
            }
            simMtr[doc2][doc1] = simMtr[doc1][doc2] = (float)intersectionCount/(2*MIN_HASH_COUNT-intersectionCount);
        }
    }
    free(unionSL);
    return simMtr;
}
void printDocSimByRate(float **minHashSimMtr,int mtrSize,float rate){
    for(int i = 0;i < mtrSize;i++){
        for(int j = i+1;j < mtrSize;j++){
            if(minHashSimMtr[i][j] > rate)
                printf("%d - %d : %.2f\n",(i+1),(j+1),minHashSimMtr[i][j]);
        }
    }

}
/*GENERAL FUNCS*/
void printMtr(float **mtr,int x,int y){
    printf("    ");
    for(int i = 0;i < x;i++)
        printf(" %-5d",i+1);
    printf("\n");
    for(int i = 0;i < x;i++){
        printf(" %-3d",i+1);
        for(int j = 0;j < y;j++){
            printf(" %.2f ",mtr[i][j]);
        }
        printf("\n");
    }
}