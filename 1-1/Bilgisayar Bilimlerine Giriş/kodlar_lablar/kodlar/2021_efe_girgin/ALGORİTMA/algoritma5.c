#include <stdio.h>
int main(){
	//degiskenleri tanýmla
	int a,b,c;
	//kullanýcýdan a sayisini al 
	printf("lutfen a sayisini giriniz \n");
	scanf("%d",&a);
	//kullanýcýdan b sayisini al
	printf("lutfen b sayisini giriniz \n");
	scanf("%d",&b);
	
	//ikisi de 50 den büyükse topla
	if(a>50 && b>50){
		c=a+b;
		printf("%d",c);
	}
	else{
		printf("hicbir islem yapilmadi");
	}
}
//denendi ve compile yapildi
//a ve b sayilari 50 den buyukse c=a+b iþlemini yapan algoritma ve programý
//sayfa 2
//kod calýsýyor
