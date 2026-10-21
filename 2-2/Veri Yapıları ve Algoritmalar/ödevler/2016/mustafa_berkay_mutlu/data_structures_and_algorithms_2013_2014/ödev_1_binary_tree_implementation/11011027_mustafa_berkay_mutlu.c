/****************************************************************************
 * main.c                                                                   *
 * Modified in 16 March 2014                                                *
 * Written by Mustafa Berkay Mutlu                                          *
 * http://www.berkaymutlu.com/                                              *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION: This program demonstrates creating a Binary Search Tree     *
 * using Dynamic Memory Allocation, showing elements in different orders    *
 * and adding/deleting items by using recursive functions.                  *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_NODE_CHAR -1

// Kullanilan fonksiyonlar:
int UsAl(int, int); // Parametreler: (int ussuAlinacakSayi, int usDegeri)
int CocuguVarMi(int *, int, int); // Donu degeri 1 ise sol ve sag var, 2 ise sol var, 3 ise sag var, 4 ise hic cocugu yok demektir.
void EkranaGoster(int *, int, int); // Parametreler: (int *tree, int elemanSayisi, int baslangicNoktasi)
void ElemanEkle(int *, int *, int, int);   // Parametreler: (int *tree, int elemanSayisi, int eklenecekEleman)
int ElemanSil(int *, int, int); // Eleman silme islemlerinin yapildigi rekursif fonksiyon.
int EnKucukBul(int *, int, int); // Kok index'i verilen agac bolumunun minimum elemaninin index'ini bulur.

// Ekrana gosterme fonksiyonlari.
void PreOrderGoster(int, int *, int);
void InOrderGoster(int, int *, int);
void PostOrderGoster(int, int *, int);
void DiziOlarakGoster(int *, int);

// Kullanicidan eleman alma fonksiyonlari.
void PreOrderAl(int, int *, int);
void InOrderAl(int, int *, int);
void PostOrderAl(int, int *, int);
void DiziOlarakAl(int, int *, int, int);



int main(){

    int eklenecekEleman;    // Agaca eleman eklenirken kullanilan eklenecek elemani tutan degisken.
    int elemanSayisi; // BST'nin eleman sayisi.
    int i; // Dongu degiskeni.
    int derinlik; // BST'nin derinligi.
    int *BST;   // Binary Search Tree dizisi. Alan, dinamik olarak ayirilacaktir.
    int programdanCik; // Menude kullanilan 0 veya 1 olan kontrol degiskeni.
    char secim1,secim2; // Menude kullanilan secim tuslari.
    int BST_Alindi; // Kullanicinin elemanlari girdigini ifade eden kontrol degiskeni.
    int girilenEleman; // DiziOlarakAl fonksiyonu icin kullanilan gecici degisken.
    int index;  // Eleman silme islemi icin kullanilan degisken.


    printf("Olusturacaginiz Binary Search Tree'nin derinligi nedir> ");
    scanf("%d",&derinlik);
    elemanSayisi = UsAl(2,derinlik+1) - 1;
    printf("Bu durumda toplam %d eleman olacak. \n\n", elemanSayisi);

    // Memory allocation ile BST icin gerekli yer ayiriliyor.
    BST = (int *) malloc (elemanSayisi*sizeof(int));

    // Olusturulan dizinin elemanlari sifirlaniyor.
    for(i=0;i<elemanSayisi;i++)
        BST[i] = EMPTY_NODE_CHAR;

    // BST denemek icin atanir.
//    BST = (int []){10,5,15,-1,-1,13,20,-1,-1,-1,-1,12,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,-1,-1,-1,-1,-1,-1,-1};
//    BST_Alindi = 1;

    printf("Lutfen istediginiz secenegin tusuna basin: \n\n");
    // Kullanicidan elemanlar aliniyor.
    BST_Alindi = 0;
    while(BST_Alindi == 0){

        printf("[1] Dizi olarak gir. (Direkt atama yapilir, bilgisayar islem yapmaz) \n");
        printf("[2] Dizi olarak gir. (Agaci bilgisayar olusturur ama 'balance' yapilmaz, duzgun calismasi 'balanced' tree girmelisiniz) \n");
        printf("[3] Pre-order gir.\n");
        printf("[4] In-order gir.\n");
        printf("[5] Post-order gir.\n");

        secim1 = getch();
        switch(secim1){

            case '1':{
                printf("\nBST'nin elemanlarini sirayla giriniz. Eger gozu bos birakmak isterseniz eleman yerine %d yazin. \n",EMPTY_NODE_CHAR);
                for(i=0;i<elemanSayisi;i++){
                    printf("%d. elemani giriniz> ",i);
                    scanf("%d",&BST[i]);
                }
                BST_Alindi = 1;
                break;
            }

            case '2':{
                printf("\nBST'nin elemanlarini sirayla giriniz. Elemanlariniz bittikten sonra gozu bos birakmak icin eleman yerine %d yazin. \n",EMPTY_NODE_CHAR);
                for(i=0;i<elemanSayisi;i++){
                        printf("%d. elemani giriniz> ",i+1);
                        scanf("%d",&girilenEleman);
                        DiziOlarakAl(0,BST,elemanSayisi,girilenEleman);
                }
                BST_Alindi = 1;
                break;
            }

            case '3':{
                PreOrderAl(0,BST,elemanSayisi);
                BST_Alindi = 1;
                break;
            }

            case '4':{
                InOrderAl(0,BST,elemanSayisi);
                BST_Alindi = 1;
                break;
            }

            case '5':{
                PostOrderAl(0,BST,elemanSayisi);
                BST_Alindi = 1;
                break;
            }

            default:{
                printf("Yanlis bir secenek sectiniz lutfen tekrar deneyin. \n\n");
                break;
            }
        }
    }


    // Alinan elemanlar kullaniciya gosteriliyor.
    EkranaGoster(BST,elemanSayisi,0);

    // Ana menu.
    programdanCik = 0;
    while(programdanCik == 0){
        printf("\n\nLutfen uygun secenegin tusuna basin: \n");
        printf("----  MENU  ----\n\n");
        printf("[1] Binary Search Tree'yi goster. \n");
        printf("[2] Eleman ekle. \n");
        printf("[3] Eleman sil. \n");
        printf("[4] Programdan cik. \n\n\n");

        secim2 = getch();

        switch(secim2){
            case '1':{
                EkranaGoster(BST,elemanSayisi,0); // Buradaki 0 baslangic noktasini ifade ediyor.
                break;
            }

            case '2':{
                printf("Eklemek istediginiz elemani giriniz> ");
                scanf("%d",&eklenecekEleman);
                ElemanEkle(BST,&elemanSayisi,eklenecekEleman,derinlik);
                break;
            }

            case '3':{
                printf("Index  Dizi\n");
                printf("-----  ----\n");
                for(i=0;i<elemanSayisi;i++){
                    printf(" %0.2d:    %d\n",i,BST[i]);
                }
                printf("\nSilmek istediginiz elemanin index'ini giriniz> ");
                scanf("%d",&index);
                ElemanSil(BST,elemanSayisi,index);
                break;
            }

            case '4':{
                printf("\n\nCikiliyor..\n");
                free(BST);
                programdanCik = 1;
                break;
            }

            default:{
                printf("Yanlis bir secenek sectiniz lutfen tekrar deneyin. \n\n");
                break;
            }
        }
    }


    getch();
    return 0;
}


int UsAl(int alt, int ust){
    int retVal = 1;
    int i;
    for(i=ust;i>0;i--)
        retVal = retVal * alt;
    return retVal;
}


void PreOrderGoster(int node, int *BST, int elemanSayisi){

    if(node < elemanSayisi){
        if(BST[node] != EMPTY_NODE_CHAR) printf("%d  ",BST[node]);
        PreOrderGoster(2*node+1,BST,elemanSayisi);
        PreOrderGoster(2*node+2,BST,elemanSayisi);
    }

}


void InOrderGoster(int node, int *BST, int elemanSayisi){

    if(node < elemanSayisi){
        PreOrderGoster(2*node+1,BST,elemanSayisi);
        if(BST[node] != EMPTY_NODE_CHAR) printf("%d  ",BST[node]);
        PreOrderGoster(2*node+2,BST,elemanSayisi);
    }

}


void PostOrderGoster(int node, int *BST, int elemanSayisi){

    if(node < elemanSayisi){
        PreOrderGoster(2*node+1,BST,elemanSayisi);
        PreOrderGoster(2*node+2,BST,elemanSayisi);
        if(BST[node] != EMPTY_NODE_CHAR) printf("%d  ",BST[node]);
    }

}


void DiziOlarakGoster(int *BST, int elemanSayisi){
    int i;

    for(i=0;i<elemanSayisi;i++){
        printf("%d  ",BST[i]);      // eskiden: if(BST[i] != EMPTY_NODE_CHAR) printf("%d  ",BST[i]);
    }

}


void EkranaGoster(int *BST, int elemanSayisi, int baslangic){

    printf("\n\nBinary Search Tree\n");
    printf("-------------------------\n\n");

    printf("Dizi:       ");
    DiziOlarakGoster(BST,elemanSayisi);
    printf("\n");

    printf("Pre-order:  ");
    PreOrderGoster(baslangic,BST,elemanSayisi);
    printf("\n");

    printf("In-order:   ");
    InOrderGoster(baslangic,BST,elemanSayisi);
    printf("\n");

    printf("Post-order: ");
    PostOrderGoster(baslangic,BST,elemanSayisi);
    printf("\n");

    printf("\n-------------------------");
}


void PreOrderAl(int node, int *BST, int elemanSayisi){

    if(node < elemanSayisi){
        printf("%d. elemani girin> ",node);
        scanf("%d",&BST[node]);
        PreOrderAl(2*node+1,BST,elemanSayisi);
        PreOrderAl(2*node+2,BST,elemanSayisi);
    }

}


void InOrderAl(int node, int *BST, int elemanSayisi){

    if(node < elemanSayisi){
        PreOrderAl(2*node+1,BST,elemanSayisi);
        printf("%d. elemani girin> ",node);
        scanf("%d",&BST[node]);
        PreOrderAl(2*node+2,BST,elemanSayisi);
    }
}


void PostOrderAl(int node, int *BST, int elemanSayisi){

    if(node < elemanSayisi){
        PreOrderAl(2*node+1,BST,elemanSayisi);
        PreOrderAl(2*node+2,BST,elemanSayisi);
        printf("%d. elemani girin> ",node);
        scanf("%d",&BST[node]);
    }
}


void DiziOlarakAl(int node, int *BST, int elemanSayisi, int girilenEleman){

    int i;

    if(node < elemanSayisi){

        if(BST[node] == EMPTY_NODE_CHAR){     // Gozun bos oldugu durum.
            BST[node] = girilenEleman;
        }
        else if(girilenEleman < BST[node]){     // Gozde girilen elemandan buyuk eleman var.
            DiziOlarakAl(2*node+1,BST,elemanSayisi,girilenEleman);
        }
        else if(girilenEleman > BST[node]){     // Gozde girilen elemandan kucuk eleman var.
            DiziOlarakAl(2*node+2,BST,elemanSayisi,girilenEleman);
        }

    }
}


void ElemanEkle(int *BST,int *elemanSayisi, int eleman, int derinlik){

    int bulundu = 0;
    int eskiElemanSayisi = *elemanSayisi;
    int i = 0;
    int j;

    while( (i < *elemanSayisi) && (!bulundu) ){

        if(BST[i] > eleman){ // Burda agaca gore sola dallanir.
            if(BST[i] == EMPTY_NODE_CHAR) { // Gozun BOS ve eleman koymak icin musait oldugu durum.
                BST[i] = eleman;
                bulundu = 1;
            }
            else{ // Gozun DOLU ve eleman koymak icin musait OLMADIGI durum.
                i = 2*i + 1;
            }
        }
        else{ // Burda agaca gore saga dallanir.
            if(BST[i] == EMPTY_NODE_CHAR) { // Gozun BOS ve eleman koymak icin musait oldugu durum.
                BST[i] = eleman;
                bulundu = 1;
            }
            else{ // Gozun DOLU ve eleman koymak icin musait OLMADIGI durum.
                i = 2*i + 2;
            }
        }
    }

    // Dizi yeteri kadar buyuk degil. Realloc ile yeni sira aciliyor.
    if((i >= *elemanSayisi) && (!bulundu)){

        derinlik++;
        *elemanSayisi = UsAl(2,derinlik+1) - 1;     // Yeni eleman sayisi ana fonksiyonda da degistiriliyor.
        BST = (int *) realloc(BST, *elemanSayisi*sizeof(int));
        for(j=eskiElemanSayisi;j<*elemanSayisi;j++){
            BST[j] = EMPTY_NODE_CHAR;       // Yeni acilan sira bos olarak isaretleniyor.
        }
        BST[i] = eleman;

    }

    printf("i:: %d",i);

}


int ElemanSil(int *BST, int elemanSayisi, int index){

    int temp = EMPTY_NODE_CHAR;
    int cocukVarMi = CocuguVarMi(BST,elemanSayisi,index);
    int sagdakiEnKucukIndex;

    if(cocukVarMi == 1){   // Sol ve sag cocuk var.
        sagdakiEnKucukIndex = EnKucukBul(BST,2*index+2,elemanSayisi);
        BST[index] = BST[sagdakiEnKucukIndex];
        ElemanSil(BST,elemanSayisi,sagdakiEnKucukIndex);

    }
    else if (cocukVarMi == 2){     // Sadece sol cocuk var.
        temp = BST[index];
        BST[index] = ElemanSil(BST,elemanSayisi,2*index+1);
        return temp;

    }
    else if(cocukVarMi == 3){      // Sadece sag cocuk var.
        temp = BST[index];
        BST[index] = ElemanSil(BST,elemanSayisi,2*index+2);
        return temp;

    }
    else if (cocukVarMi == 4){     // Hic cocuk yok.
        temp = BST[index];
        BST[index] = EMPTY_NODE_CHAR;
        return temp;

    }

    return temp;
}


int CocuguVarMi(int *BST,int elemanSayisi,int index){

    int solCocuk = 2*index+1;
    int sagCocuk = 2*index+2;
    int solCocukVar = 0;
    int sagCocukVar = 0;



    if((BST[solCocuk] != EMPTY_NODE_CHAR) && (solCocuk < elemanSayisi)){
        solCocukVar = 1;
    }

    if((BST[sagCocuk] != EMPTY_NODE_CHAR) && (sagCocuk < elemanSayisi)){
        sagCocukVar = 1;
    }

    if(solCocukVar && sagCocukVar) return 1;    // Iký cocuk varsa 1 donuyor.
    else if(solCocukVar) return 2;  // Sadece sol cocuk varsa 2 donuyor.
    else if(sagCocukVar) return 3;  // Sadece sag cocuk varsa 3 donuyor.
    else return 4;     // Cocuk yoksa 4 donuyor.

}


int EnKucukBul(int *BST, int kokIndex, int elemanSayisi){

    if((BST[2*kokIndex+1] == EMPTY_NODE_CHAR) || (2*kokIndex+1) >= elemanSayisi)    // Bir sonraki eleman bos ise, su andaki index i dondur.
        return kokIndex;
    else    // Bir sonraki eleman bos degil ise oraya git.
        return EnKucukBul(BST,2*kokIndex+1,elemanSayisi);

}


