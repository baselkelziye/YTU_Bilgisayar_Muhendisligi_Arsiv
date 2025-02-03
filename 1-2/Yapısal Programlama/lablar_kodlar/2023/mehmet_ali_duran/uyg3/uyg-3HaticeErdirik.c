/* 
SORU:
Verilen 3 boyutlu noktalarýn orjine olan uzaklýklarýný Selection Sort algoritmasýyla büyükten küçüðe
veya küçükten büyüðe sýralayan bir algoritmayý C dilinde gerçekleyelim. 
*/

#include <stdio.h> 
#include <stdlib.h>
#define arraySize 5

struct point
{
    int x;
    int y;
    int z;
};

void selectionSort( struct point array[], const int size, int (*compare)(float distance1, float distance2) ); //O(n^2)
void swap(struct point *a, struct point *b); 
int ascending(float distance1, float distance2); // implements ascending order 
int descending(float distance1, float distance2); // implements descending order 
float distance(int x, int y, int z);

int main() 
{ 
    int xArray[arraySize]={ 12, 2, 4, 8, 10};
    int yArray[arraySize]={ 10, 5, 2, 3, 12};
    int zArray[arraySize]={  5, 2, 0, 4,  1};
    int order; // 1 = ascending, 2 = descending 
    int counter; // array index 
    struct point *a;
    a = (struct point *) malloc(arraySize*sizeof(struct point));

    for (counter = 0; counter < arraySize; ++counter ) 
    {
        a[counter].x = xArray[counter];
        a[counter].y = yArray[counter];
        a[counter].z = zArray[counter];
        printf("Point %d: (%d, %d, %d) ", counter+1, a[counter].x, a[counter].y, a[counter].z);
        printf("Distance to orjin: %.2f\n", distance(a[counter].x, a[counter].y, a[counter].z));
    }
    printf("\n");

    printf("Enter 1 to sort in ascending order,\nEnter 2 to sort in descending order: "); 
    scanf("%d",&order); 

    if (order == 1) 
    { 
        selectionSort(a, arraySize, ascending ); 
        printf("\nData items in ascending order\n"); 
    }
   
    else 
    { 
        selectionSort( a, arraySize, descending ); 
        printf("\nData items in descending order\n"); 
    }

    for (counter = 0; counter < arraySize; ++counter ) 
        printf("(%d, %d, %d)", a[counter].x, a[counter].y, a[counter].z); 

    printf("\n"); 
    
    return 0;    
}

void selectionSort(struct point array[], const int size, int (*compare)(float distance1, float distance2))
{ 
    int smallestOrLargest, index, i; // index of smallest (or largest) element 
    float d1,d2;
   // loop over size - 1 elements 
    for (i = 0; i < size - 1; ++i ) 
    { 
        smallestOrLargest = i; // first index of remaining vector 

        // loop to find index of smallest (or largest) element 
        for (index = i + 1; index < size; ++index ) 
        {
            d1 = distance(array[smallestOrLargest].x, array[smallestOrLargest].y, array[smallestOrLargest].z);
            d2 = distance(array[index].x, array[index].y, array[index].z);
            //printf("d1: %ld\t",d1);
            //printf("d2: %ld\n",d2);
            if (!compare(d1,d2))
                smallestOrLargest = index; 
        }
        swap(&array[smallestOrLargest], &array[i]); 
   }
}

void swap( struct point *a, struct point *b)
{ 
    struct point tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
   /*
   //point a to tmp
   tmpX=a->x;
   tmpY=a->y;
   tmpZ=a->z; 
   //point b to a 
   a->x=b->x;
   a->y=b->y;
   a->z=b->z;
   //tmp to point b
   b->x=tmpX;
   b->y=tmpY;
   b->z=tmpZ;
   */
}

int ascending(float distance1, float distance2)
{ 
    return (distance1 < distance2);
    // returns true if a is less than b printf("%d ",a[counter]); 
}

int descending(float distance1, float distance2)
{ 
    return (distance1 > distance2);
    // returns true if a is greater than b printf("%d ",a[counter]); 
}

float distance(int x,int y,int z)
{
    return sqrt((x*x)+(y*y)+(z*z));
}
