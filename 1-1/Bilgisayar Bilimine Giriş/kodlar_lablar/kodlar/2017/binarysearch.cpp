		/* This program binary search */
		#include <stdio.h>
    	#include <conio.h>
		#define SIZE 15

		int binarySearch( const int b[], int searchKey, int low, int high );		
	
    	/* function main begins program execution */
		int main( void ) 
		{   
		   /* initialize a */
		   int a[ SIZE ];
		   int key; /* value to locate in array a */
		   int result; /* variable to hold location of key or -1 */
		   int i; 

   		   printf( "input search key\n" );
   		   scanf("%d",&key);

		   printf( "Data items\n" );
		   /* generate and print a array */
		   for ( i = 0; i < SIZE; i++ ) {
		      a[i]= i*2;
   		      printf( "%4d", a[ i ] );
		   } /* end for */  
		   
           /* binary search */                                         
		   result = binarySearch( a, key, 0, SIZE - 1 );
		   
		   /* display results */
		   if ( result != -1 ) {
		      printf( "\n%d found in %d th indice\n", key, result );
		   } /* end if */
		   else {
		      printf( "\n%d not found\n", key );
		   } /* end else */
		
     	   getch();
		   return 0; /* indicates successful termination */
		}

		int binarySearch( const int b[], int searchKey, int low, int high )
		{
		   int middle; /* variable to hold middle element of array */

		   /* loop until low subscript is greater than high subscript */
		   while ( low <= high ) {
		
		      /* determine middle element of subarray being searched */
		      middle = ( low + high ) / 2;
		
		      /* if searchKey matched middle element, return middle */
		      if ( searchKey == b[ middle ] ) {                       
		         return middle;                                       
		      } /* end if */                                          
		
		      /* if searchKey less than middle element, set new high */
		      else if ( searchKey < b[ middle ] ) {                    
		         high = middle - 1; /* search low end of array */      
		      } /* end else if */                                      
		
		      /* if searchKey greater than middle element, set new low */
		      else {                                                     
		         low = middle + 1; /* search high end of array */        
		      } /* end else */                                           
		
		   } /* end while */
		
		   return -1;   /* searchKey not found */
		
		} /* end function binarySearch */
