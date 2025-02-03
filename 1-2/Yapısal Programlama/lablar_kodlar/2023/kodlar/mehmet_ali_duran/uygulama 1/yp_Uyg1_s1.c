//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CHAR 100

int indexOfV1(char *ptr1, char *ptr2);

int main () {

    char str1[MAX_CHAR], str2[MAX_CHAR];
    printf("Enter the 1st string (Max. %d characters): ", MAX_CHAR);
    scanf("%s",str1);
    printf("Enter the 2nd string (Max. %d characters): ", MAX_CHAR);
    scanf("%s",str2);
    printf("Found at: %d", indexOfV1(str1,str2));

    return 0;


}
int indexOfV1( char *ptr1, char *ptr2 ){
    	int i, matchCount = 0;
    	int len1 = strlen(ptr1), len2 = strlen(ptr2);
    	for( i=0; i<=len1-len2; i++ ) {
    		printf("%c  %c,", *ptr1, *ptr2);
        	while( *ptr1 == *ptr2 && matchCount != len2 ) {
		    	matchCount++; ptr1++; ptr2++;
	        }
	        
		    if( matchCount == len2 ) return i;
		   	else {
				ptr1 -= (matchCount-1);
				ptr2 -= matchCount; matchCount = 0;
		    }
    }
    return -1;
}

//verisyon2 strstr fonksiyonunu kullanıyor. strstr fonksiyonu aranan aranan string ana string içerinde varsa bulunduğu indisi döndürüyor. 
int indexOfV2( char *ptr1, char *ptr2) {
    char *ptr;
    ptr = strstr(ptr1, ptr2);
    if( ptr != NULL )   return ptr-ptr1;
    else                return -1;
}


  

