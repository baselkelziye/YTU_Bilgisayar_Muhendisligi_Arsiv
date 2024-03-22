/* BOL VE YONET */
#include<stdio.h> 


void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
/*
// Bu fonksiyon quicksort a�rma i�lemi yapar.
 
int diziay�r(int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot en �st de�er se�ilir
	int i = (low - 1); // ilk element se�ilir

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
	
		int pi = diziay�r(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
*/

/*Rasgele se�ilen bir  Key[i]anahtar� i�in,  Lockdizisi �zerinde arama yaparak  Lockdizisini 
bu anahtardan k���k olan kilitler, e�it olan kilitler ve b�y�k olan kilitler olarak yeniden 
d�zenleyiniz. Bu durumda Lock[x], Key[i]anahtar�n�n uydu�u kilittir. */
  
    
/*Ayn� i�lemi bu sefer Lock[x]kilitine uygun anahtar� bulmak i�in  Keydizisini x. kilitten k���k 
anahtarlar ve b�y�k anahtarlar �eklinde d�zenlerseniz  Key[i]anahtar� ile  Lock[x]kiliti  kar�� 
kar��ya gelmi�olur.*/
   
    
/*Bundan sonra �nce son yerle�tirdi�iniz anahtardan k���k anahtarlar�n i�inden rasgele bir anahtar 
se�erek, k���k anahtarlar�n kilitlerini bulmay� bitirdikten sonra b�y�k anahtarlar i�in i�lemi 
tekrarlayarak b�t�n anahtarlara uygun kilitleri bulabilirsiniz.*/
  


/* Fonksiyonu yazd�r�r */
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

