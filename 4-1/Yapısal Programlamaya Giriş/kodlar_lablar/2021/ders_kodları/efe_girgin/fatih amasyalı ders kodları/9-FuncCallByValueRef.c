// FUNCTIONS CALL BY VALUE AND REFERENCE
#include <stdio.h>
int topla (int,int);
void swap(int*,int*);
void carpv1 (int,int,int *);
int kareAl(int);

int main()
{

  int i=2, j=4;
  int sonuc;
  printf("yer degistirmeden once i ve j: %d %d\n", i, j);
  swap(&i, &j); /* pass the addresses of i and j */
  printf("yer degistirmeden sonra i ve j: %d %d\n", i, j);
 
  carpv1(i,j,&sonuc);
  printf("carpimv1 sonucu: %d\n",sonuc);

  sonuc=topla(i,j);
  printf("toplam sonucu: %d\n",sonuc);
  
  printf("%d'nin karesi: %d\n",i,kareAl(i));
}

int topla(int i, int j)  // call by value - return value
{
	return i+j;
}

void swap(int *x, int *y) // call by reference
{
  int temp;

  temp = *x;  /* save the value at address x */
  *x = *y;    /* put y into x */
  *y = temp;  /* put x into y */
}

int kareAl(int i)
{
	int kuvvet;
	carpv1(i,i,&kuvvet);
	return kuvvet;
}

void carpv1 (int sayi1,int sayi2,int *carpim) // call by value
{
	*carpim=sayi1*sayi2;
}

