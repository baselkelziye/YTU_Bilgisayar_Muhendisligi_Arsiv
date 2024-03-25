#include <stdio.h>
#include <stdlib.h>
//Eger hashTable.txt dosyasi olusturulmamissa bu dosyayi olusturan fonksiyon
//hashTable.txt dosyasi silinmedigi surece sadece 1 kere islem yapmaktadir
void createHashTable(char **hashTable,char **dictionary)
{

    FILE *fp;//file pointer
    char x;//EOF karakterine gelindigi bilgisini tutar
    int i,j,k;//index degiskenleri
    int key;//hash fonksiyonunun uretecegi key degerini tutar
    int h1,h2;//hashing fonksiyonlarinin degerlerini tutarlar
    int MM,M;//hash tablosunun uzunlugunu tutar
    M=487;//load factor=0.7 kabul edildiginde tablo uzunlugu en kucuk asal sayi 487 olur
    MM=M-1;
    fp = fopen("hashTable.txt", "r");
    if (fp == NULL)
    {
        //hashTable.txt dosyasi eger olusturulmamissa bu islemleri yapar.Yani sadece 1 defa calismasi icin yapilmistir
        fp = fopen("smallDictionary.txt", "r");
        if (fp == NULL) {
         printf("I couldn't open smallDictionary.txt\n");
         exit(0);
        }
        i=0;
        do{
                x=fscanf(fp,"%s",dictionary[i]);//sozlukte 339 kayit var
                i++;
        }while(x!=EOF);


        for(i=0;i<339;i++)//sozlukte 339 kayit oldugu icin i<339
        {
            key=0;
            for(j=0;j<strlen(dictionary[i]);j++)
            {
                key+=(dictionary[i][j]-'a')*26*j;

            }
            h1=key%M;
            h2=1+(key%MM);


            j=0;

            while( hashTable[(h1+j*h2)%M][0]!=NULL)//tablonun bakilan hucresi dolu ise bos hucre arar
            {
                j++;
            }
            ///////////////////////////////////////////////sozlukteki kelimeyi hash tablosuna kopyalar
            k=0;
            while(dictionary[i][k]!='\0')
            {
                hashTable[(h1+j*h2)%M][k]=dictionary[i][k];
                k++;
            }
             hashTable[(h1+j*h2)%M][k]=dictionary[i][k];
            ////////////////////////////////////////////////
        }
        fclose(fp);

        fp = fopen("hashTable.txt", "w");
        if (fp == NULL) {
        printf("I couldn't write hashTable.txt\n");
        exit(0);
        }
        for(i=0;i<487;i++)
        {
             if(hashTable[i][0]==NULL)
             fprintf(fp,"# ");//hash table da bos hucreler icin # sembolu yazilmistir
             else
             fprintf(fp,"%s ",hashTable[i]);
        }


        fclose(fp);
        printf("hashTable.txt didn't create.I create it.\n");
    }
}
//hashTable isimli string dizisine hashTable.txt isimli dosyada yer alan kelimeleri atar
void readHashTable(char **hashTable)
{
    FILE *fp;//file pointer
    char x;//EOF karakterine gelindigi bilgisini tutar
    int i;//index degiskeni
    fp = fopen("hashTable.txt", "r");
    if (fp == NULL) {
         printf("I couldn't open hashTable.txt\n");
         exit(0);
    }
    i=0;

    do{

       x=fscanf(fp,"%s",hashTable[i]);

        i++;
    }while(x!=EOF);
    fclose(fp);
}
//parametre olarak aktarilan kelimenin yine parametre olarak aktarilan hash tablosunda olup olmadigini bulur
//Sonuc olarak hash tablosunda aranan kelime varsa 1, yoksa -1 dondurur
int find(char kelime[],char **hashTable)
{
    int i,j;//index degiskenleri
    int key;//hash fonksiyonunun uretecegi key degerini tutar
    int h1,h2;//hashing fonksiyonlarinin degerlerini tutarlar
    int MM,M;//hash tablosunun uzunlugunu tutar
    int found=0;//sonucun donduruldugu bayrak degiskeni
    M=487;//load factor=0.7 kabul edildiginde tablo uzunlugu en kucuk asal sayi 487 olur
    MM=M-1;

    key=0;
    j=0;
    for(i=0;i<strlen(kelime);i++)
    {
        key+=(kelime[i]-'a')*26*i;

    }
    while(found==0)
    {

            h1=key%M;
            h2=1+(key%MM);
            printf("h1=%d h2= %d key=%d \n",h1,h2,(h1+j*h2)%M);
            if(strcmp(hashTable[(h1+j*h2)%M],kelime)==0)
            found=1;
            else if(strcmp(hashTable[(h1+j*h2)%M],"#")==0)//hash tablosunda # karakteri ile karsilasilmissa
            found=-1;                                     //daha ilerisine bakmaya gerek yok, kelime yoktur

            j++;



    }
    return found;
}
//Parametre olarak aktarilan kelime parametre olarak aktarilan hash tablosunda varsa kelimeye erisim yollarini
//yazar.Eger yoksa hash tablosunda onerilebilecek kelime varsa onlari onerir.
void search(char kelime[],char **hashTable)
{

    int found=0;
    found=find(kelime,hashTable);
    if(found==-1)
    {
        printf("Aranilan Kelime Sozlukte Yok\n Onerilen kelimeler:\n");
        suggestion(hashTable,kelime);
    }
    else
    {
        printf("Aranilan Kelime Sozlukte Var\n");
    }

}
void suggestion(char **hashTable,char kelime[])
{
    char tmp;//kelimedeki degistirilmis karakteri tekrar geri alabilmek icin kullanilmistir
    int i,j,k,l;//index degiskenleri
    int key;//hash fonksiyonunun uretecegi key degerini tutar
    int h1,h2;//hashing fonksiyonlarinin degerlerini tutarlar
    int MM,M;//hash tablosunun uzunlugunu tutar
    int found=0;//sonucun donduruldugu bayrak degiskeni
    int x=0;//Eger sozlukte hic onerilecek kelime yoksa bunu kullaniciya belirtmek icin kullanilmistir
    M=487;//load factor=0.7 kabul edildiginde tablo uzunlugu en kucuk asal sayi 487 olur
    MM=M-1;
    for(i=0;i<strlen(kelime);i++)
    {
        tmp=kelime[i];
        for(j=97;j<=122;j++)//a'nin ascii karsiligi=97 ,z'nin ascii karsiligi=122
        {
            kelime[i]=j;
            k=0;
            found=0;
            key=0;
            for(l=0;l<strlen(kelime);l++)
            {
                key+=(kelime[l]-'a')*26*l;

            }
            while(found==0)
            {

                h1=key%M;
                h2=1+(key%MM);

                if(strcmp(hashTable[(h1+k*h2)%M],kelime)==0)
                found=1;
                else if(strcmp(hashTable[(h1+k*h2)%M],"#")==0)
                found=-1;
                k++;
            }
            if(found==1)
            {
                printf("%s ",kelime);
                x=1;
            }
        }

        kelime[i]=tmp;
    }
    if(x==0)
    printf(" ----------\nSozlukte onerilebilecek kelime yok!!\n");

}
int main()
{
    char **dictionary;//sozlukte yer alan kelimeleri tutar
    char **hashTable;//hash tablosundaki kelimeleri tutar
    char kelime[50];//kullanicidan alinan kelimeyi tutar
    int i;//index degiskeni

    dictionary=(char **)malloc(sizeof(char *) * 500);
    for (i = 0; i < 500; ++i)
    dictionary[i] = (char *)malloc(sizeof(char) * 50);

    hashTable=(char **)malloc(sizeof(char *) * 500);
    for (i = 0; i < 500; ++i)
    hashTable[i] = (char *)malloc(sizeof(char) * 50);

    createHashTable(hashTable,dictionary);
    readHashTable(hashTable);

    printf("string=");
    gets(kelime);

    search(kelime,hashTable);

    free(hashTable);
    free(dictionary);
    return 0;
}
