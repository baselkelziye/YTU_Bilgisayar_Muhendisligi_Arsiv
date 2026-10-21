/****************************************************************************
 * main.c                                                                   *
 * Modified in 07 April 2014                                                *
 * Written by Mustafa Berkay Mutlu                                          *
 * http://www.berkaymutlu.com/                                              *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION: This program was written to find the median in an array.    *
 * In order to sort the elements of the array, this program uses the        *
 * same algorithm with Quick Sort. In order to choose the median, it uses   *
 * both first "element in array" and "median of three" ways (depends on     *
 * your code, you should pick PivotChoose or PivotChoose2).                 *
 *                                                                          *
 ****************************************************************************/


#include <stdio.h>
#include <stdlib.h>


void FindMedian(int [], int, int,int);
int PivotChoose(int [], int, int);
int PivotChoose2(int [], int, int);
void Swap(int *, int *);

int main()
{
    int *dizi;
    int elemanSayisi;
    int i,j;
    int temp;
    int pivot;

    printf("Diziniz kac elemanli olacak> ");
    scanf("%d",&elemanSayisi);

    dizi = (int *) malloc (elemanSayisi * sizeof(int));

    for(i=0;i<elemanSayisi;i++){
        printf("%d. elemani giriniz> ",i+1);
        scanf("%d",&dizi[i]);
    }


    FindMedian(dizi,0,elemanSayisi-1,elemanSayisi);

    for(i=0;i<elemanSayisi;i++)
        printf("%d ",dizi[i]);


    getch();
    free(dizi);
    return 0;
}


void FindMedian(int dizi[], int l, int r,int elemanSayisi){

    int pivotAddress;
    int i = l;
    int j = r;

    if(l < r){
        pivotAddress = PivotChoose2(dizi,l,r);

        do{

            while((i < r) && (dizi[i] <= dizi[pivotAddress])) i++;
            while((j > l) && (dizi[j] > dizi[pivotAddress])) j--;
            Swap(&dizi[i],&dizi[j]);

        }while(i < j);

        Swap(&dizi[i],&dizi[j]);
        Swap(&dizi[pivotAddress],&dizi[j]);
        pivotAddress = j;

        if(pivotAddress == elemanSayisi/2 - 1){
            printf("\n\n");
            printf("Medyan: %d \n", dizi[pivotAddress] );
            printf("Medyan adresi: %d\n", pivotAddress);
        }
        else if(pivotAddress > elemanSayisi/2 - 1){
            FindMedian(dizi,l,pivotAddress-1,elemanSayisi);
        }
        else if(pivotAddress < elemanSayisi/2 - 1){
            FindMedian(dizi,pivotAddress+1,r,elemanSayisi);
        }

    }


}


int PivotChoose(int dizi[], int l, int r){
    return l;
}


int PivotChoose2(int dizi[],int l, int r){
    int m = (l + r)/2;
    int i;
    int count[3];

    // Linear Sort with Counting (Count Sort):

    // Baslangic degerleri ataniyor.
    for(i=0;i<3;i++)
        count[i] = -1;


    if(dizi[l]<dizi[m])
        count[1]++;
    else
        count[0]++;

    if(dizi[l]<dizi[r])
        count[2]++;
    else
        count[0]++;

    if(dizi[m]<dizi[r])
        count[2]++;
    else
        count[1]++;



    if(count[0] == 2)
        return l;
    else if(count[1] == 2)
        return m;
    else
        return r;



}


void Swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

