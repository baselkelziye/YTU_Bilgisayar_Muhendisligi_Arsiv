#include <stdio.h>
#include <math.h>

void swap(float [][25], int, int);
void kosegen1(float [][25], int, int);

void swap(float matris[25][25], int m, int n){//Matrisin çaprazlarýný mutlak deðerce ayarlýyorum
	int i,j,k;
	float temp;
	for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(matris[i][i])<fabs(matris[k][i])){
                for(j=0;j<n;j++){                
                    temp=matris[i][j];
                    matris[i][j]=matris[k][j];
                    matris[k][j]=temp;
            	}
            }
        }
	}
}

void kosegen1(float matris[25][25],int m, int n){
	int i,j;
	float s;
	for(i=0;i<m-1;i++){
		s=matris[i][i];
        for(j=0;j<n;j++){
           	matris[i][j]/=s;
		}
	}
}

int main(){
	float matris[25][25],cevap[25],s,temp;
	int i,j,m,k;
	printf(" Gauss Eliminasyon Metodu\n\n");
	printf(" Matrisin denklem sayisi = ");scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("\n");
		for(j=0;j<m+1;j++){
			printf("\tM[%d][%d] = ",i,j);scanf("%f",&matris[i][j]);
		}
	}
	swap(matris,m,m+1);
	for(i=0;i<m;i++){
		printf("\n");
		for(j=0;j<m+1;j++){
			printf("\t%f",matris[i][j]);
		}
	}
	kosegen1(matris,m,m+1);
	for(i=0;i<m-1;i++){//Satýr iþlemleri uygulayarak üst üçgen yapýyorum		
		for(k=i+1;k<m;k++){
			s=matris[k][i]/matris[i][i];
            for(j=0;j<m+1;j++){
                matris[k][j]=matris[k][j]-s*matris[i][j];
            }
        }
        kosegen1(matris,m,m+1);
		swap(matris,m,m+1);
	}
	s=matris[m-1][m-1];
    for(i=0;i<m+1;i++){
        matris[m-1][i]/=s;
	}
	for(i=m-1;i>=0;i--){//üst üçgeni kullanarak deðiþkenlerin deðerleri buluyorum
        cevap[i]=matris[i][m];
        for(j=i+1;j<m;j++){
            cevap[i]=cevap[i]-matris[i][j]*cevap[j];
        }
        cevap[i]=cevap[i]/matris[i][i];
    }
	printf("\nUst ucgen matris : \n");
	for(i=0;i<m;i++){
		printf("\n");
		for(j=0;j<m+1;j++){
			if(j==m){
                printf(" | %f",matris[i][j]);
            }else{
                printf("%f ",matris[i][j]);           
        	}
		}
	}
	printf("\n\n Dogrusal denklemlerin cozumunde bulunan kokler : \n\n");
	for(i=0;i<m;i++){
    	printf("\tX[%d] = %f\n",i+1,cevap[i]);
   	}	
	return 1;	
}
