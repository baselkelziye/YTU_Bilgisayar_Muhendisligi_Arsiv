#include <stdio.h>
int TopRecurse(int a, int b)	//iki pozitif sayiyi toplar, sayilar negatif olursa nasýl cozeriz?
{ 
	if (b==0) return a; 
	else 
		return TopRecurse(a+1,b-1); 
} 

int DiziTopRecurse(int* dizi, int b)	//bir dizinin elemanlarini toplayalim
{ 
	if (b==0) return dizi[b]; 
	else 
		return dizi[b]+DiziTopRecurse(dizi,b-1); 
} 

int ElemanAraRecurse(int* dizi, int b, int x)	//bir dizinin elemanlarini toplayalim
{ 
	if (b<0) return -1; 
	else 
		if (dizi[b]==x)	return b;
		else 			return ElemanAraRecurse(dizi,b-1,x); 
} 

int main( )
{ 
int dizi[5]={3,2,1,5,1};
printf ( "%d\n", TopRecurse(4,2) );
printf ( "%d\n", DiziTopRecurse(dizi,4) );
printf ( "%d\n", ElemanAraRecurse(dizi,4,7) );
return 0;
} 
