#include <stdio.h>

int main(){
	//degiskenleri tanýmla
	int t,v;
	
	//kullanicidan zamani aliniz
	printf("zamani giriniz\n");
	scanf("%d",&t);
	
	//
	if(t<15){
		v=32*t;
		printf("hiziniz=%d \n",v);
	}
	else if(t>15 && t<35){
		printf("hiziniz 480 \n");
		
	}
	else if(t>35 &&t<50){
		v=1600-32*t;
		printf("hiziniz =%d \n",v);
	}
	else if(t>50){
		printf("araciniz durmustur \n");
	}
}
//deneme ve compile yapildi
//bir uçak 15 dk boyunca düzgün hýzlanarak 480 km/s oluyor.sonra
// 20 dk sabit hýzla gidiyor ve 15 dk boyunca düzgün yavaslayarak hizi 
//sifir oluyor.herhangi bir t aninda hizi veren algoritma ve programi
//sayfa 3
//kod calýsýyor
