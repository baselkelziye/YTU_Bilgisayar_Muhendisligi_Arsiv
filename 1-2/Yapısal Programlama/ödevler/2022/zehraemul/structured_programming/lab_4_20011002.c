#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50


int harfkontrol(char ch,char* harf,int current){
	int kontrol=0,i;
	for(i=0;i<current-1;i++){
		if(harf[i]==ch){
			kontrol=1;
		}
	}
	return kontrol;
}

int baslabitkontrol(int basla,int bit){
	int kontrol=0;
	if(basla>bit){
		kontrol=1;
	}
	return kontrol;
}

void GanttDraw(int n,char* kod,int* basla,int* bit){
	int i,j;
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c:",kod[i]);
		for(j=0;j<basla[i];j++){
			printf(" ");
		}
		for(j=0;j<(bit[i]-basla[i]);j++){
			printf("#");
		}
		printf("\n");
	}
}

int main(){
	int i,n;
	char harf[size];
	int start[size];
	int stop[size];
	
	printf("Faaliyet sayisini giriniz:");
	scanf("%d",&n);
	
	printf("Yapilacak islerin harf kodlarini giriniz:\n");
	
	for(i=0;i<n;i++){
		printf("%d. isin harf kodunu girin: ",i+1);
		scanf(" %c",&harf[i]);
		while(harfkontrol(harf[i],harf,i)==1){
			printf("bu harf koduna sahip baska is var. Tekrar giriniz:");
			scanf("%c",&harf[i]);
		}
	}
	
	printf("Yapilacak islerin sirasiyla baslangic ve bitis zamanlarini girin:\n");
	
	for(i=0;i<n;i++){
		printf("%c isin baslangicini girin:",harf[i]);
		scanf("%d",&start[i]);
		printf("%c isin bitisini girin:",harf[i]);
		scanf("%d",&stop[i]);
		while(start[i]<=0 || stop[i]<=0 || baslabitkontrol(start[i],stop[i])){
			printf("bir hata var. tekrar deneyiniz...\n");
			printf("%c isin baslangicini girin:",harf[i]);
			scanf("%d",&start[i]);
			printf("%c isin bitisini girin:",harf[i]);
			scanf("%d",&stop[i]);
		}
	}
	
	GanttDraw(n,harf,start,stop);
	
	
	return 0;
}
