#include <stdio.h>
#include <stdlib.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta3_codes
cc -o test hafta3_5_alloc.c 
*/

int main() {
	int n;	int *list;	printf("How many numbers are you going to enter ?");	scanf("%d", &n);	list = (int *) malloc( n * sizeof(int) );
	// list = (int *) calloc( n, sizeof(int) );
	if(list==NULL)  {
		printf("Can not allocate memory for the array...\n");
		return -1;
	}	
	
	
	printf("Enter the elements of your array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &list[i]);

	// int *list2; list2 = (int *) realloc( list, (n+1) * sizeof(int) );
	list = (int *) realloc( list, (n+1) * sizeof(int) );
	
	printf("These are the elements of the array:\n");
	for(int i=0; i<n+1; i++)
		printf("%d\t", list[i]);
	printf("\n");
	
	return 0;
}
