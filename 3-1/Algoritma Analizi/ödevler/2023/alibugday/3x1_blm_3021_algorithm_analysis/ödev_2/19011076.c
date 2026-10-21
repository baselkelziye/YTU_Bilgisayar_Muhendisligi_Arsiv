//this code used for finding largest block within an array that can contain negatif numbers
//M Ali Bugday
//date created: 5.11.2022
//date modified: 6.11.2022
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i, index_1,index_2, result; 
	
	int dizi[]={8, -1, -11, 10, 4,8, -30, 36, 2, -6, 52};
	int dizi_length = 11;
	
	//int dizi[]={-3, -4, 5, -3, -3, 2, 6, -6};
	//int dizi_length = 8;
	
	//int dizi[]={-5};
	//int dizi_length = 1;
	
		
	result = DiziBol(dizi, 0, dizi_length-1, &index_1, &index_2);
	printf("max:%d, baslangic:%d, bitis:%d",result, index_1, index_2);

	return 0;
}


int DiziBol(int dizi[], int l, int r, int *indis_1, int *indis_2)
{
	int i, j, m;
	if(l==r)
	{
		return dizi[l];	
	}
	else if(l>r)
	{
		return dizi[l];	
	}
	else
	{
		m = (l+r)/2;
		int i1, i2, i3, i4, i5, i6;
		
		int a = DiziBol(dizi, l, m-1, &i1, &i2); 	
		int b = DiziBol(dizi, m+1, r, &i3, &i4);
		int c = MaxOrtaBlock(dizi, l, m, r, &i5, &i6);
		
		//finding max(a,b,c)
		if (a>b){
			if(a>c){
				*indis_1=i1;
				*indis_2=i2;
				return a;
			}
			else{
				*indis_1=i5;
				*indis_2=i6;
				return c;
			}
		}
		else{
			if(b>c){
				*indis_1=i3;
				*indis_2=i4;
				return b;
			}
			else{
				*indis_1=i5;
				*indis_2=i6;
				return c;
			}
		}
	}
}
	



int MaxOrtaBlock(int dizi[], int l, int m, int r, int *i1, int *i2)
{
	int i, toplam, a, b, c, left = l, right = r;
	
	toplam = 0;
	int solMax = -1000;
	for(i=m;i>=l;i--)
	{
		toplam += dizi[i];
		if(toplam > solMax){
			solMax = toplam;
			left = i;
		}	
	}
	
	
	toplam = 0;
	int sagMax = -1000;
	for(i=m;i<=r;i++)
	{
		toplam += dizi[i];
		if(toplam > sagMax){
			sagMax = toplam;
			right = i;
		}	
	}
	
	
	a = solMax;
	b = sagMax;
	c = solMax + sagMax - dizi[m];
	
	
	//finding max(a, b, c)
	if (a>b){
		if(a>c){
			*i1=left;
			*i2=m;
			return a;
		}
		else{
			*i1=left;
			*i2=right;
			return c;
		}
	}
	else{
		if(b>c){
			*i1=m;
			*i2=right;
			return b;
		}
		else{
			*i1=left;
			*i2=right;
			return c;
		}
	}
} 

