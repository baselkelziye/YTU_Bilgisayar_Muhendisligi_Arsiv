/*Her bir harfi 
�ifre matrisinde kar��l�k geldi�i sat�r ve s�tun numaralar�n� 
kullanarak �ifreleme*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>
int main(){
char tab[3][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'}};
char kelime[5];
int i,j,k,sifkelime[5];
printf("5 HARFLi kelime yi giriniz:");
scanf("%s",kelime);
// S�FRELE
printf("SIFRELENMIS KELIME:");
for (i=0;i<5;i++)
{
    j=0;
    k=0;
    sifkelime[i]=11;
    while ((tab[j][k]!=kelime[i])&&(j<3))
    {
      k=0;
      while ((tab[j][k]!=kelime[i])&&(k<3))
        k++;
      if   (tab[j][k]!=kelime[i])
        j++;
      else 
      { 
        j++;
        k++; 
        sifkelime[i]=10*j+k;
      }
    }  
printf("%d ",sifkelime[i]);    
}    
getch();
return 0;
}
