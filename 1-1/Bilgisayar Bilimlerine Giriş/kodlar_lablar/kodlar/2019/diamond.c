#include <stdio.h>


int main()
{
 int i,j,boyut;
 
 printf("Baklava diliminin kose uzunlugunu giriniz:");
 scanf("%d",&boyut);
 
 for(i=1;i<=boyut;i++)
 {
  for(j=1;j<=boyut-i;j++)
  {
   printf(" ");
  }
  
  for(j=boyut;j>=boyut+1-i;j--)
  {
   printf("*");
  }
  
  for(j=boyut+1;j<=i+boyut-1;j++)
  {
   printf("*");
  }
  
 printf("\n");  
 }
 
 
 for(i=2;i<=boyut;i++)
 {
  for(j=boyut;j>boyut+1-i;j--)
  {
         printf(" ");
  }   

  for(j=1;j<=boyut+1-i;j++)
               {
                      printf("*");
               }
   
  for(j=1;j<boyut+1-i;j++)
  {
       printf("*");
  }        
  
  printf("\n");  
       }  
 
return 0; 
} 
