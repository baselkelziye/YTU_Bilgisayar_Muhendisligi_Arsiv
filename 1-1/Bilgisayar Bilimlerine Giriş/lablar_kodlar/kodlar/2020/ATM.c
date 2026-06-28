#include <stdio.h>

int main(){
    int x;
    int a,b,c,d,e,f;
    printf("enter the amount of money:");
    scanf("%d",&x);
    if(x%5==0){
    //number of 200    
        a=x/200;    
        x=x%200;
    //number of 100
        b=x/100;
        x=x%100;
    //number of 50
        c=x/50;
        x=x%50;
    //number of 20
        d=x/20;
        x=x%20;
    //number of 10 
        e=x/10;
        x=x%10;
    //number of 5
        f=x/5;
        x=x%5;
    
    
    //printf("\n remaining money %d",x);
    printf("\n number of 200 is \n %d",a);
    printf("\n number of 100 is \n %d",b);
    printf("\n number of 50 is \n %d",c);
    printf("\n number of 20 is \n %d",d);
    printf("\n number of 10 is \n %d",e);
    printf("\n number of 5 is \n %d",f);

}
    else{ 
        printf("\n EROR \n number Must be a multiple of five"); 
    }
    return 0;
}