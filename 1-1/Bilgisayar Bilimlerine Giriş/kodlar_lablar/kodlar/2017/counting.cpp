		/* This program linear sort with counting an array's values into descending order */
		#include <stdio.h>
    	#include <time.h>
		#include <stdlib.h>
    	#include <conio.h>
		#define SIZE 10
		
		/* function main begins program execution */
		int main( void ) 
		{   
		   /* initialize a */
		   int a[ SIZE ];
		   int aa[ SIZE ]; /* new array*/
		   int c[ SIZE ]={0}; /* stores counts */
		   int j; 
		   int i; 
		   
		   srand( time( NULL ) ); /* seed random-number generator */
		   
		   printf( "Data items in original order\n" );
		   
		   /* generate and print a array */
		   for ( i = 0; i < SIZE; i++ ) {
		      a[i]= 1 + rand() % 100;
   		      printf( "%4d", a[ i ] );
		   } /* end for */  
		   
		   /* linear sort with counting */                                         
           /* for each indis, find the number of element that bigger than ith element then place the i.th place*/
		   for ( i = 0; i < SIZE; i++ ) {                   
		      for ( j = i+1; j < SIZE; j++ ) {                     
		         /* find the number of element that bigger than ith element */
           	         if ( a[ i ] > a[ j ] ) 
		                      c[i]++;
		             else 
		                      c[j]++;
		      } /* end inner for */                                  

		   } /* end outer for */                                     
           
   		   /* print counts  */
   		   printf( "\n Counts: \n" );
		   for ( i = 0; i < SIZE; i++ ) {
   		      printf( "%4d", c[ i ] );
		   } /* end for */  

           /* place the elements */	           	                                                             
		   for ( i = 0; i < SIZE; i++ ) {                   
              aa[c[i]] = a[ i ];                                   
		   } /* end  for */                                                    
		   printf( "\nData items in ascending order\n" );
		
		   /* output sorted array */
		   for ( i = 0; i < SIZE; i++ ) {
		      printf( "%4d", aa[ i ] );
		   } /* end for */
		
		   printf( "\n" );
     	   getch();
		   return 0; /* indicates successful termination */
		}
