#include <stdlib.h>
#include <stdio.h>

/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta3_codes
cc -o test hafta3_4_PtoP.c 
*/

int main(){
  int **p, j;
  p=(int**)malloc(sizeof(int*));      // if not, you'll get seg-fault 	
  p[0] = (int *)malloc(sizeof(int) ); // if not, you'll get seg-fault 

  //scanf("p degerini giriniz: %d\n", *p);
  printf("j degerini giriniz\n");
  scanf("%d", &j);
  printf("j degeri: %d\n", j);
 
  printf("p degerini giriniz:\n");
  scanf("%d", *p);
  printf("p degeri: %d\n", **p);

  return 0; }
