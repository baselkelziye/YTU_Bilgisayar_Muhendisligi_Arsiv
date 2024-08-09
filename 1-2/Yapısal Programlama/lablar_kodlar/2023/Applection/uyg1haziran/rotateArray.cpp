#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
#define MAXSIZE 30
 
int haveARN(int max);
void leftRotate(int array[MAXSIZE],int n);
void rotateByOne(int array[MAXSIZE],int n);
void printArray(int array[MAXSIZE],int n);
 
int main()
{
   srand(time(NULL));	
   int size=15;
   int sampleArray[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   printArray(sampleArray,size);
   leftRotate(sampleArray,size);
   printArray(sampleArray,size);
   return 0;
}
 
int haveARN(int max)
{
   return rand() % max;
}
 
void leftRotate(int array[MAXSIZE],int n)
{
   int i,randomNumber;
   randomNumber=haveARN(n);
   printf("The Array Will Be Rotated By %d\n",randomNumber);
   for (i=0;i<randomNumber;i++)
   {
       rotateByOne(array,n);
   }
}
 
void rotateByOne(int array[MAXSIZE],int n)
{
   int i,temp;
   temp=array[0];
   for(i=1;i<n;i++)
   {
       array[i-1]=array[i];
   }
   array[n-1]=temp;
}
 
void printArray(int array[MAXSIZE],int n)
{
   int i;
   for(i=0;i<n;i++)
       printf("%d ",array[i]);
   printf("\n");
}

