//backtracking
//Ali Bugday
//date created:29.12.2022
//date modified: 03.01.2023  
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void read_matrix(int, int **);
void print_matrix(int, int **);
void slide_row(int N, int satir, int **matris);
int ust_satirlar_kontrol(int n, int satir, int **matris);
void backtrack(int n, int **matrix, int satir, int mod);

int main() {
	int i, j, n, mod=0;
	
	do{
		printf("N sayisini griniz:");
		scanf("%d",&n);
	}while(n<3 || n>8);
	
	printf("normal mod için 0 detay mod icin 1 giriniz:");
	scanf("%d",&mod);
	
	
	int **matris=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		matris[i]=(int*)malloc(n*sizeof(int));
	}
	/*
	matris[0][0]=1;
	matris[0][1]=2;
	matris[0][2]=3;
	matris[0][3]=4;
	matris[0][4]=5;
	
	matris[1][0]=5;
	matris[1][1]=1;
	matris[1][2]=2;
	matris[1][3]=3;
	matris[1][4]=4;
	
	matris[2][0]=4;
	matris[2][1]=5;
	matris[2][2]=1;
	matris[2][3]=2;
	matris[2][4]=3;
	
	
	matris[3][1]=4;
	matris[3][1]=5;
	matris[3][2]=1;
	matris[3][3]=2;
	matris[3][4]=3;
	
	matris[4][0]=2;
	matris[4][1]=3;
	matris[4][2]=4;
	matris[4][3]=5;
	matris[4][4]=1;*/
	read_matrix(n, matris);
	//slide_row(n, 0, matris);
	//print_matrix(n, matris);
	//int sonuc=ust_satirlar_kontrol(n,1,matris);
	//printf("%d",sonuc);
	backtrack(n, matris, 0, mod);
	
	for (i = 0; i < n; i++) {
	    free(matris[i]);
	}
	free(matris);	
	return 0;
}


void read_matrix(int n, int **graph)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d satir %d stun numaralý degeri giriniz:",i,j);
			scanf("%d",&graph[i][j]);
		}
	}
	
}

void print_matrix(int n, int **matris)
{
	int i, j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d-",matris[i][j]);
		}
		printf("\n");
	}
}

void slide_row(int n, int satir, int **matris)
{
	int temp[n],i;
    
    for (i = 0; i < n; i++) {
        temp[(i + 1) % n] = matris[satir][i];
        //printf("%d",temp[(i + 1) % n]);
    }

    for (i = 0; i < n; i++) {
        matris[satir][i] = temp[i];
    }
}


int ust_satirlar_kontrol(int n, int satir, int **matris)
{
	int i, j, flag=0;
	
	for(i=satir-1;i>=0;i--){
		for(j=0;j<n;j++)
		{
			if(matris[satir][j]==matris[i][j])
			{
				flag=1;
			}		
		}
	}
	if(flag)
	{
		return 1;		
	}
	else{
		return 0;
	}
}

int alt_satirlar_kontrol(int n, int satir, int **matris)
{
	int i, j, flag=0;
	
	for(i=1;i<n;i++){
		for(j=0;j<n;j++)
		{
			if(matris[satir][j]==matris[i][j])
			{
				flag=1;
			}		
		}
	}
	if(flag)
	{
		return 1;		
	}
	else{
		return 0;
	}
}


void backtrack(int n, int **matrix, int row, int mod)
{
	int shift;
	
	
	if (row == n) {
        printf("basarili, son hal:\n");
        print_matrix(n, matrix);
        printf("\n");
        exit(0);
    }
	

    for (shift = 0; shift < n; shift++) {
        
        if(mod == 1)
        {	
        	printf("-------------------\n");
        	print_matrix(n, matrix);
			printf("-------------------\n");
		}
        slide_row(n, row, matrix);
        
        
        if (ust_satirlar_kontrol(n, row, matrix)==0) {
            backtrack(n, matrix, row + 1, mod);
        }
    }
    
    if(row == 0)
    {
    	printf("basarisiz");
	}
}
