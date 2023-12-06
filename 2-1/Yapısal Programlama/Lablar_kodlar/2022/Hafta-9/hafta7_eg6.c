/* how to compile and create exe for the main function:
cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test _hafta6_eg6.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char std_name[30]; 
  char std_tcno[11];
  unsigned int std_bdate_day : 5,  std_bdate_month : 4, std_bdate_year : 11;
  char std_no[8];
} STUDENT_INFO;

void sort_by_number(STUDENT_INFO *stdptr, int n){ // bubble sort
  int i,j;
  long int first, second;
  STUDENT_INFO tmp;
  for(i=0; i<n-1; i++)
    for(j=0; j<n-i-1; j++){
	first = atoll(stdptr[j].std_no);
	second = atoll(stdptr[j+1].std_no);
	if(first > second ){
	  tmp=stdptr[j]; 
	  stdptr[j]=stdptr[j+1]; 
	  stdptr[j+1]=tmp;
	}
    }
}
int main ()  {  int j, n;
  unsigned int val;
  STUDENT_INFO *stdinfo;
  printf("Enter the number of the students: \n"); scanf("%d", &n);
  stdinfo=(STUDENT_INFO *) malloc(n*sizeof(STUDENT_INFO));
  if(stdinfo == NULL){
    printf("Malloc is not successful\n");
    exit(0);
  }
  for(j=0; j<n; j++){
    printf("Enter name of the %d-th person:\n", j+1);
    scanf("%s", stdinfo[j].std_name);
    printf("Enter tcno of the %d-th person:\n", j+1);
    scanf("%s", stdinfo[j].std_tcno);
    printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
    scanf("%u", &val); stdinfo[j].std_bdate_day=val;
    printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
    scanf("%u", &val); stdinfo[j].std_bdate_month=val;
    printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
    scanf("%u", &val); stdinfo[j].std_bdate_year=val;
    printf("Enter student number of the %d-th person:\n", j+1);
    scanf("%s", stdinfo[j].std_no);
  }


  for(j=0; j<n; j++)
    printf("%d-th person: %s\t%s\t%u.%u.%u\t%s\n", j+1, stdinfo[j].std_name, 
	stdinfo[j].std_tcno, stdinfo[j].std_bdate_day, stdinfo[j].std_bdate_month, 
	stdinfo[j].std_bdate_year, stdinfo[j].std_no);

  sort_by_number(stdinfo, n);
  printf("After sorting the students by the student number: \n");  for(j=0; j<n; j++)
    printf("%d-th person: %s\t%s\t%u.%u.%u\t%s\n", j+1, stdinfo[j].std_name, 
	stdinfo[j].std_tcno, stdinfo[j].std_bdate_day, stdinfo[j].std_bdate_month, 
	stdinfo[j].std_bdate_year, stdinfo[j].std_no);
   return 0; 
}