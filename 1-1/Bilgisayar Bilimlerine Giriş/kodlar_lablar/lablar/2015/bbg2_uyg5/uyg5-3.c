#include <stdio.h>
 
int enBykBul(int[], int, int);
 
int main(){
    int n; // Dizinin boyutu
    int dizi[20]; // En büyük eleman aranacak dizi
    int enbyk; // Dizinin anlik en buyuk elemanini tutan degisken
    int i; //Ç evrim deðiþkeni
 	
 	// Dizi kullanicidan okunuyor.
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n);
    
    for (i = 0; i < n ; i++){
        printf("dizi[%d] : ",i);
        scanf("%d",&dizi[i]);
    }
    
    // Dizinin en büyük elemaný, dizinin ilk elemaný olarak belirleniyor.
    enbyk = dizi[0];
    
    // Rekürsif en büyük elemaný bulmak fonksiyonu çaðýrýlýyor.
    enbyk = enBykBul(dizi, n-1, enbyk);
    
    printf("\nDizinin en buyuk elemani: %d\n", enbyk);
    
    return 0;
}

int enBykBul(int dizi[], int n, int enbyk){
	//Rekürsif fonksiyondan çýkma koþulu
    if (n == 0)
        return enbyk;
 	
 	//Eðer dizi[n], enbyk'ten büyükse yeni enbyk dizi[n] oluyor
    if (dizi[n] > enbyk)
        enbyk = dizi[n];
    
	//Rekürsif fonksiyon çaðýrýlýyor.    
    return(enbyk = enBykBul(dizi, n-1, enbyk));
}
