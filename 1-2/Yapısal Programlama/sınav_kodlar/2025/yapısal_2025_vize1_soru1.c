//yapýsal 2025 vize 1 soru 1

#include <stdio.h>

// bir karakter dizisi veriliyor.
// Kod içinde de BÝRBÝRÝNDEN BAÐIMSIZ ÇALIÞACAÐI kabul edilen 10 printf ifadesi var.
// Doðru olduðunu düþündüðünüz printf çýktýsýný yanýnda verilen yorum satýrý boþluðuna yazýnýz.
// Hatalý kullanýmlar varsa "compiler error" yazmanýz yeterlidir.
// (10x3 = 30 puan)

int main() {
	
    char *x[5] = { "THYAO-304.75", "ASELS-117.40", "TKFEN-130.30",
                   "AEFES-161.30", "ARCLK-132.70" };
                   
    int j=1, m=1, n=0, w=7, z=4;
    float a=2;
    
    char *y[] = { x[1], x[3], x[0] };
    char *p=x[2]; 
    
    printf("%s \n", (p+4));                     		 // (N-130.30)
    printf("%s \n", y[1]);                      		 // (AEFES-161.30)
    printf("%c \n", *(*(y+1))[6]);           		     // (compile error)
    printf("%c \n", *(*(x+2)+1));               		 // (K)
    printf("%c%c%c\n", x[1][2], x[3][2], x[2][4]);		 // (EFN)
    printf("%c \n", p[3]+1);                     		 // (F)
    printf("%s \n", *p[3]);                  		     // (compile error)
    printf("%d \n", j < (++m && n-j) );          		 // (0)
    w/=a;
    printf("%d \n", w<<1 );                      		 // (6)
    printf("%f \n", z++ * 2.5 + --j );           		 // (10.000000)
    
    return 0;
}
