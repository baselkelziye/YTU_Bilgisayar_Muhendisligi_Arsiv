#include<stdio.h>
#define DIZI_SIZE 100

int main(){
    int array[DIZI_SIZE];
    int n,i;

printf("how many elements are you gonna enter?\n");
scanf("%d",&n);

printf("enter the elements of the array:\n");

for ( i = 0; i < n; i++)
{
    scanf("%d",&array[i]);
}

for ( i = 0; i < n; i++)
{
    printf("%d ",array[i]);
}

int low,j;
int temp;

for ( i = 0; i < n-1; i++)
{
   low=i;
   for ( j = i+1; j< n; j++)
   {
      if (array[j]<array[low])
      {
         low=j;
      }
      
   }
   temp=array[low];
   array[low]=array[i];
   array[i]=temp;

}

printf("\n");
for ( i = 0; i < n; i++)
{
    printf("%d ",array[i]);
}


return 0;
}