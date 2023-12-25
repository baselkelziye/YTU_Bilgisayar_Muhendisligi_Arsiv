// 1_DimMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

void matrisYaz (double *XX ,int m, int n){
	printf("\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("(%d,%d):%5.1f   ",i+1,j+1,XX[i*m+j]);
			/*ch=getchar();*/
		}
		printf("\n");
	}
	printf("\n");
}

void matrisTopla(double *AA, double *BB, double *CC, int m ,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			CC[i*m+j]=AA[i*m+j]+BB[i*m+j];
		}
	}

}

// m x l boyutlu AA matrisi ile l x n boyutlu BB matrisinin çarpýmýný
// m x n boyutlu CC matrisine atar
void matrisCarp(double *AA, double *BB, double *CC, int m ,int n,int l){
	int i,j,k;
	// CC matrisinin tüm elemanlarýný sýfýrlar
	printf ("Matrix Multiplication\n");
	for (i=0;i<m*n;i++){
		CC[i]=0;
	}
	// Çarpma iþlemi
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			for (k=0;k<l;k++){
				CC[i*m+j]=CC[i*m+j]+AA[i*m+k]*BB[k*m+j];
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	double C[16];
	double A[16]={1,-2,1,2,2,2,4,7,3,2,-5,4,1,-1,5,-3};
	double B[16]={1,2,3,4,5,6,9,8,9,1,11,12,13,14,15,5};
	printf("\tA");
	matrisYaz(A,4,4);
	printf("\tB");
	matrisYaz(B,4,4);
	matrisTopla(A,B,C,4,4);
	printf("Matrislerin toplami\n\tC");
	matrisYaz(C,4,4);
	matrisCarp(A,B,C,4,4,4);
	printf("Matrislerin Carpimi\n\tC");
	matrisYaz(C,4,4);

	return 0;
}

