#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 5;
	int k = n+1; 
  
    // Loop to print rows 
    for (int i=1; i<=n; i++) 
    { 
        // This loops runs only after first 
        // iteration of outer loop. It prints 
        // numbers from n to k 
        int temp = k; 
        while (temp <= n) 
        { 
            printf("%d ", temp); 
            temp++; 
        } 
  
        // This loop prints numbers from 1 to k-1. 
        for (int j=1; j<k; j++) 
            printf("%d ", j); 
  
        k--; 
        printf("\n"); 
        
        
    } return 0;
}
