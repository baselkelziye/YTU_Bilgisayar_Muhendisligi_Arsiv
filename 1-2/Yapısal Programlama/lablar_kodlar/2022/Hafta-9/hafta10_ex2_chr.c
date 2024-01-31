/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta10_codes
cc -o test hafta10_ex2_chr.c 
*/

#include <stdio.h>
#include <stddef.h> 
#define FAIL 0 
#define SUCCESS 1
int copyfile(char * infile, char * outfile){
  FILE *fp1, *fp2;
  if ((fp1 = fopen(infile, "rb" )) == NULL) {
    printf("Could not open the input file\n");
    return FAIL; 
  }
  if ((fp2=fopen (outfile, "wb" )) == NULL)
  {
    printf("Could not open the output file\n");
    fclose ( fp1 );
    return FAIL;
  }
  // **** When the end-of-file is encountered, the feof() function returns a non-0 value. 
  while (!feof( fp1 ))
    putc( getc(fp1), fp2 );

/* NOTE: we cannot use the return value of getc() to test for an end-of-file character
    because the file is opened in the binary mode. For example, if we wrote
    int c;
    while ((c = getc( fp1 )) != EOF)
    the loop will exit whenever the character read has the same value as EOF. 
    This may or may not be a true end-of-file condition in binary files. 
    However, the feof() function will exactly provide us to check if we reach the eof.
*/ 

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
