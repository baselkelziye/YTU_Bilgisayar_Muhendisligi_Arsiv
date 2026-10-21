#include<stdio.h>

int main(){
	
	int r,c,i,j,k,matris[50][50];
	int matrisRota[50];
	printf("satir sayisini girin: ");
	scanf("%d",&r);
	printf("sutun sayisini girin: ");
	scanf("%d",&c);
	
	printf("matris elemanlarini girin:\n ");
	printf("lutfen sadece 1 ve 0 giriniz ");
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			
			scanf("%d",&matris[i][j]);
			
		}
	}
	
	for(i=0;i<r;i++){
        for(j=0;j<c;j++){

            printf("%d ", matris[i][j]);

        }
        printf("\n");
    }

	i=0;
    j=0;
    k=0;

        if(matris[i][j+1]==1){

            while(matris[i][j+1]==1&&j<c){
                matrisRota[k]=1;
                j++;
                k++;
            }
            while(matris[i+1][j]==1&&i<r){
                matrisRota[k]=2;
                i++;
                k++;
            }

        }
        else{
            while(matris[i+1][j]==1){
                matrisRota[k]=2;
                i++;
                k++;
            }
            while(matris[i][j+1]=1){
                matrisRota[k]=1;
                i++;
                k++;

            }
        }
        
    for(i=0;i<k;i++){
        printf("%d ", matrisRota[i]);
    }
    if(k!=1 || k!=2){
    	printf("rota olusturulamadi");
	}
	return 0;
}
