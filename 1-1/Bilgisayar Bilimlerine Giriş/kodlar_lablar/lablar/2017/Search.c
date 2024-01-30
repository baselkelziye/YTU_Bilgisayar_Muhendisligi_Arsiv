#include <stdio.h>
#define SIZE 1025
void linearSearch1(int array[], int , int  );
void linearSearch2(int array[], int , int );
void binarySearch(int array[], int ,int  );
void interpolationSearch(int array[], int ,int );

int main()
{
   int c,   n, search, array[SIZE];
   printf("Enter number of elements\n");
   n=1024;//scanf("%d",&n);
 
   printf("Enter %d integers\n", n);
   for (c = 0; c < n; c++)
      array[c]=c;
	  //scanf("%d",&array[c]);
 
   printf("Enter value to find\n");
   scanf("%d", &search);

   linearSearch1(array, n, search);  
   linearSearch2(array, n, search);  
   binarySearch(array, n, search); 
   interpolationSearch(array, n, search);
 
   return 0;   
} 
/*
 * Linear Search by using flag(isFound)
 */
void linearSearch1(int array[], int n, int search ){
   int c=0;
   int isFound=0;
   while(c<n && !isFound)
   {
   	    if(array[c]==search)
   	    	{
   	    		printf("%d found at location %d, in the %d th iteration\n", search, c,c+1);
				isFound=1;	
			}
	c++;
   }
   if (!isFound)
      printf("Not found! %d is not present in the list.\n", search);
}
/*
 * // Linear Search -2 without using flag(isFound)
 */
void linearSearch2(int array[], int n, int search){
   int c=0;   
   while(array[c]!=search && c<n)
   {
   	   c++;
   }
   if (c!=n-1)
     	printf("%d found at location %d, in the %d th iteration\n", search, c,c+1);
   else
		printf("Not found! %d is not present in the list.\n", search);   
}

void binarySearch(int array[], int n,int search ){
   int isFound=0;
   int first = 0;
   int last = n - 1;
   int middle = (first+last)/2;
   int c=1;
 
   while (first <= last && !isFound) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location %d, in the %d th iteration\n", search, middle,c);
         isFound=1;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
      c++;
   }
   if (!isFound)
      printf("Not found! %d is not present in the list.\n", search);
}

void interpolationSearch(int arr[], int n,int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);
 	int c=0;
 	int isFound=0;
 	int pos;
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi] && !isFound)
    {
        c++;
		// Probing the position with keeping
        // uniform distribution in mind.
        pos = lo + (((double)(hi-lo) / (arr[hi]-arr[lo]))*(x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x){
        	isFound=1;
        	printf("%d found at location %d, in the %d th iteration\n", x, pos,c);	
		}     
        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;
        // If x is smaller, x is in lower part
        else
            hi = pos - 1;
    }
    if (!isFound)
      printf("Not found! %d is not present in the list.\n", x);    
}
