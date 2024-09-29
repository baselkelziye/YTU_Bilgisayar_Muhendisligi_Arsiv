		/* This program bubble sorts an array's values into ascending order */
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
		   int pass; /* passes counter */
		   int i;    /* comparisons counter */
		   int hold; /* temporary location used to swap array elements */
		   
		   srand( time( NULL ) ); /* seed random-number generator */
		   
		   printf( "Data items in original order\n" );
		   
		   /* generate and print a array */
		   for ( i = 0; i < SIZE; i++ ) {
		      a[i]= 1 + rand() % 100;
   		      printf( "%4d", a[ i ] );
		   } /* end for */  
		
		   /* bubble sort */                                         
		   /* loop to control number of passes */ 
           int K=SIZE-1;                   
		   for ( pass = 1; pass < SIZE; pass++ ) {                   
		                                                             
		      /* loop to control number of comparisons per pass */   
		      for ( i = 0; i < K; i++ ) {                     
		                                                             
		         /* compare adjacent elements and swap them if first              
	             element is greater than second element */           
	             if ( a[ i ] > a[ i + 1 ] ) {
		            hold = a[ i ];                                   
		            a[ i ] = a[ i + 1 ];                             
		            a[ i + 1 ] = hold;                               
		         } /* end if */                                      
                                                               
		      } /* end inner for */  
              K--;                                
	   	      /* output pass.th result */
	   	      printf( "\n%d.pass result\n",pass );
              for ( i = 0; i < SIZE; i++ ) {
	            printf( "%4d", a[ i ] );
	          } /* end for */

		                                                             
		   } /* end outer for */                                     
		
		   printf( "\nData items in ascending order\n" );
		
		   /* output sorted array */
		   for ( i = 0; i < SIZE; i++ ) {
		      printf( "%4d", a[ i ] );
		   } /* end for */
		
		   printf( "\n" );
     	   getch();
		   return 0; /* indicates successful termination */
		}
