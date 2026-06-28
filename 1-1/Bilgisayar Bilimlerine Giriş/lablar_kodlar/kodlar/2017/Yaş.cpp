#include <stdio.h>

int main (){

int DogumYili, Yil;
printf("Hangi yildayiz : ");
scanf("%d", &Yil);
printf("Dogum yiliniz : ");
scanf("%d", &DogumYili);
printf("Siz %d yasindasiniz.", Yil-DogumYili);
return 0;
}

