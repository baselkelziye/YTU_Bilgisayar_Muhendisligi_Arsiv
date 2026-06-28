#include <stdio.h>
void elemanEkle (int*,int,int,int*);
void elemanSil (int*,int,int*);
void listeleriYazdir(int*,int*,int);
void siraliYazdir (int*,int*);
int main()
{
	static int B[10],A[10],PO[10],N,i,j,k,ek,sil;
	printf("eklenecek dizi eleman sayisi?\n");
	scanf("%d",&N);
	printf("elemanlar?\n");
	for (i=1;i<=N;i++)
		scanf("%d",&B[i]);
	PO[0]=1;
	A[1]=B[1];
	PO[1]=-1;
	for (i=2;i<=N;i++)
	{
		ek=B[i];
		elemanEkle (A,i,ek,PO);		
	}
	
	listeleriYazdir(A,PO,N);
	
	printf("eklenecek eleman?\n");
	scanf("%d",&ek);
	elemanEkle (A,i,ek,PO);	
	N=N+1;
	listeleriYazdir(A,PO,N);
	siraliYazdir(A,PO);
	printf("silineceklenecek eleman?\n");
	scanf("%d",&sil);
	elemanSil (A,sil,PO);			
	listeleriYazdir(A,PO,N);
	siraliYazdir(A,PO);
	return 0;
	
}

void elemanEkle (int A[],int i,int ek,int PO[])
{
	int k=0,j;
	A[i]=ek;
	j=PO[0];
	while ((j!=-1) && (A[j]<ek))
	{
		k=j;
		j=PO[j];
	}
	PO[k]=i;
	PO[i]=j;
}

void elemanSil (int A[],int sil,int PO[])
{
	int k=0,j;
	j=PO[0];
	while ((j!=-1) && (A[j]!=sil))
	{
		k=j;
		j=PO[j];
	}
	if (j==-1)
	{
		printf("Silinecek eleman bulunamadi\n");
		return;
	}
	PO[k]=PO[j];
}

void listeleriYazdir(int A[],int PO[],int N)
{
	int i;
	printf("i--A[]--PO[]\n");
	for (i=0;i<=N;i++)
		printf("%d   %d   %d\n",i,A[i],PO[i]);
	
}

void siraliYazdir (int A[],int PO[])
{
	int j;
	j=PO[0];
	printf("i--A[]--PO[]\n");
	while (j!=-1)
	{
		printf("%d  %d  %d\n",j, A[j], PO[j]);
		j=PO[j];
	}
}
