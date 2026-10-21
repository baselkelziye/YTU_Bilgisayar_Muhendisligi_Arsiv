/*------ kutuphaneler -------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


/*------ degiskenler -------*/
#define MAX_USERS 100

/*----------------------------- struct ---------------------------- */
struct kullaniciData{
    int kullaniciSayisi;
};

struct userInfo {
    char isim[50];
    char soyisim[50];
    char kullaniciAdi[50];
    char sifre[50];
    int skor;
    struct kullaniciData userData;
};

struct elementler{
    int artiP;
    int eksiP;
    int artiE;
    int eksiE;
};
/*----------------------------- Fonksiyonlar ---------------------------- */

void matrisyazdir(int row, int col, char **matris){
int i,j;
    // Matris iÃ§erigini ekrana yazdirma
    printf("\n\nlabirent:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf(" ___");
        }
        printf("\n");
        for (j = 0; j < col; j++) {
            printf("| %c ", matris[i][j]);
            if(j ==  col-1){
                printf("|");
            }
        }

        printf("\n");
    }
    printf("\n");
}




char** matrisOku(FILE *dosya, int row,int col){
int i,j;
    fgetc(dosya);
    
    char **matris = (char **) malloc (row+1 * sizeof(char *));
    for (i = 0; i < row; i++) {
        matris[i] = (char *)malloc(col +1 * sizeof(char));
        if (matris[i] == NULL) {
            perror("Bellek ayirma hatasi");
            // Daha Ã¶nce ayrilmis bellegi serbest birak
            for (j = 0; j < i; j++) {
                free(matris[j]);
            }
            free(matris);
            fclose(dosya);
            exit(1);
        }
    }

    // Dosyadan matrise okuma
    for ( i = 0; i < row; i++) {
        for ( j = 0; j < col; j++) {
            char karakter = fgetc(dosya);
            if (karakter == EOF) {
                // fprintf(stderr, "Dosya yeterince uzun degil.\n");
                // fclose(dosya);
                exit(1);
            }
            matris[i][j] = karakter;
        }
        // Satir sonundaki bosluk karakterini atla
        fgetc(dosya);
    }
    matrisyazdir(row, col, matris);
    return (matris);
}



int dosyadanOku(struct userInfo *kullainicbilgi) {

    FILE* data_dosya = fopen("kullanici_veritabani.txt", "r");
    if (data_dosya == NULL) {
        printf("Dosya acilamadi veya bulunamadi.\n");
        exit(1);
    }
    int kisi_sayisi=0;
    while(fscanf(data_dosya, "%s %s %d", kullainicbilgi[kisi_sayisi].kullaniciAdi, 
    kullainicbilgi[kisi_sayisi].sifre, &kullainicbilgi[kisi_sayisi].skor) == 3){
        kisi_sayisi++;
    }
    // simdi eski kullanici sayisini hesapladim ve struct icerisinde tuttugum kullanicisayisi degiskenine atadim
    // her program acilidiginda kullanici sayisi degiskeni eski userlarin sayisini tutacak
    kullainicbilgi->userData.kullaniciSayisi = kisi_sayisi;
    
    // Dosyayi kapat
    fclose(data_dosya);

    return(kisi_sayisi);
}



void dosyayaYaz(struct userInfo *kullanicibilgi) {
    FILE* data_dosya = fopen("kullanici_veritabani.txt", "a");
    if (data_dosya == NULL) {
        printf("Dosya acilamadi veya bulunamadi.\n");
        return;
    }

    fprintf(data_dosya, "%s %s 0",kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].kullaniciAdi,
    kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].sifre);
    kullanicibilgi->userData.kullaniciSayisi++;
    fclose(data_dosya);

    printf("Hesap olusturuldu.\n");

}




