#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
typedef struct {
	int x;
	int y;
	int z;
}bak;
int kare(bak a){
	return a.x*a.x+a.y*a.y+a.z*a.z;
}
bak * degeroku(bak *a,int * n){
	int i,j;
	printf("Lutfen eleman sayisini giriniz");
	scanf("%d",n);
	a=(bak*)malloc(*n*sizeof(bak));
	for(i=0;i<*n;i++){
		printf("Lutfen %d. elemanin x degerini giriniz",i+1);
		scanf("%d",&j);a[i].x=j;
		printf("Lutfen %d. elemanin y degerini giriniz",i+1);
		scanf("%d",&j);a[i].y=j;
		printf("Lutfen %d. elemanin z degerini giriniz",i+1);
		scanf("%d",&j);a[i].z=j;
	}
	return a;
}
void swap(bak *a, bak*b){
	bak tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int kb(int a, int b){
	return (a>b);
}
int bk(int a, int b){
	return (a<b);
}
bak* sort(bak * a, int n,int (*point)()){
	int kob,i,j,k,l;
	
	for(i=0;i<n;i++){
		kob=i;
		for(j=i+1;j<n;j++){
			l=kare(a[j]);
			k=kare(a[kob]);
			if(point(l,k)){
				kob=j;
			}
			
		}
		swap(&a[i],&a[kob]);
	}
	return a;
	
}
int main(){
	bak * a;
	int n,order,i=0;
	a=degeroku(a,&n);
	printf("asending=1 decending=2");
	scanf("%d",&order);

	if(order==1){
		a=sort(a,n,kb);
	}
	else{
		a=sort(a,n,bk);
	}
	for(i=0;i<n;i++)
	printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
	
	return 0;
}
