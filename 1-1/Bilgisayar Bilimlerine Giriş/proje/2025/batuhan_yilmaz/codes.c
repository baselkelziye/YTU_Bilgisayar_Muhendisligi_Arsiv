#include <stdio.h>
#include <stdlib.h>

char rastgele_olusum();
void yazdirma(char oyun_alani[20][20], int N, int M);

int main(){
    srand(42); /*Hayatın, evrenin ve her şeyin anlamı.*/
    int secim = 0;
    int i,j,k;
    int N,M,tempN,tempM; 
    char oyun_alani[20][20];
    int oyun_modu;
    int D1X,D1Y,D2X,D2Y;
    int PX,PY;
    int ust_satir;
    int yer_degisikligi = 0;
    int patlatma_sayisi = 0;

    printf("--------Panel De Pon Oyununa Hosgeldiniz--------\n ");

    do{
    printf("Matris boyutlarini giriniz: \n");
    printf("Satir sayisi(En fazla 20): ");
    scanf("%d",&N);
    printf("Sutun sayisi(En fazla 20): ");
    scanf("%d",&M);

    if(N<3 || N>20 || M<3 || M>20){
        printf("Hatali matris boyutu girisi lutfen tekrar giris yapin.\n");}
    }while(N<3 || N>20 || M<3 || M>20);

    ust_satir = N/2;
    printf("Oyun modunu seciniz: \n 1-Oyun Modu \n 2-Kontrol Modu\n");
        scanf("%d",&oyun_modu);


    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            oyun_alani[i][j] = '.';
        }
    }

    if(oyun_modu == 1){
        for(i=N-1; i>=(N/2); i--){
            for(j=0; j<M; j++){
                oyun_alani[i][j] = rastgele_olusum();
            }
        }

    }
    else if(oyun_modu == 2){
        for(i=N-1; i>=(N/2); i--){
            for(j=0; j<M; j++){
                char temp_char;
                int dogru = 0;
                do {
                    printf("Oyun alaninin %d. satir %d. sutun elemanini giriniz: ",i - (N/2) + 1,j + 1);
                    scanf(" %c",&temp_char);
                    if (temp_char == '0' || temp_char == '*' || temp_char == '/' || temp_char == '+' || temp_char == '%') {
                        dogru = 1;
                        oyun_alani[i][j] = temp_char;
                    } else {
                        printf("Hatali giris! Lutfen gecerli karakterlerden birini giriniz (0, *, /, +, %%).\n");
                    }
                } while (dogru == 0);
            }
        }
        yazdirma(oyun_alani,N,M);

    }else{
        printf("Hatali oyun modu secimi yaptiniz.\n");
    }

    if(oyun_modu == 1 || oyun_modu == 2){
        while(secim != 3 && ust_satir != 0){


            if(oyun_modu == 1) {
                        for(k=0; k<50; k++) printf("\n"); 
                        yazdirma(oyun_alani,N,M); 
            }
            printf("Yer degisikligi: %d\n",yer_degisikligi);
            printf("Patlatma sayisi: %d\n",patlatma_sayisi);
            
            printf("Giris Yapiniz:\nYer degisikligi icin 1\n Patlatma icin 2\nCikis icin 3\n");
            scanf("%d",&secim);
            if(secim == 1){
                printf("Yer degistirmek istediğiniz ilk nesnenin satir numarasini girin: ");
                scanf("%d",&D1X);
                printf("Yer degistirmek istediğiniz ilk nesnenin sutun numarasini girin: ");
                scanf("%d",&D1Y);
                printf("Yer degistirmek istediğiniz ikinci nesnenin satir numarasini girin: ");
                scanf("%d",&D2X);
                printf("Yer degistirmek istediğiniz ikinci nesnenin sutun numarasini girin: ");
                scanf("%d",&D2Y);
                /*Yer degisikligi islemi*/
                if(oyun_alani[D1X-1][D1Y-1] == '.' || oyun_alani[D2X-1][D2Y-1] == '.'){
                    printf("Bosluk ile yer degisikligi yapilamaz!\n");
                } else {
                    char temp = oyun_alani[D1X-1][D1Y-1];
                    oyun_alani[D1X-1][D1Y-1] = oyun_alani[D2X-1][D2Y-1];
                    oyun_alani[D2X-1][D2Y-1] = temp;

                    int satir_kontrol = 0;
                    for(j=0; j<M; j++){
                        if(oyun_alani[ust_satir][j] == '.'){
                            satir_kontrol = satir_kontrol + 1;
                        }
                    }
                    if(satir_kontrol == M){
                        ust_satir = ust_satir + 1;
                    }else{
                        ust_satir = ust_satir - 1;
                    }
                

                    for(i=ust_satir; i<N; i++){
                    for(j=0; j<M; j++){
                        oyun_alani[i-1][j] = oyun_alani[i][j];
                        }
                    }

                    for(j=0; j<M; j++){
                        oyun_alani[N-1][j] = rastgele_olusum();
                    }
                   /* yazdirma(oyun_alani,N,M);*/
                    yer_degisikligi = yer_degisikligi + 1;
                    printf("Yer degisikligi: %d\n",yer_degisikligi);
                    printf("Patlatma sayisi: %d\n",patlatma_sayisi);
                }
                
            }else if(secim == 2){
                printf("Patlatmak istediginiz grubun satir numarasini girin: ");
                scanf("%d",&PX);
                printf("Patlatmak istediginiz grubun sutun numarasini girin: ");
                scanf("%d",&PY);

                
                if(oyun_alani[PX-1][PY-1] == '.'){
                    printf("Bosluk patlatilamaz!\n");
                } else {
                    /*Patlatma yonunun secilmesi*/
                    char patlatma_karakter = oyun_alani[PX-1][PY-1];
                    
                    int yatay_say = 1;
                    for(j = PY-2; j >= 0 && oyun_alani[PX-1][j] == patlatma_karakter; j--){
                        yatay_say++;
                    }
                    for(j = PY; j < M && oyun_alani[PX-1][j] == patlatma_karakter; j++){
                        yatay_say++;
                    }
                    
                    int dikey_say = 1;
                    for(i = PX-2; i >= 0 && oyun_alani[i][PY-1] == patlatma_karakter; i--){
                        dikey_say++;
                    }
                    for(i = PX; i < N && oyun_alani[i][PY-1] == patlatma_karakter; i++){
                        dikey_say++;
                    }
                    
                    if(yatay_say >= 3 || dikey_say >= 3){
                        if(yatay_say >= dikey_say){
                            oyun_alani[PX-1][PY-1] = '.';
                            for(j = PY-2; j >= 0 && oyun_alani[PX-1][j] == patlatma_karakter; j--){
                                oyun_alani[PX-1][j] = '.';
                            }
                            for(j = PY; j < M && oyun_alani[PX-1][j] == patlatma_karakter; j++){
                                oyun_alani[PX-1][j] = '.';
                            }
                            patlatma_sayisi = patlatma_sayisi + yatay_say;
                        } else {
                            oyun_alani[PX-1][PY-1] = '.';
                            for(i = PX-2; i >= 0 && oyun_alani[i][PY-1] == patlatma_karakter; i--){
                                oyun_alani[i][PY-1] = '.';
                            }
                            for(i = PX; i < N && oyun_alani[i][PY-1] == patlatma_karakter; i++){
                                oyun_alani[i][PY-1] = '.';
                            }
                            patlatma_sayisi = patlatma_sayisi + dikey_say;
                        }
                        /*Yercekimi mekanigi*/
                        int oku;
                        int kalan;
                        for(j = 0; j < M; j++){
                            int yaz = N - 1;
                            for(oku = N - 1; oku >= 0; oku--){
                                if(oyun_alani[oku][j] != '.'){
                                    oyun_alani[yaz][j] = oyun_alani[oku][j];
                                    if(yaz != oku){
                                        oyun_alani[oku][j] = '.';
                                    }
                                    yaz--;
                                }
                            }
                            for(kalan = yaz; kalan >= 0; kalan--){
                                oyun_alani[kalan][j] = '.';
                            }
                        }
                        
                    } else {
                        printf("Bu koordinatta en az 3 ayni tas arka arka degil!\n");
                    }
                }
            }

        
            
        }


            if(secim == 3){
                printf("Oyun bitti. Tesekkurler!\n");}
            if(ust_satir == 0){
                printf("Oyun alani doldu. Oyun bitti!\n");}
    }




    return 0;
}


char rastgele_olusum(){
    char karakter;
    int rastgele = rand() % 5;
    if(rastgele == 0){
        karakter = '0';
    }else if(rastgele == 1){
        karakter = '*';}
    else if(rastgele == 2){
        karakter = '/';
    }else if (rastgele == 3)
    {
        karakter = '+';
    }else if(rastgele == 4){
        karakter = '%';
    }

    return karakter;
}

void yazdirma(char oyun_alani[20][20], int N, int M){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%c ",oyun_alani[i][j]);
        }
        printf("\n");
    }
}


    
