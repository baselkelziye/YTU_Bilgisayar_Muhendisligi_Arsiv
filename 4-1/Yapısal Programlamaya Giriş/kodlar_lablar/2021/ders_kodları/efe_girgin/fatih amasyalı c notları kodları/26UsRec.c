#include <stdio.h>
float UsRecurse(int x, int n)	//pozitif usler icin calisir
{ 
	if (n==1) return x; 
	else 
		return x*UsRecurse(x,n-1); 
} 

float UsRecurseV2(int x, int n)	//negatif usler icin calisir
{ 
	if (n==0) return 1; 
	else 
		return 1.0/x*UsRecurseV2(x,n+1); 
} 

float UsRecurseV3(int x, int n) //pozitif ve negatif usler icin calisir
{ 
	if (n==0) return 1; 
	else 
		if (n<0)	return 1.0/x*UsRecurseV3(x,n+1); 
	return x*UsRecurse(x,n-1); 
}

int main( )
{ 
printf ( "%f\n", UsRecurseV3(4,-2) );
return 0;
} 
