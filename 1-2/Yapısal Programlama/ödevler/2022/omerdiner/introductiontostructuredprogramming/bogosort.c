#include <stdio.h>
#include <stdlib.h>
#define SIZE 500
int isSorted(int *arr, int n);
void printArray(int *arr,int n);
int bogoSort(int *arr,int n);
int main(){
	srand(time(NULL));//random sayýlar düzgün üretilsin diye
	int i,n,arr[SIZE];
	
	printf("Array size:");
	scanf("%d",&n);
	
	// kullanýcý uðraþmasýn diye diziyi 1-1000 arasýnda rastgele elemanlarla doldurur
	for(i=0;i<n;i++){
		arr[i] = rand()%(999) + 1;
	}
	
	printf("Random generated array:\n");
	printArray(arr,n);
	//sýralama bittikten sonra fonksiyonun toplam kaç kere diziyi karýþtýrmak için en içteki swap iþlemini yaptýðýný gösteren sayýyý deðiþkenle alýyorum
	
	int complexityCount=bogoSort(arr,n);
	
	printf("\n\nAfter sorted:\n");
	printArray(arr,n);
	printf("\n\nTotal %d swap processes.",complexityCount);
	
	return 0;
}

// dizi sýralý mý diye bakýyor deðilse -1 döndürüyor
int isSorted(int *arr, int n){
	//n eleman sayýsýný temsil ediyor ama indisler 0'dan baþladýðý için hata oluþmasýn diye n 1 azalýyor
	n=n-1;
   while ( n >= 1 ) {
      if ( arr[n] < arr[n-1] ){
    	  return -1;
	  }else{
		n--;
	 }
   }
   
    return 1;
}
void printArray(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

//normalde void olarak iþlem yapýlýrdý ama iþlem sayýsýný maine döndürmek için int döndüren bir fonksiyon tanýmladým
int bogoSort(int *arr,int n){
	int i, tmp, randomIndex , count=0;
	
	
	while(isSorted(arr,n)==-1){//sýralý olmadýðý sürece
	      
		  for(i=0; i < n; i++) { //n kere dizinin elemanlarýný rastgele indisleriyle swap iþlemi yap
		        count++;
                tmp = arr[i];
                randomIndex = rand() % n;
                arr[i] = arr[randomIndex];
                arr[randomIndex] = tmp;
           }
   }
   return count; 
}
