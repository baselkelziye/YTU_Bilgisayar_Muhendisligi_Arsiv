#include <stdio.h>
int main(){
	int sayi,i;
	printf("bir tane pozitif sayi giriniz\n");
	scanf("%d",&sayi);
	
	printf("%d sayisinin facctorleri:\n",sayi);
	for(i=1;i<=sayi;i++){
		if(sayi%i==0){
			printf("%d\t",i);
		}
	}
	return 0;
	
	
}
//Pozitif Tamsayýnýn Faktörleri
