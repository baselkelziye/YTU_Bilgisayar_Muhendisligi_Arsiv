#include<stdio.h>


	
	void randomMatris( int matris[3][3] ){
		
		srand(time(0));
		
		int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				matris[i][j]=rand()%10;
			}
		
			printf("\n");
		}
	}
	
	void yazdir( int matris[3][3] ){
		
	int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%d",matris[i][j]);
			
			}
			printf("\t");
			printf("\n");
			
			
		}
		
		
	}
	
int det(int matris[3][3], int n)
{
    int c, i, j, k, l;
    int s=1, sum=0, matris2[3][3];

    if(n == 1){
        return(matris[0][0]);
    }
    else{
        sum = 0;

        for(c=0; c<n; c++){
            k = 0;
            l = 0;

            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    matris2[i][j] = 0;

                    if(i!=0 && j!=c){
                        matris2[k][l] = matris[i][j];

                        if(l==n-2){
                            l = 0;
                            k++;
                        }
                        else{
                            l++;
                        }
                      }
                   }
            }

            sum = sum + s * (matris[0][c] * det(matris2, n-1));
            s = -1 * s;
        }
    }

    return sum;
}




	





int main(){
	
	int matris[3][3];
	int determinant,n=3;

	randomMatris(matris);
	yazdir(matris);
	

	determinant=det(matris,n);
	printf("determinant: %d",determinant);
	
	return 0;
}
