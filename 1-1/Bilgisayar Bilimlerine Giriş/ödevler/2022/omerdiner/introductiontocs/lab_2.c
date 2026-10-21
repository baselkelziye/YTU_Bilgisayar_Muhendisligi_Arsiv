#include <stdio.h>
#define SIZE 5000

int main(void){
	//deðiþken tanýmlarý
	char dizi[SIZE];
	int i,length=0;
	
	//kullanýcýdan metni alýr
	printf("Metni giriniz:");
	gets(dizi);
	
	//dizi uzunluðunu bulur
	while(dizi[length]!='\0'){
		length++;
	}
	
	//ilk harf küçükse düzeltir
	if(dizi[0]<'z'&&dizi[0]>'a'){
		dizi[0]=dizi[0]+('A'-'a');
	}
	//dizi üzerinde tek döngüyle gerekli iþlemleri yapar
	for(i=0;i<length;i++){
		//noktadan sonraki karakter boþluksa ondan sonraki karakteri büyük harf yapar
		if(array[i]=='.'&&array[i+1]==' '){
			if(array[i+2]<='z'&&array[i+2]>='a'){
				array[i+2]=array[i+2]+('A'-'a');
			}   
		    
		}
		//noktadan sonraki karakter küçük harfse büyük harf yapar
		if(array[i]=='.'&&array[i+1]!=' '){
			if(array[i+1]<='z'&&array[i+1]>='a'){
				 array[i+1]=array[i+1]+('A'-'a');
			}
		           	
		}
		
	}
	//düzeltilmiþ metni yazdýrýr
	printf("Cikti:\n%s",array);
	
	return 0;
}
