#include <stdio.h>
#include <stdlib.h>
int * sifirDizisi(int size);
int ** menu(int ** board,int * size);
void renkleriYazdir(int ** masa,int size);
void cozumVarMi(int **masa, int N, int sayi,int yazdir,int * flag);
int validMi(int** masa,int size,int sayi);

int main() {
	int i,j;
	int size,choice=1,flag;
	int **masa;
	masa = menu(masa,&size);
	printf("Secim yapiniz\n1 Detay Mod\n2 Normal Mod\n0 Cikis\n");
	scanf("%d",&(choice));
	if(choice==2){
		cozumVarMi(masa,size,2,0,&flag);
		if (flag) {
	       renkleriYazdir(masa,size);
	       printf("Cozum bulundu tebrikler...\n");
	    } else {
	    	renkleriYazdir(masa,size);
	        printf("Cozum Yok.\n");}
	}
    else if(choice==1){
    	cozumVarMi(masa,size,2,1,&flag);
    	if (flag) {
	       printf("Cozum bulundu tebrikler...\n");
	    } else {
	    	renkleriYazdir(masa,size);
	        printf("Cozum Yok.\n");
	    }
	}
	else if(choice!=0)
		printf("Duzgun secim yapilmadi!!!\n");
	else
		printf("Cikis basariyla yapildi...");
	return 0;
}
int * sifirDizisi(int size){
	int * dizi;
	dizi=(int *)calloc(size,sizeof(int));
	return dizi;
}
int ** menu(int ** masa,int * size){
	int i,j;
	printf("Renk tablosu\n");
	printf("Kirmizi icin 0\nSari icin 1\nMavi icin 2\nYesil icin 3\nMor icin 4\nTuruncu icin 5\nTurkuaz icin 6\nPembe icin 7\n");
	printf("Sececeginiz renk, girdiginiz boyuttan kucuk olmalidir!!!\n");
	printf("Boyutu giriniz. Boyut>=3 && Boyut<=8 olmalidir\n");
	do{
		scanf("%d",&(*size));
		if(*size>8 || *size<3)
			printf("Boyutu duzgun giriniz!!!\n");
	}while(*size>8 || *size<3);
	masa =(int**)malloc((*size)*sizeof(int*));
	for(i=0;i<*size;i++){
		masa[i]=(int*)malloc(sizeof(int)*(*size));
	}
	for(i=0;i<*size;i++){
		for(j=0;j<*size;j++){
				printf("%d. satir %d. sutunu giriniz\n",i,j);
			do{
				scanf("%d",&masa[i][j]);
				if(masa[i][j]>=*size || masa[i][j]<0)
					printf("Rengi duzgun aralikta giriniz!!!");
			}while(masa[i][j]>=*size || masa[i][j]<0);
		}
	}
	return masa;
}
void renkleriYazdir(int ** masa,int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			switch(masa[i][j]){
				case 0:
					printf("Kirmizi\t");
					break;
				case 1:
					printf("Sari\t");
					break;
				case 2:
					printf("Mavi\t");
					break;
				case 3:
					printf("Yesil\t");
					break;
				case 4:
					printf("Mor\t");
					break;
				case 5:
					printf("Turuncu\t");
					break;
				case 6:
					printf("Turkuaz\t");
					break;
				case 7:
					printf("Pembe\t");
					break;		
			}
		}
		printf("\n");
	}
	printf("\n");
}
int validMi(int** masa,int size,int sayi) {
	int i,j,k;
    for (i = 0; i < size; i++) {
        int * sifirDizi=sifirDizisi(size);
        for (j = 0; j <sayi; j++) {
        	sifirDizi[masa[j][i]]++;
        }
        for(k=0;k<size;k++)
        	if(sifirDizi[k]>1){
        		return 0;
        		free(sifirDizi);
			}
        		
        free(sifirDizi);
    }
    return 1;
}
void rotate(int ** matrix,int index,int N){
	int i,tmp;
	tmp=matrix[index][N-1];
	for(i=N-1;i>0;i--){
		matrix[index][i]=matrix[index][i-1];
	}
	matrix[index][0]=tmp;
}
void cozumVarMi(int **masa, int N, int sayi,int yazdir,int * flag) {
	int i,j,le,m;
	if(sayi>N){
		*flag = 1;
		return;
	}
	if(validMi(masa,N,sayi)){
		if(sayi==N){
			*flag=1;
			return;
		}	
	} 
	for (i = 0; i < N; i++) {
		rotate(masa,sayi-1,N);
        if(yazdir==1)
    		renkleriYazdir(masa,N);
  		if(validMi(masa,N,sayi))
  			cozumVarMi(masa,N,sayi+1,yazdir,flag);
  		if(*flag==1)
  			return;
    }
    *flag=0;
    return;
}