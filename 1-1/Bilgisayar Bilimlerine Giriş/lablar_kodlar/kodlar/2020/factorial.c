/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int x;
    int i;
    int mul=1;
    printf("enter the number that you want to learn his factorial:");
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        mul=mul*i;
        
    }
    printf("\n %d",mul);
    
    //printf("\n ASD %d",x);
    

    return 0;
}