int kullaniciVarMi( struct userInfo *kullanicibilgi){
    int i;
    int konum;
    // Ayni kullanici adinin dosyada olup olmadigini kontrol et
    for ( i = 0; i < kullanicibilgi->userData.kullaniciSayisi -1 ; i++) {
        if (strcmp( kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].kullaniciAdi, kullanicibilgi[i].kullaniciAdi) == 0) {
            konum = i;
            return (konum); // kullanici ismi var 
        }
    }
    return 0; // kullanici ismi daha once kullanilmamis = bu isimle yeni hesap olusturabilir
}





int girisYap(struct userInfo *kullanicibilgi) {
    int i;
    int konum;
    for(i=0;i<kullanicibilgi->userData.kullaniciSayisi;i++){
        if(strcmp(kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].kullaniciAdi,kullanicibilgi[i].kullaniciAdi)==0 && 
        strcmp(kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].sifre,kullanicibilgi[i].sifre)==0 ){
            konum = i;
            return konum; // kullanici ismi ve sifre uyustu 
        }
    }
    return 0;
}




void enYuksekSkorlariYazdir(struct userInfo *kullanicibilgi) {
    struct userInfo siralikullanicilar[MAX_USERS];
    int i,j;
    // Kullanicilari sirali bir sekilde yeni diziye kopyala
    for ( i = 0; i < kullanicibilgi->userData.kullaniciSayisi; i++) {
        siralikullanicilar[i] = kullanicibilgi[i];
    }

    // Siralama islemini yeni dizide yap
    for (i = 0; i < kullanicibilgi->userData.kullaniciSayisi - 1; i++) {
        for ( j = 0; j < kullanicibilgi->userData.kullaniciSayisi - i - 1; j++) {
            if (siralikullanicilar[j].skor < siralikullanicilar[j + 1].skor) {
                // Skorlari takas et
                struct userInfo temp = siralikullanicilar[j];
                siralikullanicilar[j] = siralikullanicilar[j + 1];
                siralikullanicilar[j + 1] = temp;
            }
        }
    }

  printf("\n\nEn Yuksek 5 Skor:\n");
    for ( i = 0; i < 5; i++) {
        printf("%s: %d\n", siralikullanicilar[i].kullaniciAdi, siralikullanicilar[i].skor);
    }
}




void oyunkurallariyazdir(){
    printf("\n--------------------------------------------------------------Hosgeldinn-----------------------------------------------------------\n");
    printf("bu bir labirent oyunudur labirentte amac olabildigince cok karsit madde olusturmaktir ((+p) + (-e) = H) ,ne kadar cok \n");
    printf("H toplarsan skorun o kadar cok yuksek olur. manuel modda oyunu istedigin dort yone ok tuslariyla giderek oynayabilirsin.\n");
    printf("Karadelikler(k) uzerine gelinirse oyun sonlanir.x harfi oyunda seni temsil eder. Duvarlara(1) ve labirent disina hamle yapildiginda\n");
    printf("yerin degismez. istedigin zaman esc tusuna basarak oyundan cikabilirsin.Her hamle ile elde edilmis atom alti parcaciklar\n");
    printf("ve labirentten ciktiginda kac karsit madde uretildigi ekrana yazilir. Auto play modunda oyun,kendi kendine oynar.\n\n");
    printf("Labirentin elemanlari asagidaki gibidir. \nP+ : P \nP- : p\ne- : e \ne+ : E \nKara Delik : K \nKullanici : X \nCikis : C \nYol : 0 \nDuvar : 1 \nGiris : G\n\n");

}



int findXlocation(char** matrix, int row, int col){
    int i,j;
    int x;
    for(i=0 ; i<row ; i++ ){
        for( j=0 ; j<=col ;j++ ){
            if(matrix[i][j]=='X'){
                x = i*10 + j; // iki sayiyi dondurebilmek icin onlari tek sayiymis gibi birlestiriyorum
                // sonra ayirip kullancam, i=0 olursa tek basamakli sayi olacagindan i sifir hesaplanir.
                return x;
            }
        }
    }
    return -1; // Return -1 if 'X' is not found
}



