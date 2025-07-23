#include<stdio.h>
#include<stdlib.h>
#define DEFAULTSIZE 10


/*
Bu dosyada buble sort algoritmasýnýn implemantasyonu bulunmaktadýr. algoritmada kullanýlan fonksiyonlar açýklamalarý ile verilmiþtir. Burada gösterilen fonksiyon açýklamalarýný ödevlerde oluþturduðunuz
kodlarda da ayný þekilde kullanmalýsýnýz. Problem çok basit olduðu için kod satýrlarýnda bulunan yorumlar size basit yada gereksiz gelebilir ve çoðunluðu zaten bariz olan komutlarý açýklamakta.
Ancak burada dikkat edilmesi gereken noktalar:
	1- fonksiyon çaðrýlarý: fonksiyonlarýn ne yaptýklarýný açýklasanýzda algoritma içerisinde çaðýrdýðýnýz fonksiyonlar için küçük açýklamalar, ne yaptýklarý sonucunda ne olacaðý gibi, yazarsanýz kodunuzun
	okununurluðu büyük ölçüde artacaktýr.
	2- if, switch case gibi komutlarda koþulunuzun ne olduðunu ve hangi durumlarda true hangi durumlarda false olacaðýný yazmanýz da algoritmanýzýn okununurluðunu arttýracaktýr.
	3- for, while gibi döngülerde çýkma koþulunuz yada döngüde yapýlan iþlerin ne olduðunuz yazamanýz da yararlý olacaktýr.
	
Yorumlarýnýz çok uzun olmamalýdýr. özellikle fonksiyon baþýnda yazdýðýnýz fonksiyon tanýmý kýsmý(@brief) en fazla 2-3 cümle olmalýdýr. Eðer çok önemli bir fonksiyonsa yada fonksiyon içerisinde 
çok fazla iþlem yapýlýyorsa daha uzun olabilir ancak bu gibi durumlarda ya fonksiyondan raporda veya video da bahsedilmeli yada fonksiyon daha küçük parçalara ayrýþtýrýlmalýdýr(Ödev kapsamlarý küçük
olduðu için eðer fonksiyonunuz çok büyükse muhtemelen küçük parçalara ayýrmak size daha iyi bir kod sunacaktýr. bu ayýrma iþlemi tabii ki rastgele bir noktadan yapýlmamalý ve kod içerisinde tekrar
eden yada sadece bir iþ yapan kod bloklarý þeklinde ayrýþtýrýlmalýdýr). @param ile fonksiyon parametreleri ve @return ile de fonksiyondan dönen deðerler açýklanmalý. Burada ki yorumlarda ayný þekilde 
kýsa olmalý ve eðer bu parametrelerin önemli görevleri varsa özeti fonksiyon baþýnda detaylarý ise kod satýrlarýnda yorumlarda verilmelidir. 

Deðiþken isimleri o deðiþkenin kullaným nedenini göstermeli. Bazý kýsaltmalarda sýkýntý yok(Array yerine Arr gibi) ve i, j, k gibi index için kullanýlan deðiþkenlerde de detaylý bir isim yazmanýz gerekmez.
Ancak bu tarz tek harf içeren deðiþkenleriniz sadece index iþlemi için kullanýlmalýdýr. fonksiyonlarda her deðiþken içinde açýklama yazmanýz gerekir ancak yine index gibi deðiþkenlerde belirtmenize 
gerek yok. sayý içeren deðiþkenlerden kaçýnýn(tmp1, tmp2, tmp3 gibi deðiþkenler sadece kaos yaratýr). deðiþken ismi açýklayýcý olsada sonuna 2 3 eklediðinizde çok bir anlamý kalmamakta. 

Unutmayýn bu yorumlarda ki amaç kodunuzun baþka kiþiler tarafýndan okunulabilir olmasýný saðlamaktýr. Bu yüzden yazdýðýnýz yorumlarý o kodu yazarkenki bakýþ açýnýzla deðil o kodla ilk kez karþýlaþýyormuþ
gibi yazýn. zamanla nerelerde ne tarz yorumlar yazmanýz gerektiðini rahatlýkla görebileceksiniz ancak baþlangýçta olabildiðince yorum yazýn. 
*/


/*
@brief compares two numbers based on ordering type and returns the comparison result.

@param First first number in comparison. This is the number that comes before in the array.
@param Second second number in comparison. This number comes after the First parameter
@param orderType determines the type of ording, if 0 Ascending, if 1 Descending.

@return return the comparison results of First and Second depending on orderType
*/
int sortOrder(int First,int Second,int orderType){
	if(orderType==0){ // orderType 0 is Ascending
		return First>Second;
	}else{// Descending
		return First<Second;
	}
}



/*
@brief a function that sorts the given array with the given type of ordering style

@param Arr array that contains the values to be sorted
@param n array lenght
@param orderType determines the type of ording, if 0 Ascending, if 1 Descending.

@return
*/
void bubleSort(int* Arr, int n,int orderType){
	int i,j;
	int temp_Swap;
	
	for(i=0;i<n;i++){// outer loop repeats the inner loop n time so that every member of the array are in the right place.
		for(j=0;j<n-1;j++){ // inner loop goes through every member of the array. it stops at n-1 because the comparison is between j and j+1
			if(sortOrder(Arr[j],Arr[j+1],orderType)){ // if the function return true we swap the two number in the array. sortOrder compares two numbers based on orderType.
				temp_Swap=Arr[j];
				Arr[j]=Arr[j+1];
				Arr[j+1]=temp_Swap;
			}
		}
	}
	
}
/*
@brief a function that prints the given array

@param Arr the array that to be printed
@param n array length

@return
*/
void printArray(int* Arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",Arr[i]);
		
	}
}



int main(){
	int n;// Array length
	int *Arr;// Array that contains the number to be sorted
	int i; // index
	int orderType; // Order of the sorted array.
	
	printf("Array Size(if a number below and equal to 0 entered default size will be used): ");
	scanf("%d",&n);
	if(n<=0) // We determine if the user entered a wrong number or wished to use the default number
		n=DEFAULTSIZE;
		
		
	Arr=(int*) malloc(n*sizeof(int));// n is either the number user has entered or the default number
	
	for(i=0;i<n;i++){ // User inputs the array to be sorted
		printf("Enter %d. Number in the array: ",i);
		scanf("%d",&Arr[i]);
	}
	
	printf("Enter Order Type(0==Ascending, 1==Descending): ");
	scanf("%d",&orderType); // we take the ordering type from the user
	
	bubleSort(Arr,n,orderType); // sorting the array
	printf("Sorted Array: ");
	printArray(Arr,n);
	
	return 0;
	
}
