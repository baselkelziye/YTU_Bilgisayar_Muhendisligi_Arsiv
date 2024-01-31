#include<stdio.h>

#define MAXSIZE 30

void diagonalTraversal(int array[][MAXSIZE],int n);
void initializeMatrix(int array[][MAXSIZE],int n);
void printMatrix(int array[][MAXSIZE],int n);


int main()
{
    int n;
    int array[MAXSIZE][MAXSIZE];
    printf("Enter Row and Column Size For Diagonal Traversal\n");
    scanf("%d",&n);
    initializeMatrix(array,n);
    printf("Before Traversal\n");
    printMatrix(array,n);
    printf("\n");
    diagonalTraversal(array,n);
    return 0;
}

void diagonalTraversal(int array[][MAXSIZE],int n)
{
	int i,j,m,k,mi,mj;
	printf("\n");
	for(i=2;i<=2*n;i++){
		m=i-n;
		// nereden baslayacagiz (mi,mj)
		if (m>0){
			mi=m-1;
			mj=n-1;		
		}
		else{
			mi=0;
			mj=i-2;
		}
		// kac eleman yazdiracagiz (k)	
		if (i<=n) 
			k=i-1;
		else
			k=2*n-i+1;
			
		for(j=1;j<=k;j++){
			printf("%2d ",array[mi][mj]);
        	mi=mi+1;
        	mj=mj-1;
		}
		printf("\n");
	}
	
    return;
}

void initializeMatrix(int array[][MAXSIZE],int n)
{  
    int i,j,k=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            array[i][j]=k++;
        }
    }
    return;
}

void printMatrix(int array[][MAXSIZE],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%2d ",array[i][j]);
        }
        printf("\n");
    }
}
