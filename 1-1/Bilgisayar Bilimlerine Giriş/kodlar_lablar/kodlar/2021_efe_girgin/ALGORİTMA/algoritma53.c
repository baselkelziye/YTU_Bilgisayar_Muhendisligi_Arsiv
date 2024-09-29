#include <stdio.h>
int main(){
	int sayi,count,j,i;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
		
	
	for(i=2;i<sayi;i++){
		count=0;
		for(j=1;j<=i;j++){
		if(i%j==0){
		
			count++;
		}
	}
	if(count==2){
		printf("%d\t",i);
	}
}

		return 0;
	}
	


//kod calýsýyor
//girilen bir sayiya kadar olan asal sayilari veren algoritma ve programi
//sayfa 46
//1.soru

