#include <stdio.h>
int main()
{
	int E[50][50];
	int dizi[5]={3,-5,1,8,9};
	int s,ind,N,i,j,M;
	
	s=DiziMinMaxBul (dizi, 5, 1, &ind);
	printf("%d %d\n",s,ind);
	
	printf("matrisin satir sayisi?\n");
	scanf ("%d",&N);
	printf("sutun sayisi?\n");
	scanf ("%d",&M);
	
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			scanf ("%d",&E[i][j]);

	s=MatMinMaxBul (E,N,M,1);
	printf("%d\n",s);
}

// Kullanicinin secimine gore bir dizinin en kucuk ya da en buyuk elemanýný ve bu elemanýn yerini bulan fonksiyon
int DiziMinMaxBul (int dizi[], int n, int secim, int* indis)
{
	int i,sonuc=dizi[0];
	if (secim==1) //buyuk bul
	{
		for (i=0;i<n;i++)
			if (sonuc<dizi[i])
			{
				sonuc=dizi[i];
				*indis=i;
			}
	}
	else
	{
		for (i=0;i<n;i++)
			if (sonuc>dizi[i])
			{
				sonuc=dizi[i];
				*indis=i;
			}
	}
	return sonuc;
}

// Kullanicinin secimine gore bir matrisin en kucuk ya da en buyuk elemanýný bulan fonksiyon
// (DiziMinMaxBul() fonksiyonunu kullanarak)
int MatMinMaxBul (int mat[][50], int m, int n, int secim)
{
	int i,j, K[50], A[50], d, indis;
	for (i=0;i<m;i++)
		K[i]=0;
	
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			A[j]=mat[i][j];
		K[i]=DiziMinMaxBul(A, n, secim, &indis);
	}
	
	d=DiziMinMaxBul(K, m, secim, &indis);
	return d;
}
