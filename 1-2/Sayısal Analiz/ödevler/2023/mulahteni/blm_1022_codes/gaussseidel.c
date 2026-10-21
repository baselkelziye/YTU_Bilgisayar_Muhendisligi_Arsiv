#include <stdio.h>
#include <math.h>
void swap(float [][25], int, int);
void islem(float [][25], float [25], float, int, int);

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


void islem(float matris[25][25], float deger[25], float hata, int m, int n){//Metodu uyguluyorum
	int i,j;
	float eskideger[m], farktoplam;
	do{
		farktoplam=0;
		for(i=0;i<m;i++){
			eskideger[i] = deger[i];
			deger[i] = matris[i][n-1];
			for(j=0;j<m;j++){
				if(i!=j){
					deger[i] -= matris[i][j]*deger[j];
				}
			}deger[i]/=matris[i][i];	
		}for(i=0;i<m;i++){
			farktoplam += deger[i] - eskideger[i];
		}
	}while(fabs(farktoplam)>=hata*m);	
}


int main(){
	float deger1, hata, matris[25][25], deger[25];
	int i,j,m;
	printf(" Gauss Seidel Metodu\n\n");
	printf("\tDenklem sayisi = ");scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("\t\tM[%d][%d] = ",i,j);scanf("%f",&matris[i][j]);
		}
	}printf("\n");
	for(i=0;i<m;i++){
		printf("\n %d.Denklemin cevabi = ",i+1);scanf("%f",&matris[i][m]);
	}
	for(i=0;i<m;i++){
		printf("\n Kullanilacak ilk X%d degeri = ",i);scanf("%f",&deger[i]);
	}
	printf("\n Istenen hata degeri = ");scanf("%f",&hata);
	swap(matris,m,m+1);
	islem(matris,deger,hata,m,m+1);
	for(i=0;i<m;i++){
		printf("\n\tBulunan X%d degeri = %f",i,deger[i]);
	}

	return 1;
}
