/* BOL VE YONET */
#include<stdio.h> 


void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
/*
// Bu fonksiyon quicksort aýrma iþlemi yapar.
 
int diziayýr(int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot en üst deðer seçilir
	int i = (low - 1); // ilk element seçilir

	for (int j = low; j <= high- 1; j++) 
	{ 
	
		if (arr[j] <= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
	
		int pi = diziayýr(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
*/

/*Rasgele seçilen bir  Key[i]anahtarý için,  Lockdizisi üzerinde arama yaparak  Lockdizisini 
bu anahtardan küçük olan kilitler, eþit olan kilitler ve büyük olan kilitler olarak yeniden 
düzenleyiniz. Bu durumda Lock[x], Key[i]anahtarýnýn uyduðu kilittir. */
  
    
/*Ayný iþlemi bu sefer Lock[x]kilitine uygun anahtarý bulmak için  Keydizisini x. kilitten küçük 
anahtarlar ve büyük anahtarlar þeklinde düzenlerseniz  Key[i]anahtarý ile  Lock[x]kiliti  karþý 
karþýya gelmiþolur.*/
   
    
/*Bundan sonra önce son yerleþtirdiðiniz anahtardan küçük anahtarlarýn içinden rasgele bir anahtar 
seçerek, küçük anahtarlarýn kilitlerini bulmayý bitirdikten sonra büyük anahtarlar için iþlemi 
tekrarlayarak bütün anahtarlara uygun kilitleri bulabilirsiniz.*/
  


/* Fonksiyonu yazdýrýr */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	    printf("n"); 
} 

 
int main() 
{ 
	
	int arr[] = {10, 111, 8, 9, 1, 5}; 
	
	int Lock[]={10,5,2,24,111,55,20};
	int Key[]={5,10,20,2,111,24,55};;
	
	
	int n = sizeof(arr)/sizeof(arr[0]);  //?????????????????
	quickSort(arr, 0, n-1); 
	
	
	printArray(arr, n); 
	return 0; 
} 

