#include<stdio.h>
#define MAX_LENGHT 100

int main(){
    int n;
    int matrix[MAX_LENGHT][MAX_LENGHT]={0};
    int layer;
    int i,j;
    int value;

printf("Enter the dimension of matrix!\n");
scanf("%d",&n);

layer=1;
value=1;
while (layer<=n)
{
    if (layer%2!=0)
    {
            for ( j = 0; j <=(layer-1); j++) // how much increased
            {
                matrix[layer-j-1][j]=value;
                value++;
            } 
            
    }else{
        for ( j = 0; j <=layer-1; j++) // how much increased
        {
            matrix[j][layer-j-1]=value;
            value++;
        }
        
    }
   layer++;
}

layer=n;
value=n*n;
while (layer>=2)
{
    if (layer%2==0)
    {
            for ( j = 0; j <=n-layer; j++) // how much increased
            {
                matrix[n-1-j][layer-1+j]=value;
                value--;
            } 
            
    }else{

        for ( j = 0; j <= n-layer; j++) // how much increased
        {
            matrix[layer+j-1][n-1-j]=value;
            value--;
        }
        
    }
    layer--;
}



for ( i = 0; i < n; i++)
{
    for ( j= 0; j < n; j++)
    {
        printf("%4d ",matrix[i][j]);
    }
    printf("\n");
}


    return 0;
}