#include <stdio.h>
#include <math.h>
void ClosestPointsV4(int(*)[50],int,int,int*,int*);
void TranspozeAl(int(*)[50],int,int,int(*)[50]);
int FindDistance (int,int,char);
	
int main()
{
	int E[50][50];
	int N, M, k,i,j, ind1,ind2; 
	
	printf("Doktor sayisi?\n");
	scanf ("%d",&N);
	printf("Hasta sayisi?\n");
	scanf ("%d",&k);
	
	for (i=0;i<N;i++)
		for (j=0;j<k;j++)
			scanf ("%d",&E[i][j]);

	// E[N][k]: N doktorun k hastaya koyduðu teþhisler olsa
	// birbirine en yakin iki doktoru bulalým
	// hastalýklar 0-49 arasý deðerler ile kodlanmýþ
	ClosestPointsV4(E,N,k,&ind1,&ind2);
	printf("birbirine en yakin iki doktor: %d %d\n",ind1,ind2);
	
	// E[N][k]: N doktorun k hastaya koyduðu teþhisler olsa, teþhisleri birbirine en çok benzeyen hastalar?
	// once E'nin transpozesini alalim sonra ClosestPointsV4'e gonderelim (satir ve sutun sayisini degistirerek)
	// transpozeyi tutacak matris K[][] olsun
	int K[50][50];
	TranspozeAl(E,N,k,K);
	ClosestPointsV4(K,k,N,&ind1,&ind2);
	printf("birbirine en çok benzeyen hastalar:%d %d\n",ind1,ind2);
	
	int DogruTe[50];
	static int Madurlar[50];
	printf("Dogru teshisleri veriniz\n");
	for (i=0;i<k;i++)
		scanf("%d",&DogruTe[i]);
	
	KimlerOlecek(E,N,k,DogruTe,Madurlar);
	printf("Madur olanlar:( \n");
	for (i=0;i<k;i++)
		printf(" %d ",Madurlar[i]);
	return 0;
}

//Bir matris içindeki sayýrlardan birbirine en yakýn olan satýrlarýn indislerini bulan fonksiyon
void ClosestPointsV4(int E[][50],int N,int dim,int *ind1,int *ind2)
{
	int i,j,k,distMin=100000,dist=0;
	for (i=0;i<N;i++)
		for (j=i+1;j<N;j++)
		{
			for (k=0;k<dim;k++)
				dist+=FindDistance(E[i][k],E[j][k],'c');
			if (dist<distMin)
			{
				distMin=dist;
				*ind1=i;
				*ind2=j;
			}
			dist=0;	
		}
}


int FindDistance (int point1,int point2,char type)
{
	if (type=='c') //categorical
	{
		if (point1==point2)
			return 0;
		else 
			return 1;
	}
	else	// numerical
		return abs(point1-point2);
	
}


void TranspozeAl(int E[][50],int N,int dim,int K[][50])
{
	int i,j;
	for (i=0;i<N;i++)
		for (j=0;j<dim;j++)
			K[j][i]=E[i][j];
}

//N doktorun k hastaya koydugu teshis N*k 'lik bir E[][] matrisindeyse
//Dogru teshisler k elemanlý DogruTe[], Demokrasi usulu teþhis seçen hastalar k elemanlý Madurlar[] dizisinde ise
//Kimlerin olecegini bulan fonksiyon
void KimlerOlecek(int E[][50], int N, int k, int DogruTe[], int Madurlar[])
{
	int i,j,sonuc,indis;
	int Teshisler[50];
	static int Frekanslar[50];
	
	for (i=0;i<k;i++)
	{
		for (j=0;j<N;j++)
			Teshisler[j]=E[j][i]; //i numarali hastaya tum doktorlarin koydugu teshisler N elemanlý Teshisler[] dizisinde
			
		Frekansbul (Teshisler,N, Frekanslar); //i numarali hastaya konan teshislerin frekanslarini bulalim
		sonuc=DiziMinMaxBul(Frekanslar,50,1,&indis); //en sýk konan teþhisin numarasini bulalim
		if (DogruTe[i]!=indis) //en sýk konan teshis, doðru teþhis ile ayný mý kontrol edelim
			Madurlar[i]=1; //Eger ayný degilse i hasta madur olmustur
	}
}

void Frekansbul (int Teshisler[], int N, int Frekanslar[])
{
	int i;
	for (i=0;i<N;i++)
	{
		Frekanslar[Teshisler[i]]++;
	}
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

