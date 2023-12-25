#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
    int i,j,n,m;
    
    int ogr[40][40],cevap[20],puan[2][20],tp=0,ort=0;
    printf("Kac ogrenci ve kac soruluk sinav m X n\n"); 
  	scanf("%d %d",&m,&n); 
  	
  	for (  i = 0; i < 2; i++ ) {
        for (  j = 0; j < m; j++ ) {
            puan[i][j] =  0;
        }
    }
  	for (  i = 0; i < m; i++ ) {
        for (  j = 0; j < n; j++ ) {
            ogr[i][j] = rand() % 3+1;
             printf("%3d ", ogr[i][j]);
        }
        printf("\n");  
    }
    printf("\n"); 
    for (  i = 0; i < n; i++ ) {
    	cevap[i]= rand() % 3+1;
    	printf("%3d ", cevap[i]);
    }
    
    for (  i = 0; i < m; i++ ) {
        for (  j = 0; j < n; j++ ) 
		{
			
            if(ogr[i][j] -cevap[j]==0)
            {
            
             puan[0][i]=puan[0][i]+1;
             
            }
       }
    }
    printf("\n");
   for (  i = 0; i < m; i++ ) {
             puan[0][i]=puan[0][i]*(100/n);
            printf("%d.ogrencinin puani%d\n",i+1,puan[0][i]);
            tp=tp+puan[0][i];     
    }  
    
    ort=tp/m;
    for (  j = 0; j < m; j++ ) {
           if(puan[0][j] >=ort)
           	puan[1][j]=1;
           	else
           		puan[1][j]=0;
            
    }
     for (  j = 0; j < m; j++ ) {
     	
           if(puan[1][j]==1)
           	printf("%d.ogrenci geçti\n",j+1);
           	else
           	printf("%d.ogrenci kaldi\n",j+1);
            
    }
}
    
    
    
    
