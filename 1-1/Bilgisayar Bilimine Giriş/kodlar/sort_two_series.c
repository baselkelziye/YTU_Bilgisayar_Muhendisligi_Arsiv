/******************************************************************************

author:Zatona;
finish_date:12/12/2020;
finish_time:17:40;
subject:sort the elements of two series in new serie;


*******************************************************************************/
#include <stdio.h>
#define SIZE 100

int
main ()
{
    int n, A[SIZE], m, B[SIZE], i = 0, j = 0, x = 0;

    printf ("enter the number of elements for first serie: ");
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter %d.elenmet of first serie: ",i+1);
        scanf ("%d", &A[i]);
    }
    printf ("enter the number of elements for second serie: ");
    scanf ("%d", &m);
    
    for(i=0;i<m;i++){
        printf("enter %d.elenmet for second serie: ",i+1);
        scanf("%d",&B[i]);
    }

    int k = m + n;
    int C[SIZE];
    i=0;
    while (i < n || j < m)
    {
        if (A[i] < B[j]){
	        C[x] = A[i];
	        i += 1;
    	}
        else{
	        C[x] = B[j];
	        j += 1;
	    }
        x += 1;
    }
    
    printf("---------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < k; i++)
    {
      printf ("%d\t", C[i]);
    }

  return 0;
}

