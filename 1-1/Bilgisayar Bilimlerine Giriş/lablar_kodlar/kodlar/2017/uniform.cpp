		/* Roll a six-sided die 6000 times */
		//#include <stdio.h>
		#include <stdlib.h>
		#include <time.h> 
		#include <conio.h>
		#define SIZE 7
		
		/* function main begins program execution */
		int main( void )
		{
		   int face; /* random die value 1 - 6 */
		   int roll; /* roll counter 1-6000 */
		   int frequency[ SIZE ] = { 0 }; /* clear counts */    
		
		   srand( time( NULL ) ); /* seed random-number generator */
		
		   /* roll die 6000 times */
		   for ( roll = 1; roll <= 6000; roll++ ) {
		      face = 1 + rand() % 6;
		      ++frequency[ face ]; /* replaces 26-line switch of Fig. 5.8 */
		   } /* end for */                          
		
		   printf( "%s%17s\n", "Face", "Frequency" );
		
		   /* output frequency elements 1-6 in tabular format */
		   for ( face = 1; face < SIZE; face++ ) {
		      printf( "%4d%17d\n", face, frequency[ face ] );
		   } /* end for */
           getch();		
		   return 0; /* indicates successful termination */
		
		} /* end main */
