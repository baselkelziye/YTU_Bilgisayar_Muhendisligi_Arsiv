#include <stdio.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta3_codes
cc -o test hafta3_2_pointarg.c 
*/

/*
void clear(int *p){
  *p=0; // store a 0 at address p.
}
int main(){
  int s[3]={1,2,3};
  clear(&s[1]);
  printf("s[0]: %d\t s[1]: %d\t s[2]: %d\t", s[0], s[1], s[2]);
  printf("\n");
  return 0; 
}
*/

void clear(long *p){  *p=0; // store a 0 at address p.}int main(){  short s[3]={1,2,3};
  clear(&s[1]);
  printf("s[0]: %d\t s[1]: %d\t s[2]: %d\t", s[0], s[1], s[2]);
  printf("\n");
  return 0; }
