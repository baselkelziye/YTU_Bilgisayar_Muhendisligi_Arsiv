/*girilen sayýnýn okunusunu tersten yazar*/
#include <stdio.h>
#include <conio.h>
int main()
{
int sayi=2104591804;
char *birler[10]={" ","bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
char *onlar[10]={" ","on","yirmi","otuz","kirk","elli","atmis","yetmis","seksen","doksan"};
char *diger[10]={" ","bin","milyon","milyar"};
int z=1;
int k=1;
int T=0;
while (sayi>0)
{
      T=(sayi%10);
      if (k==1)
         printf("%s ",birler[T]);
      else if (k==2)
         printf("%s ",onlar[T]);
      else if (k==3)
         {if (T>0) printf("yuz %s ",birler[T]);}
      else if (k==4)
         {
         printf("%s ",diger[z]);
         printf("%s ",birler[T]);
         k=1;
         z++;       
         }
      sayi/=10;
      k++;
}
getch();
return 0;
}