void clearScreen() {
    // Clear the console screen
    system("cls");
}

int elementHesapla(struct elementler elementler){

    int sonuc1 =0;
    int elementH = 0;

    sonuc1 = elementler.artiP - elementler.eksiP ;
    if ( sonuc1 < 0){
        sonuc1 = sonuc1 * (-1);
        elementler.eksiP = sonuc1;
        elementler.artiP = 0;
    }
    else if ( sonuc1 >= 0){
        elementler.artiP = sonuc1;
        elementler.artiE = 0;
    }
    

    int sonuc2=0;
    sonuc2 = elementler.artiE - elementler.eksiE ;
    if ( sonuc1 < 0){
        sonuc1 = sonuc1 * (-1);
        elementler.eksiE = sonuc1;
        elementler.artiE = 0 ;
    }
    else if ( sonuc1 >= 0){
        elementler.artiE = sonuc1;
        elementler.eksiE = 0;
    }

    if (elementler.eksiP > 0 && elementler.artiE > 0 ){
        if (elementler.eksiP < elementler.artiE){
            elementH = elementler.eksiP;
        }
        else {
            elementH = elementler.artiE;
        }
    }
    printf(" %d adet element olustrdun\n", elementH);
    return elementH;
}




void elementleriYazdir(struct elementler elementler){
    if(elementler.artiE > 0){
        printf("%d adet +e topladin \n", elementler.artiE);
    }
    if(elementler.artiP > 0){
        printf("%d adet +p topladin \n", elementler.artiP);
    }
    if(elementler.eksiE > 0){
        printf("%d adet -e topladin \n", elementler.eksiE);
    }
    if(elementler.eksiP > 0){
        printf("%d adet -p topladin \n", elementler.eksiP);
    }
}




void skorGuncelle(struct elementler elementler, struct userInfo *kullanicibilgi, int kullaiciKonum){
    
    int HelementSayisi = elementHesapla(elementler);
    if (kullaniciVarMi(kullanicibilgi) != 0){
        kullaiciKonum = kullaniciVarMi(kullanicibilgi);
    }
    else if (girisYap(kullanicibilgi) != 0){
        kullaiciKonum = girisYap(kullanicibilgi);
    }

    if(kullaiciKonum != -1){
        kullanicibilgi[kullaiciKonum].skor = HelementSayisi;
    }

     // Open the file in read mode
        FILE* data_dosya = fopen("kullanici_veritabani.txt", "r");
        if (data_dosya == NULL) {
            printf("Dosya acilamadi veya bulunamadi.\n");
            return;
        }

        // Open a temporary file for writing
        FILE* temp_file = fopen("temp_file.txt", "w");
        if (temp_file == NULL) {
            printf("Gecici dosya olusturulamadi.\n");
            fclose(data_dosya);
            return;
        }

        // Read each line from the original file, update if necessary, and write to the temporary file
        int line_number = 0;
        char buffer[100];  // Adjust the buffer size as needed

        while (fgets(buffer, sizeof(buffer), data_dosya) != NULL) {
            if (line_number == kullaiciKonum) {
                // Update the score for the specific line
                fprintf(temp_file, "%s %s %d\n",
                        kullanicibilgi[kullaiciKonum].kullaniciAdi,
                        kullanicibilgi[kullaiciKonum].sifre,
                        kullanicibilgi[kullaiciKonum].skor);
            } else {
                // Write the line as is
                fputs(buffer, temp_file);
            }

            line_number++;
        }

        // Close both files
        fclose(data_dosya);
        fclose(temp_file);

        // Remove the original file
        remove("kullanici_veritabani.txt");

        // Rename the temporary file to the original file
        rename("temp_file.txt", "kullanici_veritabani.txt");
    }



