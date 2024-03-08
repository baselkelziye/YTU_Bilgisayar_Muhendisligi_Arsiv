#include <stdio.h>

/*
author:Zatona;
date:08/12/2020;
finish_time:20:22;
subject:find the smallest number out of three numbers;
*/

int main(){
    int min=0,a,b,c;
    
    printf("enter three numbers:\n");
    scanf("%d %d %d" ,&a,&b,&c);

    if(a<b){
        if(a<c){
            printf("The smallest number is %d",a);
        }
        else{
            printf("The smallest number is %d",c);
        }
    }
    else{
        if (b<c){
            printf("The smallest number is %d",b);
        }
        else{
            printf("The smallest number is %d",c);
        }
    }

    return 0;
}
