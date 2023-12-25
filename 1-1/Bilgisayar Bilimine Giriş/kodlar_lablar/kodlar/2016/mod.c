#include <stdio.h>
#include <stdlib.h>

int modAlValue(int sayi, int gore);
void modAlRef(int* sayi, int gore, int* mod_b);
const int GORE = 9;

int main(){
	int a;
	int mod_a, mod_b;
	
	printf("Modu alinacak sayiyi giriniz: ");
	scanf("%d", &a);
	
	mod_a = modAlValue(a, GORE);
	modAlRef(&a, GORE, &mod_b);
	
	
	printf("%d %% %d = %d\n", a, GORE, mod_a);
	printf("%d %% %d = %d\n\n", a, GORE, mod_b);
	
	system("PAUSE");
	return 0;
}

int modAlValue(int sayi, int gore){ //Call by Value
	int mod;
	mod = sayi - (sayi/gore)*gore;
	while(mod < 0)
		mod += gore;
	return mod;
}

void modAlRef(int* sayi_addr, int gore, int* mod_b){ //Call by Reference
	*mod_b = *sayi_addr - (*sayi_addr/gore)*gore;
	while(*mod_b < 0)
		*mod_b += gore;
}
