#include <stdio.h>
#include <math.h>
void ClosestPoints(int(*)[5],int,int(*)[5],int,int*,int*);
void ClosestPointsV2(int(*)[50],int,int(*)[50],int,int,int*,int*);
void ClosestPointsV3(int(*)[50],int,int(*)[50],int,int,int*,int*);
int FindDistance (int,int,char);
	
int main()
{
	int E[50][50], K[50][50];
	int N, M, ind1,ind2,k,i,j; 
	
	printf("ilk matrisin kayit sayisi?\n");
	scanf ("%d",&N);
	printf("ikinci matrisin kayit sayisi?\n");
	scanf ("%d",&M);
	printf("sutun sayisi?\n");
	scanf ("%d",&k);
	
	printf("ilk matrisin elemanlari?\n");
	for (i=0;i<N;i++)
		for (j=0;j<k;j++)
			scanf ("%d",&E[i][j]);
		
	printf("ikinci matrisin elemanlari?\n");
	for (i=0;i<M;i++)
		for (j=0;j<k;j++)
			scanf ("%d",&K[i][j]);
	
	ClosestPoints(E,N,K,M,&ind1,&ind2);	//iki sutunlu matrisler icin birbirine en yakin noktalarýn indislerini bulalým
//	ClosestPointsV2(E,N,K,M,k,&ind1,&ind2); // copcatan sitesi yapalým. K adet nümerik soru icin uzaklik hesaplansýn
//	ClosestPointsV3(E,N,K,M,k,&ind1,&ind2);	// copcatan sitesi yapalým. K adet kategorik soru icin uzaklik hesaplansýn

	printf("En yakin noktalarýn indisleri:%d - %d\n",ind1,ind2);
	return 0;	
}

/* 	E hava yollarýne ait uçaklarýn enlem ve boylam bilgisi E matrisinde (E[N][2]), 
	K hava yollarýne ait uçaklarýn enlem ve boylam bilgisi K matrisinde (K[M][2]), 
	Birbirine en yakýn uçaklarýn indislerini bulan fonksiyon
*/
//Ýki boyutlu veri için 
ClosestPoints(int E[][50],int N,int K[][50], int M,int *ind1,int *ind2)
{
	int i,j,distMin=100000,dist;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
		{
			dist=abs(E[i][0]-K[j][0])+abs(E[i][1]-K[j][1]);
			if (dist<distMin)
			{
				distMin=dist;
				*ind1=i;
				*ind2=j;
			}
				
		}
}

/* Çöpçatan sitesi yapalým. N erkek, M kadýn dim soru
Sorular þöyle: Ayda kaç gün sinemaya gidersiniz? Tiyatro izlemeyi ne kadar seversiniz (1-5 arasý puanlayýn) Haftada kaç sayfa kitap okursunuz?
Erkeklerin cevaplarý E[N][dim],  Kadýnlarýn cevaplarý K[M][dim], 
Birbirine en uygun çift?
*/
// dim boyutlu veri için
void ClosestPointsV2(int E[][50],int N,int K[][50], int M,int dim,int *ind1,int *ind2)
{
	int i,j,k,distMin=100000,dist=0;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
		{
			for (k=0;k<dim;k++)
				dist+=abs(E[i][k]-K[j][k]); //dist+=FindDistance(E[i][k],K[j][k],'n');
			if (dist<distMin)
			{
				distMin=dist;
				*ind1=i;
				*ind2=j;
			}
			dist=0;	
		}
}

/*
Çöpçatan sitesinde sorular deðiþmiþ. Nümerik deðil kategorik sorular gelmiþ. Sorular þöyle:
Otostop çeken birini görseniz ne yaparsýnýz?
 1)Hýzlanýrým 2)Durup otostop yapmanýn her iki taraf için de tehlikeli olduðunu söylerim 3)Durup arabaya alýrým
Ne tür film izlemeyi seversiniz?
 1)Korku  2)Romantik Komedi 3)Polisiye 4)Bilim Kurgu
 
Cevaplar arasýnda nümerik distance bulmak mantýksýz. Ayný soruya ayný cevabý vermiþ mi diye bakmalýyým. Öyleyse distance metriðim deðiþmeli
*/
// dim boyutlu veri için Distance Metriði Farklý
void ClosestPointsV3(int E[][50],int N,int K[][50], int M,int dim,int *ind1,int *ind2)
{
	int i,j,k,distMin=100000,dist=0;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
		{
			for (k=0;k<dim;k++)
				dist+=FindDistance(E[i][k],K[j][k],'c');
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

