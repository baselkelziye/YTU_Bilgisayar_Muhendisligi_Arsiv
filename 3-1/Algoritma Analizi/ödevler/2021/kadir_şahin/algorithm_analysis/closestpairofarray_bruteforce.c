#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int main(){

    int arr[MAX],N,i;


     do
     {
        printf("Lutfen dizi boyutu giriniz (2-30) :   ");
        scanf("%d",&N);
     } 
     while( (N<2 ) || (N>30)); 
     

    for(i=0;i<N;i++){
        printf("%d. elemani giriniz: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");

    for(i=0;i<N;i++){
        printf(" %d  ",arr[i]);
    }

    int j,sayi1,sayi2,dist;
    dist=abs(arr[1]-arr[0]);
    sayi1=arr[0];
    sayi2=arr[1];
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            if(abs(arr[i]-arr[j])<dist){
                dist = abs(arr[i]-arr[j]);
                sayi1=arr[i];
                sayi2=arr[j];
            }
            
        }
    }
    
    printf("en yakin sayilar: %d - %d    fark: %d",sayi1,sayi2,dist);
	
    return 0;
}