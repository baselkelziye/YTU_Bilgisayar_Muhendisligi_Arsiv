#include <stdio.h>
#include <locale.h>
int main(void){
	setlocale(LC_ALL,"turkish");
	printf("Bu kod %d. satýrdan geçiyor ve konumu %s'da\n",__LINE__,__FILE__);
	printf("Bu kodu %s. dakikada ve %s. tarihte çalýþtýrdým",__TIME__,__DATE__);
	return 0;
}
