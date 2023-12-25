// this program prints the addresses of the array elements
#include <stdio.h>
int main()
{
	int i,n=5;
	int *ptr;
	int student[5]; 
	printf("give 5 integer numbers\n");
	for (i=0;i<n;i++)	
		scanf("%d",&student[i]);
	
	//Dizi elemanları memory'de ardarda bulunur
	for (i=0;i<n;i++)	
	{
		printf("the value of the element:%d the address of the element:%p\n",student[i],&student[i]);
	}
	ptr=student; // ptr=&student[0];
	printf("the address of the first element:%p\n",ptr);
	printf("the address of the pointer ptr  :%p\n",&ptr);
	
	//Dizi elemanlarına pointer uzerinden erismek icin
	for (i=0;i<n;i++)	
	{
		printf("the value of the element:%d the address of the element:%p\n",*(ptr+i),ptr+i);
	}
	return 0;
}
