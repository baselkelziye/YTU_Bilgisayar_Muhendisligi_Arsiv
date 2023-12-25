#include <stdio.h>

int main() {
    int i,j,n,m;
    
    int imag[40][40],hist[256],temp ;
    printf("Matrisin boyutlarini giriniz n X m\n"); 
  	scanf("%d %d",&n,&m); 

    // Fill random values in the matrix
     
    for (  i = 0; i < m; i++ ) {
        for (  j = 0; j < n; j++ ) {
            imag[i][j] = rand() % 10;
             printf("%3d ", imag[i][j]);
        }
        printf("\n");  
    }
    
    
    for (  i = 0; i < m; i++ ) {
        for (  j = 0; j < n; j++ ) {
        	temp=imag[i][j];
            hist[temp] +=1;;
            
        }
    }
    for (  i = 0; i < 10; i++ )
    printf("%d\n",hist[i]);
    
      for (  i = 0; i < 10; i++ ) {
     	for (  j = 0; j < hist[i]; j++ ) {
     		printf("%c",'*');
     	}
     	 printf("\n");
     }
    
}
     	
