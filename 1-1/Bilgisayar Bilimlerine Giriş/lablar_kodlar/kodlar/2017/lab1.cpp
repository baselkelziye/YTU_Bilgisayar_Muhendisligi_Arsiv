#include <stdio.h>
#include <time.h>
#define N 15
int main()
{
    int i=0,artis,artmax;
    int dizi[N];
    int bas,basmax;
  
    printf("Sira ile dizi elemanlarinizi giriniz. \n");

    for(i=0;i<N;i++){
    	printf("%2d  ",i);
    	dizi[i]=rand()%10;
	}
    printf("\n");
    for(i=0;i<N;i++)
    	printf("%2d  ",dizi[i]);
    

    i=1;
    artis=0;
    bas=0;
    basmax=0;
    artmax=0;

    while(i<=N)
    {
        if(dizi[i-1]>dizi[i]){
        artis++;
        }
        else{
        if(artis>=artmax) { 
		artmax=artis; basmax=bas; 
		}
		
        artis=0;
        bas=i-1;
        }
        i++;
    }

   printf("\n\nAzalis:\nIndis =%d ",basmax+1);
   printf("\nUzunluk=%d",artmax+1);
   printf("\nBitis=%d",artmax+basmax+1);
   return 0;
}