void ManuelMode(struct elementler elementler, int row, int col, char** labirent, struct userInfo *kullanicibilgi, int kullaiciKonum){


    printf("\n--------------------Manuel mod---------------------\n");
    

    // finding the X's location in the matrix
    int Xlocation;
    Xlocation = findXlocation(labirent,row,col);
    int Xrow,Xcol;
    if (Xlocation != -1) {
        Xrow = Xlocation / 10;
        Xcol = Xlocation % 10;
    }
    else{
        printf("x is not found in the maze!\n");
    }


char a, key;
int XmoveCounter = 0 ;
int temp;

    do{    

                a = getch();
                if (a == 0) {  // Kontrol karakteri algılandı
                    key = getch();
                    clearScreen();

                    switch (key) {
                        case 72:

                            //Up arrow key pressed

                            temp = Xrow -1;
                            if (temp < 0){
                                printf("labirent siniri disina ciktin :(");
                            }
                            else if (labirent[temp][Xcol] == '1'){
                                printf("duvar var :( hareket edemezsin");
                            }
                            else if ( labirent[temp][Xcol] == 'K'){
                                printf("karadelige girdin\n");
                                printf("GAME OVER!!");
                                key = 27;
                            }
                            else if (labirent[temp][Xcol] == 'C'){
                                printf("cikisa ulastin\n");
                                elementHesapla(elementler);
                                skorGuncelle(elementler, kullanicibilgi,kullaiciKonum);
                            }
                            else if( labirent[temp][Xcol] == '0' || labirent[temp][Xcol] == 'G'){
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xrow = temp;
                                labirent[Xrow][Xcol] ='X';

                            }
                            else if (labirent [temp][Xcol] == 'P' || labirent [temp][Xcol] == 'p'|| labirent [temp][Xcol] == 'E'|| labirent [temp][Xcol] == 'e'){

                                if( labirent[temp][Xcol] == 'P'){
                                    elementler.artiP ++;
                                }
                                else if(labirent[temp][Xcol] == 'p'){
                                    elementler.eksiP ++;
                                }
                                else if(labirent[temp][Xcol] == 'E'){
                                    elementler.artiE ++;
                                }
                                else if(labirent[temp][Xcol] == 'e'){
                                    elementler.eksiE ++;
                                }

                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }

                                Xrow = temp;
                                labirent[Xrow][Xcol] ='X';
                            }

                            break;

                        case 80:

                            //Down arrow key pressed
                            
                            temp = Xrow +1;
                            if (temp > row){
                                printf("u r out");
                            }
                            else if (labirent[temp][Xcol] == '1'){
                                printf("duvar var");
                            }
                            else if ( labirent[temp][Xcol] == 'K'){
                                printf("karadelige girdin");
                                key = 27;
                            }
                            else if (labirent[temp][Xcol] == 'C'){
                                printf("cikisa ulastin");
                                elementHesapla(elementler); 
                                skorGuncelle(elementler, kullanicibilgi, kullaiciKonum);                              
                            }
                            else if( labirent[temp][Xcol] == '0' || labirent[Xrow][temp] == 'G'){
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xrow = temp;
                                labirent[Xrow][Xcol] ='X';

                            }
                            else if (labirent [temp][Xcol] == 'P' || labirent [temp][Xcol] == 'p'|| labirent [temp][Xcol] == 'E'|| labirent [temp][Xcol] == 'e'){
                                
                                if(labirent[temp][Xcol] == 'P'){
                                    elementler.artiP ++;
                                }
                                else if(labirent[temp][Xcol] == 'p'){
                                    elementler.eksiP ++;
                                }
                                else if(labirent[temp][Xcol] == 'E'){
                                    elementler.artiE ++;
                                }
                                else if(labirent[temp][Xcol] == 'e'){
                                    elementler.eksiE ++;
                                }
                                
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xrow = temp;
                                labirent[Xrow][Xcol] ='X';
                            }

                            break;

                        case 77:
                            //Right arrow key pressed
                            
                            temp = Xcol +1 ;
                            if (temp > col){
                                printf("u r out");
                            }
                            else if (labirent [Xrow][temp] == '1'){
                                printf("duvar var");
                            }
                            else if ( labirent [Xrow][temp] == 'K'){
                                printf("karadelige girdin");
                                key = 27;
                            }
                            else if (labirent [Xrow][temp] == 'C'){
                                printf("cikisa ulastin");
                                elementHesapla(elementler);
                                skorGuncelle(elementler, kullanicibilgi,kullaiciKonum);
                            }
                            else if( labirent [Xrow][temp] == '0' || labirent[Xrow][temp] == 'G'){
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xcol = temp;
                                labirent[Xrow][Xcol] ='X';

                            }
                            else if (labirent [Xrow][temp] == 'P' || labirent [Xrow][temp] == 'p'|| labirent [Xrow][temp] == 'E'|| labirent [Xrow][temp] == 'e'){
                                
                                if( labirent [Xrow][temp] == 'P'){
                                    elementler.artiP ++;
                                }
                                else if(labirent [Xrow][temp] == 'p'){
                                    elementler.eksiP ++;
                                }
                                else if(labirent [Xrow][temp] == 'E'){
                                    elementler.artiE ++;
                                }
                                else if(labirent [Xrow][temp] == 'e'){
                                    elementler.eksiE ++;
                                }                                
                                
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xcol = temp;
                                labirent[Xrow][Xcol] ='X';
                            }

                            break;
                            clearScreen();
                            
                        case 75:

                            //Left arrow key pressed

                            temp = Xcol-1 ;
                            if (temp < 0){
                                printf("labirent disina ciktin");
                            }
                            else if (labirent [Xrow][temp] == '1'){
                                printf("duvar var");
                            }
                            else if ( labirent [Xrow][temp] == 'K'){
                                printf("karadelige girdin");
                                key = 27;

                            }
                            else if (labirent [Xrow][temp] == 'C'){
                                printf("cikisa ulastin");
                                elementHesapla(elementler);
                                skorGuncelle(elementler, kullanicibilgi,kullaiciKonum);
                            }
                            else if( labirent [Xrow][temp] == '0' || labirent[Xrow][temp] == 'G'){
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xcol = temp;
                                labirent[Xrow][Xcol] ='X';

                            }
                            else if (labirent [Xrow][temp] == 'P' || labirent [Xrow][temp] == 'p'|| labirent [Xrow][temp] == 'E'|| labirent [Xrow][temp] == 'e'){
                                
                                if( labirent [Xrow][temp] == 'P'){
                                    elementler.artiP ++;
                                }
                                else if(labirent [Xrow][temp] == 'p'){
                                    elementler.eksiP ++;
                                }
                                else if(labirent [Xrow][temp] == 'E'){
                                    elementler.artiE ++;
                                }
                                else if(labirent [Xrow][temp] == 'e'){
                                    elementler.eksiE ++;
                                }
                                
                                if (XmoveCounter == 0 ){
                                    labirent[Xrow][Xcol] = 'G';
                                }
                                else {
                                    labirent[Xrow][Xcol] = '0';
                                }
                                Xcol = temp;
                                labirent[Xrow][Xcol] ='X';
                            }
                            break;

                            default :
                            printf("yalnis tusa basildi");

                    }

                    XmoveCounter ++;
                    matrisyazdir(row,col,labirent);
                    elementleriYazdir(elementler);


                }
        } while (key != 27);
}




