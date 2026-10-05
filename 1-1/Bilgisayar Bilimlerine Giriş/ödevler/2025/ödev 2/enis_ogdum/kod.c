#include<stdio.h>

int main(){
    int counter=1,max=1;
    int previous;
    int number;
    int color;



printf("Enter the number!\n");
scanf("%d",&number);
color=number;

if (color==-1)
{
    printf("top çekilmedi!\n");
}


while (number!=-1)
{
     previous=number;
     scanf("%d",&number);

    if (number==previous)
    {
        counter++;
    }else{
        counter=1;
    }

    if (counter>max)
    {
        max=counter;
        color=previous;
    }
    
    
    
}

if (color!=-1)
{
    printf("Renk:%d Uzunluk:%d",color,max);
}


    return 0;
}