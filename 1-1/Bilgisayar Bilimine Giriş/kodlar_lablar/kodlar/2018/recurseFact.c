#include <stdio.h>
int main( )
{ 
printf ( "%d\n", factRecurse(4) );
return 0;
} 

int factRecurse(int n)
{ 
	if (n==0) return 1; 
	else 
		return n*factRecurse(n-1);
} 



