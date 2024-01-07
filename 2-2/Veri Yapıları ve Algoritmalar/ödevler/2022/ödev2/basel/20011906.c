#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void printStack(char* stack, int sp){
    int i;
    printf("\nStack : ");
    for(i = sp; i>= 0; i--){
        printf("%c ",stack[i]);
    }
    printf("\n");
}

void Push(char x, int *sp, char* stack,int size){
   if(*sp == size-1){
       printf("\nError: StackOverFlow");
       return;
   }
    *sp = *sp +1;
    stack[*sp] = x;
}
void Pop(int *sp){
    if(*sp == -1){
        printf("Error: No element to pop\n");
        return;
    }
    *sp = *sp -1;
}


int main(){
 int sp =-1;
 int final_len,x,k,i =0;   
printf("\n");
 printf("Lutfen Sayi giriniz\n");
 scanf(" %d", &x);


    double toplam_bit_sayisi;  
    
    if(abs(x) != 1)
    {
    toplam_bit_sayisi = log(abs(x))/log(2); // kullanilacak bit sayisini bulmak icin log taban2 ni hesapladim
    final_len = ceil(toplam_bit_sayisi); //ve yukari yuvarlattim sonuc(8,0001 gibi bisey cikarsa 9 bit ayirsin en az)
    }
   else
   {
       final_len = 8; // log1 = 0 oldugu icin input 1 ve -1 oldugunda hata vermesin diye if kontrolu gerceklestirdim.
   }

   while(final_len%8 !=0){// burda bitleri 8 in katina olacak sekilde arttirim yaptim (9 bit yeterli ise 16 bit olsun bit sayisi)
       final_len++;
   }
   char* stack = (char*)malloc(sizeof(char)*final_len); // stack i bit uzunluguna gore dinamik bir sekilde olusturdum
   printf("\nToplam bit sayisi: %d\n",final_len);
 
 int result = 0;// butun digitleri bu degiskene topladim binary de digitleri toplamak 1 lerin sayisini bulmak demektir 
 // o yuzden counter kullanmadan 1 ve 0 larin (0 lar icin butun uzunlugundan 1 lerin sayisini cikarinca bulunur) bulmus oldum.

        for(i = 0; i< final_len; i++){ // burda oteleme ve maskeleme mantigi var
        //two's complement ile ugrasmamak adina bizim x degiskenimiz memory de nasil saklandigini hesaplattim.
        k = x>>i;
         result = result + (k&1);
        if(k&1){    
        Push('1', &sp, stack,final_len); //maskeleme sonucumuzu kaybetmemek icin stack'e atiyoruz
        }
        else{
         Push('0',&sp,stack,final_len);//maskeleme sonucumuzu kaybetmemek icin stack'e atiyoruz
        }   
    }
     printStack(stack,sp);

 if(result > (final_len-result)){ // 0 ve 1 leri hesaplama yontemi. 
     printf("\n1'ler fazladir. Ek %d adet '0' gereklidir.",result- (final_len-result));
 }
 else if(result < (final_len -result)){
     printf("\n0lar fazladir. Ek %d adet '1' gereklidir.",final_len-result - result);
 }
 else{
     printf("\n0 ve 1'ler esit sayidadir.");
 }
 
 free(stack); //stack icin ayirilan bellegi temizleme
printf("\n\n");
return 0;
}
