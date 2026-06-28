#include <stdio.h>

int main(){
	//degiskenleri tanimla
	int a,b,c,max;
	//kullancidan 3 tane sayi al
	printf("3 sayi giriniz \n");
	scanf("%d%d%d",&a,&b,&c);
	
	if(a>b&& a>c){
		max=a;
}
else if(b>a && b>c){
	max =b;
}
else{
	max=c;
}
printf("3 sayidan en buyugu =%d",max);
}
//deneme ve compile yapildi
//notta yazan gibi yapýlmadý 
//A;B,C,D sayilarindan en buyugunu bulan algoritma ve programi
//sayfa 3
//kod calýsýyor

