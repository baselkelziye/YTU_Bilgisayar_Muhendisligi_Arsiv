#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float fonk(float x); 
float trapez(float ilk, float son, float n); 

 
int main()
{
    float x0,xn;
    float n;
    
    printf("baþlangýc degeri giriniz:");
    scanf("%f",&x0);
    //0 
    printf("bitiþ noktasýný giriniz:");
    scanf("%f",&xn);
	//1 
	
    printf("n aralýk degerini giriniz:");
    scanf("%f",&n);
 	
    printf("integral sonucu= %0.4f\n",trapez(x0, xn, n));
    return 0;
}

//fonksiyon
float fonk(float x)
{
    return 1/(1+x*x);
}


float trapez(float ilk, float son, float n)
{
	int i;
    float h = (son-ilk)/n;
 						
    float s = (fonk(ilk)+fonk(son))/2;
 
    for (i = 1; i < n; i++)
        s += fonk(ilk+i*h);
    return h*s;
}
