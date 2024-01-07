/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta10_codes
cc -o test hafta10_ex4_blk.c 
*/

#include <stddef.h>
#include <stdio.h>
#define FAIL 0 
#define SUCCESS 1 
#define BLOCKSIZE 512
typedef char DATA;

int copyfile(char * infile, char * outfile){
  FILE *fp1, *fp2;
  int num_read; 
  char block[BLOCKSIZE];
  if ((fp1 = fopen( infile, "rb" )) == NULL){
    printf( "Error opening file %s for input.\n", infile );
    return FAIL;
  }
  if ((fp2 = fopen( outfile, "wb" )) == NULL){
    printf( "Error opening file %s for output.\n", outfile );
    fclose(fp1);
    return FAIL;
  }

  while ((num_read = fread( block, sizeof(DATA), BLOCKSIZE, fp1 )) == BLOCKSIZE)
    fwrite( block, sizeof(DATA), num_read, fp2 );

  fwrite( block, sizeof(DATA), num_read, fp2 );
  fclose(fp1); 
  fclose(fp2);
  if (ferror( fp1)) {
    printf( "Error reading file %s\n", infile );
    return FAIL;
  }
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

