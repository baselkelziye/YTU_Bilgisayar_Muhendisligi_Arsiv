#include <stdio.h>
#include <stdlib.h>

typedef struct conflict{
    int other;
    struct conflict* next;
} CONF;

void backtracking(int** S, int N, int server, int activeRacks, CONF** conflicts, float K, int C, int* found);
int checkAllRacksHeat(int** S, int N, int activeRacks, float K);
int canPlace(int** S, int N, int server, int rack, int C, CONF** conflicts);
int totalPower(int** S, int N, int rack);
int hasConflict(int** S, int N, int server, int rack, CONF** conflicts);
CONF* createConflict(int index);
void addConflict(CONF** conflicts,int i,int j);
void printSolution(int** S,int N);

int main() {
    int i, j;
    int N; //server
    int C;
    float K;
    int conflictLoop=1;
    int found=0;

    printf("Sunucu sayisini girin : ");
    scanf("%d", &N);

    // S[][0]=P		S[][1]=H		S[][2]=rack
    int** S = (int**)malloc(N*sizeof(int*));
    for (i=0; i<N ;i++) {
        S[i] = (int*)malloc(3*sizeof(int));
        for (j = 0; j < 2; j++) {
            if (j==0){
                printf("\n%d. sunucunun guc degerini girin(P) : ",i+1);
            } else {
                printf("%d. sunucunun isi degerini girin(H) : ",i+1);
            }
            scanf("%d", &S[i][j]);
        }
        S[i][2] = -1; //rack=-1
    }

    printf("\nSogutma verimliligi esigi (K) degerini girin : ");
    scanf("%f", &K);
    printf("Kabin max guc kapasite (C) degerini girin : ");
    scanf("%d", &C);

    CONF** conflicts = (CONF**)calloc(N, sizeof(CONF*)); //adjacency list

    while (conflictLoop) {
        printf("\nYeni conflict var mi? (EVET-1 / HAYIR-0): ");
        scanf("%d", &conflictLoop);
        if (conflictLoop > 0) {
            printf("1.sunucu no : ");
            scanf("%d", &i);
            printf("2.sunucu no : ");
            scanf("%d", &j);
            addConflict(conflicts,i-1,j-1);
        }
    }

    printf("\n--- Hesaplama Basliyor ---\n");
    
    backtracking(S, N, 0, 1, conflicts, K, C, &found);//server=0  rack=1 (initialize)

    if (!found) {
        printf("\nCozum bulunamadi");
    }

    //memory free
    for (i = 0; i < N; i++) {
        CONF* curr = conflicts[i];
        while (curr != NULL) {
            CONF* temp = curr;
            curr = curr->next;
            free(temp);
        }
        free(S[i]);
    }
    free(conflicts);
    free(S);
    return 0;
}

/*
@brief Sunuculari kabinlere yerlestirmek icin recursive backtracking islemini gerceklestirir.
@param S Sunucu verilerini tutan matris
@param N Toplam sunucu sayisi
@param server O an yerlestirilmeye calisilan sunucunun indexi
@param activeRacks Su ana kadar acilmis kabin sayisi
@param conflicts Sunucular arasi cakisma kisitlarini tutan linkli liste dizisi
@param K Sogutma verimlilik esigi
@param C Kabin maksimum guc kapasitesi
@param found Cozum bulundugunda isaretlenen degisken
@return
*/
void backtracking(int** S, int N, int server, int activeRacks, CONF** conflicts, float K, int C, int* found){
    if (*found) return;
    
    int r,nextActiveRacks;
    
    //heat control
    if (server == N){
        if (checkAllRacksHeat(S,N,activeRacks,K)){
            *found=1;
            printSolution(S,N);
        }
        return;
    }

    for (r=0; r<activeRacks+1 ;r++){
        
        if (canPlace(S, N, server, r, C, conflicts)) {
            
            S[server][2]=r;
            
            nextActiveRacks= (r==activeRacks) ? activeRacks+1 : activeRacks;
            
            backtracking(S,N,server+1,nextActiveRacks,conflicts,K,C,found);//next server
            
            if (*found) return;
            
            S[server][2] = -1; //undo
        }
    }
}

/*
@brief Bir sunucunun, belirtilen kabine guc ve cakisma kisitlarina gore yerlestirilip yerlestirilemeyecegini kontrol eder.
@param S Sunucu verilerini tutan matris
@param N Toplam sunucu sayisi
@param server Yerlestirilmek istenen sunucunun indisi
@param rack Hedef kabin numarasi
@param C Kabin maksimum guc kapasitesi
@param conflicts Cakisma listesi
@return sunucu o kabine yerlesebiliyorsa 1, yerlesemiyorsa 0
*/
int canPlace(int** S, int N, int server, int rack, int C, CONF** conflicts) {
    //power<=C
    int currentRackPower=totalPower(S,N,rack);
    if (currentRackPower + S[server][0] > C){
        return 0;
    }

    //conflict
    if (hasConflict(S, N, server, rack, conflicts)){
        return 0;
    }
    return 1;
}

