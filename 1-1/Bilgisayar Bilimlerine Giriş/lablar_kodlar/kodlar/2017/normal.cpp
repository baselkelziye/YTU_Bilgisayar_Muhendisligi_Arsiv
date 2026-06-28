		/* generate a gaussian like distribution */
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>
		#include <conio.h>
		#define SIZE 11
		
		/* function main begins program execution */
		int main( void )
		{
		   int s,s1,s2; 
		   int i; /* counter 1-1000 */
		   int frequency[ SIZE ] = { 0 }; /* clear counts */    
		
		   srand( time( NULL ) ); /* seed random-number generator */
		
		   /* generate a number 1000 times */
		   for ( i = 1; i <= 1000; i++ ) {
		      s1 = 1 + rand() % 10;
		      s2 = 1 + rand() % 10;
		      s=(s1+s2)/2;
		      ++frequency[ s ]; 
		   } /* end for */                          
		
		   printf( "%s%17s\n", "Number", "Frequency" );
		
		   /* output frequency elements 1-10 in tabular format */
		   for ( i = 1; i < SIZE; i++ ) {
		      printf( "%4d%17d\n", i, frequency[ i ] );
		   } /* end for */
           getch();		
		   return 0; /* indicates successful termination */
		
		} /* end main */
