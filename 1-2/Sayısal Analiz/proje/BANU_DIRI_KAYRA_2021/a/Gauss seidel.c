#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 10

int main(void)
{
	int i,j,n,m;
	float a[SIZE][SIZE],b[SIZE],c[SIZE],e;
	printf("Lutfen degisken sayisini giriniz: ");
		 scanf("%d", &n);
		 printf("Lutfen denklem sayisini giriniz: ");
		 scanf("%d", &m);
		  printf("Lutfen epsilone degerini giriniz: ");
		 scanf("%f", &e);
	printf("Lutfen denklem ve degiskenleri siralanmis sekilde giriniz:\n");
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			printf("Lutfen %d. denklemin %d. degiskenini giriniz : ",j,i);
			scanf("%f",&a[j][i]);
		}
		printf("Lutfen %d. denklemin sonucunu giriniz: \n",j);
			scanf("%f",&a[j][n+1]);
		}
	for(i=1;i<=n;i++){
		printf("Lutfen %d. degisken icin baslangic degeri giriniz: \n",i);
		scanf("%f",&b[i]);
	}
	c[1]=b[1]+2*e;
	while(c[1]-b[1]>e || b[1]-c[1]>e || c[2]-b[2]>e || b[2]-c[2]>e || c[3]-b[3]>e || b[3]-c[3]>e || c[4]-b[4]>e || b[4]-c[4]>e){
	for(i=1;i<=m;i++){
		c[i]=b[i];
		b[i]=a[i][n+1];
		for(j=1;j<=n;j++){
			if(i!=j)
			b[i]-=a[i][j]*b[j];
		}
		b[i]/=a[i][i];
		printf("%d %f\t",i,b[i]);
	}
	printf("\n");
	}
	for(i=1;i<=n;i++){
	
printf("%d. degisken = %f\n",i,b[i]);
}
	return 0;
}
