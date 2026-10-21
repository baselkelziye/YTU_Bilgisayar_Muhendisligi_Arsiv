#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **arr, int n);
int *initializeArray(int n);
void freeArray(int *arr);
void printArray(int *arr, int n);
int *reallocArray(int *arr, int newSize);


int main()
{
    srand(time(NULL));
    int N;
    int *arr;
    int count=1;
    int size=2;
    
    arr=initializeArray(size);
    
    printf("Enter N :");
    scanf("%d",&N);
    arr[0]=N;
    
    
    int ans=function(N);
    
    while(ans!=1){
    	arr[count]=ans;
    	count++;
    	if(count==size){
    		size=size*2;
    		arr=(int*)reallocArray(arr,size);
		}
		ans=function(ans);	
	}
	
	//last element
	arr[count]=1;
	count++;
	
	
	printf("Dizideki toplam eleman sayisi: %d\n",count);
	printf("Dizinin boyutu: %d\n",size);
	printArray(arr,count);
	
	freeArray(arr);

    return 0;
}

int *initializeArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("ERROR!");
        exit(-1);
    }
    return arr;
}
int function(int n){
	if(n%2==1){
		return 3*n+1;
	}else{
		return n/2;
	}
}
int *reallocArray(int *arr, int newSize)
{
    arr = realloc(arr, newSize * sizeof(int));
    return arr;
}

void freeArray(int *arr)
{
    free(arr);
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

