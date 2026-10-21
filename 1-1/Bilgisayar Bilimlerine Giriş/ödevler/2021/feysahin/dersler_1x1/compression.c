#include<stdio.h>
int main(){
	int n,m,i,j,sayac=1,k=0, dizi[10][10], A[100], a=0, S[50], counter=0, B[50], b=0, C[10][10];
	float cr;
	printf("rowNumber:");
	scanf("%d",&n);
	printf("columnNumber:");
	scanf("%d",&m);
	printf("Enter the numbers, please:");
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&dizi[i][j]);						
		}
	    printf("\n"); 
	}
	printf("\nMatrix:\n");	
	for(i=0; i<n; i++){
        for(j=0; j<m; j++){
        printf("%d \t",dizi[i][j]);}
        printf("\n");
	}	
	for(i=0; i<n; i++){
	    for(j=0; j<m; j++){
	    	
	    	A[k]=dizi[i][j];
	    	k=k+1;
		}
	    printf("\n"); 
	}
	printf("Output After Compression:\n");
	for(k=0; k<n*m; k++){
		if(A[k]!=A[k+1]){
		    S[a]=sayac;
		    B[b]=A[k];
		    printf("%d %d  ",sayac,A[k]);
		    a=a+1;
		    b=b+1;
			sayac=1;
			counter=counter+1;			 	    
			}
		else{
		    sayac=sayac+1;
		}
	}
    a=0;
    b=0;
    for(i=0; i<n; i++){
	    for(j=0; j<m; j++){
	    	if(S[a]!=1){
	    		C[i][j]=B[b];
	    		S[a]=S[a]-1;
			}
			else{
				C[i][j]=B[b];
				a=a+1;
				b=b+1;
			}
		} 
	}	
	printf("\n\nThe New Matrix After Decompression:\n");
	 for(i=0; i<n; i++){
	    for(j=0; j<m; j++){
	    	printf("%d ",C[i][j]);
		} 
		printf("\n");
	}
	cr=(float) (counter*2)/(m*n);
	printf("\nCompression Ratio: %f", 1-cr);
	return 0;
}
