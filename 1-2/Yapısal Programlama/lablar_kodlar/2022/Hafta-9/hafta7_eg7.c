/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test _hafta6_eg7.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h> // for the trigonometric functions

double * trig_generic(double * arr, int n, double (*fp)() ){
  int i; 
  double *ar2;
  ar2=(double*)malloc(n*sizeof(double));
  for(i=0; i<n; i++)
    ar2[i]=(*fp)(arr[i]);
  return ar2;
} 
int main ()  {  int i,n; 
  double *arr, *ar2;
  double (*fp)();
  
  printf("Enter the array size\n"); 
  scanf("%d", &n);
  arr=(double*)malloc(n*sizeof(double));
  printf("Enter the elements of the array\n"); 
  for(i=0; i<n; i++) 
    scanf("%lf", &arr[i]);

  printf("Enter the name of the trigonometric function, 0 for sinus; 1 for cosinus; 2 for tangent\n"); 
  scanf("%d", &i);

  if(i==0) fp=sin;
  else if(i==1) fp=cos;
  else fp=tan;
  
  ar2=trig_generic(arr, n, fp);
  for(i=0; i<n; i++) 
    printf("Trig value of %lf is: %lf\n", arr[i], ar2[i]); 

  return 0; 
}