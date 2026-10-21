#include <stdio.h>
#include <stdlib.h>
#include <string.h>     
#include <ctype.h>          
#include <conio.h>
#include <sys/time.h>   

#define  MAXSIZE 1024




void bctable(char*,int*,int);
int bmh_find(char*,char*, int*,int*,int);
void bmh_replace(char*, char*,char*, int*,int);

void bmh_replace(char* input,char* pattern,char* replace,int* found,int found_count){

    int patternsize=strlen(pattern);    //aranan metnin uzunlugu karsilartirma icin alindi
    int repsize = strlen(replace);      //yeni metnin uzunlugu alindi
    
    int i;
    for(i=0;i<found_count;i++){         //found tablomuzdaki konumlari sirayla aliyoruz
        if(patternsize==repsize){       
            int j=found[i],k;
            for(k=0;k<patternsize;k++){ //aranan metin ve yeni metin esit ise hicbir kaydirma yapmiyoruz 
                input[j+k]=replace[k];  //sadece replace'te karsilik gelen indisi atiyoruz
            }
        }
        else if(repsize<patternsize){   //yeni metin aranandan kisa ise 
            int j=found[i],k,dif,u;

            for(k=0;k<repsize;k++){
                input[j+k]=replace[k];  //yeni metni girdik
            }
            dif=patternsize-repsize;    
            for(k=j+repsize;k<strlen(input)-dif;k++){
                input[k]=input[k+dif];  //farkta olusacak bosluklari diziyi kaydirarak siliyoruz
            }

            input[k]='\0';              //son indise NULL karakter koyuyoruz

            for(u=i;u<found_count;u++){
                found[u]=found[u]-dif;  //tablomuzdaki tüm indisleri guncelliyoruz
            }

        }
        
        else{                           //yeni metin aranan metinden daha uzun ise
            
            int j=found[i],k,dif,u;
            dif=repsize-patternsize;
            
            

            for(k=strlen(input); k>(j+dif) ; k--){
                input[k+dif]=input[k];  //once yeni metni sigdiracak kadar yer acmak icin fark kadar kaydiriyoruz
            }

            for(k=0;k<repsize;k++){
                input[j+k]=replace[k];  //yeni metni yerlestiriyoruz
            }
            
            
            for(u=i;u<found_count;u++){
                found[u]=found[u]+dif;  //found tablomuzu yine guncelliyoruz
            }

        }
          
    }

}


int bmh_find(char* input, char* pattern,int* table,int* found,int cs_secim){

    int i=0,j=0,inputsize, patternsize,found_count=0;

    inputsize=strlen(input)-1;      
    patternsize=strlen(pattern)-1;


    char crnt_in,crnt_pat;
 
    i=patternsize;          //i indisini ilk yerlesmede inputta patternin 
    while(i<=inputsize){    //  son indisine karsilik gelecek yere goturduk
                            //shift etme islemlerini karsilastirmaya basladigimiz patternin son indisi
                            //input'un son indisini gecmedigi surece yapiyoruz.
                            //gecerse zaten artik daha bulma sansimiz yok
        j=patternsize;      //pattern'den karakter okumak icin kullanacagimiz indisi
                            //patternsize yaptik ki en sagdaki karakterden okumaya baslasin. 
        while(j>=0){        //pattern'i en saga kadar okumayi bitirene kadar dongu calisir

            crnt_in=input[i-patternsize+j]; // i-patternsize+j bize input patternindeki gereken indisi veriyor
            crnt_pat=pattern[j];            // pattern indisi   hep pattern boyutundan 0'a kadar gidecek

            if(cs_secim==0){                //case sensitive 0 ise okudugumuz harflerin ikisini de once 
               crnt_in=tolower(crnt_in);    //kucuk harf yapip oyle kontrol ediyoruz
               crnt_pat=tolower(crnt_pat);   
            }

            if(crnt_in==crnt_pat){          //indislerin gosterdigi harfler esit oldukca j indisini azaltiyoruz
                    j--;
                }
            else{
                break;                      //esit degilse aranan pattern bulunamadigi icin donguyu kirip indisleri shift edecegiz
            }
              
        }
        if(j==-1){                          //dongu j indisi 0 dan kucuk olana kadar devam ettiyse aranan pattern bulunmustur
         
            found[found_count]=i-patternsize; // buldugumuz konumu found dizisine ekliyoruz
            found_count++;                     // found sayacimizi arttirdik
                        
            if(cs_secim==0){
                i=i+table[tolower(input[i+patternsize])]; //i nin shift edilecegi degeri bad character table'dan aldik
            }                                              //not case sensitive ise kucuk harf ile buyuk harfin shift degeri ayni 
                                                            //yerde tutulmustu
            else{
                i=i+table[input[i+patternsize]];           //buyuk kucuk harf ayri gozlerden alindi
            }
        }
        else{
            if(cs_secim==0){
                i=i+table[tolower(input[i])];       //i'yi  yine shift ediyoruz
            }
            else{
                i=i+table[input[i]];                
            }
        }
    }

    return found_count;              //bulunma sayisini donduruyoruz

}