/*
@brief Tum sunucular yerlestirildikten sonra tum kabinlerin isi kisitini saglayip saglamadigini kontrol eder.
@param S Sunucu verilerini ve yerlesim bilgilerini tutan matris
@param N Toplam sunucu sayisi
@param activeRacks Cozumde kullanilan toplam kabin sayisi
@param K Sogutma verimlilik esigi
@return isi kisiti saglaniyorsa 1, saglanmýyorsa 0
*/
int checkAllRacksHeat(int** S, int N, int activeRacks, float K){
    int i,r,count;
    int totalH,totalP;
    float ratio;
    
    for (r=0; r<activeRacks ;r++){
        totalP=0; totalH=0; count=0;
        
        for (i=0; i<N ;i++){
            if (S[i][2]==r){
                totalP+= S[i][0];
                totalH+= S[i][1];
                count++;
            }
        }
        
        if(count>0){
            ratio=(float)totalH / (float)totalP;
            if(ratio>K){
                return 0;
            }
        }
    }
    return 1;
}

/*
@brief Belirtilen kabindeki sunucularin toplam guc tuketimini hesaplar.
@param S Sunucu verilerini tutan matris
@param N Toplam sunucu sayisi
@param rack Guc hesabi yapilacak kabin numarasi
@return Kabindeki toplam guc degeri
*/
int totalPower(int** S, int N, int rack){
    int i,sum=0;
    for(i=0; i<N ;i++){
        if(S[i][2]==rack){
            sum += S[i][0];
        }
    }return sum;
}

/*
@brief Yerlestirilmek istenen sunucunun hedef kabindeki diger sunucularla herhangi bir cakismasi olup olmadigini kontrol eder.
@param S Sunucu verilerini tutan matris
@param N Toplam sunucu sayisi
@param server Kontrol edilen sunucu indisi
@param rack Hedef kabin numarasi
@param conflicts Cakismalarin tutuldugu linkli liste arrayi
@return kabin icinde cakisma yaratan baska bir sunucu varsa 1, yoksa 0
*/
int hasConflict(int** S, int N, int server, int rack, CONF** conflicts){
    int otherServer;
	CONF* conf=conflicts[server];
    while(conf!=NULL){
        otherServer=conf->other;
        if (S[otherServer][2]==rack){
            return 1;
        }
        conf=conf->next;
    }
    return 0;
}

/*
@brief Yeni bir cakisma nodeu olusturur ve hafizada yer ayirir.
@param index Cakisma yasanan diger sunucunun indexi
@return Olusturulan cakisma nodeuna ait pointer
*/
CONF* createConflict(int index){
	CONF* n=(CONF*)malloc(sizeof(CONF));
	n->other=index;
	n->next=NULL;
	return n;
}

/*
@brief Iki sunucu arasinda karsilikli cakisma kisiti ekler ve adjacency listi gunceller.
@param conflicts Cakismalarin tutuldugu linkli liste arrayi
@param i Birinci sunucunun indexi
@param j Ikinci sunucunun indexi
*/
void addConflict(CONF** conflicts,int i,int j){
    CONF* node1=createConflict(j);
    node1->next=conflicts[i];
    conflicts[i]=node1;

    CONF* node2=createConflict(i);
    node2->next=conflicts[j];
    conflicts[j]=node2;
}

/*
@brief Algoritma sonucunda bulunan cozumun kabin iceriklerini ve hesaplanan guc/isi degerlerini ekrana yazdirir.
@param S Sunucu verilerini ve kabin yerlesimlerini tutan matris
@param N Toplam sunucu sayisi
*/
void printSolution(int** S,int N){
    int i,r;
    int maxRack = 0;
    
    for(i=0; i<N ;i++){
    	if(S[i][2] > maxRack)
			maxRack = S[i][2];
	}

    printf("\ncozum bulundu\n");
    for(r=0; r <= maxRack; r++){
        int p = 0, h = 0;
        printf("rack %d: ", r+1);
        for(i=0; i<N; i++){
            if(S[i][2] == r){
                printf("S%d ", i+1);
                p += S[i][0];
                h += S[i][1];
            }
        }printf("| Toplam P: %dW, Toplam H: %d, Ratio: %.2f\n", p, h, (float)h/p);
    }
}
