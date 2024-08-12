#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** genislet(char** kelimeler, int n, int max);
void printKelimeler(char** kelimeler, int n);
void asteriksDoldur(char** kelimeler, int n, int max);

int main(){
	
	char** kelimeler;
	int n,i,m, max=0; 
	char dummy[52];
	printf("kelime dizisinin eleman sayisini veriniz?");
	scanf("%d",&n);
	kelimeler=(char**) calloc (n,sizeof(char*));
	printf("elemanlari veriniz\n");
	for (i=0;i<n;i++)
	{
		do{
			scanf("%s",dummy);
	    	m=strlen(dummy);
	    	/*if(m>=max){
	    		max=m;
			}
			*/
	    	if(m>=50){
	    		printf("kelime 50 karakterden fazla olamaz tekrar girin: ");
			}
			
	    		
		}while(m>=50);
	    
	    printf("buraya geciyor");
	    printf("\nm:%d",m);
	    kelimeler[i]=(char*) calloc (m+1,sizeof(char)); 
	    printf("buraya da geciyor");
	    strcpy(kelimeler[i],dummy);
	    printf("buraya da da geciyor");
	    
	   
	}
	kelimeler = genislet(kelimeler, n, max);
	asteriksDoldur(kelimeler, n, max);
	printKelimeler(kelimeler, n);
	for(i=0;i<n;i++){
		free(kelimeler[i]);
	}
	free(kelimeler);

	
	return 0;
}
void asteriksDoldur(char** kelimeler, int n, int max){
	int i, j, k;
	for(i=0;i<n;i++){
		
		for(j=strlen(kelimeler[i]);j<max;j++){
			kelimeler[i][j]='*';
		}
	}
}

char** genislet(char** kelimeler, int n, int max){
	int i;
	for(i=0;i<n;i++){
		kelimeler=(char**)realloc(kelimeler, (max+1)*sizeof(char*));
	}
	return kelimeler;
}

void printKelimeler(char** kelimeler, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s\n",kelimeler[i]);
	}
}

