// Bir oyun alaninda n*m adet oda bulunmaktadir. Odalarin her birinde yan odaya ve alt odaya acilan kapilar mevcuttur. 
// Odalarda bulunan para miktarlari kullaniciya verildigine gore, sol ust odadan baslayip, sag alt odaya inildiginde toplanabilecek maximum 
// para miktari ne olur?
// oda[][]	->	2 1 4
//				5 3 2
//				10 1 3
// kazanc[][] ->	2  3   7
//					7  10  12
//					17 18  21		maxPara=21
#include <stdio.h>
int main()
{
	unsigned int n,m,i,j,kazanc[50][50],oda[50][50];
	printf("Boyutlari veriniz\n");
	scanf("%d %d",&n,&m);
	printf("Matrisi veriniz\n");
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&oda[i][j]);
	kazanc[0][0]=oda[0][0];
	for (i=1;i<n;i++)
		kazanc[i][0]=kazanc[i-1][0]+oda[i][0];
	for (i=1;i<n;i++)
		kazanc[0][i]=kazanc[0][i-1]+oda[0][i];
	for (i=1;i<n;i++)
		for (j=1;j<m;j++)
			if (kazanc[i-1][j]>kazanc[i][j-1])
				kazanc[i][j]=kazanc[i-1][j]+oda[i][j];
			else
				kazanc[i][j]=kazanc[i][j-1]+oda[i][j];
	printf("Gezinge kazanc matrisi\n");	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%d ",kazanc[i][j]);
		printf("\n");
	}
	return 0;
}
