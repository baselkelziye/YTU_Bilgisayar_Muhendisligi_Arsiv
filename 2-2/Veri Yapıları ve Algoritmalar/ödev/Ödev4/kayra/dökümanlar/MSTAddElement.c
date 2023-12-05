
#include <stdio.h>
#include <stdlib.h>
#define size 13
int recYolBul(int **matris,int n, int eleman1,int eleman2,int * indis,int kontrol,int *dizi){
	int i=0,myKontrol=0;
	if(eleman1==eleman2){
		return 1;
	}
	while(i<n && !myKontrol){
		if(matris[i][0]==eleman1 && dizi[i]!=-1){
			if(kontrol==0 || matris[i][2]>matris[*indis][2])
				*indis=i;
			dizi[i]=-1;
			myKontrol=recYolBul(matris,n,matris[i][1],eleman2,indis,1,dizi);
		}
		if(matris[i][1]==eleman1 && dizi[i]!=-1){
			if(kontrol==0 || matris[i][2]>matris[*indis][2])
				*indis=i;
			dizi[i]=-1;
			myKontrol=recYolBul(matris,n,matris[i][0],eleman2,indis,1,dizi);
		}
		i++;
	}
	return myKontrol;
	
}
int menu(){
	int n;
	printf("Baglanti eklemek icin 1\nMatris yazdirmak icin 2\nCikis icin 3\n");
	scanf("%d",&n);
	return n;
}
void yazdir(int **matris,int n){
	int i;
	printf("Baglanti 1\tBaglanti 2\tUzaklik\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\n",matris[i][0],matris[i][1],matris[i][2]);
	}
}
int main(){
	int indis=-1,n,i,**matris,eleman1,eleman2,uzaklik,choice,anlikIndis=-1,*dizi;
	printf("Matrisin eleman sayisini giriniz\n");
	scanf("%d",&n);
	matris=(int ** )malloc(sizeof(int*)*n);
	dizi=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		matris[i]=(int* )malloc(sizeof(int)*3);
	}
	for(i=0;i<n;i++){
		printf("Matrisin %d. sutununun 1. elemanini giriniz\n",i+1);
		scanf("%d",&matris[i][0]);
		printf("Matrisin %d. sutununun 2. elemanini giriniz\n",i+1);
		scanf("%d",&matris[i][1]);
		printf("Matrisin %d. sutununun uzakligini giriniz\n",i+1);
		scanf("%d",&matris[i][2]);
	}
	do{
		for(i=0;i<n;i++){
			dizi[i]=0;
		}
		choice=menu();
		switch (choice){
		case 1:
			printf("Lutfen eklemek istediginiz baglantinin 1. elemanini giriniz\n");
			scanf("%d",&eleman1);
			printf("Lutfen eklemek istediginiz baglantinin 2. elemanini giriniz\n");
			scanf("%d",&eleman2);
			
			printf("Lutfen eklemek istediginiz baglantinin uzakligini giriniz\n");
			scanf("%d",&uzaklik);
			recYolBul(matris,n,eleman1,eleman2,&indis,0,dizi);

			if(matris[indis][2]>uzaklik)
			{
				matris[indis][1]=eleman2;
				matris[indis][0]=eleman1;
				matris[indis][2]=uzaklik;
			}
			indis=-1;
			break;
		case 2:
			yazdir(matris,n);
			break;
		case 3:
			printf("Cikis yapildi\n");
			break;
		default:
			printf("Duzgun sayi giriniz");}
}while(choice!=3);
	
	
	
	
	return 0;
}