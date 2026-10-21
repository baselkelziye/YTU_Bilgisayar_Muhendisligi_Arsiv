#include <stdio.h>
#include <stdlib.h>


void mark_cells(int**,int,int,int);


int main(){

	
    int **mat;
    int row,col,i,j,N;

    printf("Von Neumann Neighborhood matrisi icin bir N degeri giriniz:  ");
    scanf("%d",&N);

    row=2*N+1+2; // 1 tane merkez icin fazladan, 2'ser tane de cerceve icin
    col=row;

    mat= (int**) malloc(row*sizeof(int *));   
    if(mat==NULL){
        printf("Matris icin bellek ayrilamadi. \n");
    }
    
    for(i=0;i<row;i++){
        mat[i]=malloc(col*sizeof(int));  
        if(mat[i]==NULL){
        printf("Matris icin bellek ayrilamadi. \n");
        }
    }

    int center=N+1;         // fonksiyona gondermek icin merkez noktayı bilmemiz gerekiyor
                            // cunku von neumann komsulugunda merkeze gore kiyaslama yapacagiz.
    int siyah=0,beyaz=0;



    mark_cells(mat,N,center,row);

                                    //fonksiyonda isaretlenmis olan matris asagida yazdiriliyor
    for( i = 0; i < row; i++ ) {
		for( j = 0; j < col; j++ )
            if(mat[i][j]==1){
                siyah++;
                printf( "%d ", mat[i][j] );
            }
            else{
                beyaz++;
                printf( "  ");
            }

		printf( "\n" );
	}

    printf( "Siyah hucre sayisi: %d \nBeyaz hucre sayisi: %d", siyah,beyaz );
    

    for(i=0;i<row;i++){
        free(mat[i]);       //matris icin ayrilan alani serbest birakiyoruz
    }

    free(mat);              

    return 0;
}

void mark_cells(int **mat,int N, int center, int row){  //matrisin adresi, komsuluk sayisi N
                                                        // merkez indisi, satir ve sutun sayisi
  
    int i,j;
    for(i=0;i<row;i++){         //matrisin tum hucrelerini komsuluk kurali icin kontrol ediyoruz
        for(j=0;j<row;j++){
            if(abs(center-i)+abs(center-j) <=N){ // von neumann komsuluk sarti
                mat[i][j]=1;
            }
            else{
                mat[i][j]=0;
            }
        }
    }
}






