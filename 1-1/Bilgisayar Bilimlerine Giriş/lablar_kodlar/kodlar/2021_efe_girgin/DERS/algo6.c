#include <stdio.h>
#define dim 25
//matris carpimi

int main(void){
	int i,j,k;
	int n,m,l;
	int tmp;
	
	int a[dim][dim],b[dim][dim],c[dim][dim];
	
	printf("please enter # of rows for mat A:");
	scanf("%d",&n);
	
	printf("please enter # of columns for mat A:");
	scanf("%d",&m);
	
	printf("please enter # of column for mat B:");
	scanf("%d",&l);
	
	//reading first matrix.
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	//reading second matrix
	
	for(i=0;i<m;i++){
		for(j=0;j<l;j++){
			printf("b[%d][%d]:",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	//performing matrix multiplication
	for(i=0;i<n;i++){
		for(k=0;k<l;k++){
			tmp=0;
			for(j=0;j<m;j++){
				tmp +=a[i][j]*b[j][k];
			}
			c[i][k]=tmp;
		}
	}
	//print matrix
	
	printf("resulting matrix-----------\n");
	for(i=0;i<n;i++){
		for(j=0;j<l;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//anlasýldý
//denendi ve compile edildi
