#include <stdio.h>
#include <math.h>
#define SIZE 20
void klm(int n,int m,int a[SIZE],int h){
	int i,k,z,j,q=0;
	if(q==0){
		for(i=0;i<n-h-1;i++){
			for(k=i+1;k<n-h;k++){
					j=a[i]+a[k]+a[k+h];
					if(j==m){
					k=n+1;
					i=n+1;
					q=1;
				}
			}
		}
	}
	if(q!=0){
				printf("Ampul yanar");
			}
			else{
				if(h<n-2)
		return klm(n,m,a,h+1);//RECURSIVE kýsým burasý
		else
			printf("Ampul yanmaz");
			}
			return 0;
			
	}
int main(){
	int i,n,h=1,m,a[SIZE],q=0;
	do{
	printf("buton sayisini giriniz");
	scanf("%d",&n);
	if(n<3){
	printf("Lutfen 2'den buyuk bir deger giriniz\n");
}
else
q=1;
	}while(q==0);
	for(i=0;i<n;i++){
	printf("butonun %d. elemanini giriniz",i+1);
	scanf("%d",&a[i]);	
	}
	printf("isik yanma degerini giriniz");
	scanf("%d",&m);
	klm(n,m,a,h);
}
