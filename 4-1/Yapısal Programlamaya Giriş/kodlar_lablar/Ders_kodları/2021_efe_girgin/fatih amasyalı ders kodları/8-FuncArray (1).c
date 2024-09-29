// DIZI IN FUNCTION
#include <stdio.h>
int toplaDiziv1(int *,int);
int toplaDiziv2(int *,int);
void degistirDizi(int *,int);
int main()
{
	int dizi[20],n,i,toplam;
	int *dizi2;
	printf("Dizinin eleman sayisiniz giriniz\n");
	scanf("%d",&n);
	printf("elemanlari giriniz\n");
	for (i=0;i<n;i++)
		scanf("%d",&dizi[i]);
	toplam=toplaDiziv1(dizi,n);
	printf("toplam v1:%d\n",toplam);

	toplam=toplaDiziv2(dizi,n);
	printf("toplam v2:%d\n",toplam);
    degistirDizi(dizi,n);    
    for (i=0;i<n;i++)
		printf("%d ",dizi[i]);
	return 0;
}

int toplaDiziv1(int *dizi,int boyut)
{
	int i,toplam=0;
	for (i=0;i<boyut;i++)
		toplam+=dizi[i];
	return toplam;
}

int toplaDiziv2(int dizi[],int boyut)
{
	int i,toplam=0;
	for (i=0;i<boyut;i++)
		toplam+=*(dizi+i);
	return toplam;
}

void degistirDizi(int dizi[],int boyut)
{
	int i;
	for (i=0;i<boyut;i++)
		dizi[i]=i*i;
}


