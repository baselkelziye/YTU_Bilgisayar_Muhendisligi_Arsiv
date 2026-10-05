#include<stdio.h>
#define MAX_SIZE 100

int main(){

int i,j;
int n;
char matrix[MAX_SIZE][MAX_SIZE]={' '};
int offset;
int square_number;
int square_size;


printf("Enter the dimension of matrix\n");
scanf("%d",&n);

square_number=(n/4)+1;
square_size=n;
offset=0;

for ( i = 0; i < square_number; i++)
{
    for ( j = 0; j < square_size; j++)
    {
        matrix[offset+j][offset]='*'; // left
        matrix[offset][j+offset]='*'; // top
        matrix[n-1-offset][j+offset]='*'; //bottom
        matrix[j+offset][n-1-offset]='*'; // right
    }
    offset+=2;
    square_size-=4;

}

for ( i = 0; i < n; i++)
{
    for ( j = 0; j < n; j++)
    {
        if (matrix[i][j]=='*')
        {
            printf("%c ",matrix[i][j]);
        }
        else
{
    printf("  ");
}
    }
    printf("\n");
}



    return 0;
}