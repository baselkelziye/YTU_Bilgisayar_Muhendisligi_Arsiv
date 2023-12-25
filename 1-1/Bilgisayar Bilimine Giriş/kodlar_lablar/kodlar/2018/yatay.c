#include<stdio.h> 
#define width 50
#define height 50
int main() 
{ 
  srand(time(NULL));
  int n,m;
  char matrix[height][width],find[10]; 
  int k=0,i,j,len=0,temp,count=0 ; 
 
  printf("Matrisin boyutlarini giriniz n X m\n"); 
  scanf("%d %d",&n,&m); 
  
    // Fill random values in the matrix
    for (  i = 0; i < n; i++ ) {
        for (  j = 0; j < m; j++ ) {
            matrix[i][j] ='A'+rand() % 3;
            printf("%3c ", matrix[i][j]);
        }
         printf("\n");
    }
    printf("Aranacak kelimeyi giriniz\n");
    scanf("%s",find); 
    //len=strlen(find); 
    
    while(find[len]!='\0') len++;
 
   for(i=0;i<n;i++) 
  { 
  		j=0;
  		k=0;
        while(j<=m-len+k) 
        { 
          	if(k==len) 
			  {
        			k = 0;
			    	count++;
			    	printf("Matriste aranan kelime %d. satir, %d. sutundadir\n",i,j-2); 
			    	//j=j+1;
			  }
              else
              {
               	if(matrix[i][j]==find[k]) 
	           { 
	             	k++;
			   }
			   else
			   {
			   		j = j-k;
			   		k=0;
			   }
			   j++;
            }
           
        } 
   
   	} 
   	if(count==0)
   		printf("\nAranan Kelime Bulunamadi");
}
