#include <stdio.h>
#include <stdlib.h>
//*******************************************************************FREKANS OY SEÇÝM***************************************************************




int main( ){
int N;printf("dizi boyut : ");scanf("%d",&N);
int A, oylama, F[ 11 ] = { 0 };
int A[ 40 ] =
 { 1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
 1, 6, 3, 8, 6, 10, 3, 8, 2, 7,
 6, 5, 7, 6, 8, 6, 7, 5, 6, 6,
 5, 6, 7, 5, 6, 4, 8, 6, 8, 10 };

 for(int i = 0;i<=40 - 1;i++ )
 F[ A [i] ]++;

 printf( "%s%17s\n", "Oylama", "Frekans" );

 for ( oylama = 1; oylama<= 11 - 1; oylama++ )
 printf( "%6d%17d\n", oylama,F[ oylama] );

 return 0;
 }
