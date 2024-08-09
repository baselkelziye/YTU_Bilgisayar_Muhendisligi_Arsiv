#include <stdio.h>
int hesaplaR(int s1, int s2)
{
    int y;
    y=s1%s2;
	if (y!= 0)
       hesaplaR(s2, y);
    else 
       return s2;
}

int hesaplaS(int s1, int s2)
{
	int y;
	y=s1%s2;
	while (y>0)
	{	
		s1=s2;
		s2=y;
		y=s1%s2;
	}
	return s2;
}


int main()
{
   int s1, s2;
   printf("Iki pozitif sayi veriniz: ");
   scanf("%d %d", &s1, &s2);
   printf("hesaplaS sonucu=%d\n", hesaplaS(s1,s2));
   printf("hesaplaR sonucu=%d\n", hesaplaR(s1,s2));
   return 0;
}

