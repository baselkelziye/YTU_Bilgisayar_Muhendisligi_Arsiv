/* Soru: Verilen 3 boyutlu noktalarýn orijine olan uzaklýklarýný selection sort algoritmasýyla 
büyükten küçüðe ya da küçükten büyüðe sýralayan bir algoritmayý C dilinde gerçekleyiniz
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arraySize 5

struct point{
	int x;
	int y;
	int z;
};

void selectionSort(struct point array[], const int size, int (*compare) (float distance1, float distance2));
//void selectionSort(struct point *array, const int size, int (*compare) (float distance1, float distance2));

void swap(struct point *a, struct point *b);
int ascending(float distance1, float distance2);
int descending(float distance1, float distance2);
float distance(int x, int y, int z);

int main() {
	
	int xArray[arraySize] = {12, 2, 4, 8, 10};
	int yArray[arraySize] = {10, 5, 2, 3, 12};
	int zArray[arraySize] = {5, 2, 0, 4, 1};
	
	int order, counter; // 1 ise descending 1 den farklýysa ise ascending
	struct point *a;
	
	a = (struct point *)malloc(arraySize*sizeof(struct point));
	
	for(counter = 0; counter < arraySize; counter++){
		//alternatif kullaným unutma çünkü dizi ile array ayný þey 
	//	(*(a+counter)).x =  xArray[counter];
	//	(*(a+counter)).y =  yArray[counter];
	//	(*(a+counter)).z =  zArray[counter];
		a[counter].x =  xArray[counter];
		a[counter].y =  yArray[counter];
		a[counter].z =  zArray[counter];
		printf("Point %d: (%d, %d, %d) ", counter+1, a[counter].x, a[counter].y, a[counter].z);
		printf("Distance to orijin: %.2f\n", distance(a[counter].x, a[counter].y, a[counter].z));
		
	}
	
	printf("Enter 1 to sort in ascending order, \nEnter 2 to sort descending order :");
	scanf("%d",&order);
	
	if(order == 1){
		selectionSort(a, arraySize, ascending);
		printf("\nData items in ascending order\n");
	}else{
		selectionSort(a, arraySize, descending);
		printf("\nData items in descending order\n");
	}
	
	for(counter = 0; counter < arraySize; counter++){
		printf("Point %d: (%d, %d, %d) ", counter+1, a[counter].x, a[counter].y, a[counter].z);
		printf("Distance to orijin: %.2f\n", distance(a[counter].x, a[counter].y, a[counter].z));		
	}
	printf("\n");
	
	
	
	return 0;
}

void selectionSort(struct point array[], const int size, int (*compare) (float distance1, float distance2)){
	//void selectionSort(struct point *array, const int size, int (*compare) (float distance1, float distance2));
	int smallestOrLargest, index, i;
	float d1, d2;
	
	for(i=0; i<size-1; i++){
		
		smallestOrLargest = i;
		
		for(index = i + 1; index < size; index++){
			
			d1 = distance(array[smallestOrLargest].x, array[smallestOrLargest].y, array[smallestOrLargest].z);
			d2 = distance(array[index].x, array[index].y, array[index].z);
			
			if(!compare(d1, d2)){
				smallestOrLargest = index;
			} 
			
		}
		swap(&array[smallestOrLargest], &array[i]);
	}
	
}

void swap(struct point *a, struct point *b){
	struct point temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
 
int ascending(float distance1, float distance2){
	return (distance1 < distance2);
}

int descending(float distance1, float distance2){
	return (distance1 > distance2);
}

float distance(int x, int y, int z){
	return sqrt((x*x) + (y*y) + (z*z));
}



