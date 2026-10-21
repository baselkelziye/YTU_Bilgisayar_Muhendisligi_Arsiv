// 1. Verilen 2 adet sayýyý recursive fonksiyon ile çarpan fanksiyonu yazýnýz. Sayýlar fonksiyon parametresi olarak alýnacaktýr.
// 2. Macro yardýmýyla verilen  2 sayýdan birincisini bir azaltýp ikinci sayýnýn 3 eklenmiþ haliyle çarpýnýz.
#include <stdio.h>
#define birincisoru(a,b) (((a)-1)*((b)+3)) // 2018-Vize2  2. sorunun cevabý, sadece 1 satýr. :)
//  2018-Vize2  1. sorunun cevabýsadece int lale fonksiyonudur. 5 satýrlýk kod. 
int recursive(int d, int e){
		static int c=0;
		
			if (e > 0) {
				c=d + c;
				e--;
				recursive(d,e);
			}
	return c;
	}

int main(){
	int d=20, e=7;
	printf("%d\n",recursive(d,e));
	printf("%d",birincisoru(d,e));  // 2018-Vize2  2. sorunun ekran çýktýsý.
}