void freeVisited(int **visited, int row) {
    for (int i = 0; i < row; i++) {
        free(visited[i]);
    }
    free(visited);
}




int isValidMove(char** labirent, int Xrow, int Xcol, int **visited,int row, int col) {
    return (Xrow >= 0 && Xrow < row && Xcol >= 0 && Xcol < col && labirent[Xrow][Xcol] != '1' && visited[Xrow][Xcol] == 0 && labirent[Xrow][Xcol] != 'K') ;
}




int AutoMode(char **labirent,int Xrow, int Xcol , struct elementler elementler, int row, int col){

    int** visited = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++) {
        visited[i] = (int *)calloc(col, sizeof(int));
    }




    if (Xrow < 0 || Xrow >= row || Xcol < 0 || Xcol >= col || labirent[Xrow][Xcol] == '1' || visited[Xrow][Xcol] == 1) {
        freeVisited(visited, row);
        return 0;
    }

    visited[Xrow][Xcol] = 1;

    if (labirent[Xrow][Xcol] == 'C') {
        return 1;
    }


    if (isValidMove(labirent, Xrow - 1, Xcol, visited, row,col) && AutoMode(labirent, Xrow - 1, Xcol, elementler, row, col)) {
        labirent[Xrow][Xcol] = 'X';
        if (labirent[Xrow-1][Xcol] == 'p') {
            elementler.eksiP += 1;
        }
        else if (labirent[Xrow-1][Xcol] == 'P') {
            elementler.artiP += 1;
        }
        else if (labirent[Xrow-1][Xcol] == 'E') {
            elementler.artiE += 1;
        }
        else if (labirent[Xrow-1][Xcol] == 'e') {
            elementler.eksiE += 1;
        }
        matrisyazdir(row,col,labirent);
 
        return 1;
    }

    if (isValidMove(labirent, Xrow + 1, Xcol, visited, row, col) && AutoMode(labirent, Xrow + 1, Xcol, elementler, row, col)) {
        labirent[Xrow][Xcol] = 'X';
        if (labirent[Xrow+1][Xcol] == 'p') {
            elementler.eksiP += 1;
        }
        else if (labirent[Xrow+1][Xcol] == 'P') {
            elementler.artiP += 1;
        }
        else if (labirent[Xrow+1][Xcol] == 'E') {
            elementler.artiE += 1;
        }
        else if (labirent[Xrow+1][Xcol] == 'e') {
            elementler.eksiE += 1;
        }
        matrisyazdir(row,col,labirent);

        return 1;
    }

    if (isValidMove(labirent, Xrow, Xcol - 1, visited, row, col) && AutoMode(labirent,Xrow, Xcol - 1,elementler, row, col)) {
        labirent[Xrow][Xcol] = 'X';
        if (labirent[Xrow][Xcol-1] == 'p') {
            elementler.eksiP += 1;
        }
        else if (labirent[Xrow][Xcol-1] == 'P') {
            elementler.artiP += 1;
        }
        else if (labirent[Xrow][Xcol-1] == 'E') {
            elementler.artiE += 1;
        }
        else if (labirent[Xrow][Xcol-1] == 'e') {
            elementler.eksiE += 1;
        }     
        matrisyazdir(row,col,labirent);
  
        return 1;
    }

    if (isValidMove(labirent, Xrow, Xcol + 1, visited, row, col) && AutoMode(labirent, Xrow, Xcol + 1,elementler, row, col)) {
        labirent[Xrow][Xcol] = 'X';
        if (labirent[Xrow][Xcol+1] == 'p') {
            elementler.eksiP += 1;
        }
        else if (labirent[Xrow][Xcol+1] == 'P') {
            elementler.artiP += 1;
        }
        else if (labirent[Xrow][Xcol+1] == 'E') {
            elementler.artiE += 1;
        }
        else if (labirent[Xrow][Xcol+1] == 'e') {
            elementler.eksiE += 1;
        }    
        matrisyazdir(row,col,labirent); 
        return 1;
   
    }
        printf("\n%d adet +e topladin\n", elementler.artiE);
        printf("\n%d adet -e topladin\n", elementler.eksiE);
        printf("\n%d adet +p topladin\n", elementler.artiP);
        printf("\n%d adet -p topladin\n", elementler.eksiP);
        
        

    freeVisited(visited, row);

    visited[Xrow][Xcol] = 0;

    return 0;
}





