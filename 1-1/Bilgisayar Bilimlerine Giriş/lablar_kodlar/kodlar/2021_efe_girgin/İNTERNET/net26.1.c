#include <stdio.h>
#include <math.h>
int main(){
	double base,exp,sonuc;
	printf("lutfen taban sayisini giriniz\n");
	scanf("%lf",&base);
	
	printf("lutfen ussu giriniz\n");
	scanf("%lf",&exp);
	
	sonuc=pow(base,exp);
	
	printf("%.1lf^%.1lf=%.2lf",base,exp,sonuc);
	return 0;
}
//Power Using pow() Function
