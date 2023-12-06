#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
	int M[50], P[50], ind[50];
	int X, N, i; 
	
	printf("Kume merkezi sayisi:");
	scanf ("%d",&X);
	
	printf("Kume merkezlerinin 1 boyutlu koordinatlarini giriniz:\n");
	for (i=0;i<X;i++)
		scanf ("%d",&M[i]);
	
	printf("Nokta sayisi:");
	scanf ("%d",&N);
		
	printf("Noktalarin 1 boyutlu koordinatlarini giriniz:\n");
	for (i=0;i<N;i++)
		scanf ("%d",&P[i]);
	
	ClosestCenter(M,X,P,N,ind); 
	
	printf("Noktalarin ait olduklari merkezlerin indisleri: ");
	for(i=0;i<N;i++)
		printf("%d  ", ind[i]);
	return 0;	
}



void ClosestCenter(int M[],int X,int P[], int N,int ind[])
{
	int i,j,distMin=INT_MAX,dist;
	
	for (i=0;i<N;i++){
		for (j=0;j<X;j++){
			dist=abs(P[i]-M[j]); 
			
			if (dist<distMin)
			{
				distMin=dist;
				ind[i]=j;
			}
		}		
		distMin=INT_MAX;		
	}
			

}