/*----------------------------------- main function ------------------------------------- */

int main() {

    struct userInfo *kullanicibilgi = (struct userInfo *)malloc((MAX_USERS + 1) * sizeof(struct userInfo));
    char isim[10], soyisim[10];
    int secim,secim2,secim3,kisi_sayisi,i;
    kisi_sayisi = dosyadanOku(kullanicibilgi);
    kullanicibilgi->userData.kullaniciSayisi = 0;
    kullanicibilgi->userData.kullaniciSayisi = kisi_sayisi;
    int buul=0;
    struct elementler elementler;
    elementler.artiE = 0; 
    elementler.artiP = 0;
    elementler.eksiE = 0;
    elementler.eksiP = 0;
    int zorluk;
    int row, col;
    FILE *dosya;
    char** labirent = (char **)malloc(MAX_USERS +1 * sizeof(char *));
    int kullaiciKonum;


    printf("-------------------welcome--------------------\n");
    do{
        printf("1-hesap olustur \n2-giris yap \n3-cikis\n");
        scanf("%d", &secim);

        if(secim == 1){
             // hesap olustur
            printf("isim : ");
            scanf("%s", &isim);
            printf("soyisim :");
            scanf("%s", &soyisim);
            printf("Kullanici Adi: ");
            scanf("%s", &kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].kullaniciAdi);
            printf("Sifre: ");
            scanf("%s", &kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].sifre);

            // Kullanici var mi kontrolÃ¼
            if (kullaniciVarMi(kullanicibilgi) != 0) {
                kullaiciKonum = kullaniciVarMi(kullanicibilgi);
                printf("Kullanici zaten var.\n\n");
                buul = 1;
            }
            else if(kullaniciVarMi(kullanicibilgi) == 0){
                // Hesap olustur
                dosyayaYaz(kullanicibilgi);
                buul = 0;
            }
        }


        else if(secim == 2){
            // Kullanicidan kullanici adi ve sifre bilgilerini al
            printf("Kullanici Adi: ");
            scanf("%s", &kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].kullaniciAdi);
            printf("Sifre: ");
            scanf("%s", &kullanicibilgi[kullanicibilgi->userData.kullaniciSayisi].sifre);
            // Giris yap
            if (girisYap( kullanicibilgi) != 0) {
                kullaiciKonum = girisYap(kullanicibilgi);
                printf("Giris basarili!\n");
                buul = 0;
            }
            else {
                printf("Kullanici adi veya sifre yanlis.\n\n");
                buul = 1;
            }
        }   
        else if (secim == 3){
            buul = 0;
            exit(1);
        }
    }while(buul == 1);

    enYuksekSkorlariYazdir(kullanicibilgi);
    char csecim;
    printf("\n1-oyun kurallarini ogrenmek ister misin ?(y or n )\n");
    scanf(" %c", &csecim);
    
    if(csecim == 'y' || csecim == 'Y'){
         oyunkurallariyazdir();
    }
    printf("\n\noynamaya basla \n");

    printf("1-hazir labirent\n2-ben kendi labirentimi yuklemek isterim\n");
    scanf("%d", &secim);
    if(secim == 1){
        // hazir labirent:
        printf("\n\n1'den 5'e kadar zorluk derecesi sec\n");
        scanf("%d", &zorluk);
        switch (zorluk){
            case 1:
                dosya = fopen("0.txt", "r");
                if (dosya == NULL) {
                perror("Dosya acma hatasi");
                exit (1);
                }
                if (fscanf(dosya, "%d %d", &row, &col) != 2) {
                 // stderr = standard error
                fprintf(stderr, "Dosya formati uyumsuz.\n");
                fclose(dosya);
                exit(1);
                }
                labirent = matrisOku(dosya,row,col);
                break;

            case 2:
                dosya = fopen("1.txt", "r");
                if (dosya == NULL) {
                perror("Dosya acma hatasi");
                exit (1);
                }
                if (fscanf(dosya, "%d %d", &row, &col) != 2) {
                 // stderr = standard error
                fprintf(stderr, "Dosya formati uyumsuz.\n");
                fclose(dosya);
                exit(1);
                }
                labirent = matrisOku(dosya,row,col);
                break;

            case 3:
                dosya = fopen("2.txt", "r");
                if (dosya == NULL) {
                perror("Dosya acma hatasi");
                exit (1);
                }
                if (fscanf(dosya, "%d %d", &row, &col) != 2) {
                 // stderr = standard error
                fprintf(stderr, "Dosya formati uyumsuz.\n");
                fclose(dosya);
                exit(1);
                }
                labirent = matrisOku(dosya,row,col);
                break;

            case 4:
                dosya = fopen("3.txt", "r");
                if (dosya == NULL) {
                perror("Dosya acma hatasi");
                exit (1);
                }
                if (fscanf(dosya, "%d %d", &row, &col) != 2) {
                 // stderr = standard error
                fprintf(stderr, "Dosya formati uyumsuz.\n");
                fclose(dosya);
                exit(1);
                }
                labirent = matrisOku(dosya,row,col);
                break;

            case 5:
                dosya = fopen("4.txt", "r");
                if (dosya == NULL) {
                perror("Dosya acma hatasi");
                exit (1);
                }
                if (fscanf(dosya, "%d %d", &row, &col) != 2) {
                 // stderr = standard error
                fprintf(stderr, "Dosya formati uyumsuz.\n");
                fclose(dosya);
                exit(1);
                }
                labirent = matrisOku(dosya,row,col);
                break;

            default:
            printf("Invalid choice.\n");
        }

    }
    else if (secim == 2){
        char dosyaAdi[50];

        printf("oyun haritasi text dosyasi icinde olmalidir, ilk satirda haritanin ebatlari yazilir\n");
        printf("mesela: 2 3\n01e\n0X0 \ngibi...\n");
        printf("lutfen dosya adini girin: (benimlabirent.txt) gibi\n");
        scanf("%s", &dosyaAdi);

        // bu durumu temizlemek iÃ§in bir kontrol yapalim
        if (dosyaAdi[strlen(dosyaAdi) - 1] == '\n') {
            dosyaAdi[strlen(dosyaAdi) - 1] = '\0'; // '\n' karakterini '\0' ile degistir
        }
        dosya = fopen(dosyaAdi, "r");
        if (dosya == NULL){
            printf("dosya bulunmadi\n");
            exit (1);
        }
        if (fscanf(dosya, "%d %d", &row, &col) != 2) {
            // stderr = standard error
            fprintf(stderr, "Dosya formati uyumsuz.\n");
            fclose(dosya);
            exit(1);
        }
        labirent = matrisOku(dosya,row,col);
    }
        int Xrow=0, Xcol=0, Xlocation =0;
        Xlocation = findXlocation(labirent, row, col);
        if (Xlocation != -1) {
            Xrow = Xlocation / 10;
            Xcol = Xlocation % 10;
        } 
        else 
        {
            printf("x is not found in the maze!\n");
        }

        printf("\nhangi modda oynamak istersin : \n1-Manuel Mode\n2-Auto Mode\n");
        scanf("%d", &secim3);
        if (secim3 == 1){
            ManuelMode(elementler, row, col, labirent, kullanicibilgi, kullaiciKonum);
        }
        else if (secim3 == 2){

            if (AutoMode(labirent,Xrow,Xcol, elementler, row, col)) {
                printf("Path found:\n");
                matrisyazdir(row,col,labirent);
            } else {
            printf("No path found.\n");
            }
        }
    return 0;
}
// the 1000th line :)