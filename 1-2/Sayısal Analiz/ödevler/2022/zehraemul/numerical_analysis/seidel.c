#include<stdio.h>
#include<math.h>
int main(){
	float matris[10][10],c,temp,sonuc[10],max[10],xyz[10];
	int x,y,i,j,k,n;
	
	printf("GAUSS SEIDEL YONTEMI\n");
	printf("Bilinmeyen sayisini girin:\n");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		sonuc[i]=0;
	}
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("%d. denklemin %d. katsayisini girin:\n",i+1,j+1);
			scanf("%f",&matris[i][j]);
		}
		printf("%d. denklemin sonucunu girin:\n",i+1);
		scanf("%f",&matris[i][x]);
	}
	printf("\n");
    for(i=0;i<x;i++){
    	printf("%d. degiskenin baslangic degeri?:\n",i+1);
    	scanf("%f",&xyz[i]);
	}
	printf("Istediginiz iterasyon sayisini girin:\n");
	scanf("%d",&n);
	for(i=0;i<x;i++){
		for(j=0;j<x+1;j++){
			if(j==x){
				printf(" | %f",matris[i][j]);
			}else{
				printf("%f ",matris[i][j]);			
			}
		}
		printf("\n");
	}

	for(i=0;i<x;i++){
		temp=fabs(matris[i][0]);
		max[i]=0;	
		for(j=0;j<x;j++){
			if(fabs(matris[i][j])>fabs(temp)){
				temp=matris[i][j];
				max[i]=j;
			}
		}
	}
	for(i=0;i<x;i++){
		if(max[i]!=i){
			for(j=0;j<x;j++){
				if(max[i]==j){
					for(k=0;k<x+1;k++){
			    	temp=matris[i][k];
			    	matris[i][k]=matris[j][k];
				    matris[j][k]=temp;				
					}	
					max[j]=max[i];
					max[i]=i;
				}
			}
		}
	}
	printf("\nEN BUYUK DEGER KOSEGEN USTUNDE\n");
	for(i=0;i<x;i++){
		for(j=0;j<x+1;j++){
			if(j==x){
				printf(" | %f",matris[i][j]);
			}else{
				printf("%f ",matris[i][j]);			
			}
		}
		printf("\n");
	}	
	for(k=0;k<n;k++){
		for(i=0;i<x;i++){
		temp=matris[i][x];
		for(j=0;j<x;j++){
			if(i!=j){
			    sonuc[i]=temp-matris[i][j]*xyz[j];
				temp=sonuc[i];			
			}
		}
			xyz[i]=sonuc[i]/matris[i][i];
	}	
	printf("\n%d.ITERASYON\n",k+1);
		for(i=0;i<x;i++){
		printf(" %d. bilinmeyenin degeri = %f\n",i+1,xyz[i]);
	 }
	}

	return 0;
}
