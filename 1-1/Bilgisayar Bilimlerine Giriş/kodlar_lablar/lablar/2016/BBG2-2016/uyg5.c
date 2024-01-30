#include <stdio.h>

int BykBul(int, int, int);
int MutlakDegerAl(int tmp);

int main(){
	int a1, a2, a3, a_byk;
	printf("3 deger gireceksiniz...\n");
	printf("1 -> ");
	scanf("%d", &a1);
	printf("2 -> ");
	scanf("%d", &a2);
	printf("3 -> ");
	scanf("%d", &a3);
	
	a_byk = BykBul(a1, a2, a3);
	
	printf("En byk deger : %d\n", a_byk);
	
	return 0;
}

int BykBul(int a1, int a2, int a3){
	if(MutlakDegerAl(a1) > MutlakDegerAl(a2))
		if(MutlakDegerAl(a1) > MutlakDegerAl(a3))
			return a1;
		else
			return a3;
	else
		if(MutlakDegerAl(a2) > MutlakDegerAl(a3))
			return a2;
		else
			return a3;
}

int MutlakDegerAl(int sayi){
	if(sayi < 0)
		return sayi * -1;
	else
		return sayi;	
}
