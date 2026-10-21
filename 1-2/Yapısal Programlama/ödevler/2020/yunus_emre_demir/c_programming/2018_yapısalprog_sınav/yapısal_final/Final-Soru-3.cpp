#include <stdio.h>
#include <stddef.h> 
#include <string.h>

int copyfile(FILE *fp1, FILE *fp2){
int i=0;
char str1[100], str2[100];
  
  while (!feof( fp1 )){
	str1[i]=fgetc(fp1);
	i++;
	}
	printf("%s\n",str1);
	
  i=0;
  while (!feof( fp2 )){
	str2[i]=fgetc(fp2);
	i++;
	}

	if(strcmp(str1,str2) == 0)
		return 0;
	else
		return -20;
}

int main(){
  FILE *fp1, *fp2;
  int result;
  
  if ((fp1 = fopen("birinci.txt", "r+" )) == NULL) 
    printf("Could not open the input file\n");

  if ((fp2=fopen ("ikinci.txt", "r+" )) == NULL)
    printf("Could not open the output file\n");

  result=copyfile(fp1, fp2);
  if(result == 0)
    printf("ayni\n");
  else
    printf("ayni degil\n");
    
fclose(fp1); 
fclose(fp2); 

  return 0; 
}
