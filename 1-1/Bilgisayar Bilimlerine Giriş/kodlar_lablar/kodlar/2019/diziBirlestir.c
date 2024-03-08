// buyukten kucuge sirali A ve B dizileri verildiginde bu dizileri birlestirerek
// sirali sekilde C dizisine yerlestiren programi yaziniz
#include <stdio.h>
int main()
{
	int NA, NB, IA, IB, IC, i;
	int A[20], B[20], C[40];
	//A ve B dizilerini alalim
	scanf("%d",&NA);
	for (i=0;i<NA;i++)
		scanf("%d",&A[i]);
	scanf("%d",&NB);
	for (i=0;i<NB;i++)
		scanf("%d",&B[i]);
	IA=0;	//A dizisinde gezmek icin
	IB=0;	//B dizisinde gezmek icin
	IC=0;   //C dizisine eklemek icin
	//dizilerin ikisi de sona ulasmadigi surece
	while ((IA<NA) && (IB<NB))	
	{
		//karsilikli elemanlari kontrol et
		if (A[IA]<B[IB])
		{
			C[IC]=A[IA];
			IA++;
			IC++;
		}
		else
		{
			C[IC]=B[IB];
			IB++;
			IC++;
		}
	}
	//dizilerden hangisi bitti ise, digerinin elemanlarini sona ekle
	if (IA>=NA)
	{
		for (i=IB;i<NB;i++)
		{
			C[IC]=B[i];
			IC++;
		}
	}
	else
	{
	for (i=IA;i<NA;i++)
		{
			C[IC]=A[i];
			IC++;
		}
	}
	for (i=0;i<NA+NB;i++)
		printf("%d ",C[i]);
	return 0;
}
