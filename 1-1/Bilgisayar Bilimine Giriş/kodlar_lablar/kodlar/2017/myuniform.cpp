		/* Roll a size-sided die 100 times using my random*/
		/* R(n)=(a*R(n-1) +c) mod m  R(0)=0 a=1366 c=150889 m=714025 */
		#include <stdio.h>
		#include <conio.h>
		#define SIZE 8
		
		/* function main begins program execution */
		int main( void )
		{
		   int face; /* random die value 1 - SIZE-1 */
		   int roll; /* roll counter 1-100 */
		   int frequency[ SIZE ] = { 0 }; /* clear counts */    
		   int a=1366;
		   int c=150889;
		   int m=714025;
		
		   /* roll die 100 times */
		   face=0; /* seed */
		   for ( roll = 1; roll <= 100; roll++ ) {
		      face = ((a * face + c ) % (SIZE-1));
		      ++frequency[ face +1]; 
		   } /* end for */                          
		
		   printf( "%s%17s\n", "Face", "Frequency" );
		
		   /* output frequency elements 1-6 in tabular format */
		   for ( face = 1; face < SIZE; face++ ) {
		      printf( "%4d%17d\n", face, frequency[ face ] );
		   } /* end for */
           getch();		
		   return 0; /* indicates successful termination */
		
		} /* end main */
