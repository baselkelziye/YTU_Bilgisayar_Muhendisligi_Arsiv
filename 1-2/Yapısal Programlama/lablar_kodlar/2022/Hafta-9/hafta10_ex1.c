/* how to compile and create exe for the main function:
After each upgrade: xcode-select --install
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta10_codes
cc -o test hafta10_ex1.c 
*/

#include <stdio.h>
#include <stddef.h> 
// Returns a pointer to FILE struct:
FILE *open_file1() { 
  FILE *fp;
  if ((fp = fopen( "test","r" )) == NULL)
    fprintf( stderr, "Error opening file test\n" );
  return fp;
}
FILE *open_file2(char* file_name, char* access_mode){
  FILE *fp;
  if ((fp = fopen(file_name, access_mode)) == NULL)
    fprintf( stderr, "Error opening file %s with access mode %s\n", file_name, access_mode);
  return fp;
}

int main(){
  char flnm[100], mode[2]; 
  printf("enter name of the file to be opened\n"); 
  scanf("%s", flnm);
  printf("enter name of the access mode\n"); 
  scanf("%s", mode);

  if ((open_file2(flnm, mode))  == NULL)
    return 1;

  printf("file is opened\n"); 
  return 0; 
}
