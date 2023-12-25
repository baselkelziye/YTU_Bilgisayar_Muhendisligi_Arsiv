#include <stdio.h>


int main(){
    int MAX_SIZE=100;
    int x,i;
    
    printf("enter the number of elements:");
    scanf("%d",&x);
    
    int A[MAX_SIZE];
    //int A[x];
    //Taking serie elements from the user
    printf("enter elements \n");
    for(i=0;i<x;i++){
        int a;
        scanf("%d",&a);
        A[i]=a;
    }
    //printing elements of serie
    /*for(i=0;i<x;i++){
        printf("\n %d",A[i]);
        
    }*/
    //Calculate the average
    int avg=0;
    for(i=0;i<x;i++){
        avg +=A[i];
    }
    avg /=x;
    printf("\n avrage is: %d",avg);
    
    return 0;
}
