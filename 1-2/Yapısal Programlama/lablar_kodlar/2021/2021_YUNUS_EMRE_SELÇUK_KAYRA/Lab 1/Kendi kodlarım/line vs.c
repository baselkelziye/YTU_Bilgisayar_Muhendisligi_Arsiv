#include <stdio.h>
#include <locale.h>
int main(void){
	setlocale(LC_ALL,"turkish");
	printf("Bu kod %d. sat�rdan ge�iyor ve konumu %s'da\n",__LINE__,__FILE__);
	printf("Bu kodu %s. dakikada ve %s. tarihte �al��t�rd�m",__TIME__,__DATE__);
	return 0;
}
