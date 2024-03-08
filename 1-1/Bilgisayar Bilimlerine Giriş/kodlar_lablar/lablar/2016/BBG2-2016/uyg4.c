#include <stdio.h>

int MutlakDegerAl(int);

int main(){
	int a, a_mut;
	printf("Mutlak degeri alinacak sayiyi giriniz: ");
	scanf("%d", &a);
	
	a_mut = MutlakDegerAl(a);
	
	printf("|%d| -> %d\n", a, a_mut);
	
	return 0;
}

int MutlakDegerAl(int sayi){
	if(sayi < 0)
		return sayi * -1;
	else
		return sayi;	
}
