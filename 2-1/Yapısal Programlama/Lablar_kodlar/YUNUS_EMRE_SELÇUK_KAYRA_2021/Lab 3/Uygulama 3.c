/*
SORU:
Verilen 3 boyutlu noktalarýn orjine olan uzaklýklarýný Selection Sort algoritmasýyla büyükten küçüðe
veya küçükten büyüðe sýralayan bir algoritmayý C dilinde gerçekleyelim. 
*/

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#define arraySize 5

struct point{
	int x;
	int y;
	int z;
};
int descending(float d1, float d2);
int ascending(float d1, float d2);
float distance(int x, int y, int z);
void swap(struct point *a, struct point *b);
void selectionSort(struct point array[], const int size, int (*compare)(float distance1, float distance2));
int main() 
{
	int xArray[arraySize] = {12, 2, 4, 8, 10};
	int yArray[arraySize] = {10, 5, 2, 3, 12};
	int zArray[arraySize] = { 5, 2, 0, 4,  1};
	int order; // 1 = ascending, 2 = descending
	int counter;
	
	struct point *a;
	a = (struct point*)malloc(arraySize*sizeof(struct point));
	
	for(counter = 0; counter < arraySize; counter++)
	{
		a[counter].x = xArray[counter];
		a[counter].y = yArray[counter];
		a[counter].z = zArray[counter];
		printf("Point %d: (%d, %d, %d) :", counter+1, a[counter].x, a[counter].y, a[counter].z);	
		printf("Distance to orijin: %.2f\n", distance(a[counter].x, a[counter].y, a[counter].z));
	}
	
	printf("\nEnter 1 to sort ascending order,\nEnter 2 to sort in descending order:");
	scanf("%d", &order);
	
	if(order == 1)
	{
		selectionSort(a, arraySize, ascending);
	}
	else{
		selectionSort(a, arraySize, descending);
	}
	for(counter = 0; counter < arraySize; counter++)
	{
		printf("(%d, %d, %d) \n", a[counter].x, a[counter].y, a[counter].z);
	}
	
	return 0; 
}

float distance(int x, int y, int z)
{
	return sqrt((x*x)+ (y*y)+(z*z));
}

int ascending(float d1, float d2)
{
	return (d1 < d2);
}

int descending(float d1, float d2)
{
	return (d1 >= d2);
}

void swap(struct point *a, struct point *b)
{
	struct point tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void selectionSort(struct point array[], const int size, int (*compare)(float distance1, float distance2))
{
	int i, j, smallestOrLargest;
	float d1, d2;
	for(i=0; i < size-1; i++)
	{
		smallestOrLargest = i;
		for(j=i+1; j < size; j++)
		{
			d1 = distance(array[smallestOrLargest].x, array[smallestOrLargest].y, array[smallestOrLargest].z);
			d2 = distance(array[j].x, array[j].y, array[j].z);
			
			if(compare(d1, d2))
				smallestOrLargest = j;
		}
		swap(&array[smallestOrLargest], &array[i]);
	}
}
