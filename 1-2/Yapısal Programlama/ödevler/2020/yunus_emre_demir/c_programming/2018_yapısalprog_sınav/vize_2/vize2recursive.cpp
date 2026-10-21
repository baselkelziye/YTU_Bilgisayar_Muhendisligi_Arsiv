// 1. Verilen 2 adet sayıyı recursive fonksiyon ile çarpan fanksiyonu yazınız. Sayılar fonksiyon parametresi olarak alınacaktır.
// 2. Macro yardımıyla verilen  2 sayıdan birincisini bir azaltıp ikinci sayının 3 eklenmiş haliyle çarpınız.

#include <stdio.h>
#define birincisoru(a,b) (((a)-1)*((b)+3)) // 2018-Vize2  2. sorunun cevabı, sadece 1 satır. :)

//  2018-Vize2  1. sorunun cevabısadece int lale fonksiyonudur. 5 satırlık kod. 
int recursive(int d, int e){
	
	if (e != 0) {
       		return (d + recursive(d, (e-1))); 
	}
	return 0;
	}

int main(){
	int d=5, e=10;
	printf("%d\n",recursive(d,e));
	printf("%d",birincisoru(d,e));  // 2018-Vize2  2. sorunun ekran çıktısı.
}

