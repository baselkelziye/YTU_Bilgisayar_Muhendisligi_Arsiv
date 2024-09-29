#include <stdio.h>
int main()
{
	// S: sepetID, ürünID’leri tutan bir matris. N satır, 2 sütun
	int S[10][2]={	{1,2},
					{2,1},
					{2,4},
					{2,2},
					{1,4},
					{1,0},
					{1,3},
					{0,0}};
	int N=8;
	int urunSayisi=5;
	int sepetSayisi=3;
	// 	A: hangi ürünlerin, hangi sepetlerde olduğunu gösteren sadece 1 ve 0’lardan oluşan bir matris. 
	static int A[10][10];
	static int T[10][10][10];
	int i,j,k,m;
	for (i=0;i<N;i++)
		A[S[i][1]][S[i][0]]=1;
	printf("urunlerin bulunduklari sapetler:\n");
	for (i=0;i<urunSayisi;i++)
	{
		for (j=0;j<sepetSayisi;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	//	T: hangi ürünlerin hangi ürünlerle birlikte kaç kez satıldıklarını göstersin. 
	//	T: ürünSayisi*ürünSayisi*ürünSayisi boyutunda bir matris
	printf("\nurunlerin birlikte satilma sayilari:");
	for (i=0;i<urunSayisi;i++)
		for (j=i+1;j<urunSayisi;j++)
			for (k=j+1;k<urunSayisi;k++)
				for (m=0;m<sepetSayisi;m++)
					T[i][j][k]=T[i][j][k]+A[i][m]*A[j][m]*A[k][m];
	printf("\n");
	for (i=0;i<urunSayisi;i++)
		for (j=0;j<urunSayisi;j++)
			for (k=0;k<urunSayisi;k++)
				printf("%d - %d - %d adet:%d\n",i,j,k,T[i][j][k]);
	return 0;	

}
