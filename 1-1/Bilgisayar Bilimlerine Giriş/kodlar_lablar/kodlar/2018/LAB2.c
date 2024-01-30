#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int n,i,x;
	float a[50],b[50];
	float c[50];
	//elemanlar?n al?nmas?
	printf("dizi eleman sayisini giriniz:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a dizisinin %d. elemanini giriniz:",i+1);
		scanf("%f",&a[i]);
	}
	for(i=0;i<n;i++)
	{            printf("b dizisinin %d. elemanini giriniz:",i+1);
		scanf("%f",&b[i]);
	}
	//islemler gercekle?iyor
	for(i=0;i<n;i++)
	{           x=rand()%4;
		if(x==0){
			c[i]=a[i]+b[i];
			printf("%f + %f = %f",a[i],b[i],c[i]);
			printf("\n");	
		}
		else if(x==1){
			c[i]=a[i]-b[i];	
			printf("%f - %f = %f",a[i],b[i],c[i]);
			printf("\n");
	    }
		else if(x==2){
			c[i]=a[i]*b[i];
			printf("%f * %f = %f",a[i],b[i],c[i]);
			printf("\n");
		}
		else{
			c[i]=a[i]/b[i];
			printf("%f / %f = %f",a[i],b[i],c[i]);
			printf("\n");	
		}
	}
	printf("\n");
	//c dizisini yzd?rma
	for(i=0;i<n;i++)
	{
		printf("%f	",c[i]);
	}
	return 0;
}

