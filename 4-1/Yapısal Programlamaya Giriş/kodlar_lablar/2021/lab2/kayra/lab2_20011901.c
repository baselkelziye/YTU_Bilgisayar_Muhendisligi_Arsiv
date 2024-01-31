#include <stdio.h>
#define SIZE 100
//Muhammet Kayra Bulut 20011901
int main(void){
	int i,j,k=0,q,n,m,a[SIZE][SIZE],b[SIZE],c[SIZE],p[SIZE],g[SIZE][SIZE];
	do{
	printf("(1) Seyrek Matristen Sikistirilmis Matrise\n");
	printf("(2) Sikistirilmis matristen seyrek Matrise\n");
	printf("(3) cikis\n");
	scanf("%d",&q);
	if(q==1){
		printf("lutfen matrisin satir sayisini giriniz");
		scanf("%d",&m);
		printf("lutfen matrisin sutun sayisini giriniz");
		scanf("%d",&n);
		printf("Matrisin elemanlarini giriniz\n");
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
			
			printf("[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(a[i][j]!=0){
					k+=1;
					g[k][1]=i;
					g[k][2]=j;
					g[k][3]=a[i][j];
					
				}
			}
		}
		printf("Sikistirilmis matris\n");
		for(i=1;i<=k;i++){
			printf("%d\t",g[i][1]);
			printf("%d\t",g[i][2]);
			printf("%d\t",g[i][3]);
			printf("\n");
		}
		j=-1;
		
	}
	else{
		if(q==2){
		printf("lutfen matrisin satir sayisini giriniz");
		scanf("%d",&m);
		printf("lutfen matrisin sutun sayisini giriniz");
		scanf("%d",&n);
		
		printf("Kac tane sikistirilmis eleman vardir");
		scanf("%d",&k);
		for(i=1;i<=k;i++){
			printf("%d. eleman icin satir sutun ve deger girin",i);
			scanf("%d",&b[i]);
			scanf("%d",&c[i]);
			scanf("%d",&p[i]);
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				a[i][j]=0;
				
			}
		}
		for(i=1;i<=k;i++){
			a[b[i]][c[i]]=p[i];
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				printf("%d\t",a[i][j]);
				
			}
			printf("\n");
		}
		j=-1;
	}
	else{
		j=1;
	}

}
}while(j==-1);
	return 0;
}
