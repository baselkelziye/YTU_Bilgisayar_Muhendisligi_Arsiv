#include <stdio.h>
 
int enBykBul(int[], int, int);
 
int main(){
    int n; // Dizinin boyutu
    int dizi[20]; // En b�y�k eleman aranacak dizi
    int enbyk; // Dizinin anlik en buyuk elemanini tutan degisken
    int i; //� evrim de�i�keni
 	
 	// Dizi kullanicidan okunuyor.
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n);
    
    for (i = 0; i < n ; i++){
        printf("dizi[%d] : ",i);
        scanf("%d",&dizi[i]);
    }
    
    // Dizinin en b�y�k eleman�, dizinin ilk eleman� olarak belirleniyor.
    enbyk = dizi[0];
    
    // Rek�rsif en b�y�k eleman� bulmak fonksiyonu �a��r�l�yor.
    enbyk = enBykBul(dizi, n-1, enbyk);
    
    printf("\nDizinin en buyuk elemani: %d\n", enbyk);
    
    return 0;
}

int enBykBul(int dizi[], int n, int enbyk){
	//Rek�rsif fonksiyondan ��kma ko�ulu
    if (n == 0)
        return enbyk;
 	
 	//E�er dizi[n], enbyk'ten b�y�kse yeni enbyk dizi[n] oluyor
    if (dizi[n] > enbyk)
        enbyk = dizi[n];
    
	//Rek�rsif fonksiyon �a��r�l�yor.    
    return(enbyk = enBykBul(dizi, n-1, enbyk));
}
