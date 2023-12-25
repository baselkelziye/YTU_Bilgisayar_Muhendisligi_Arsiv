// 3.kuvveti kendisi ile sonlanan sayilara trimorphic sayilar denir. Verilen bir sayinin trimorphic olup olmadigini bulan program
#include <stdio.h>
int main()
{
	int N,kup,bol,carp;
	scanf("%d",&N);
	kup=N*N*N;

	carp=1;
	bol=N;
	while (bol>0)
	{
		bol=bol/10;
		carp=carp*10;
	}
	if ((kup-N)%carp==0)
		printf("Trimorphic");
	else
		printf("degil");
		
}
