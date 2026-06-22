// Verilen fonksiyonun çıktısını (Hata varsa belirtmesi) istenmişti
#include <stdio.h>
void printfxy(int);
int x=8;
static int j=2,y=4;
int main(){
    int x,y,k;
    for(x=0;x<2;x++){
        y=3,k=0;
        printf("%d %d %d", x,y,j); // İlk çıktı -> 0,3,2  //----------// 3. Çıktı -> 1,3,1 (j'nin statik değerini azaltmıştık, unutma!)
        printfxy(k);
    }
    return 0;
}
void printfxy(int a){
    static int y=12;
    y++;
    printf("%d %d %d %d", x,y,--j,a++); // 2. çıktı ->  8,13,1,0: 8->x'in global (program scope) değerini görüyor, 13->bloktaki y'yi görür, 1->j'nin f,le scope değerini görür, 0-> a++ demesi hem statik değil hem de önce değeri verir artımı sonra yapar
}                                       // 4. Çıktı -> 8,14,0,0: 14-> y, statil old. için 12'den yazsa bile 13'ten başlar ve de 13'ü arttırır.
// Kısacası sırasıyla cevaplar 0,3,2 - 8,13,1,0 - 1,3,1 - 8,14,0,0