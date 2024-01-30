// sepetlerin ve iclerindeki urunlerin verildigi bir durumda, urun ikililerinin
// birlikte kacar kaz satildiklarini (ayni sepet icinde bulunduklarini bulur
// S matrisi (satisN,2), her satirinda, sepetid, urunid var. sepetid numarali sepette, urunid numarali urun var.
// A matrisi (urunN,sepetN), S matsiniden uretilir, her bir urunun hangi sepetlerde oldugunu tutar
// T matrisi (urunN,urunN), A matrisinde uretilir, urunlerin birlikte kacar kez satildiklarini tutar

#include <stdio.h>
#include <conio.h>
#define satisN 15
#define urunN 5
#define sepetN 6
int main()
{
    int S[satisN][2]={{0,0},{0,2},{0,3},{1,1},{1,2},{2,0},{2,1},{3,1},{3,2},{3,3},{4,3},{4,4},{5,1},{5,2},{5,3}};
    int A[urunN][sepetN]={0};
    int T[urunN][urunN]={0};
    int i,j,k,max,maxi,maxj;
    for (i=0;i<satisN;i++)
     A[S[i][1]][S[i][0]]=1;

    printf("A matrisi:\n");    
    for (i=0;i<urunN;i++)
    {for (j=0;j<sepetN;j++)
     printf("%d ",A[i][j]);
     printf("\n");
     }
 
    for (i=0;i<urunN-1;i++)
     for (j=i+1;j<urunN;j++)
      for (k=0;k<sepetN;k++)
       if ((A[i][k]==1) && (A[j][k]==1))
        T[i][j]++; 

    printf("T matrisi:\n");
    max=0;    
    for (i=0;i<urunN;i++)
     {
      for (j=0;j<urunN;j++)
      {printf("%d ",T[i][j]);
       if (max<T[i][j])
        {max=T[i][j];
         maxi=i;
         maxj=j;
        }
       }
      printf("\n");
     }
    printf("en cok birlikte satilan urunler: %d %d",maxi,maxj);
    
    getch();
    return 0;
}
