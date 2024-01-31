/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta10_codes
cc -o test hafta10_ex3_ln.c 
*/

#include <stddef.h>
#include <stdio.h>
#define FAIL 0 
#define SUCCESS 1 
#define LINESIZE 100

int copyfile(char * infile, char * outfile){
  FILE *fp1, *fp2;
  char line[LINESIZE];
  if ((fp1 = fopen( infile, "r" )) == NULL)
     return FAIL;
  if ((fp2 = fopen( outfile, "w" )) == NULL){
    fclose(fp1);
    return FAIL;
  }

  while (fgets ( line, LINESIZE-1, fp1 ) != NULL)
    fputs( line, fp2 );
  fclose(fp1); 
  fclose(fp2);
  return SUCCESS;
}

int main(){
  char infl[100], outfl[100]; 
  int result;
  printf("enter name of the input file\n"); 
  scanf("%s", infl);

  printf("enter name of the output file\n"); 
  scanf("%s", outfl);
 
  result=copyfile(infl, outfl);
  if(result == SUCCESS)
    printf("input file is copied to the output file \n");
  if(result == FAIL)
    printf("input file could not be copied to the output file \n");

  return 0; 
}
