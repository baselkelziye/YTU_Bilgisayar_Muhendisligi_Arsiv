#include <stdio.h>
int main(){ // Klavyeden girilen N (N>2 olmak zorunda) sayisina kadar olan asal sayilar ekrana yazan program
    int N, i,j,k; //local degiskenler
    do{
        printf("N ");
        scanf("%d",&N);
    }while(N<2);
    
    printf("2 asaldir\n");
    for(i=3;i<N;i++){
        k=2;
        
        
        
        
        while(i % k!=0 && k<i){
            k++;
        }
        if(k==i)
            printf("%d asaldir\n",i);
    }
}  //grup-2


