#include <stdio.h>
#define SIZE 50
void ganttDraw(char *arr,int * starts,int * finishes, int n);
int isFinishBigger(int start,int finish);
int isUnique(char *arr,char c,int n);


int main(){
	
	int i,n,tmp=0;
	char ch;
	char chars[SIZE] ;
	int starts[SIZE],finishes[SIZE];
	
	printf("Faaliyet sayisi:");
	scanf("%d",&n);
	
	while(tmp<n){
		printf("%d. isin harf kodu:",tmp+1);
		scanf(" %c",&ch);
		if(isUnique(chars,ch,n)==0){
			printf("Ayni is zaten girildi. %d. isi tekrar giriniz.\n",tmp+1);
		}else{
			chars[tmp]=ch;
			tmp++;
		}
	}
	for(i=0;i<n;i++){
		printf("%c islemi baslangic zamani:",chars[i]);
		scanf("%d",&starts[i]);
		while(starts[i]<1){
			printf("Baslangic zamani 1'den buyuk olmali.Bir daha giriniz.\n");
			scanf("%d",&starts[i]);
		}
		
		printf("%c islemi bitis zamani:",chars[i]);
		scanf("%d",&finishes[i]);
		while(isFinishBigger(starts[i],finishes[i])==0){
			printf("Bitis zamani baslangictan buyuk olmali.Bir daha giriniz:\n");
			scanf("%d",&finishes[i]);
		}
	}
	
	printf("\n---------GANTT CIZELGESI-------\n");
    ganttDraw(chars,starts,finishes,n);
	
	
	return 0;
}

void ganttDraw(char *arr,int * starts,int * finishes, int n){
	
	int i;
	int tmp=0;
	
	for(i=0;i<n;i++){
		
		tmp=0;
		while(tmp<starts[i]-1){
			printf("_");
			tmp++;		
		}
		while(tmp<finishes[i]){
			printf("%c",arr[i]);
			tmp++;
		}
		
		printf("\n");
	}
	
}
int isFinishBigger(int start,int finish){
	if(finish<=start){
		return 0;
	}else{
		return 1;
	}
}
int isUnique(char *arr,char c,int n){
	
	int i;
	
	for(i=0;i<n;i++){
		if(arr[i]==c){
			return 0;
		}
	}
	
	
	return 1;
	
}
