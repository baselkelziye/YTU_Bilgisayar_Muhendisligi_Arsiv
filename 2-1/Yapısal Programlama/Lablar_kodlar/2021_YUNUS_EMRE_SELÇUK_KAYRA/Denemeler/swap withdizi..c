#include <stdio.h>
void print(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
}
void swap(int* a ,int n){
	int tmp,i;
	
	for(i=0;i<n/2;i++){
		tmp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=tmp;
	}
	print(a,n);
}
int* scan(int *n){
	int i,*a;
	printf("Lutfen eleman sayisini giriniz");
	scanf("%d",n);
	a=(int*)calloc(*n,sizeof(int));
	for(i=0;i<*n;i++){
		printf("Lutfen %d. elemani giriniz",i+1);
		scanf("%d",a+i);
	}
	return a;
}
int main(void){
	int *i,n;
	i=scan(&n);
	swap(i,n);
	return 0;
}
