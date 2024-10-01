#include <stdio.h>
#include <math.h>
int main(){
	//degiskenleri tanýmla
	int x,y,xx,yy,c;
	
	//kullanicidan x degerini aliniz
	printf("bir x degeri giriniz\n");
	scanf("%d",&x);
	
	//kullancidan y degerini aliniz
	printf("bir y degeri giriniz\n");
	scanf("%d",&y);
	
	xx=abs(x);
	yy=abs(y);
	
	c=xx+yy;
	
	if(c==1){
		printf("uzerinde");
	}
	else if(c>1){
		printf("disinda");
	}
	else{
		printf("icinde");
	}
	return 0;
	
}
//denendi ve compile edildi
//verilen bir noktanin koordinatlari (x,y)dir.bu noktanin |x|+|y|=1 grafiginin neresinde bulundugunu bulan algoritma ve programi
//sayfa 5
//kod calýsýyor
