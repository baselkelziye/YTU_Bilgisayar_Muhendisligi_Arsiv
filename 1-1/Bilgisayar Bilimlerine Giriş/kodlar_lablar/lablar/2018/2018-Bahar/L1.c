#include <stdio.h>
int main(){ // klavyeden girilen bir say�n�n asal b�lenlerini ekrana yazan program
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
				/*if(counter !=i) e�er soruda asal �arpanlar�n� sadece bir kez yazd�r deseydi bu �eilde bir kontrol yeterli olurdu.
	            {
	                printf("%d ",i);
	                counter = i; //counter de�i�keninin ayr�ca bu durum i�in tan�mlanmas� gerekir
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
int main(){ // Klavyeden girilen N (N>2 olmak zorunda) say�s�na kadar olan asal say�lar� ekrana yazan program
	int N, i,j,k;
	do{
		do{
			printf("N ");
			scanf("%d",&N);
		}while(N<2);
		printf("2 asaldir\n"); // Bu sat�ra gelmi�se 2'den b�y�k bir �ey girilmi� demektir.
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
