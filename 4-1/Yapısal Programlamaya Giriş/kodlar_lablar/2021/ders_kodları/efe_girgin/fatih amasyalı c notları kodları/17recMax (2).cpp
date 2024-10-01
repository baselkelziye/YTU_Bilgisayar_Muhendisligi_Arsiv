#include <stdio.h>
#include <conio.h>
	
int findMax(int array[], int size, int index)
{
  if (index == size - 1) return array[index];
  int result = findMax(array, size, index + 1);
  if (array[index] > result) 
    return array[index];
  else
    return result;
}

int main(int argc, char* argv[])
{
 int a[5]={1,14,6,2,5};
 printf("dizinin en buyugu=%d",findMax(a,5,0));
 getch();
 return 0;
}
