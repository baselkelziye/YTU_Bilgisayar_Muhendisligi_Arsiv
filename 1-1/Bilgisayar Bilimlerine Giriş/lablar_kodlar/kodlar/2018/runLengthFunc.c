#include <stdio.h>
#include <stdlib.h>
void diziYap(int **,int *,int,int,int);
int runLength(int *,int*,int);

int main()
{
    int** mat, *dizi, *code,*codeNew,i,j,k,en,boy;
    printf("matrisin satir ve sutun sayisini veriniz\n"); scanf("%d %d",&boy, &en);
    mat = (int **) calloc (boy, sizeof(int *));
    for(i=0;i<boy;i++)
    	mat[i] = (int *) calloc (en, sizeof(int));
    
    printf("matrisin elemanlarini veriniz\n");
    for(i=0;i<boy;i++)
    	for(j=0;j<en;j++)        
           		scanf("%d",&mat[i][j]);        
    dizi = (int *) calloc (en*boy, sizeof(int));
    code = (int *) calloc (en*boy*2, sizeof(int));
    diziYap(mat,dizi,en,boy,sizeof(mat[0])/sizeof(mat[0][0]));
    printf("matrisin dizi hali:\n");
    for (i=0;i<en*boy;i++)
    	printf("%d ",dizi[i]);
    printf("\nkodlanmis dizi:\n");
    	k=runLength(dizi,code,en*boy);
    codeNew = realloc(code, k *sizeof(int) ); 
    for (i=0;i<k;i++)
    	printf("%d ",codeNew[i]);
    printf("\nsikistirma orani:%f",(float)k/(en*boy));
    for (i=0; i<boy; i++)
   	free(mat[i]);
    free(mat);
    free(dizi);
    free(code);
    scanf("%d",&i);
return 0;    
}


int runLength(int *dizi,int *code,int boyut)
{
    int i=0,j=0,k=0,length=0,run;
    while (i<boyut)
    {
          run=dizi[i];
          length=0;
          while ((i<boyut) && (dizi[i]==run))
          {
                i++;
                length++;
          }
          code[k]=length;
          code[k+1]=run;
          k=k+2;
    }
    return k;
}

void diziYap(int **mat,int *dizi,int en,int boy, int boyut)
{
     int i=0,j=0,k=0;
     printf("boyut: %d\n",boyut);
     for (i=0;i<boy;i++)
     {
         if ((i%2)==0 )
            for (j=0;j<en;j++)
            {
                dizi[k]=mat[i][j];  
                k++;
            }
         else
             for (j=en-1;j>=0;j--)
            {
                dizi[k]=mat[i][j];  
                k++;
            }         
     }     
}



