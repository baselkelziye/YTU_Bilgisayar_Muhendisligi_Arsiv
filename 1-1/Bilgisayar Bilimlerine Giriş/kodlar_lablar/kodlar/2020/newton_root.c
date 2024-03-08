/******************************************************************************

author:Zatona;
creat:19/12/2020 --:--;
finish_date:19/12/2020;
finish_time:20:29;
subject:newton root ;

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main(){
    float x;
    float old=1, e=0.000000001, asd;

    printf("enter number:");
    scanf("%f", &x);
    float new= (old+x/old)/2;
    asd= fabs(new-old);
    while(asd>e){
        old=new;
        new= (old+ x/old)/2;
        asd= fabs(new-old);
    }
    printf("%f", new);

    return 0;
}
