#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

typedef struct node
{
	int xApsis[MAX];
	int yOrdinat[MAX];
	
}POINTS;

POINTS inputArray(int size);
void printStruct(POINTS first,int size);
int calculateMedian(int size);
void quickSort(int arrayX[],int arrayY[],int low,int high);

void swap(int *num1, int *num2);

int findDistance(POINTS first, int low, int high, int sizeOfCoordinates);

int closer(POINTS array,int size,int min,int median);

int findRectangle(POINTS array,int size,int min);
int findMin(int number1,int number2);





void main()
{
	int sizeOfCoordinates; //N adet kullanýcý tarafýndan verilen nokta kordinatlarý sayýsý
	int i,j; //For için kullanýlan deðiþken
	POINTS first;
	int min;
	int firstIndex,secondIndex;
	int median;
	
	printf("How many coordinates? ");
	scanf("%d" , &sizeOfCoordinates);
	
	first=inputArray(sizeOfCoordinates);
	
	min=findDistance(first,0,sizeOfCoordinates-1,sizeOfCoordinates);
	min=closer(first,sizeOfCoordinates,min,calculateMedian(sizeOfCoordinates));
	
	printf("final min is: %f" , sqrt(min));
	
	
}

POINTS inputArray(int size)
{
	int i=0;
	POINTS first;
	FILE *file;
	file=fopen("Input.txt", "r");
	
	if(file==NULL)
	{
		printf("[ERROR]! Not read\n");
		exit(-1);
	}
	else
	{
		
		while(!feof(file))
		{
			fscanf(file, "%d %d", &first.xApsis[i],&first.yOrdinat[i]);		
			i++;
		}
	}
		
	printf("Your coordinates...\n");
	printStruct(first,size);
	quickSort(first.xApsis, first.yOrdinat, 0, size-1);
	printf("Your sorted by X coordinates ...\n");
	printStruct(first,size);
	
	return first;	
}	

void printStruct(POINTS first,int size)
{
	int i; 
	
	for(i=0; i<size; i++)
	{
		printf("%d %d \n" , first.xApsis[i], first.yOrdinat[i]);
	}
}

int calculateMedian(int size)
{
	int median;
	
	if(size%2 == 0)
	{
		median=(size/2)-1;
	}
	else
	{
		median=size/2;
	}
		
	return median;
}


void quickSort(int arrayX[],int arrayY[],int low,int high)
{
    int i,j,pivot;

     if(low < high){
         pivot = low;
         i = low;
         j = high;

         while(i < j)
		 {
             while(arrayX[i] <= arrayX[pivot] && i < high)
             {
             	i++;
			 }
             while(arrayX[j] > arrayX[pivot])
             {
             	j--;
			 }
             if(i <j)
			 {
			 	swap(&arrayX[i],&arrayX[j]);
			 	swap(&arrayY[i],&arrayY[j]);
             }
         }
         swap(&arrayX[pivot],&arrayX[j]);
         swap(&arrayY[pivot],&arrayY[j]);
         quickSort(arrayX,arrayY,low,j-1);
         quickSort(arrayX,arrayY,j+1,high);
    }
}

void swap(int *num1, int *num2)
{
	int temp;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


int findDistance(POINTS first, int low, int high, int sizeOfCoordinates)
{
	int min=10000;
	int min1,min2;
	int i,j;
	int tempMin;
	int firstIndex,secondIndex;
	int median;
	
	
	if((2<=sizeOfCoordinates)&&(sizeOfCoordinates<=3))
	{
		for(i=low; i<high; i++)
		{
			for(j=i+1; j<sizeOfCoordinates; j++)
			{
				tempMin=pow(abs(first.xApsis[i]-first.xApsis[j]), 2);
				tempMin+=pow(abs(first.yOrdinat[i]-first.yOrdinat[j]), 2);
				if(tempMin<=min)
				{
					min=tempMin;
					firstIndex=i;
					secondIndex=j;
				}
			}	
		}
		printf("The closest points are ");
		printf("%d %d--", first.xApsis[firstIndex], first.yOrdinat[firstIndex]);
		printf("%d %d\n", first.xApsis[secondIndex], first.yOrdinat[secondIndex]);
		
		
		return min;
				
	}
	else if(sizeOfCoordinates>3)
	{
		
		median=calculateMedian(sizeOfCoordinates);
		min1=findDistance(first,low,median,(median-low+1));
		min2=findDistance(first,median+1,high,(high-median));
		
		if(min1>=min2)
		{
			return min2;
		}
		else
		{
			return min1;
		}
	}
	else
	{
		printf("[ERROR!] Invalid number of coordinates!\n");
	}
}

int closer(POINTS array,int size,int min,int median)
{
	int i;
	int j=0;
	POINTS rectangle;
	
	for(i=0; i<size; i++)
	{
		if(abs(array.xApsis[i]-array.xApsis[median])<min)
		{
			rectangle.xApsis[j]=array.xApsis[i];
			rectangle.yOrdinat[j]=array.yOrdinat[i];
			j++;
		}
	}
	
	return findMin(min,findRectangle(rectangle,j+1,min));
}

int findRectangle(POINTS array,int size,int min)
{
	int i,j;
	int tempMin;
	
	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			tempMin=pow(abs(array.xApsis[i]-array.xApsis[j]),2);
			tempMin+=pow(abs(array.yOrdinat[i]-array.yOrdinat[j]),2);
			if(tempMin<min)
			{
				min=tempMin;
			}
		}
	}
	return min;
}
int findMin(int number1,int number2)
{
	if(number1<number2)
	{
		return number1;
	}
	else
	{
		return number2;
	}
}
