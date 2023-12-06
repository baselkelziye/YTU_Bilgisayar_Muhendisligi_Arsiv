/******************************************************************************

author:Zatona;
creat:12/12/2020 18:28;
finish_date:12/12/2020;
finish_time:18:42;
subject:triangle type (angle);

*******************************************************************************/
#include <stdio.h>

int main(){
    int a, b, c;
    
    printf("enter the lengths of the sides of the triangle in sorted order:(from S to L)\n");
    printf("enter first side : ");
    scanf("%d",&a);
    
    printf("enter second side: ");
    scanf("%d",&b);
    
    printf("enter third side : ");
    scanf("%d",&c);
    
    if(a^2+b^2==c^2){
        printf("this is right triangle");
    }
    else{
        if(a^2+b^2<c^2){
            printf("this is obtuse triangle");
        }
        else{
            printf("this is acute triangle");
        }
    }

    return 0;
}