void bctable(char* pattern, int* table,int cs_secim){

    int i,patternsize,shift;
    patternsize=strlen(pattern);

    
    for(i=0 ; i<256 ; i++){
        table[i]=patternsize;   //once tum harfler icin shift degerini varsayilan olarak
    }                           //pattern size'a esitliyoruz

    for(i=0 ; i<patternsize-1; i++){

        shift=patternsize-i-1;    //pattern'deki indis kaydikca harfin son goruldugu yerin son harfe uzakligi 
                                  //guncellenecek
        if(cs_secim==0){           
            char tmp;
            tmp=pattern[i];
            tmp=tolower(tmp);     // not case sensitive ise buyuk kucuk harfin shift degerini ayni gozde tut
            table[tmp]=shift;       
        }
        else{
            table[pattern[i]]=shift; //buyuk kucuk harf shift degerleri ayri gozlerde
        }
        
    }

}


int main(){

    char pattern[20],replace[20];

    char filename[20],buffer[MAXSIZE];
    int cs_secim;
    int table[256]={0};
    int found[128]={-1};
    int found_count;
    int inputsize;
    FILE *pfile=NULL;

    struct timespec t0;
    struct timespec t1;
    long int elapsed;
    
   
   
    

    
    while(pfile==NULL){
        printf("dosya ismini giriniz: \n");
        scanf("%s",filename);
        pfile=fopen(filename,"r+");
        if(pfile==NULL){
            printf(" \n dosya ismi yanlis ya da dosya acilamadi \n");
        }        
    }

    
    inputsize = fread (buffer,1,MAXSIZE,pfile);
    buffer[inputsize]='\0';
    fclose(pfile);

    printf("\n INPUT file:\n\n  %s \n\n\n",buffer);

    printf("aranacak kelimeyi giriniz: \n");
    scanf("%s",pattern);

    printf("yerine yazilacak ifadeyi giriniz: \n");
    scanf("%s",replace);

    printf("case sensitive : [1] \n case sensitive degil: [0] \n");
    scanf("%d",&cs_secim);
    
    clock_gettime(CLOCK_MONOTONIC,&t0);    //fonksiyonlar cagrilmadan time degeri alindi

    bctable(pattern,table,cs_secim);
    found_count = bmh_find(buffer,pattern,table,found,cs_secim);
    bmh_replace(buffer,pattern,replace,found,found_count);

    clock_gettime(CLOCK_MONOTONIC,&t1);     //fonksiyonlar bitince time degeri tekrar alindi

    elapsed=(t1.tv_sec-t0.tv_sec)*1000000000+(t1.tv_nsec-t0.tv_nsec);  //saniye ve nanosaniyeler toplami alindi

    printf("\n Running time:  %ld nanoseconds   \n",elapsed);    


    printf("\n Found and Replaced: %d  \n",found_count);

   

    printf("\n NEW file:\n  %s \n",buffer);


    inputsize=strlen(buffer);   

    pfile=fopen(filename,"w+");

    fseek(pfile, 0, SEEK_SET);

    fwrite(buffer,1,inputsize,pfile);

    fclose(pfile);

    getch();


    return 0;
}