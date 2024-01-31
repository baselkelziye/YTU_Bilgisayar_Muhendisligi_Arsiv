#include <stdio.h>
#include <stdlib.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta4_codes
cc -o test hafta4_1_eg_bubble.c 
*/

// A function to implement bubble sort void bubbleSort(int *ptr, int n) {    int i, j, temp;    for (i = 0; i < n-1; i++)                // Last i elements are already in place           for (j = 0; j < n-i-1; j++)             if (ptr[j] > ptr[j+1]) {              temp=ptr[j];              ptr[j]= ptr[j+1];               ptr[j+1]=temp;           } }
int main() {
	int n;	int *list;	printf("How many numbers are you going to enter ?");	scanf("%d", &n);	list = (int *) malloc( n * sizeof(int) );
	if(list==NULL)  {
		printf("Can not allocate memory for the array...\n");
		return -1;
	}	
	
	printf("Enter the elements of your array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &list[i]);

	bubbleSort(list, n);	
	printf("This is the sorted array:\n");
	for(int i=0; i<n; i++)
		printf("%d\t", list[i]);
	printf("\n");	

	return 0;
}
