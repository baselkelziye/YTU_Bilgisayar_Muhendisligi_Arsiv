#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

int main() {
	
	srand(time(NULL));
	int i, j, m, n; //i ve j iterasyonlar icin n ve m matrisin satir ve sutun degerleri icin
	int matris[MAX][MAX]; //matrisimiz
	int flag = 0; //matrisin satir sutun degerlerinin dogrulugu icin kullanilacak flag
	int f = 0;//bos satir buldugumuzda degisecek flag
	
	
	while(flag == 0){
		printf("matrisin SATIR degerini giriniz (0 dan buyuk olmali) :  ");
    	scanf("%d", &n);


    	printf("matrisin SUTUN degerini giriniz (0 dan buyuk olmali) :  ");
    	scanf("%d", &m);
    
    	if(n > 0 && m > 0){
    		flag = 1;
		}else{
			printf("matris SATIR veya SUTUN degerini hatali girdiniz Lutfen tekrar deneyiniz!\n\n");	
		}
	}

    printf("\n");

    for(i = 0; i < n;i++) {
    	for(j = 0; j < m;j++) {
			matris[i][j] = rand()%2;
    		printf("%d ", matris[i][j]);
    		
    	}
    	printf("\n");
    }
    
    printf("\n");
    printf("CIKTI:\t");

	for( i=0; i<n;i++){
		j=0;
		while(matris[i][j] == 0 && j < m){
			j++;
		}if(j == m){
			printf("%d,",i+1);
			f=1;
		}
	
}
	if(f==0){
		printf("%d X %d MATRIS`imizde BOS SATIR YOKTUR",n,m);
	}else{
		printf(" BOS SATIRDIR.");
	}


	return 0;
}
