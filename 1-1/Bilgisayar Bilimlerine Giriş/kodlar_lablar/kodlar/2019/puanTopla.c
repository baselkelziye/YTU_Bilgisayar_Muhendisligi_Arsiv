#include <stdio.h>
int main()
{
	int n,m,adimsay,puan;	//oyun alani boyutu ve adimsayisi limiti, kazanilan puan
	int i,j,engel,a,yon;	//oyuncu indisleri, kontrol anahtari, atilan adim sayisi, hamle
	int ti,tj;
	n=5; m=6;
	int mat[5][6]={{5,6,2,7,1,0},
				   {4,-1,-1,-1,1,2},
				   {2,1,3,-1,2,4},
				   {5,6,1,-1,5,3},
				   {2,2,4,-1,-1,-1}}; //kullainicidan almak yerine koda gomelim
	printf("adim sayisi?\n");
	scanf("%d",&adimsay);
	a=0;
	engel=0;
	puan=mat[0][0];
	i=0;	j=0;
	while ((a<adimsay) && (engel==0))
	{
		// kullanici oyun alaninin disana cikmak icin hamle yaparsa,
		// adimi geri al. Uygun bir hamle gelene kadar kullaniciya sormaya devam et
		do
		{
		ti=i; tj=j;
		printf("%d %d noktasindasiniz hamleniz?\n",ti,tj);
		scanf("%d",&yon);
		if (yon==1)
			tj++;	//saga git
		else
			ti++;	//asagi git
		}while ((ti>=n) || (tj>=m));//eger hamle oyun alani disina cikmiyorsa do-while'dan cik	
		i=ti; j=tj;
		if (mat[i][j]==-1)
		{	
			puan=0;
			engel=1;
		}
		else
			puan=puan+mat[i][j];
		a++;
	}
	printf("Puan:%d",puan);
	return 0;
}
