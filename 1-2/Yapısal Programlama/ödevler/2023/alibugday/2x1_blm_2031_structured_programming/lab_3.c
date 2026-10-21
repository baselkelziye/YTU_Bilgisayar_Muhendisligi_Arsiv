#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct arac{
	 char model[20];
	 int yil;
	 int fiyat;
	 int adet;
}ARAC;

int karsilastir(char*,char*);
void sort_yazdir(ARAC *dz,int N,int (*f)(char*,char*),int);

int main() {
	int i,j,N,secim,sira;
	N=3;
	struct arac arac1={"mercedes",2013,320000,2};
	struct arac arac2={"fiat",2005,150000,3};
	struct arac arac3={"toyota",2010,200000,5};
	
	struct arac *dizi=(ARAC*)malloc(N*sizeof(struct arac));
	
	dizi[0]=arac1;
	dizi[1]=arac2;
	dizi[2]=arac3;
	
	
	do{
		printf("araclari gormek icin 2 eklemek icin 1 tuslayiniz");
    	scanf("%d",&secim);
    	if (secim==1){
    		N+=1;
    		dizi=(ARAC*)realloc(dizi,(N)*sizeof(struct arac));
    		printf("yeni aracin ismini(modeli) giriniz:");
    		scanf("%s",&dizi[N-1].model);
    		printf("yeni aracin yilini giriniz:");
    		scanf("%d",&dizi[N-1].yil);
    		printf("yeni aracin fiyatini giriniz:");
    		scanf("%d",&dizi[N-1].fiyat);
    		printf("yeni aracin adetini giriniz:");
    		scanf("%d",&dizi[N-1].adet);
		}
		if (secim==2){
			printf("artan siralama icin 1 azalan icin 2 giriniz:");
    		scanf("%d",&sira);
    		sort_yazdir(dizi,N,karsilastir,sira);
    		for (i=0;i<N;i++){
    			/*printf("%d inci arabanýn modeli:%s\n",i,dizi->model);
				printf("%d inci arabanýn fiyati:%d\n",i,dizi->fiyat);
				printf("%d inci arabanýn yili:%d\n",i,dizi[i].yil);
				printf("%d inci arabanýn adeti:%d\n",i,dizi[i].adet);
				dizi++;*/
			}
		}
    	
	}while(secim!=2); 
		

	return 0;
}


int karsilastir(char kelime1[],char kelime2[]){
	return strcmp(kelime1,kelime2);
}

void sort_yazdir(ARAC *dz,int N,int (*f)(char*,char*),int sira){
	int i,j;
	char temp[10];
	char dizi[N][10];
	
	ARAC *temp2=dz;//(ARAC*)malloc(N*sizeof(ARAC));
	//temp2=dz;
	
	for (i=0;i<N;i++){
			strcpy(dizi[i],temp2->model);
	}
	
	if(sira==1){
	
		for (i=0;i<N-1;i++)
		{
			for (j=0;j<(N-1-i);j++)
			{
				if ((*f)(dizi[j],dizi[j+1])==-1)
				{
					strcpy(temp,dizi[j]);
					strcpy(dizi[j],dizi[j+1]);
					strcpy(dizi[j+1],temp);
				}
			}
		}
	}
	else if(sira==2){
		for (i=0;i<N-1;i++)
		{
			for (j=0;j<(N-1-i);j++)
			{
				if ((*f)(dizi[j],dizi[j+1])==1)
				{
					strcpy(temp,dizi[j]);
					strcpy(dizi[j],dizi[j+1]);
					strcpy(dizi[j+1],temp);
				}
			}
		}
	}
	
	
	for (i=0;i<N;i++)
	{
		printf("sýralý harf %s \n",dizi[i]);
	}
	
}


