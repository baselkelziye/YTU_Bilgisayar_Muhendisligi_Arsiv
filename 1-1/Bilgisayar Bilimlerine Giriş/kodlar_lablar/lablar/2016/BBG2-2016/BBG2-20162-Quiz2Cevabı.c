#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>

int main()
{
   int N;
   int i,j;
   
   printf("matris satÄ±r boyutunu giriniz\n");
   scanf("%d",&N);
   
   int B[N*N];
   int C[N*N];
   int D[N*N];
   int matris[N][N];  
   
   ////////////////////////////////////
   /////////////////1.soru/////////////N*N boyutunda random M matrisi oluşturunuz (1-10 arası sayılarla doldurunuz) ve matrisi yazdırınız.
   ////////////////////////////////////
   printf("\n");
   printf("\n");
   srand(time(NULL));
   for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            matris[i][j] = (rand() % 10) + 1;
            
   printf("random matris\n");
   for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ",matris[i][j]);
        }
        printf("\n");
    }
    
    ////////////////////////////////////
    /////////////////2.soru/////////////M matrisi üzerinde satır satır gezerek sırasıyla değerleri A dizisine kaydedin, A’yi yazdırın
    ////////////////////////////////////
    printf("\n");
    printf("\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            B[(i*N)+j] = matris[i][j]; 
    
    printf("B dizisi\n");
    for(i = 0; i < N*N; i++)
        printf("%d ",B[i]);
    
    ////////////////////////////////////
    /////////////////3.soru/////////////M matrisi üzerinde sütun sütun gezerek sırasıyla değerleri B dizisine kaydedin, B’yi yazdırın
    ////////////////////////////////////
    printf("\n");
    printf("\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            C[(j*N)+i] = matris[i][j]; 
    
    printf("C dizisi\n");
    for(i = 0; i < N*N; i++)
        printf("%d ",C[i]);
    
    ////////////////////////////////////
    /////////////////4.soru/////////////M matrisi üzerinde zigzag gezerek sırasıyla değerleri C dizisine kaydedin, C’yi yazdırın
    ////////////////////////////////////
    printf("\n");
    printf("\n");
    int istart=0,jstart=0, Dindis=0;
    while(istart<N && jstart<N)
    {
        for(i=istart,j=jstart; i>=0 && j<N; --i,++j)
        {
            D[Dindis] = matris[i][j];
            Dindis++;
        }
        if(j>=N)
        {
            istart=i+2;
            jstart=j-1;
        }
        else
        {
        istart=i+1;
        jstart=j;
        }
        for(i=istart,j=jstart;i<N && j>=0 ;++i,--j)
        {
            D[Dindis] = matris[i][j]; //printf("%d ",matris[i][j]);
            Dindis++;
        }
        if(i>=N)
        {
            istart=i-1;
            jstart=j+2;
        }
        else
        {
            istart=i;
            jstart=j+1;
        }
    }
      
    printf("D dizisi\n");
    for(i = 0; i < N*N; i++)
        printf("%d ",D[i]);
    
   ////////////////////////////////////Verilen iki dizi arasındaki karesel hatayı rekürsif bulan KARESEL_HATA(…) fonksiyonunu yazınız.
   /////////////////5.soru/////////////Fonksiyon integer hata değerini döndürecektir. KARESEL_HATA(A,B), KARESEL_HATA(A,C),
   ////////////////////////////////////KARESEL_HATA(B,C) değerlerini yazdırınız.
   printf("\n");
   printf("\n");
   printf("karesel fark B-C\n");
   printf("%d\n", KARESEL_HATA(B,C,N*N -1));
   printf("karesel fark C-D\n");
   printf("%d\n", KARESEL_HATA(C,D,N*N -1));
   printf("karesel fark B-D\n");
   printf("%d\n", KARESEL_HATA(B,D,N*N -1));
    
    return 0;
}//main

int KARESEL_HATA(int A[], int B[], int i){
   int result;
   result = pow(A[i]-B[i],2);
   if (i == 0)
       return result;
   else
       return result + KARESEL_HATA(A, B, i-1);
}










