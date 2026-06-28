#include <stdio.h>
//Kullanıcıdan alınan N sayısı ile oluşturulmuş NxN matrisi iteratif şekilde artarak zigzag şekilde tarayan ve yerleştiren kod
int main() {
int i,j,N,yon=1,matris[50][50],satir=0,sutun=0; // yön 1 iken sağ yukarı olsun 
printf("Matrisinizin boyutunu giriniz: ");
scanf("%d", &N);
//Matrisimiz verilen örneklerde 1'den başlıyordu!
for(i=1; i<= N*N; i++){ //Bu for'u matris için değil İteratif artış için açtık, 1 den N'ye kadar. N^2 oldu mu çıkacak
    matris[satir][sutun] = i; //Satir-sutun zigzaglığı sağlarken i bize iteratifliği sağlayacak
    if(yon == 1){// Sağ veya Üst duvara çarpma ihtimalimiz var
        if(sutun == N-1){ //Köşelerde hem satır 0 hem sütun N-1. Önce sağ duvarı kontrol etmeliyiz. 
            satir++;
            yon=0;
        }else if(satir == 0){ //Eğer bu else if'i yukarıya, ilk kontrol olarak yazsaydık köşelerde sütun artıp dışarı çıkacaktık!
            sutun++;
            yon=0;
        }else{ //Sorun olmadığı sürece satır azalır sütun artar. Çünkü sağ yukarı çıkıyoruz!
            satir--;
            sutun++;
        }
    }
    else{ //Sol aşağı giderken sol ve alt duvara dikkat etmeliyiz ve önceliğimiz alt duvar!
        if(satir == N-1){
            sutun++;
            yon=1;
        }else if(sutun == 0){
            satir++;
            yon=1;
        }else{ //Sorun olmadığı sürece aşağı ve sola gideceğiz 
            satir++;
            sutun--;
        }

    }
}
printf("Matrisinizi görebilirsiniz: \n");
for(i=0; i<N; i++){
    for(j=0; j<N; j++){
        printf(" %2d", matris[i][j]); //Tek hane çift hane ayrımı olmasın diye %2d yazdım, sadece biraz görsellik :)
    }
    printf("\n");
}
}