#include <stdio.h>
int main(){ // klavyeden girilen bir sayýnýn asal bölenlerini ekrana yazan program
	int N, i, counter=0;
	do{	
		do{
			printf("N ");
			scanf("%d",&N);
		}while(N<=1);	
		i=2;
		while(i<=N){
			if(N % i==0){
				N/=i;
				printf("%d ",i); 
				/*if(counter !=i) eðer soruda asal çarpanlarýný sadece bir kez yazdýr deseydi bu þeilde bir kontrol yeterli olurdu.
	            {
	                printf("%d ",i);
	                counter = i; //counter deðiþkeninin ayrýca bu durum için tanýmlanmasý gerekir
	            } */
			}
			else
				i++;	
		}
		printf("\nDevam Etmek Icin <1>"); scanf("%d",&i);
		system("cls");
		}while(i==1);
	printf("Program Kapatildi. Bir tusa basiniz");
}  //grup-1

/*
int main(){ // Klavyeden girilen N (N>2 olmak zorunda) sayýsýna kadar olan asal sayýlarý ekrana yazan program
	int N, i,j,k;
	do{
		do{
			printf("N ");
			scanf("%d",&N);
		}while(N<2);
		printf("2 asaldir\n"); // Bu satýra gelmiþse 2'den büyük bir þey girilmiþ demektir.
		for(i=3;i<N;i++){
			k=2;
			while(i % k!=0 && k<i){
				k++;
			}
			if(k==i)
				printf("%d asaldir\n",i);
		}
		printf("Devam Etmek Icin <1>"); scanf("%d",&i);
		system("cls");
	}while(i==1);
	printf("Program Kapatildi. Bir tusa basiniz");
} */ //grup-2
