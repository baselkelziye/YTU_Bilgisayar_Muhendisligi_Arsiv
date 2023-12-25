#include <stdio.h>

int topla(int n);

int main(){
    int n, top;
	
    printf("Pozitif tam sayi giriniz: ");
    scanf("%d",&n);
    
    top = topla(n);
    
    printf("\nToplam = %d", top);
    
    return 0;
}

int topla(int n){
    if(n == 0)
       return n;
    else
       return n + topla(n-1);
}
