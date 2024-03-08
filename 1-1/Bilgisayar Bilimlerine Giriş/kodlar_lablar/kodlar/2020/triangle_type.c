#include <stdio.h>

int main(){
    int a,b,c;
    
    printf("enter the lengths of the sides of the triangle: \n");
    scanf("%d",&a); scanf("%d",&b); scanf("%d",&c);
    //printf("%d%d%d",a,b,c);
    
    if(a==b){
        if(a==c){
            printf("equilateral triangle \n");
        }
        else{
            printf("isosceles triangle \n");
        }
    }
    else{
        if(a==c){
            printf("isosceles triangle \n");
        }
        else{
            if(b==c){
                printf("isosceles triangle\n");
            }
            else{
                printf("scalene triangle \n");
            }
        }
    }

    return 0;
}
