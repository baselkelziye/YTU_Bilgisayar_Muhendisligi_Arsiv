		/* This program selection sorts an array's values into descending order */
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
		   int j; 
		   int i; 
		   int hold; /* temporary location used to swap array elements */
		   int max;
		   int ith;
		   
		   srand( time( NULL ) ); /* seed random-number generator */
		   
		   printf( "Data items in original order\n" );
		   
		   /* generate and print a array */
		   for ( i = 0; i < SIZE; i++ ) {
		      a[i]= 1 + rand() % 100;
   		      printf( "%4d", a[ i ] );
		   } /* end for */  
		   
		   /* selection sort */                                         
           /* for each indis, find max element of subarray [i,end] then place the i.th place*/
		   for ( i = 0; i < SIZE; i++ ) {                   
              max=a[ i ];
              ith=i;
		      for ( j = i+1; j < SIZE; j++ ) {                     
		         /* find max element */
           	         if ( a[ j ] > max ) {
		                      max=a[ j ];
		                      ith=j; 
                     } /* end if */
		      } /* end inner for */                                  
              /* place the i.th place */		                                                             
              hold = a[ i ];                                   
              a[ i ] = a[ith];                             
              a[ith] = hold; 
		   } /* end outer for */                                     
		
		   printf( "\nData items in descending order\n" );
		
		   /* output sorted array */
		   for ( i = 0; i < SIZE; i++ ) {
		      printf( "%4d", a[ i ] );
		   } /* end for */
		
		   printf( "\n" );
     	   getch();
		   return 0; /* indicates successful termination */
		}
