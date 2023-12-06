#include <stdio.h>
// a1 X ^ n + a2 X ^n-1 ...+ an X ^ 0  
typedef struct terim{
	double katsayi;
	int derece;
	char isim[30];
}TERM;

int main(){
	TERM t1, t2 = {6.4, 6};
	TERM *pt;
	printf("%lf -- %d\n",t1.katsayi, t1.derece);
	printf("%lf -- %d\n",t2.katsayi, t2.derece);
	pt = &t2;
	(*pt).derece = 77;
	pt->katsayi = 7.7;
	printf("%lf -- %d\n",pt->katsayi, pt->derece);
	
	scanf("%lf", &t2.katsayi);
	scanf("%d",&t2.derece);
	scanf("%s",t2.isim);
	
	printf("%lf -- %d --- %s\n",pt->katsayi, pt->derece,pt->isim);
	
	scanf("%lf", &pt->katsayi);
	scanf("%d",&(*pt).derece);
	scanf("%s",t2.isim);
	
	printf("%lf -- %d --- %s\n",pt->katsayi, pt->derece,pt->isim);
}
