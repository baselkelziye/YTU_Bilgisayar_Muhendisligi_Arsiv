#include<stdio.h>
#include<math.h>
int main(){
	float matris[10][10],c,tmp,temp;
	int x,y,i,j,k,flag,a=0;
	
	printf("GAUSS ELEMINASYON YONTEMI\n");
	printf("Bilinmeyen sayisini giriniz: ");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		sonuc[i]=0;
	}
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("%d. denklemin %d. katsayisini girin: ",i+1,j+1);
			scanf("%f",&matris[i][j]);
		}
		printf("%d. denklemin sonucunu girin: ",i+1);
		scanf("%f",&matris[i][x]);
	}
	printf("\nDenklemin matris uzerindeki hali\n");
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
	for(k=0;k<x;k++){
	
	    if(matris[k][k] == 0){
              flag = 0;

              while(a<x && flag==0){

                  if(matris[a][k] != 0){

                       for(y=0; y<x+1; y++){                                          	
                           tmp = matris[k][y];
                           matris[k][y] = matris[a][y];
                           matris[a][y] = tmp;
                    }
                    flag = 1;
            }
             a++;
        }		
   }
}
	for(k=0;k<x-1;k++){
	for(i=k+1;i<x;i++){
		c=matris[i][k]/matris[k][k];
		for(j=0;j<x+1;j++){
			matris[i][j]=matris[i][j]-(c*matris[k][j]);
		}
	}
}
	
	printf("\nUst ucgen hali\n");
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
	matris[x-1][x]=matris[x-1][x]/matris[x-1][x-1];
	tmp=matris[i][x];
	for(i=x-2;i>=0;i--){
		for(j=i+1;j<x;j++){
			matris[i][x]=matris[i][x]-matris[i][j]*matris[j][x];	
		}
		matris[i][x]=matris[i][x]/matris[i][i];
    }
	
	printf("\nSonuclar:\n");
	for(i=0;i<x;i++){
		printf("%d. bilinmeyen = %f\n",i+1,matris[i][x]);
	}	

	return 0;
}
