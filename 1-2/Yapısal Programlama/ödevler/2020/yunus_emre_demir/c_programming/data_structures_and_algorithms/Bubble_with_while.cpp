#include<stdio.h>

/*Bublenin xchg degiskeni ve while eklenerek daha stabil hale getirilmis hali
Burada Bubble xchg=1 olduðu sürece (yani sýralama yapýldýysa) tekrar döngüye
girecek yok eger hic siralama yapilmadiysa artik dizi siralanmis demektir dolayýsýyla donguden cikacak! 

while icine girince xchg=0 yapiyoruz ilerleyen kodda siralama gerceklesirse xchg=1
olur ve sistem tekrar while dongusune girer yok siralama gerceklesmezse xchg=0 degeri
bozulmadan kalýr ve birdaha donguye girmez.
*/
int main(){
	int n=0,i=0,j,xchg,tmp=0;
	
	printf("Diziniz kac elemanli?");
	scanf("%d",&n);
	int dizi[n];
	
	printf("\nDizinize elemanlarini giriniz.");
	for(i=0; i<n ; i++){  scanf("%d",&dizi[i]);}	 	//dizi yarat  
	printf("\nMevcut diziniz : \n");
	for(i=0; i<n ; i++){  printf("%d ",dizi[i]);	} // dizi yazdýr.
	
	i= 0;
	xchg= 1;
	while(i<(n-1) && xchg==1){   
		xchg=0;
		for(j=0; j<n-1-i ; j++){  
			if(dizi[j]>dizi[j+1]){
				tmp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=tmp;
				xchg=1;
			}
		}
		i++;
	}
	
	printf("\nSirali diziniz : \n");
	for(i=0; i<n ; i++){  printf("%d ",dizi[i]);	} // dizi yazdýr.
	
	
	return 0;
}
