#include <stdio.h>

int topla(int n);

int main(){
    int n; // ka�a kadar say�lar�n toplanaca��
	int top; //toplam�n yaz�laca�� de�i�ken
	
	//Say� kullan�c�dan okunuyor
    printf("Pozitif tam sayi giriniz: ");
    scanf("%d",&n);
    
    //Rek�rsif fonksiyon �a��r�l�yor.
    top = topla(n);
    
    printf("\nToplam = %d", top);
    
    return 0;
}

int topla(int n){
    if(n == 0) //rek�rsif fonksiyondan ��kma �art�
       return n;
    else
       return n + topla(n-1); //fonksiyon rek�rsif olarak �a��r�l�yor.
}
