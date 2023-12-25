// Sýralý bir dizide bir elemaný aramak O(log2n) Binary Search

#include <stdio.h> 
 
int main(void) 
{ 
    int arr[] = { 2, 4, 7, 10, 17, 25, 32, 37, 39, 43}; 
    int n = 10,bas,son,m; 
    int x = 35; 
    bas=0;
    son=n-1;
    m = bas + (son - bas) / 2;
    while ((bas < son) && (arr[m]!=x))
	{ 
        
        // If x greater, ignore left half 
        if (arr[m] < x) 
            bas = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            son = m - 1; 
       	m = bas + (son - bas) / 2; 
  
    } 
    
    if (arr[m] == x) 
       	printf("Element is present at index %d",m);
	else
  		printf("Element is not present in array");
  		
    return 0; 
} 
