#include <stdio.h>

int main(){
    int steps,i;
    int first=1,second=1;
    
    printf("enter the number of steps:");
    scanf("%d",&steps);
    
    for(i=2;i<steps;i++){
        second=second+first;
        first=second-first;
    }
    printf("your Fibonacci number is: %d",second);

    return 0;
}
