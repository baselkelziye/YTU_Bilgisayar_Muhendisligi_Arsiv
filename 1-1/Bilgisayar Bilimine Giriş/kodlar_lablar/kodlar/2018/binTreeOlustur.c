#include <stdio.h>
int AddElement(int BinT[],int element)
{
	int i=0;
	while (BinT[i]!=0)
	{
		if (element>BinT[i])
			i=i*2+2;
		else
			i=i*2+1;
	}
		BinT[i]=element;
	return i;
}

int ConstructBinaryTree (int A[], int BinT[], int N)
{
	int i,j,max=0;
	BinT[0]=A[0];
	for (j=1;j<N;j++)
	{
		i=AddElement(BinT, A[j]);
		if (i>max) max=i;
	}
	return max;
}

int searchElement (int BinT[], int element)
{
	int i=0;
	while ((element!=BinT[i]) && (BinT[i]!=0))
	{
		if (element>BinT[i])
			i=i*2+2;
		else
			i=i*2+1;
	}
	if (element==BinT[i]) return i;
	else return -1;
}

int main()
{
	int A[]={55,60,40,56,30,45,70,42,47,43,41};
	int N=11,element;
	static int BinT[2046];         //(2^(N-1)+2)
	int max,i;
	max=ConstructBinaryTree (A, BinT, N);
	for (i=0;i<=max;i++)
		printf("node:%d - value:%d\n",i,BinT[i]);
	scanf("%d",&element);
	printf("sonuc:%d",searchElement(BinT, element));
	return 0;
}
