#include <stdio.h>
#include <stdlib.h>

#define MAX 30

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int main()
{

    int arr[MAX], N, i;

    do
    {
        printf("Lutfen dizi boyutu giriniz (2-30) :   ");
        scanf("%d", &N);
    } while ((N < 2) || (N > 30));

    for (i = 0; i < N; i++)
    {
        printf("%d. elemani giriniz: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf(" %d  ", arr[i]);
    }

    printf("\n");

    int j,sayi1, sayi2, dist;

    
    mergeSort(arr, 0, N - 1);

    for (i = 0; i < N; i++)
    {
        printf(" %d  ", arr[i]);
    }

    printf("\n");

    i=0;
    j=N;

                    //Asagidaki while blogunda sirali diziyi iki taraftan sikistiriyoruz.
                    // En yakin cifti bulmak icin her seferinde basta ve sondaki ikililerden
                    // farki buyuk olan ikilinin bir ucunu eliyoruz ve indisi kaydiriyoruz.
    while(i<j-1){
        if(abs(arr[i+1]-arr[i]) < abs(arr[j]-arr[j-1]) ){
           j--;
        }
        else
        {
            i++;
        }
    }

    sayi1=arr[i];
    sayi2=arr[j];
    dist = abs(arr[i]-arr[j]);


    printf("en yakin sayilar: %d - %d    fark: %d", sayi1, sayi2, dist);

    return 0;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);         // en soldaki ikili indise kadar gidiyor
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);   // dizinin bolunmus en kucuk parcalari 
                                        // her cikista 2'li tekrar karsilastirilip birlestirilerek
                                        // son turda ana sirali diziyi olusturuyor
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;  // olusturulacak 1. gecici dizinin boyutu
    int n2 = right - mid;     // olusturulacak 2. gecici dizinin boyutu
    
    int L[n1], R[n2];   

    for (i = 0; i < n1; i++){
        L[i] = arr[left + i]; // sirasiz dizinin ilk yarisi L gecici dizisine atiliyor 
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j]; // sirasiz dizinin ikinci yarisi R gecici dizisine atiliyor 
    }


    i = 0;
    j = 0;
    k = left;       // birlesecek dizinin referans indisi k degerinde tutuluyor
    while (i < n1 && j < n2)    // iki gecici dizi elemanlari karsilastirilarak birlestiriliyor 
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) // ikinci gecici dizideki elemanlarin siralanmasi ilk kisimdan once bitmisse ilk dizideki
                    // kalan elemanlar sona ekleniyor
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)  //ikinci dizideki kalan elemanlar sona ekleniyor
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
