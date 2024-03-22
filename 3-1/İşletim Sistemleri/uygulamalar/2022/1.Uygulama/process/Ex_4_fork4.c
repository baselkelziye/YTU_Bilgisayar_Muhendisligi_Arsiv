#include <stdio.h> 
#include <unistd.h> 
  
int main() 
{ 
    if (fork()) { 
        if (!fork()) { 
            fork(); 
            printf("1 "); 
        } 
        else { 
            printf("2 "); 
        } 
    } 
    else { 
        printf("3 "); 
    } 
    printf("4 "); 
    return 0; 
} 
