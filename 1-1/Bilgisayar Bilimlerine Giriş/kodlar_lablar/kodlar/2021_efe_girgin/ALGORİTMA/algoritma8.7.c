#include <stdio.h>
int main(){
	int N,i;
	float olasi;
	
	
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	olasi=1;
	
	for(i=1;i<=N;i++){
		
		olasi=olasi*(366-i)/365;
	}
	olasi=1-olasi;
	printf("%f",olasi);
	return 0;
}
//bir gruptaki kiþilerin en az iki tanesinin 
//yas günlerinin ayni güne gelme olasiligi
// :[(366-2)/365*(366-3)/365*___*(366-N)/365]seklindedir.
//buna göre 60 kiþilik bir grupta iki kiþinin yaþ günlerinin 
//ayni olma olasiligini hesaplayan algoritma ve programi
//sayfa 9
//kod calýsýyor
