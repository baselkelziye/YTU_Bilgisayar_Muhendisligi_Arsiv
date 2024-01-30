#include <stdio.h>

int topla(int n);

int main(){
    int n; // kaça kadar sayýlarýn toplanacaðý
	int top; //toplamýn yazýlacaðý deðiþken
	
	//Sayý kullanýcýdan okunuyor
    printf("Pozitif tam sayi giriniz: ");
    scanf("%d",&n);
    
    //Rekürsif fonksiyon çaðýrýlýyor.
    top = topla(n);
    
    printf("\nToplam = %d", top);
    
    return 0;
}

int topla(int n){
    if(n == 0) //rekürsif fonksiyondan çýkma þartý
       return n;
    else
       return n + topla(n-1); //fonksiyon rekürsif olarak çaðýrýlýyor.
}
