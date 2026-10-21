#include<stdio.h>
#include<stdlib.h>

/*
	En kötü durum-> n*m
	En iyi durum-> 
*/

int main(){
	
	int n, m, i, j, k, say, flag=0, c=0;
	printf("matris boyutunu giriniz (n-m): ");
	scanf("%d %d", &n, &m);
	int piksel[n][m], *pikselDizisi, renk[2][n*m];
	
	for(i=0; i<2; i++){
		for(j=0; j<n*m; j++){
			renk[i][j]=-1;
		}
	}	
	//piksel  deðerlerini kullanýcýdan alma
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d-%d: ", i, j);
			scanf("%d", &piksel[i][j]);
		}
	}
	//kontrolü kolaylaþtýrmak için diziye dönüþtürme
	pikselDizisi = (int*)malloc(n*m*sizeof(int));
	while(k<n*m){
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				pikselDizisi[k] = piksel[i][j];
				
				printf("%d ", pikselDizisi[k]);
				k++;
			}
		}
	}
	for(i=0; i<n*m; i++){
		say=0;
		flag=0;
		//renk matrisini kontrol etme
		for(j=0; j<n*m; j++){
			if(renk[0][j]==pikselDizisi[i]){
				flag=1;
			}
		}
		if(flag==0){
			for(k=0; k<n*m; k++){
				if(pikselDizisi[i]==pikselDizisi[k]){
					say++;
				}
			}
			renk[0][c] = pikselDizisi[i];
			renk[1][c] = say;
			//printf("%d-%d\n", renk[0][c], renk[1][c]);
			c++;				
		}
	}
	printf("\nFarkli renk sayisi: %d\n\n", c);	
	printf("renk: ");
	for(i=0; i<c; i++) printf("%d ", renk[0][i]);
	printf("\nadet: ");
	for(i=0; i<c; i++) printf("%d ", renk[1][i]);
	free(pikselDizisi);
	return 0;
}
