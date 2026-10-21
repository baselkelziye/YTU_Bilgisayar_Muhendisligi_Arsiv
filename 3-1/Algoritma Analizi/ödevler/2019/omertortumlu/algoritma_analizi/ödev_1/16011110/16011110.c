#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
int donus;	//solvable fonksiyonundan dönüþ deðeri 
int tmp1=1000;	//Arttýrýlan baþlangýç deðeri tmp1
int tmp2=1000;	//Azaltýlan baþlangýç deðeri de tmp2
int k;
int j=0;
int  solvable(int start,int leapCount[],int n){	
	if(j==n){
		printf("!!!Çok boyutlu loop\n");
		return 0;
	}
	j++;
	if(start<0 || start>=n){ //Start deðiþkeninin belirlediðimiz dizi içinde olduðunu kontrol ediyor.
		return 0;				
	}
	if(start==n-1){	//Start deðiþkeninin son indise ulaþtýðýný kontrol ediyor.
		return 1;
	}		
	if(leapCount[start]+start>=n){ //start ile indisin deðerinin toplamý n den buyuk olursa bir sola geliyor
		printf("!!!Saga Atla:[%d](+%d):%d(Ooops)\n",start+1,leapCount[start],leapCount[start]+start+1);
		printf("Sola Atla:[%d](-%d):%d\n",start+1,leapCount[start],start-leapCount[start]+1);
		start=start-leapCount[start];
		if(start<0){ //( Örneðin: 1-1-5-1-1) baþlangýç 3 olarak ayarlanýrsa saðdan ve soldan sýçrama yapýlamaz.
			return 0;
		}	
		tmp1=leapCount[start]; //Arttýrýlan baþlangýç deðeri tmp1, azaltýlan baþlangýç deðeri de tmp2 deðiþkeninde tutulur.
		if(tmp1==tmp2 ){ //Eðer arttýrýmda sýnýr aþýlýyorsa ve tmp ler eþit çýkarsa bir sola daha kayýlýr.
			if(start+tmp1>=n && start-tmp2<0)
				return 0;				
			else if(start-tmp2>0){ //tmp1 ile tmp2 ayný deðilse iki kere sola gidilir
				printf("Sola Atla:[%d](-%d):%d\n",start+1,leapCount[start],start-leapCount[start]+1);
				start=start-leapCount[start];
				donus=solvable(start,leapCount,n);
				if(donus==1) return 1;
				if(donus==0) return 0;				
			}
		}
		else{																	
			donus=solvable(start,leapCount,n);	//tmp1 ile tmp2 ayný deðilse bir kere sola gidilir
			if(donus==1) return 1;
			if(donus==0) return 0;
		}
	}
	else{	
		printf("Saga Atla:[%d](+%d):%d\n",start+1,leapCount[start],leapCount[start]+start+1);
		start=leapCount[start]+start;		//start ile indisin deðerinin toplamý n den kucukse		
		tmp2=leapCount[start];		 //Azaltýlan baþlangýç deðeri tmp2 deðiþkeninde tutulur.
		donus=solvable(start,leapCount,n);		//starta yeni deðeri ataniyor
		if(donus==1) return 1;
		if(donus==0) return 0; 
	}	
}
int main(){
					// Dinamik bir dizi yaratmak için pointer kullanýlýr.
	int n,i,start,*leapCount;	// Dizimizin kac elemanli olacagini n de, cekirgenin nerden baþlýyacaðýný startta tutuyorum.i yi indis iþlemlerinde kullanýyorum
	printf( "Cekirgenin atlayacagi tas sayisini giriniz-> ");	// Kullanicidan tas sayisini girmesini istiyoruz.
	scanf( "%d", &n );	//Toplam taþ sayýsý girilir
	leapCount= calloc( n, sizeof( int ) );	// calloc( ) fonksiyonuyla dinamik olarak dizi girilen boyuta göre ayarlanýr. 
	for(i = 0; i < n-1; i++ ){	//Taþlarýn üstündeki sayý deðerlerini alýyoruz son taþ haric(0)
		printf( "%d:", i+1 );
		scanf("%d",&leapCount[i]);
	}
	for(i = 0; i < n; i++ ){
		printf( "[%d]:%d--", i+1,leapCount[i] ); //Taþlarýn üstündeki sayý deðerlerini yazdýrýyoruz.
	}	
	printf("\nCekirge atlamaya hangi tastan baslasin?[1-%d]:",n); //Start deðiþkenini kullanýcýdan istiyoruz
	scanf("%d",&start);	//Kullanýcý tarafýndan start deðiþkeni giriliyor.
	printf("Start:%d\n", start,leapCount[start]); //Baþlanýlacak taþtaki bilgi veriliyor
	donus=solvable(start-1,leapCount,n);	//Cekirgenin taþlardan çýkýp çýkmadýðý bilgisi recursive fonksiyon yardýmýyla hesaplanýyor
	if(donus==1){	//Cekirgenin son taþa ulaþýp ulaþamadýðý yazdýrýlýr.
		printf("Exit, cekirge son tasa ulasmayi basardi...\n");	
	}
	else 
		printf("Loop, cekirge son tasa ulasmayi basaramadi...\n");
	free(leapCount);// Dinamik olan diziyi kullandiktan sonra free fonksiyonunu kullanýyorum.
	system("pause");		
	return 0;
	//Ömer Lütfü Tortumlu 16011110
}
