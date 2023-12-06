/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta11_codes
cc -o test hafta11_ex1_create_file_first.c 
*/
#include <stdio.h>

typedef struct { 	unsigned int day : 5;
 	unsigned int month : 4;
 	unsigned int year : 11;
} DATE; 			
typedef struct {   char ps_name[19], ps_tcno[11];   DATE ps_birth_date;} PERSONALSTAT;
int main(){
	int j;
	FILE *fp;
	unsigned int val;
	PERSONALSTAT ps2[4];

	fp=fopen("records.dat", "wb");

	for(j=0; j<4; j++){
		printf("Enter name of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_name);
		printf("Enter tcno of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_tcno);
		printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
		// NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.day);
		scanf("%u", &val); ps2[j].ps_birth_date.day=val;
		printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
		// NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.month);
		scanf("%u", &val); ps2[j].ps_birth_date.month=val;
		printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
		// NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.year);
		scanf("%u", &val); ps2[j].ps_birth_date.year=val;

		fwrite(&ps2[j], sizeof(PERSONALSTAT), 1, fp);
		// char *stz="\n"; fwrite(stz, 1, 1, fp);
	}

	return 0;
}
