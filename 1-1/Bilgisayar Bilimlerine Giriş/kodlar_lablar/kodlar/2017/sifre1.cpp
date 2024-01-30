/*Her harfi X sonraki harfle yerdeðiþtirerek þifreleme*/
/* sadece büyük harflerle çalýþýr*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>
int main()
{
int k,i;
char kelime[6],sifkelime[6];
printf("5 HARFLi kelime yi giriniz:");
scanf("%s",kelime);
printf("harflerin ne kadar kaydirilacagini giriniz:");
scanf("%d",&k);
// SIFRELE
for (i=0;i<5;i++)
    sifkelime[i]='A'+((kelime[i]-'A'+k+26)%26);

sifkelime[5]='\0';
printf("sifrelenmis kelime %s",sifkelime);     
  
getch();
return 0;
}
