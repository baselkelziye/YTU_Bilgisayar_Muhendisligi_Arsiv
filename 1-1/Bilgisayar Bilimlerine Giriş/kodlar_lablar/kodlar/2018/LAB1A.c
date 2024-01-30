#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main()
{
    int n,m,A[20],B[20],C[20],i,j,k,maxEleman,islemSayisi,islem;
    srand(time(NULL));
    printf("Birinci dizinin eleman sayisini giriniz(max 20): \n");
    scanf("%d",&n);
    printf("Ikinci dizinin eleman sayisini giriniz(max 20): \n");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        printf("Birinci dizinin %d. elemanini giriniz: \n",(i+1));
        scanf("%d",&A[i]);
    }
    for(i=0;i<m;i++)
    {
        printf("Ikinci dizinin %d. elemanini giriniz: \n",(i+1));
        scanf("%d",&B[i]);
    }
    printf("Birinci dizi: ");
    for(i=0;i<n;i++)
        printf("  %d  ",A[i]);
    printf("\n");
    printf("Ikinci dizi: ");
    for(i=0;i<m;i++)
        printf("  %d  ",B[i]);
    printf("\n");
    if(n>m)
        maxEleman=n;
    else
        maxEleman=m;
    islemSayisi=0;
    k=0;
    while(maxEleman>islemSayisi)
    {
        i=rand()%n;
        j=rand()%m;
        islem=islemSayisi%4;
        switch(islem)
        {
            case 0:
                C[k]=A[i] + B[j];
                printf("%d + %d = %d \n",A[i],B[j],C[k]);
            break;
            case 1:
                C[k]=A[i] - B[j];
                printf("%d - %d = %d \n",A[i],B[j],C[k]);
            break;
            case 2:
                C[k]=A[i] * B[j];
                printf("%d * %d = %d \n",A[i],B[j],C[k]);
            break;
            case 3:
                C[k]=A[i] / B[j];
                printf("%d / %d = %d \n",A[i],B[j],C[k]);
            break;
        }
        islemSayisi++;
        k++;
    }
    printf("Yeni dizi: ");
    for(k=0;k<maxEleman;k++)
        printf(" %d ",C[k]);
    return 0;
}
