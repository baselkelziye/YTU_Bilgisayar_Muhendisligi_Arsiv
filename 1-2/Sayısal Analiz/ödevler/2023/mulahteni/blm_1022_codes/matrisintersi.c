#include <stdio.h>
#include <math.h>
#include <conio.h>

float determinant(float [][25],float);
void cofactors(float [][25],float);
void trans(float [][25],float [][25],float);
 
float determinant(float a[25][25], float k) {
	float s=1,det=0,b[25][25];
	int i,j,m,n,c;
	if(k==1){
		return(a[0][0]);
	}else{
 		det=0;
		for(c=0;c<k;c++){
			m=0;
			n=0;
			for (i=0;i<k;i++) {
				for (j=0;j<k;j++) {
					b[i][j] = 0;
					if (i!=0&&j!=c) {
						b[m][n]=a[i][j];
						if (n<(k-2)){
							n++;
						}else {
							n=0;
							m++;
						}
					}
				}
			}
			det=det+s*(a[0][c]*determinant(b,k-1));
			s=-1*s;
		}
	}
	return (det);
}

void cofactors(float num[25][25], float f) {
	float b[25][25],fac[25][25];
	int p,q,m,n,i,j;
	for(q=0;q<f;q++){
		for(p=0;p<f;p++){
			m=0,n=0;			
			for(i=0;i<f;i++){
				for(j=0;j<f;j++){
					b[i][j] = 0;
					if(i!=q&&j!=p){
						b[m][n]=num[i][j];
						if(n<(f-2)){
							n++;						
						}else{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p]=pow(-1,q+p)*determinant(b,f-1);
		}
	}
	trans(num,fac,f);
}

void trans(float num[25][25],float fac[25][25],float r) {
	int i,j;
	float b[25][25],inv[25][25],d;
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
 			b[i][j]=fac[j][i];
		}
 	}
 	d = determinant(num, r);
 	inv[i][j]=0;
 	for(i=0;i<r;i++){
 		for(j=0;j<r;j++){
 			inv[i][j]=b[i][j]/d;
 		}
 	}
 	printf("\n Matrisin Tersi Alinmis Hali...\n");
 	for(i=0; i < r; i++){
 		for(j=0;j<r;j++){
 			printf("\t%2f",inv[i][j]);
 		}
 		printf("\n");
 	}
 }

int main() {
	float a[25][25],n,d;
	int i,j;
	printf(" Matrisin Tersi\n");
	printf(" NxN lik Matrisin N degeri = ");scanf("%f", &n);
	printf(" Matrisin Elemanlari...\n"); 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\tM[%d][%d] = ",i+1,j+1);scanf("%f", &a[i][j]);
		}
	}
	d=determinant(a,n);
	if(d==0){
		printf("\n Matrisin tersi alinamaz...\n");
	}else{
		printf("\n Matrisin ilk hali...\n");
		for(i=0;i<n;i++){printf("\n");
			for(j=0;j<n;j++){
			printf("\tM[%d][%d] = ",i+1,j+1);
			}
		}
		cofactors(a,n);
	}  
	return 1; 
}
 

 


